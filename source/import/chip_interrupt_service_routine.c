/* *****************************************************************************************
 *    File Name   :chip_interrupt_service_routine.c
 *    Create Date :2021-04-11
 *    Modufy Date :
 *    Information :
 */

#include "LPC845.h"
#include "fsl_usart.h"


/* *****************************************************************************************
 *    Macro
 */

/* *****************************************************************************************
 *    Parameter
 */

/* *****************************************************************************************
 *    Type/Structure
 */ 
 
/* *****************************************************************************************
 *    Extern Function/Variable
 */
extern void chip_usart_irqHandle_0(void);
extern void chip_usart_irqHandle_1(void);
extern void chip_usart_irqHandle_2(void);
extern void chip_usart_irqHandle_3(void);
extern void chip_usart_irqHandle_4(void);

extern void chip_ioint_irqHandle_0(void);
extern void chip_ioint_irqHandle_1(void);
extern void chip_ioint_irqHandle_2(void);
extern void chip_ioint_irqHandle_3(void);
extern void chip_ioint_irqHandle_4(void);
extern void chip_ioint_irqHandle_5(void);
extern void chip_ioint_irqHandle_6(void);
extern void chip_ioint_irqHandle_7(void);
/* *****************************************************************************************
 *    Public Variable
 */

/* *****************************************************************************************
 *    Private Variable
 */

/* *****************************************************************************************
 *    Inline Function
 */

/* *****************************************************************************************
 *    Private Function
 */ 

/* *****************************************************************************************
 *    Public Function
 */

/* ------------------------------
 *    Usart
 * ------------------------------*/
void USART0_IRQHandler(void){
  chip_usart_irqHandle_0();
}

void USART1_IRQHandler(void){
  chip_usart_irqHandle_1();
}

void USART2_IRQHandler(void){
  chip_usart_irqHandle_2();
}

/* ------------------------------
 *    Timer
 * ------------------------------*/



/* ------------------------------
 *    Ioint
 * ------------------------------*/
void PIN_INT0_IRQHandler(void){
  chip_ioint_irqHandle_0();
}

void PIN_INT1_IRQHandler(void){
  chip_ioint_irqHandle_1();
}

void PIN_INT2_IRQHandler(void){
  chip_ioint_irqHandle_2();
}

void PIN_INT3_IRQHandler(void){
  chip_ioint_irqHandle_3();
}

void PIN_INT4_IRQHandler(void){
  chip_ioint_irqHandle_4();
}

void PIN_INT5_DAC1_IRQHandler(void){
  chip_ioint_irqHandle_5();
}

void PIN_INT6_USART3_IRQHandler(void){
	if((USART_GetStatusFlags(USART3) & (kUSART_RxReady | kUSART_TxReady)))
		chip_usart_irqHandle_3();
	
	if((PINT->RISE | PINT->FALL) & 0x00000040)
		chip_ioint_irqHandle_6();
}

void PIN_INT7_USART4_IRQHandler(void){
	if((USART_GetStatusFlags(USART4) & (kUSART_RxReady | kUSART_TxReady)))
		chip_usart_irqHandle_4();
	
	if((PINT->RISE | PINT->FALL) & 0x00000080)
		chip_ioint_irqHandle_7();
}


/* *****************************************************************************************
 *    End of file
 */