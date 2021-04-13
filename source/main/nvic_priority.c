/* *****************************************************************************************
 *    File Name   :nvic.c
 *    Create Date :2021-03-31
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
typedef struct _nvic_priority_level_t{
  IRQn_Type irq;
	uint8_t level;
}nvic_priority_level_t;

/* *****************************************************************************************
 *    Extern Function/Variable
 */

/* *****************************************************************************************
 *    Public Variable
 */

/* *****************************************************************************************
 *    Private Variable
 */
const nvic_priority_level_t nvic_priority_level[] = {
	{SPI0_IRQn,            2},
	{SPI1_IRQn,            2},
	{DAC0_IRQn,            2},
	{USART0_IRQn,          2},
	{USART1_IRQn,          2},
	{USART2_IRQn,          2},
	{I2C1_IRQn,            2},
	{I2C0_IRQn,            2},
	{SCT0_IRQn,            2},
	{MRT0_IRQn,            1},
	{CMP_CAPT_IRQn,        2},
	{WDT_IRQn,             2},
	{BOD_IRQn,             2},
	{FLASH_IRQn,           3},
	{WKT_IRQn,             2},
	{ADC0_SEQA_IRQn,       3},
	{ADC0_SEQB_IRQn,       3},
	{ADC0_THCMP_IRQn,      3},
	{ADC0_OVR_IRQn,        3},
	{DMA0_IRQn,            1},
	{I2C2_IRQn,            2},
	{I2C3_IRQn,            2},
	{CTIMER0_IRQn,         1},
	{PIN_INT0_IRQn,        0},
	{PIN_INT1_IRQn,        0},
	{PIN_INT2_IRQn,        0},
	{PIN_INT3_IRQn,        0},
	{PIN_INT4_IRQn,        0},
	{PIN_INT5_DAC1_IRQn,   2},
	{PIN_INT6_USART3_IRQn, 1},
	{PIN_INT7_USART4_IRQn, 1},
};
/* *****************************************************************************************
 *    Inline Function
 */
 
/* *****************************************************************************************
 *    Private Function
 */ 
 
/* *****************************************************************************************
 *    Public Function
 */
void nvic_priority_init(){
	int i;
	int count = (sizeof(nvic_priority_level) / sizeof(nvic_priority_level_t));
	
	const nvic_priority_level_t* nvic_level;
	
	for(i=0, nvic_level = nvic_priority_level; i<count; i++){
		NVIC_SetPriority(nvic_level->irq, nvic_level->level);
		nvic_level++;
	}
}
/* *****************************************************************************************
 *    End of file
 */
 