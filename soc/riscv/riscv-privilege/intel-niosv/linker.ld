/*
 * Copyright (c) 2021 Henrik Brix Andersen <henrik@brixandersen.dk>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <linker/linker-tool.h>
/*
#include <system.h>
*/

/*
 * SA RAM_BASE and RAM_SIZE_VALUE get from system.h

#define CONFIG_SRAM_BASE_ADDRESS RAM_BASE 
#define CONFIG_SRAM_SIZE RAM_SIZE_VALUE
*/

/*
#define CONFIG_SRAM_BASE_ADDRESS 0x0 
#define CONFIG_SRAM_SIZE 131072
*/

#include <arch/riscv/common/linker.ld>
