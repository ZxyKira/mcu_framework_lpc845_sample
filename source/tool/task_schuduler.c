/*****************************************************************************
 *			File Name		 : task_scheduler.c
 *			Create Date	 : 2021-03-30
 *      Modufy Date  : 
 *      Author       : Danny
 *			Information  :
 */

#include "stdint.h"
#include "fw_timer.h"
#include "tool_task_scheduler.h"

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
tool_task_scheduler_handle_t task_scheduler_handle;

/* *****************************************************************************************
 *    Private Variable
 */
static tool_task_scheduler_event_t task_scheduler_high[NUMB_TASK];
static tool_task_scheduler_event_t task_scheduler_normal[NUMB_TASK];
static tool_task_scheduler_event_t task_scheduler_low[NUMB_TASK];



/* *****************************************************************************************
 *    Inline Function
 */
 
/* *****************************************************************************************
 *    Private Function
 */ 
 
/* *****************************************************************************************
 *    Public Function
 */

/* *****************************************************************************************
 *    End of file
 */


void task_scheduler_init(void){
  tool_task_scheduler_config_t config;
	
  config.prtorityHigh.eventBuffer = task_scheduler_high;
	config.prtorityHigh.bufferQuantity = NUMB_TASK;
	config.prtorityNormal.eventBuffer = task_scheduler_normal;
	config.prtorityNormal.bufferQuantity = NUMB_TASK;
	config.prtorityLow.eventBuffer = task_scheduler_low;
	config.prtorityLow.bufferQuantity = NUMB_TASK;
	
	tool_task_scheduler_api.initialze(&task_scheduler_handle, &config);
}


/*****************************************************************************
 *	End of file
 */