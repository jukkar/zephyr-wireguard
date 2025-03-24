/*
 * Copyright (c) 2025 Jukka Rissanen
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(vpn_sample, LOG_LEVEL_DBG);

extern int init_vpn(void);

int main(void)
{
	init_vpn();
	return 0;
}
