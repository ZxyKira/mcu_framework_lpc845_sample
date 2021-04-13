/* *****************************************************************************************
 *    File Name   :pinmux.h
 *    Create Date :2021-04-01
 *    Modufy Date :
 *    Information :
 */
 
#ifndef pinmux_H
#define pinmux_H

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

//basic include
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

//framework include
#include "fw_base.h"

static const fw_pin_t pinmux_speaker            = fw_pin_define(1, 17);

static const fw_pin_t pinmux_button_isp         = fw_pin_define(0, 12);
static const fw_pin_t pinmux_button_wkp         = fw_pin_define(0, 4);

static const fw_pin_t pinmux_spim0_mosi         = fw_pin_define(0, 28);
static const fw_pin_t pinmux_spim0_miso         = fw_pin_define(0, 29);
static const fw_pin_t pinmux_spim0_sclk         = fw_pin_define(0, 30);
static const fw_pin_t pinmux_spim0_ssel0        = fw_pin_define(0, 31);

static const fw_pin_t pinmux_usart0_comport_txd = fw_pin_define(0, 24);
static const fw_pin_t pinmux_usart0_comport_rxd = fw_pin_define(0, 25);

static const fw_pin_t pinmux_usart1_console_txd = fw_pin_define(0, 14);
static const fw_pin_t pinmux_usart1_console_rxd = fw_pin_define(0, 15);
#ifdef __cplusplus
}
#endif //__cplusplus
#endif
/* *****************************************************************************************
 *    End of file
 */ 
