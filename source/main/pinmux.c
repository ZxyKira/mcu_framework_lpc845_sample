/* *****************************************************************************************
 *    File Name   :pinmux.c
 *    Create Date :2021-03-30
 *    Modufy Date :
 *    Information :
 */
#include "chip_lpc845.h"
#include "pinmux.h"

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

/* *****************************************************************************************
 *    Inline Function
 */
 
/* *****************************************************************************************
 *    Private Function
 */ 

static void pinmux_init_spi(){
	chip_swm.movable(pinmux_spim0_mosi, kSWM_SPI0_MOSI);
	chip_swm.movable(pinmux_spim0_miso, kSWM_SPI0_MISO);
	chip_swm.movable(pinmux_spim0_sclk, kSWM_SPI0_SCK);
	chip_swm.movable(pinmux_spim0_ssel0, kSWM_SPI0_SSEL0);
}

static void pinmux_init_usart0_comport(){
	chip_swm.movable(pinmux_usart0_comport_txd, kSWM_USART0_TXD);
	chip_swm.movable(pinmux_usart0_comport_rxd, kSWM_USART0_RXD);
	chip_iocon.mode(pinmux_usart0_comport_txd, CHIP_IOCON_MODE_PULLUP);
	chip_iocon.mode(pinmux_usart0_comport_rxd, CHIP_IOCON_MODE_PULLUP);
}

static void pinmux_init_usart1_console(){
	chip_swm.movable(pinmux_usart1_console_txd, kSWM_USART1_TXD);
	chip_swm.movable(pinmux_usart1_console_rxd, kSWM_USART1_RXD);
	chip_iocon.mode(pinmux_usart1_console_txd, CHIP_IOCON_MODE_PULLUP);
	chip_iocon.mode(pinmux_usart1_console_rxd, CHIP_IOCON_MODE_PULLUP);
}

static void pinmux_init_button(){
	chip_iocon.mode(pinmux_button_isp, CHIP_IOCON_MODE_PULLUP);
	chip_iocon.mode(pinmux_button_wkp, CHIP_IOCON_MODE_PULLUP);
}
/* *****************************************************************************************
 *    Public Function
 */
void pinmux_init(){
	chip_swm.init();
	chip_iocon.init();
	pinmux_init_usart0_comport();
	pinmux_init_usart1_console();
	pinmux_init_button();
}

/* *****************************************************************************************
 *    End of file
 */
 