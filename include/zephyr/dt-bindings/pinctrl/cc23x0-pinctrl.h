/*
 * Copyright (c) 2024 Texas Instruments Incorporated
 * Copyright (c) 2024 BayLibre, SAS
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef CC23X0_PINCTRL_COMMON_H_
#define CC23X0_PINCTRL_COMMON_H_

/*
 * The whole TI CC23X0 pin configuration information is encoded in a 32-bit
 * bitfield organized as follow:
 *
 * - 31:     Reserved
 * - 30:     Input hysteresis
 * - 29:     Input capability of IO
 * - 28..27: Reserved
 * - 26..24: IO mode
 * - 23..22: Reserved
 * - 21..20: Wakeup configuration from shutdown
 * - 19:     Reserved
 * - 18:     Wakeup capability from standby
 * - 17..16: Edge detection configuration
 * - 15:     Reserved
 * - 14..13: Pull control
 * - 12..3:  Reserved
 * - 2..0:   Function configuration
 */

/* TI CC23X0 function configuration */

#define IOC_PORTCFG_BASE	0U
#define IOC_PORTCFG_PFUNC1	1U
#define IOC_PORTCFG_PFUNC2	2U
#define IOC_PORTCFG_PFUNC3	3U
#define IOC_PORTCFG_PFUNC4	4U
#define IOC_PORTCFG_PFUNC5	5U
#define IOC_PORTCFG_ANA		6U
#define IOC_PORTCFG_DTB		7U

/* TI CC23X0 peripheral pin mapping */

#define DIO0_GPIO0		IOC_PORTCFG_BASE
#define DIO0_SPI0_CSN		IOC_PORTCFG_PFUNC1
#define DIO0_I2C0_SDA		IOC_PORTCFG_PFUNC2
#define DIO0_T3_C2		IOC_PORTCFG_PFUNC3
#define DIO0_ADC5		IOC_PORTCFG_ANA

#define DIO1_GPIO1		IOC_PORTCFG_BASE
#define DIO1_T3_C1		IOC_PORTCFG_PFUNC1
#define DIO1_LRFD7		IOC_PORTCFG_PFUNC2
#define DIO1_T1_F		IOC_PORTCFG_PFUNC3
#define DIO1_UART0_RTS		IOC_PORTCFG_PFUNC4
#define DIO1_ADC4		IOC_PORTCFG_ANA
#define DIO1_DTB2		IOC_PORTCFG_DTB

#define DIO2_GPIO2		IOC_PORTCFG_BASE
#define DIO2_T0_PE		IOC_PORTCFG_PFUNC1
#define DIO2_T2_C1N		IOC_PORTCFG_PFUNC2
#define DIO2_UART0_CTS		IOC_PORTCFG_PFUNC3
#define DIO2_ADC3		IOC_PORTCFG_ANA

#define DIO3_GPIO3		IOC_PORTCFG_BASE
#define DIO3_LFCI		IOC_PORTCFG_PFUNC1
#define DIO3_T0_C1N		IOC_PORTCFG_PFUNC2
#define DIO3_LRFD0		IOC_PORTCFG_PFUNC3
#define DIO3_T3_C1		IOC_PORTCFG_PFUNC4
#define DIO3_T1_C2		IOC_PORTCFG_PFUNC5
#define DIO3_LFXT_P		IOC_PORTCFG_ANA
#define DIO3_DTB7		IOC_PORTCFG_DTB

#define DIO4_GPIO4		IOC_PORTCFG_BASE
#define DIO4_T0_C2N		IOC_PORTCFG_PFUNC1
#define DIO4_UART0_TXD		IOC_PORTCFG_PFUNC2
#define DIO4_LRFD1		IOC_PORTCFG_PFUNC3
#define DIO4_SPI0_MOSI		IOC_PORTCFG_PFUNC4
#define DIO4_T0_C2		IOC_PORTCFG_PFUNC5
#define DIO4_LFXT_N		IOC_PORTCFG_ANA
#define DIO4_DTB8		IOC_PORTCFG_DTB

#define DIO5_GPIO5		IOC_PORTCFG_BASE
#define DIO5_T2_C2		IOC_PORTCFG_PFUNC1
#define DIO5_LRFD6		IOC_PORTCFG_PFUNC3
#define DIO5_ADC2		IOC_PORTCFG_ANA

