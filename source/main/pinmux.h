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

static const fw_pin_t pinmux_speaker            = FW_PIN_DEFINE(1, 17);

static const fw_pin_t pinmux_button_isp         = FW_PIN_DEFINE(0, 12);
static const fw_pin_t pinmux_button_wkp         = FW_PIN_DEFINE(0, 4);

static const fw_pin_t pinmux_spim0_mosi         = FW_PIN_DEFINE(0, 28);
static const fw_pin_t pinmux_spim0_miso         = FW_PIN_DEFINE(0, 29);
static const fw_pin_t pinmux_spim0_sclk         = FW_PIN_DEFINE(0, 30);
static const fw_pin_t pinmux_spim0_ssel0        = FW_PIN_DEFINE(0, 31);

static const fw_pin_t pinmux_usart0_comport_txd = FW_PIN_DEFINE(0, 24);
static const fw_pin_t pinmux_usart0_comport_rxd = FW_PIN_DEFINE(0, 25);

static const fw_pin_t pinmux_usart1_console_txd = FW_PIN_DEFINE(0, 14);
static const fw_pin_t pinmux_usart1_console_rxd = FW_PIN_DEFINE(0, 15);
#ifdef __cplusplus
}
#endif //__cplusplus
#endif
/* *****************************************************************************************
 *    End of file
 */ 
