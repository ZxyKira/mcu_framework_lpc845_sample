/* *****************************************************************************************
 *    File Name   :button.c
 *    Create Date :2021-03-30
 *    Modufy Date :
 *    Information :
 */
#include "fw_io_pin.h"
#include "tool.h"
#include "task.h"


/* *****************************************************************************************
 *    Macro
 */
#define BASE_SCAN_TIME_MS 50
#define BASE_DEBOUNCE_TIME_MS 50
/* *****************************************************************************************
 *    Type/Structure
 */ 
typedef struct _button_memory_t{
  void (*ececute)(void* attachment);
	void* attachment;
	fw_io_pin_handle_t* pin;
}button_memory_t;


/* *****************************************************************************************
 *    Extern Function/Variable
 */

/* *****************************************************************************************
 *    Public Variable
 */

/* *****************************************************************************************
 *    Private Variable
 */
static button_memory_t button_memory_wkp;
static button_memory_t button_memory_isp;

/* *****************************************************************************************
 *    Inline Function
 */
 
/* *****************************************************************************************
 *    Private Function
 */ 
static void button_execute(void* attachment);
 
static void button_execute_debounce(void* attachment){
  button_memory_t* memory = attachment;
	if(!memory->pin->api->getValue(memory->pin))
		tool_timer_scheduler_schedule(&timer_scheduler_handle, button_execute_debounce, memory, BASE_DEBOUNCE_TIME_MS);
	else
	  tool_timer_scheduler_schedule(&timer_scheduler_handle, button_execute, attachment, BASE_SCAN_TIME_MS);
}

static void button_execute(void* attachment){
  button_memory_t* memory = attachment;
	
	if(!memory->pin->api->getValue(memory->pin)){
		tool_ts_api.addTask(&task_scheduler_handle, memory->ececute, memory->attachment, tool_ts_prtority_high);
		tool_timer_scheduler_schedule(&timer_scheduler_handle, button_execute_debounce, memory, BASE_DEBOUNCE_TIME_MS);
	}
	else{
	  tool_timer_scheduler_schedule(&timer_scheduler_handle, button_execute, memory, BASE_SCAN_TIME_MS);
	}
}

static void button_init(button_memory_t* memory, fw_io_pin_handle_t* pin, void (*ececute)(void*), void* attachment){
	pin->api->setInput(pin);
	
  memory->pin = pin;
	memory->ececute = ececute;
	memory->attachment = attachment;
	
	tool_timer_scheduler_schedule(&timer_scheduler_handle, button_execute, memory, 50);
}

/* *****************************************************************************************
 *    Public Function
 */
void button_init_wkp(fw_io_pin_handle_t* pin){
	button_init(&button_memory_wkp, pin, task_button_wkp, 0);
}

void button_init_isp(fw_io_pin_handle_t* pin){
  button_init(&button_memory_isp, pin, task_button_isp, 0);
}

/* *****************************************************************************************
 *    End of file
 */
 