#define DIO6_GPIO6		IOC_PORTCFG_BASE
#define DIO6_SPI0_CSN		IOC_PORTCFG_PFUNC1
#define DIO6_I2C0_SCL		IOC_PORTCFG_PFUNC2
#define DIO6_T1_C2		IOC_PORTCFG_PFUNC3
#define DIO6_LRFD2		IOC_PORTCFG_PFUNC4
#define DIO6_UART0_TXD		IOC_PORTCFG_PFUNC5
#define DIO6_ADC1_AREFP		IOC_PORTCFG_ANA
#define DIO6_DTB6		IOC_PORTCFG_DTB

#define DIO7_GPIO7		IOC_PORTCFG_BASE
#define DIO7_T3_C1		IOC_PORTCFG_PFUNC1
#define DIO7_LRFD4		IOC_PORTCFG_PFUNC3
#define DIO7_ADC0_AREFM		IOC_PORTCFG_ANA

#define DIO8_GPIO8		IOC_PORTCFG_BASE
#define DIO8_SPI0_SCLK		IOC_PORTCFG_PFUNC1
#define DIO8_UART0_RTS		IOC_PORTCFG_PFUNC2
#define DIO8_T1_C0N		IOC_PORTCFG_PFUNC3
#define DIO8_I2C0_SDA		IOC_PORTCFG_PFUNC4
#define DIO8_T0_C0N		IOC_PORTCFG_PFUNC5
#define DIO8_DTB3		IOC_PORTCFG_DTB

#define DIO9_GPIO9		IOC_PORTCFG_BASE
#define DIO9_T3_C0		IOC_PORTCFG_PFUNC1
#define DIO9_LRFD3		IOC_PORTCFG_PFUNC3

#define DIO10_GPIO10		IOC_PORTCFG_BASE
#define DIO10_LPC0		IOC_PORTCFG_PFUNC1
#define DIO10_T2_PE		IOC_PORTCFG_PFUNC2
#define DIO10_T3_C0N		IOC_PORTCFG_PFUNC3

#define DIO11_GPIO11		IOC_PORTCFG_BASE
#define DIO11_SPI0_CSN		IOC_PORTCFG_PFUNC1
#define DIO11_T1_C2N		IOC_PORTCFG_PFUNC2
#define DIO11_T0_C0		IOC_PORTCFG_PFUNC3
#define DIO11_LRFD0		IOC_PORTCFG_PFUNC4
#define DIO11_SPI0_MISO		IOC_PORTCFG_PFUNC5
#define DIO11_DTB9		IOC_PORTCFG_DTB

#define DIO12_GPIO12		IOC_PORTCFG_BASE
#define DIO12_SPI0_MISO		IOC_PORTCFG_PFUNC1
#define DIO12_SPI0_MOSI		IOC_PORTCFG_PFUNC2
#define DIO12_UART0_RXD		IOC_PORTCFG_PFUNC3
#define DIO12_T1_C1		IOC_PORTCFG_PFUNC4
#define DIO12_I2C0_SDA		IOC_PORTCFG_PFUNC5
#define DIO12_DTB13		IOC_PORTCFG_DTB

#define DIO13_GPIO13		IOC_PORTCFG_BASE
#define DIO13_SPI0_MISO		IOC_PORTCFG_PFUNC1
#define DIO13_SPI0_MOSI		IOC_PORTCFG_PFUNC2
#define DIO13_UART0_TXD		IOC_PORTCFG_PFUNC3
#define DIO13_T0_C0N		IOC_PORTCFG_PFUNC4
#define DIO13_T1_F		IOC_PORTCFG_PFUNC5
#define DIO13_DTB4		IOC_PORTCFG_DTB

#define DIO14_GPIO14		IOC_PORTCFG_BASE
#define DIO14_T3_C2		IOC_PORTCFG_PFUNC1
#define DIO14_T1_C2N		IOC_PORTCFG_PFUNC2
#define DIO14_LRFD5		IOC_PORTCFG_PFUNC3
#define DIO14_T1_F		IOC_PORTCFG_PFUNC4

#define DIO15_GPIO15		IOC_PORTCFG_BASE
#define DIO15_UART0_RXD		IOC_PORTCFG_PFUNC1
#define DIO15_T2_C0N		IOC_PORTCFG_PFUNC2
#define DIO15_CKMIN		IOC_PORTCFG_PFUNC3

#define DIO16_GPIO16		IOC_PORTCFG_BASE
#define DIO16_SPI0_MOSI		IOC_PORTCFG_PFUNC1
#define DIO16_UART0_RXD		IOC_PORTCFG_PFUNC2
#define DIO16_I2C0_SDA		IOC_PORTCFG_PFUNC3
#define DIO16_T1_C2		IOC_PORTCFG_PFUNC4
#define DIO16_T1_C0N		IOC_PORTCFG_PFUNC5
#define DIO16_DTB10		IOC_PORTCFG_DTB

