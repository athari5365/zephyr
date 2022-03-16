/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <sys/printk.h>

bool g_debug = false;
char *version = "POC";

void main(void)
{
    //while loop
    while(g_debug == true){};

    printk("Hello World loop 5 times\n");
    for(int i=0;i<5;i++) {
	printk("%d: Hello World from RISCV Zephyr! BOARD=%s, version=%s.\n",i+1, CONFIG_BOARD, version);
    }

    printk("main End\n");
    return;
}
