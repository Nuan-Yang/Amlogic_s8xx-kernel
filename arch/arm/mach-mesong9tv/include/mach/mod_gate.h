/*
 * arch/arm/mach-mesong9tv/include/mach/mod_gate.h
 *
 * Copyright (C) 2014 Amlogic, Inc.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef __MACH_MESONG9TV_MOD_GATE_H
#define __MACH_MESONG9TV_MOD_GATE_H

#include <mach/power_gate.h>

typedef enum {
	MOD_VDEC = 0,
	MOD_AUDIO,
	MOD_HDMI,
	MOD_VENC,
	MOD_TCON,
//	MOD_LVDS,
	MOD_LCD,
	MOD_SPI,
	MOD_UART0,
	MOD_UART1,
	MOD_UART2,
	MOD_SANA,
	MOD_ROM,
	MOD_EFUSE,
	MOD_RANDOM_NUM_GEN,
	MOD_ETHERNET,
	MOD_MEDIA_CPU,
	MOD_GE2D,
	MOD_AHB,
	MOD_DEMUX,
	MOD_SMART_CARD,
	MOD_SDHC,
	MOD_STREAM,
	MOD_BLK_MOV,
	MOD_MISC_DVIN,
	MOD_USB,
	MOD_SDIO,
	MOD_MAX_NUM,
} mod_type_t;

#define GATE_ON(_MOD) \
	do { \
		if (0) printk(KERN_INFO "gate on %s %x, %x\n", GCLK_NAME_##_MOD, GCLK_REG_##_MOD, GCLK_MASK_##_MOD); \
		SET_CBUS_REG_MASK(GCLK_REG_##_MOD, GCLK_MASK_##_MOD); \
	} while(0)


#define GATE_OFF(_MOD) \
	do { \
		if (0) printk(KERN_INFO "gate off %s %x, %x\n", GCLK_NAME_##_MOD, GCLK_REG_##_MOD, GCLK_MASK_##_MOD); \
		CLEAR_CBUS_REG_MASK(GCLK_REG_##_MOD, GCLK_MASK_##_MOD); \
	} while(0)

extern void switch_mod_gate_by_type(mod_type_t type, int flag);
extern void switch_mod_gate_by_name(const char* mod_name, int flag);
extern void power_gate_init(void);
extern void switch_lcd_mod_gate(int flag);

#endif // __MACH_MESONG9TV_MOD_GATE_H
