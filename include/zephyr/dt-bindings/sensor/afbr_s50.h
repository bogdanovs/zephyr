/*
 * Copyright (c) 2025 Croxel Inc.
 * Copyright (c) 2025 CogniPilot Foundation
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#ifndef ZEPHYR_INCLUDE_DT_BINDINGS_BRCM_AFBR_S50_H_
#define ZEPHYR_INCLUDE_DT_BINDINGS_BRCM_AFBR_S50_H_

/**
 * @name afbr_s50 Dual Frequency Mode Settings
 * @{
 */
#define AFBR_S50_DT_DFM_MODE_OFF		0
#define AFBR_S50_DT_DFM_MODE_4X			1
#define AFBR_S50_DT_DFM_MODE_8X			2
/** @} */

/**
 * @name afbr_s50 Measurement Modes
 * @{
 */
#define AFBR_S50_DT_MODE_SHORT_RANGE					1
#define AFBR_S50_DT_MODE_LONG_RANGE					2
#define AFBR_S50_DT_MODE_HIGH_SPEED_SHORT_RANGE				5
#define AFBR_S50_DT_MODE_HIGH_SPEED_LONG_RANGE				6
#define AFBR_S50_DT_MODE_HIGH_PRECISION_SHORT_RANGE			9
#define AFBR_S50_DT_MODE_SHORT_RANGE_LASER_CLASS_2			129
#define AFBR_S50_DT_MODE_LONG_RANGE_LASER_CLASS_2			130
#define AFBR_S50_DT_MODE_HIGH_SPEED_SHORT_RANGE_LASER_CLASS_2		133
#define AFBR_S50_DT_MODE_HIGH_SPEED_LONG_RANGE_LASER_CLASS_2		134
#define AFBR_S50_DT_MODE_HIGH_PRECISION_SHORT_RANGE_LASER_CLASS_2	137
/** @} */

#endif /* ZEPHYR_INCLUDE_DT_BINDINGS_BRCM_AFBR_S50_H_ */
