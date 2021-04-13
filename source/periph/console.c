/* *****************************************************************************************
 *    File Name   :console.c
 *    Create Date :2021-03-31
 *    Modufy Date :
 *    Information :
 */
#include "fw_usart.h"
#include "tool.h"
#include "periph.h"
#include "stdio.h"

void console_send(const void* data, uint32_t size);
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
static fw_usart_handle_t* console_usart;
static fw_memory_t console_memory_txd;
static char console_sprintf_buffer[64];

/* *****************************************************************************************
 *    Inline Function
 */

/* *****************************************************************************************
 *    Private Function
 */ 
static void console_loopSend(){
	int size = sprintf(console_sprintf_buffer, "cpu: %d\n", dashboard_getUsingPercentage());
	
	console_send(console_sprintf_buffer, size);
	tool_timer_scheduler_api.schedule(&timer_scheduler_handle, console_loopSend, 0, 1000);
}

/* *****************************************************************************************
 *    Public Function
 */
void console_send(const void* data, uint32_t size){
	console_memory_txd.ptr = (void*)data;
	console_memory_txd.size = size;
	console_usart->api->send(console_usart, &console_memory_txd, 0, 0);
}

void console_init(fw_usart_handle_t* usart){
  console_usart = usart;
	console_usart->api->init(console_usart);
	console_usart->api->setBaudrate(console_usart, 9600);
	
	tool_timer_scheduler_api.schedule(&timer_scheduler_handle, console_loopSend, 0, 1000);
}
/* *****************************************************************************************
 *    End of file
 */
 