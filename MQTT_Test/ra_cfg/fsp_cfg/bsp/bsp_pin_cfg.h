/* generated configuration header file - do not edit */
#ifndef BSP_PIN_CFG_H_
#define BSP_PIN_CFG_H_
#include "r_ioport.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

#define ARDUINO_A0 (BSP_IO_PORT_00_PIN_00)
#define ARDUINO_A1 (BSP_IO_PORT_00_PIN_01)
#define ARDUINO_A2 (BSP_IO_PORT_00_PIN_02)
#define ARDUINO_A4 (BSP_IO_PORT_00_PIN_03)
#define ARDUINO_A3 (BSP_IO_PORT_00_PIN_04)
#define PMOD1_RESET (BSP_IO_PORT_00_PIN_05)
#define ARDUINO_D8 (BSP_IO_PORT_00_PIN_06)
#define ARDUINO_D7 (BSP_IO_PORT_00_PIN_08)
#define ARDUINO_A5 (BSP_IO_PORT_00_PIN_13)
#define PMOD2_GPIO1 (BSP_IO_PORT_00_PIN_14)
#define PMOD2_GPIO2 (BSP_IO_PORT_00_PIN_15)
#define PMOD2_SCL0_ARDUINO_SCL (BSP_IO_PORT_01_PIN_00)
#define PMOD2_SDA0_ARDUINO_SDA (BSP_IO_PORT_01_PIN_01)
#define LED1 (BSP_IO_PORT_01_PIN_04)
#define ARDUINO_D2 (BSP_IO_PORT_01_PIN_05)
#define PMOD1_GPIO1 (BSP_IO_PORT_01_PIN_06)
#define PMOD1_GPIO2 (BSP_IO_PORT_01_PIN_07)
#define DEBUG_SWDIO (BSP_IO_PORT_01_PIN_08)
#define PMOD1_TX_ARDUINO_D11 (BSP_IO_PORT_01_PIN_09)
#define PMOD1_RX_ARDUINO_D12 (BSP_IO_PORT_01_PIN_10)
#define PMOD1_RSPCK_ARDUINO_D13 (BSP_IO_PORT_01_PIN_11)
#define LED2 (BSP_IO_PORT_01_PIN_12)
#define ARDUINO_D6 (BSP_IO_PORT_01_PIN_13)
#define PMOD2_IRQ (BSP_IO_PORT_02_PIN_05)
#define PMOD2_SSIDATA (BSP_IO_PORT_02_PIN_06)
#define PMOD2_SSICLK (BSP_IO_PORT_02_PIN_07)
#define ARDUINO_RESET (BSP_IO_PORT_02_PIN_08)
#define DEBUG_SWDCLK (BSP_IO_PORT_03_PIN_00)
#define ARDUINO_D10 (BSP_IO_PORT_03_PIN_01)
#define PMOD1_IRQ (BSP_IO_PORT_04_PIN_02)
#define ARDUINO_D9 (BSP_IO_PORT_04_PIN_03)
#define PMOD2_SSIBCK (BSP_IO_PORT_04_PIN_07)
#define ARDUINO_D3 (BSP_IO_PORT_04_PIN_08)
#define ARDUINO_D5 (BSP_IO_PORT_04_PIN_09)
#define PMOD2_MISO_ARDUINO_D0 (BSP_IO_PORT_04_PIN_10)
#define PMOD2_SENSOR_RESET_ARDUINO_D1 (BSP_IO_PORT_04_PIN_11)
#define ARDUINO_D4 (BSP_IO_PORT_05_PIN_00)
extern const ioport_cfg_t g_bsp_pin_cfg; /* BGK_RA6E2.pincfg */

void BSP_PinConfigSecurityInit();

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER
#endif /* BSP_PIN_CFG_H_ */
