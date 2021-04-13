/*****************************************************************************
 *			File Name		 : main.c
 *			Version			 : V1.0
 *			Create Date	 : 2020-10-06
 *      Modufy Date  : 2020-10-06
 *      Author       : Danny
 *			Information  :
 */
 
#include "stdint.h"

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
