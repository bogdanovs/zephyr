#!/usr/bin/env bash
# Copyright 2023 Nordic Semiconductor
# SPDX-License-Identifier: Apache-2.0

source $(dirname "${BASH_SOURCE[0]}")/../../_mesh_test.sh

# Test if callback `lost_target` is called on every target failing on Verify step and `ended`
# callback is called when all targets are lost at this step.

# The test instance sequence must stay as it is due to addressing scheme
overlay=overlay_pst_conf
RunTest dfu_all_tgts_lost_on_verify \
	dfu_cli_all_targets_lost_on_verify \
	dfu_target_fail_on_verify \
	dfu_target_fail_on_verify \
	dfu_target_fail_on_verify \
	-- -argstest targets=3
