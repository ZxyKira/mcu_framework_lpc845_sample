/* *****************************************************************************************
 *    File Name   :tool.h
 *    Create Date :2021-03-30
 *    Modufy Date :
 *    Information :
 */
 
#ifndef tool_H
#define tool_H

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

//framework include
#include "fw_timer.h"

//task_scheduler
extern tool_task_scheduler_handle_t task_scheduler_handle;
extern void task_scheduler_init(void);

//timer_scheduler
extern tool_timer_scheduler_handle_t timer_scheduler_handle;
extern void timer_scheduler_init(fw_timer_handle_t* timer, uint32_t base_ms);

#ifdef __cplusplus
}
#endif //__cplusplus
#endif
/* *****************************************************************************************
 *    End of file
 */ 
