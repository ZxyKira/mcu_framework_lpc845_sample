/* *****************************************************************************************
 *    File Name   :task_button.c
 *    Create Date :2021-04-01
 *    Modufy Date :
 *    Information :
 */
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
static inline void delay_us_a(){
//  __NOP();
//	__NOP();
//	__NOP();
//	__NOP();
//	__NOP();
	__NOP();
	__NOP();
	__NOP();
}

static inline void delay_us_b(){
//  __NOP();
//	__NOP();
//	__NOP();
//	__NOP();
//	__NOP();
}


//290
//#define DELAY_NOP() __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP()

//320
//#define DELAY_NOP() __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP()

//370
//#define DELAY_NOP() __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP()

//390
#define DELAY_NOP() __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP()
/* *****************************************************************************************
 *    Inline Function
 */

/* *****************************************************************************************
 *    Private Function
 */ 

/* *****************************************************************************************
 *    Public Function
 */
void task_button_wkp(void* attachment){
	
	int i;
	
	#if 1  
	for(i=0; i<100; i++){
		DELAY_NOP();
		GPIO->NOT[1] = 0x00000011;
		DELAY_NOP();
		__NOP();
		__NOP();
		GPIO->NOT[1] = 0x00000022;
		DELAY_NOP();
		__NOP();
		__NOP();
		GPIO->NOT[1] = 0x00000011;
		DELAY_NOP();
		__NOP();
		__NOP();
		GPIO->NOT[1] = 0x00000022;
	}
	#endif
	
	//GPIO->NOT[1] = 0x00000002;
}

void task_button_isp(void* attachment){
	
	int i;
	
	#if 1  
	for(i=0; i<100; i++){
		DELAY_NOP();
		GPIO->NOT[1] = 0x00000022;
		DELAY_NOP();
		__NOP();
		__NOP();
		GPIO->NOT[1] = 0x00000011;
		DELAY_NOP();
		__NOP();
		__NOP();
		GPIO->NOT[1] = 0x00000022;
		DELAY_NOP();
		__NOP();
		__NOP();
		GPIO->NOT[1] = 0x00000011;
	}
	
	#endif
	
	
	
	#if 0
	for(i=0; i<100000; i++){
		//__NOP();
		//__NOP();
		//__NOP();
		//__NOP();
		//__NOP();
		//__NOP();
		//
		
		__NOP();
		__NOP();
		__NOP();
		__NOP();
		GPIO->NOT[1] = 0x00000003;
	}
	#endif
	
	#if 0
	for(i=0; i<100000; i++){
		__NOP();
		__NOP();
		__NOP();
		GPIO->NOT[1] = 0x00000001;
		__NOP();
		__NOP();
		__NOP();
		__NOP();
		__NOP();
		__NOP();
		GPIO->NOT[1] = 0x00000002;
	}
	#endif

}
/* *****************************************************************************************
 *    End of file
 */
 