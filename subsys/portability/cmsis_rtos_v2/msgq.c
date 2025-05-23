/*
 * Copyright (c) 2018 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/portability/cmsis_types.h>
#include <string.h>
#include "wrapper.h"

K_MEM_SLAB_DEFINE(cmsis_rtos_msgq_cb_slab, sizeof(struct cmsis_rtos_msgq_cb),
		  CONFIG_CMSIS_V2_MSGQ_MAX_COUNT, 4);

static const osMessageQueueAttr_t init_msgq_attrs = {
	.name = "ZephyrMsgQ",
	.attr_bits = 0,
	.cb_mem = NULL,
	.cb_size = 0,
	.mq_mem = NULL,
	.mq_size = 0,
};

/**
 * @brief Create and Initialize Message queue.
 */
osMessageQueueId_t osMessageQueueNew(uint32_t msg_count, uint32_t msg_size,
				     const osMessageQueueAttr_t *attr)
{
	struct cmsis_rtos_msgq_cb *msgq;

	BUILD_ASSERT(K_HEAP_MEM_POOL_SIZE >= CONFIG_CMSIS_V2_MSGQ_MAX_DYNAMIC_SIZE,
		     "heap must be configured to be at least the max dynamic size");

	if (k_is_in_isr()) {
		return NULL;
	}

	if ((attr != NULL) && (attr->mq_size < msg_count * msg_size)) {
		return NULL;
	}

	if (attr == NULL) {
		attr = &init_msgq_attrs;
	}

	if (attr->cb_mem != NULL) {
		__ASSERT(attr->cb_size == sizeof(struct cmsis_rtos_msgq_cb), "Invalid cb_size\n");
		msgq = (struct cmsis_rtos_msgq_cb *)attr->cb_mem;
	} else if (k_mem_slab_alloc(&cmsis_rtos_msgq_cb_slab, (void **)&msgq, K_MSEC(100)) != 0) {
		return NULL;
	}
	(void)memset(msgq, 0, sizeof(struct cmsis_rtos_msgq_cb));
	msgq->is_cb_dynamic_allocation = attr->cb_mem == NULL;

	if (attr->mq_mem == NULL) {
		__ASSERT((msg_count * msg_size) <= CONFIG_CMSIS_V2_MSGQ_MAX_DYNAMIC_SIZE,
			 "message queue size exceeds dynamic maximum");

#if (K_HEAP_MEM_POOL_SIZE > 0)
		msgq->pool = k_calloc(msg_count, msg_size);
		if (msgq->pool == NULL) {
			if (msgq->is_cb_dynamic_allocation) {
				k_mem_slab_free(&cmsis_rtos_msgq_cb_slab, (void *)msgq);
			}
			return NULL;
		}
		msgq->is_dynamic_allocation = TRUE;
#else
		if (msgq->is_cb_dynamic_allocation) {
			k_mem_slab_free(&cmsis_rtos_msgq_cb_slab, (void *)msgq);
		}
		return NULL;
#endif
	} else {
		msgq->pool = attr->mq_mem;
		msgq->is_dynamic_allocation = FALSE;
	}

	k_msgq_init(&msgq->z_msgq, msgq->pool, msg_size, msg_count);

	msgq->name = (attr->name == NULL) ? init_msgq_attrs.name : attr->name;

	return (osMessageQueueId_t)(msgq);
}

/**
 * @brief Put a message to a Queue.
 */
osStatus_t osMessageQueuePut(osMessageQueueId_t msgq_id, const void *msg_ptr, uint8_t msg_prio,
			     uint32_t timeout)
{
	struct cmsis_rtos_msgq_cb *msgq = (struct cmsis_rtos_msgq_cb *)msgq_id;
	int retval;

	ARG_UNUSED(msg_prio);

	if (msgq == NULL) {
		return osErrorParameter;
	}

	/* Can be called from ISRs only if timeout is set to 0 */
	if (timeout > 0 && k_is_in_isr()) {
		return osErrorParameter;
	}

	if (timeout == 0U) {
		retval = k_msgq_put(&msgq->z_msgq, (void *)msg_ptr, K_NO_WAIT);
	} else if (timeout == osWaitForever) {
		retval = k_msgq_put(&msgq->z_msgq, (void *)msg_ptr, K_FOREVER);
	} else {
		retval = k_msgq_put(&msgq->z_msgq, (void *)msg_ptr, K_TICKS(timeout));
	}

	if (retval == 0) {
		return osOK;
	} else if (retval == -EAGAIN) {
		return osErrorTimeout;
	} else {
		return osErrorResource;
	}
}

/**
 * @brief Get a message or Wait for a Message from a Queue.
 */
