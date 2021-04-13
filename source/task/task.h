/* *****************************************************************************************
 *    File Name   :tool.h
 *    Create Date :2021-03-30
 *    Modufy Date :
 *    Information :
 */
 
#ifndef task_H
#define task_H

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

//basic include
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

//tool include
#include "tool_fifo.h"
#include "tool_task_scheduler.h"
#include "tool_timer_scheduler.h"


//task_led
extern void task_led_blink_0(void* attachment);
extern void task_led_blink_1(void* attachment);
extern void task_led_blink_2(void* attachment);
extern void task_led_blink_3(void* attachment);
extern void task_led_blink_4(void* attachment);
extern void task_led_blink_5(void* attachment);
extern void task_led_blink_6(void* attachment);
extern void task_led_blink_7(void* attachment);

//task_button
extern void task_button_isp(void* attachment);
extern void task_button_wkp(void* attachment);

#ifdef __cplusplus
}
#endif //__cplusplus
#endif
/* *****************************************************************************************
 *    End of file
 */ 