#define DIO17_GPIO17		IOC_PORTCFG_BASE
#define DIO17_SPI0_SCLK		IOC_PORTCFG_PFUNC1
#define DIO17_UART0_TXD		IOC_PORTCFG_PFUNC2
#define DIO17_I2C0_SCL		IOC_PORTCFG_PFUNC3
#define DIO17_T1_C1N		IOC_PORTCFG_PFUNC4
#define DIO17_T0_C2		IOC_PORTCFG_PFUNC5
#define DIO17_DTB11		IOC_PORTCFG_DTB

#define DIO18_GPIO18		IOC_PORTCFG_BASE
#define DIO18_T3_C0		IOC_PORTCFG_PFUNC1
#define DIO18_LPC0		IOC_PORTCFG_PFUNC2
#define DIO18_UART0_TXD		IOC_PORTCFG_PFUNC3
#define DIO18_SPI0_SCLK		IOC_PORTCFG_PFUNC4
#define DIO18_DTB12		IOC_PORTCFG_DTB

#define DIO19_GPIO19		IOC_PORTCFG_BASE
#define DIO19_T3_C1		IOC_PORTCFG_PFUNC1
#define DIO19_T2_PE		IOC_PORTCFG_PFUNC2
#define DIO19_SPI0_MOSI		IOC_PORTCFG_PFUNC4
#define DIO19_DTB0		IOC_PORTCFG_DTB

#define DIO20_GPIO20		IOC_PORTCFG_BASE
#define DIO20_LPC0		IOC_PORTCFG_PFUNC1
#define DIO20_UART0_TXD		IOC_PORTCFG_PFUNC2
#define DIO20_UART0_RXD		IOC_PORTCFG_PFUNC3
#define DIO20_T1_C0		IOC_PORTCFG_PFUNC4
#define DIO20_SPI0_MISO		IOC_PORTCFG_PFUNC5
#define DIO20_ADC11		IOC_PORTCFG_ANA
#define DIO20_DTB14		IOC_PORTCFG_DTB

#define DIO21_GPIO21		IOC_PORTCFG_BASE
#define DIO21_UART0_CTS		IOC_PORTCFG_PFUNC1
#define DIO21_T1_C1N		IOC_PORTCFG_PFUNC2
#define DIO21_T0_C1		IOC_PORTCFG_PFUNC3
#define DIO21_SPI0_MISO		IOC_PORTCFG_PFUNC4
#define DIO21_LRFD1		IOC_PORTCFG_PFUNC5
#define DIO21_ADC10_LPCP	IOC_PORTCFG_ANA
#define DIO21_DTB15		IOC_PORTCFG_DTB

#define DIO22_GPIO22		IOC_PORTCFG_BASE
#define DIO22_T2_C0		IOC_PORTCFG_PFUNC1
#define DIO22_UART0_RXD		IOC_PORTCFG_PFUNC2
#define DIO22_T3_C1N		IOC_PORTCFG_PFUNC3
#define DIO22_ADC9		IOC_PORTCFG_ANA
#define DIO22_DTB1		IOC_PORTCFG_DTB

#define DIO23_GPIO23		IOC_PORTCFG_BASE
#define DIO23_T2_C1		IOC_PORTCFG_PFUNC1
#define DIO23_T3_C2N		IOC_PORTCFG_PFUNC3
#define DIO23_ADC8_LPCP_LPCM	IOC_PORTCFG_ANA

#define DIO24_GPIO24		IOC_PORTCFG_BASE
#define DIO24_SPI0_SCLK		IOC_PORTCFG_PFUNC1
#define DIO24_T1_C0		IOC_PORTCFG_PFUNC2
#define DIO24_T3_C0		IOC_PORTCFG_PFUNC3
#define DIO24_T0_PE		IOC_PORTCFG_PFUNC4
#define DIO24_I2C0_SCL		IOC_PORTCFG_PFUNC5
#define DIO24_ADC7_LPCP_LPCM	IOC_PORTCFG_ANA
#define DIO24_DTB5		IOC_PORTCFG_DTB

#define DIO25_GPIO25		IOC_PORTCFG_BASE
#define DIO25_SPI0_MISO		IOC_PORTCFG_PFUNC1
#define DIO25_I2C0_SCL		IOC_PORTCFG_PFUNC2
#define DIO25_T2_C2N		IOC_PORTCFG_PFUNC3
#define DIO25_ADC6		IOC_PORTCFG_ANA

#endif  /* CC23X0_PINCTRL_COMMON_H_ */