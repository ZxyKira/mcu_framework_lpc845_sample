/*****************************************************************************
 *			File Name		 : task.c
 *			Create Date	 : 2021-03-28
 *      Modufy Date  : 
 *      Author       : Danny
 *			Information  :
 */
#include <stdint.h>

#include "chip_lpc845.h"
#include "tool.h"

void task_led_blink_0(void* attachment){
	GPIO->NOT[1] = (1<<0);
}

void task_led_blink_1(void* attachment){
	GPIO->NOT[1] = (1<<1);
}

void task_led_blink_2(void* attachment){
	GPIO->NOT[1] = (1<<2);
}

void task_led_blink_3(void* attachment){
	GPIO->NOT[1] = (1<<3);
}

void task_led_blink_4(void* attachment){
	GPIO->NOT[1] = (1<<4);
}

void task_led_blink_5(void* attachment){
	GPIO->NOT[1] = (1<<5);
	tool_timer_scheduler_api.schedule(&timer_scheduler_handle, task_led_blink_5, 0, 750);
}

void task_led_blink_6(void* attachment){
	GPIO->NOT[1] = (1<<6);
	tool_timer_scheduler_api.schedule(&timer_scheduler_handle, task_led_blink_6, 0, 500);
}

void task_led_blink_7(void* attachment){
	GPIO->NOT[1] = (1<<7);
}