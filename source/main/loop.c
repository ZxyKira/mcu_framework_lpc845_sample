/*****************************************************************************
 *			File Name		 : loop.c
 *			Create Date	 : 2020-11-26
 *      Modufy Date  : 
 *      Author       : Danny
 *			Information  :
 */
#include "tool.h"


void loop(){
	tool_ts_api.execute(&task_scheduler_handle);
}
	