/* *****************************************************************************************
 *    File Name   :optical_ruler.c
 *    Create Date :2021-03-30
 *    Modufy Date :
 *    Information :
 */
#include "fw_ioint.h"
#include "LPC845.h"
#include "fw_io.h"
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
volatile int optical_ruler_x_count;
volatile int optical_ruler_y_count;
volatile int optical_ruler_z_count;

volatile uint32_t* optical_ruler_x_io;
volatile uint32_t* optical_ruler_y_io;
volatile uint32_t* optical_ruler_z_io;
/* *****************************************************************************************
 *    Inline Function
 */
 
/* *****************************************************************************************
 *    Private Function
 */ 
void PIN_INT0_IRQHandler(void){
  PINT->FALL = 1;
	(*optical_ruler_x_io)?(optical_ruler_x_count++):(optical_ruler_x_count--);
}
 
void PIN_INT1_IRQHandler(void){
  PINT->FALL = 2;
	(*optical_ruler_y_io)?(optical_ruler_y_count++):(optical_ruler_y_count--);
}

static void optical_ruler_x_fall(fw_ioint_handle_t* handle, void* attachment){
	if(*optical_ruler_x_io)
		optical_ruler_x_count++;
	else
		optical_ruler_x_count--;
}

static void optical_ruler_y_fall(fw_ioint_handle_t* handle, void* attachment){
	if(*optical_ruler_y_io)
		optical_ruler_y_count++;
	else
		optical_ruler_y_count--;
}

static void optical_ruler_z_fall(fw_ioint_handle_t* handle, void* attachment){
	if(*optical_ruler_z_io)
		optical_ruler_z_count++;
	else
		optical_ruler_z_count--;
}
/* *****************************************************************************************
 *    Public Function
 */
void optical_ruler_x_init(fw_ioint_handle_t* ioint, const fw_pin_t* pin){
	optical_ruler_x_count = 0;
	optical_ruler_x_io = &GPIO->W[pin->group.port][pin->group.pin];
	ioint->api->init(ioint);
	ioint->api->enableFall(ioint , optical_ruler_x_fall, 0);
}

void optical_ruler_y_init(fw_ioint_handle_t* ioint, const fw_pin_t* pin){
	optical_ruler_y_count = 0;
	optical_ruler_y_io = &GPIO->W[pin->group.port][pin->group.pin];
  ioint->api->init(ioint);
	ioint->api->enableFall(ioint , optical_ruler_y_fall, 0);
}

void optical_ruler_z_init(fw_ioint_handle_t* ioint, const fw_pin_t* pin){
	optical_ruler_z_count = 0;
	optical_ruler_z_io = &GPIO->W[pin->group.port][pin->group.pin];
  ioint->api->init(ioint);
	ioint->api->enableFall(ioint , optical_ruler_z_fall, 0);
}
/* *****************************************************************************************
 *    End of file
 */
 