/* *****************************************************************************************
 *    File Name   :main.h
 *    Create Date :2021-03-30
 *    Modufy Date :
 *    Information :
 */
 
#ifndef main_H
#define main_H

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

//basic include
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

//framework include
#include "chip_lpc845.h"


//pinmux
extern void pinmux_init();

//nvic_priority
void nvic_priority_init();

//pininit
void pininit_init(fw_io_handle_t *io);

#ifdef __cplusplus
}
#endif //__cplusplus
#endif
/* *****************************************************************************************
 *    End of file
 */ 
