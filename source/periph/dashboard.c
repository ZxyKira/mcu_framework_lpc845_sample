/* *****************************************************************************************
 *    File Name   :dashboard.c
 *    Create Date :2021-03-31
 *    Modufy Date :
 *    Information :
 */
#include "fw_timer.h"
#include "LPC845.h"
/* *****************************************************************************************
 *    Macro
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

/* *****************************************************************************************
 *    Private Variable
 */
static fw_timer_handle_t* dashboard_timer;
static uint32_t* dashboard_sourceCount;
static uint32_t dashboard_lastSourceCount;
static uint32_t dashboard_maxCount;
/* *****************************************************************************************
 *    Inline Function
 */
 
/* *****************************************************************************************
 *    Private Function
 */ 
static void dashboard_event(fw_timer_handle_t* handle, void* attachment){
	dashboard_lastSourceCount = *dashboard_sourceCount;
	*dashboard_sourceCount = 0;
}
 
/* *****************************************************************************************
 *    Public Function
 */
void dashboard_init(fw_timer_handle_t* timer, uint32_t* sourceCount, uint32_t maxCount){
	dashboard_sourceCount = sourceCount;
	dashboard_maxCount = maxCount;
	dashboard_timer = timer;
	
	dashboard_timer->api->init(dashboard_timer);
	dashboard_timer->api->startAtTime(dashboard_timer, 1000000, dashboard_event, 0);
}

uint32_t dashboard_getUsingPercentage(){
	uint32_t result = dashboard_maxCount - dashboard_lastSourceCount;
	result *= 100;
	result /= dashboard_maxCount;
	return result;
}

float dashboard_getUsing(){
	float result = (dashboard_maxCount - dashboard_lastSourceCount)*100;
	result /= dashboard_maxCount;
	return result;
}
/* *****************************************************************************************
 *    End of file
 */
 