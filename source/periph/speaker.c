/* *****************************************************************************************
 *    File Name   :speaker.c
 *    Create Date :2021-03-30
 *    Modufy Date :
 *    Information :
 */
#include "fw_io_pin.h"
#include "tool.h"

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
static fw_io_pin_handle_t* speaker_io_pin;
static uint32_t speaker_sound;

/* *****************************************************************************************
 *    Private Variable
 */

/* *****************************************************************************************
 *    Inline Function
 */
 
/* *****************************************************************************************
 *    Private Function
 */ 
static void speaker_task(void* attachment){
	if(!speaker_sound){
		speaker_io_pin->api->setHigh(speaker_io_pin);
		return;
	}
	
	if((speaker_sound & 0x01))
		speaker_io_pin->api->setLow(speaker_io_pin);
	else
		speaker_io_pin->api->setHigh(speaker_io_pin);
		
	speaker_sound = (speaker_sound >> 1);
	tool_timer_scheduler_api.schedule(&timer_scheduler_handle, speaker_task, 0, 100);
}
 
/* *****************************************************************************************
 *    Public Function
 */
void speaker_init(fw_io_pin_handle_t* pin){
	speaker_io_pin = pin;
	speaker_io_pin->api->setOutput(speaker_io_pin);
	speaker_io_pin->api->setHigh(speaker_io_pin);
}

bool speaker_buzzer(uint32_t sound){
	if(speaker_sound)
		return false;
	
	speaker_sound = sound;
	tool_timer_scheduler_api.schedule(&timer_scheduler_handle, speaker_task, 0, 50);
	return true;
}


/* *****************************************************************************************
 *    End of file
 */
 