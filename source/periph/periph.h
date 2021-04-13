/* *****************************************************************************************
 *    File Name   :periph.h
 *    Create Date :2021-03-30
 *    Modufy Date :
 *    Information :
 */
 
#ifndef periph_H
#define periph_H

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "fw_ioint.h"
#include "fw_io.h"
#include "fw_usart.h"
#include "fw_timer.h"

//button
void button_init_wkp(fw_io_pin_handle_t* pin);
void button_init_isp(fw_io_pin_handle_t* pin);

//speaker
void speaker_init(fw_io_pin_handle_t* pin);
bool speaker_buzzer(uint32_t sound);

//console 
void console_init(fw_usart_handle_t* usart);

//dashboard
void dashboard_init(fw_timer_handle_t* timer, uint32_t* sourceCount, uint32_t maxCount);
uint32_t dashboard_getUsingPercentage();
float dashboard_getUsing();

#ifdef __cplusplus
}
#endif //__cplusplus
#endif
/* *****************************************************************************************
 *    End of file
 */ 