osStatus_t osMessageQueueGet(osMessageQueueId_t msgq_id, void *msg_ptr, uint8_t *msg_prio,
			     uint32_t timeout)
{
	struct cmsis_rtos_msgq_cb *msgq = (struct cmsis_rtos_msgq_cb *)msgq_id;
	int retval;

	ARG_UNUSED(msg_prio);

	if (msgq == NULL) {
		return osErrorParameter;
	}

	/* Can be called from ISRs only if timeout is set to 0 */
	if (timeout > 0 && k_is_in_isr()) {
		return osErrorParameter;
	}

	if (timeout == 0U) {
		retval = k_msgq_get(&msgq->z_msgq, msg_ptr, K_NO_WAIT);
	} else if (timeout == osWaitForever) {
		retval = k_msgq_get(&msgq->z_msgq, msg_ptr, K_FOREVER);
	} else {
		retval = k_msgq_get(&msgq->z_msgq, msg_ptr, K_TICKS(timeout));
	}

	if (retval == 0) {
		return osOK;
	} else if (retval == -EAGAIN) {
		return osErrorTimeout;
	} else if (retval == -ENOMSG) {
		return osErrorResource;
	}

	return osOK;
}

/**
 * @brief Get maximum number of messages in a Message Queue.
 */
uint32_t osMessageQueueGetCapacity(osMessageQueueId_t msgq_id)
{
	struct cmsis_rtos_msgq_cb *msgq = (struct cmsis_rtos_msgq_cb *)msgq_id;

	if (msgq == NULL) {
		return 0;
	} else {
		return msgq->z_msgq.max_msgs;
	}
}

/**
 * @brief Get maximum message size in a Message Queue.
 */
uint32_t osMessageQueueGetMsgSize(osMessageQueueId_t msgq_id)
{
	struct cmsis_rtos_msgq_cb *msgq = (struct cmsis_rtos_msgq_cb *)msgq_id;

	if (msgq == NULL) {
		return 0;
	} else {
		return msgq->z_msgq.msg_size;
	}
}

/**
 * @brief Get number of queued messages in a Message Queue.
 */
uint32_t osMessageQueueGetCount(osMessageQueueId_t msgq_id)
{
	struct cmsis_rtos_msgq_cb *msgq = (struct cmsis_rtos_msgq_cb *)msgq_id;

	if (msgq == NULL) {
		return 0;
	} else {
		return k_msgq_num_used_get(&msgq->z_msgq);
	}
}

/**
 * @brief Get number of available slots for messages in a Message Queue.
 */
uint32_t osMessageQueueGetSpace(osMessageQueueId_t msgq_id)
{
	struct cmsis_rtos_msgq_cb *msgq = (struct cmsis_rtos_msgq_cb *)msgq_id;

	if (msgq == NULL) {
		return 0;
	} else {
		return k_msgq_num_free_get(&msgq->z_msgq);
	}
}

/**
 * @brief Get name of a Message Queue object.
 * This function may be called from Interrupt Service Routines.
 */
const char *osMessageQueueGetName(osMessageQueueId_t msgq_id)
{
	struct cmsis_rtos_msgq_cb *msgq = (struct cmsis_rtos_msgq_cb *)msgq_id;

	if (msgq == NULL) {
		return NULL;
	}
	return msgq->name;
}

/**
 * @brief Reset a Message Queue to initial empty state.
 */
osStatus_t osMessageQueueReset(osMessageQueueId_t msgq_id)
{
	struct cmsis_rtos_msgq_cb *msgq = (struct cmsis_rtos_msgq_cb *)msgq_id;

	if (msgq == NULL) {
		return osErrorParameter;
	}

	if (k_is_in_isr()) {
		return osErrorISR;
	}

	/* The status code "osErrorResource" (the message queue specified by
	 * parameter msgq_id is in an invalid message queue state) is not
	 * supported in Zephyr.
	 */

	k_msgq_purge(&msgq->z_msgq);

	return osOK;
}

/**
 * @brief Delete a Message Queue object.
 */
osStatus_t osMessageQueueDelete(osMessageQueueId_t msgq_id)
{
	struct cmsis_rtos_msgq_cb *msgq = (struct cmsis_rtos_msgq_cb *)msgq_id;

	if (msgq == NULL) {
		return osErrorParameter;
	}

	if (k_is_in_isr()) {
		return osErrorISR;
	}

	/* The status code "osErrorResource" (the message queue specified by
	 * parameter msgq_id is in an invalid message queue state) is not
	 * supported in Zephyr.
	 */

	if (msgq->is_dynamic_allocation) {
		k_free(msgq->pool);
	}
	if (msgq->is_cb_dynamic_allocation) {
		k_mem_slab_free(&cmsis_rtos_msgq_cb_slab, (void *)msgq);
	}
	return osOK;
}
