/*****************************************************************************
 *			File Name		 : main.c
 *			Create Date	 : 2020-10-06
 *      Modufy Date  : 2021-05-24
 *      Author       : Danny
 *			Information  :
 */
 
#include "stdint.h"
#include "LPC845.h"

/*****************************************************************************
 *	Extern Function/Variable
 */
extern void start(void);
extern void loop(void);

uint32_t loopCount = 0;
/*****************************************************************************
 *	Public function
 */
int main(){
	start();
	while(1){
		loop();
	  loopCount++;
	}
}

/*****************************************************************************
 *	End of file
 */
