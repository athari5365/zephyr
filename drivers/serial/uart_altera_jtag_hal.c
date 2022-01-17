/*
 * Copyright (c) 2017 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */


#include <kernel.h>
#include <arch/cpu.h>
#include <drivers/uart.h>
#include <sys/sys_io.h>

//#include "altera_avalon_jtag_uart.h"
//#include "altera_avalon_jtag_uart_regs.h"

#define DT_DRV_COMPAT	altr_jtag_uart

#define UART_ALTERA_JTAG_DATA_REG                  0
#define UART_ALTERA_JTAG_CONTROL_REG               1

#define IE_TX        (1 << 0)    /* TX Interrupt Enable */
#define IE_RX        (1 << 1)    /* RX Interrupt Enable */
#define TXDATA_MASK   0xFF        /* Transmit Data Mask */
#define WFIFO_MASK    0xFFFF0000        /* Transmit Data Mask */

struct uart_altera_jtag_regs_t {
	uint32_t data;
	uint32_t cnt;
};

#define DEV_CFG(dev) \
	((const struct uart_device_config * const)(dev)->config)

#define DEV_UART(dev)						\
	((struct uart_altera_jtag_regs_t *)(DEV_CFG(dev))->base)

/*SA
extern int altera_avalon_jtag_uart_read(altera_avalon_jtag_uart_state *sp,
		char *buffer, int space, int flags);
extern int altera_avalon_jtag_uart_write(altera_avalon_jtag_uart_state *sp,
		const char *ptr, int count, int flags);
*/
static void uart_altera_jtag_poll_out(const struct device *dev,
					       unsigned char c)
{
//	const struct uart_device_config *config;
//	altera_avalon_jtag_uart_state ustate;

//	config = DEV_CFG(dev);

//	ustate.base = JTAG_UART_0_BASE;
//	altera_avalon_jtag_uart_write(&ustate, &c, 1, 0);

    volatile struct uart_altera_jtag_regs_t *uart = DEV_UART(dev);

    /* Wait while TX FIFO not full*/
    while(!(uart->cnt & WFIFO_MASK)){
	}

	uint32_t data_val = uart->data;
	data_val &= ~TXDATA_MASK;
	data_val |= c;
	uart->data = data_val;

}

static int uart_altera_jtag_init(const struct device *dev)
{
	/*
	 * Work around to clear interrupt enable bits
	 * as it is not being done by HAL driver explicitly.
	 */
//	IOWR_ALTERA_AVALON_JTAG_UART_CONTROL(JTAG_UART_0_BASE, 0);
//	return 0;

    /* Disable read and write interrupt*/
	volatile struct uart_altera_jtag_regs_t *uart = DEV_UART(dev);
	uint32_t cnt_val = uart->cnt;

	cnt_val &= ~(IE_TX | IE_RX);
	uart->cnt = cnt_val;
	return 0;
}

static const struct uart_driver_api uart_altera_jtag_driver_api = {
	.poll_in = NULL,
	.poll_out = &uart_altera_jtag_poll_out,
	.err_check = NULL,
};

static const struct uart_device_config uart_altera_jtag_dev_cfg_0 = {
	.base = (void *)JTAG_UART_0_BASE,
	.sys_clk_freq = 0, /* Unused */
};

DEVICE_DT_INST_DEFINE(0, uart_altera_jtag_init, NULL,
		      NULL, &uart_altera_jtag_dev_cfg_0,
		      PRE_KERNEL_1, CONFIG_KERNEL_INIT_PRIORITY_DEVICE,
		      &uart_altera_jtag_driver_api);
