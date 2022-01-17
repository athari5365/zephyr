/*
 * Copyright (c) 2021 Henrik Brix Andersen <henrik@brixandersen.dk>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef RISCV_INTEL_NIOSV_SOC_H
#define RISCV_INTEL_NIOSV_SOC_H

#include <soc_common.h>
#include <devicetree.h>

/* Machine System Timer (MTIME) registers */
//#define RISCV_MTIME_BASE    ALT_CPU_MTIME_OFFSET + 0x8
//#define RISCV_MTIMECMP_BASE ALT_CPU_MTIME_OFFSET

//SA TBD define JTAG related reg
//#define JTAG_UART_0_BASE JTAG_UART_BASE

//SA hardcode value here, need to extrac from system.h
#define RISCV_MTIME_BASE    0x00090000 + 0x8
#define RISCV_MTIMECMP_BASE 0x00090000

#define JTAG_UART_0_BASE 0x90078

#endif /* RISCV_INTEL_NIOSV_SOC_H */
