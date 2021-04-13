/* *****************************************************************************************
 *    File Name   :start.c
 *    Create Date :2021-03-30
 *    Modufy Date :
 *    Information :
 */
#include <stdint.h>

#include "pinmux.h"

#include "tool.h"
#include "main.h"
#include "periph.h"
#include "task.h"

/* *****************************************************************************************
 *    Macro
 */

/* *****************************************************************************************
 *    Type/Structure
 */ 
 
/* *****************************************************************************************
 *    Extern Function/Variable
 */
extern uint32_t loopCount;
/* *****************************************************************************************
 *    Public Variable
 */

fw_io_pin_handle_t pin_led[8];
fw_io_pin_handle_t pin_speaker;

fw_io_pin_handle_t pin_button_isp;
fw_io_pin_handle_t pin_button_wkp;

/* *****************************************************************************************
 *    Private Variable
 */
//io 
static fw_io_handle_t start_io;

//timer - timer_scheduler
static fw_timer_handle_t start_timer_timer_scheduler;
static chip_timer_memory_t start_timer_timer_scheduler_memory;

//timer - dashboard
static fw_timer_handle_t start_timer_dashboard;
static chip_timer_memory_t start_timer_dashboard_memory;

//ioint - ioint_optical_ruler_x
static fw_ioint_handle_t start_ioint_optical_ruler_x;
static chip_ioint_memory_t start_ioint_optical_ruler_x_memory;

//ioint - ioint_optical_ruler_y
static fw_ioint_handle_t start_ioint_optical_ruler_y;
static chip_ioint_memory_t start_ioint_optical_ruler_y_memory;

//usart - console
static fw_usart_handle_t usart_console;
static chip_usart_memory_t start_usart_console_memory;
static uint8_t start_usart_console_buffer[64];

//usart - comport
static chip_usart_memory_t start_usart_comport_memory;
static uint8_t start_usart_comport_buffer[64];
/* *****************************************************************************************
 *    Inline Function
 */
 
/* *****************************************************************************************
 *    Private Function
 */ 
 
static void start_hw_ioint(){
	start_ioint_optical_ruler_x = chip_construct.ioint(0, &start_ioint_optical_ruler_x_memory);
	start_ioint_optical_ruler_y = chip_construct.ioint(1, &start_ioint_optical_ruler_y_memory);
}

static void start_hw_timer(){
  start_timer_timer_scheduler = chip_construct.timer(0, &start_timer_timer_scheduler_memory);
	start_timer_dashboard = chip_construct.timer(1, &start_timer_dashboard_memory);
}

static void start_hw_io(){
	start_io = chip_construct.io();
	start_io.api->init(&start_io);
	
	pin_button_isp = start_io.api->getFwPin(&start_io, &pinmux_button_isp);
	pin_button_wkp = start_io.api->getFwPin(&start_io, &pinmux_button_wkp);
	
	pin_speaker = start_io.api->getFwPin(&start_io, &pinmux_speaker);

	
	int i;
	for(i=0; i<8; i++){
		pin_led[i] = start_io.api->getPin(&start_io, 1, i);
		pin_led[i].api->setOutput(&pin_led[i]);
		pin_led[i].api->setHigh(&pin_led[i]);
	}
}

static void start_hw_usart(){
  usart_console = chip_construct.usart(1, &start_usart_console_memory, start_usart_console_buffer, sizeof(start_usart_console_buffer));
}


static void start_hw(){
	start_hw_io();
	start_hw_ioint();
	start_hw_timer();
	start_hw_usart();
}

static void start_tool(){
	task_scheduler_init();
	timer_scheduler_init(&start_timer_timer_scheduler, 50);
	speaker_init(&pin_speaker);
	dashboard_init(&start_timer_dashboard, &loopCount, 70000);
}

static void start_periph(){
  button_init_isp(&pin_button_isp);
  button_init_wkp(&pin_button_wkp);
	
	console_init(&usart_console);
}

/* *****************************************************************************************
 *    Public Function
 */

void start(){
	chip_power.chipInit();
	nvic_priority_init();
  pinmux_init();
	
	start_hw();
	start_tool();
	start_periph();
	
	tool_timer_scheduler_api.schedule(&timer_scheduler_handle, task_led_blink_6, 0, 500);
	tool_timer_scheduler_api.schedule(&timer_scheduler_handle, task_led_blink_5, 0, 750);
	
	speaker_buzzer(0x53);
}

/* *****************************************************************************************
 *    End of file
 */