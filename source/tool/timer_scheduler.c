/*****************************************************************************
 *			File Name		 : timer_scheduler.c
 *			Create Date	 : 2021-03-30
 *      Modufy Date  : 
 *      Author       : Danny
 *			Information  :
 */

#include "stdint.h"
#include "fw_timer.h"
#include "tool_timer_scheduler.h"

#include "tool.h"

/* *****************************************************************************************
 *    Macro
 */
 
 #define NUMB_TASK 16

/* *****************************************************************************************
 *    Parameter
 */
 
/* *****************************************************************************************
 *    Type/Structure
 */ 
 
/* *****************************************************************************************
 *    Extern Function/Variable
 */

/* *****************************************************************************************
 *    Public Variable
 */
tool_timer_scheduler_memory_t timer_scheduler_handle;


/* *****************************************************************************************
 *    Private Variable
 */
static fw_timer_handle_t* timer_scheduler_timer;
static tool_timer_scheduler_task_t timer_scheduler_task[NUMB_TASK];

/* *****************************************************************************************
 *    Inline Function
 */
 
/* *****************************************************************************************
 *    Private Function
 */ 
static void timer_scheduler_execute_task(void* attachment){
	tool_timer_scheduler_execute(&timer_scheduler_handle);
} 

static void timer_scheduler_event(fw_timer_handle_t* handle, void* attachment){
	tool_ts_api.addTask(&task_scheduler_handle, timer_scheduler_execute_task, 0, tool_ts_prtority_normal);
}
 
/* *****************************************************************************************
 *    Public Function
 */

/* *****************************************************************************************
 *    End of file
 */
void timer_scheduler_init(fw_timer_handle_t* timer, uint32_t base_ms){
	timer_scheduler_timer = timer;
	tool_timer_scheduler_init(&timer_scheduler_handle, timer_scheduler_task, NUMB_TASK, base_ms);
	
	timer_scheduler_timer->api->init(timer_scheduler_timer);
	timer_scheduler_timer->api->startAtTime(timer_scheduler_timer, base_ms*1000, &timer_scheduler_event, 0);
}


/*****************************************************************************
 *	End of file
 */