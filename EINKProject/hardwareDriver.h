/*
 * hardwareDriver.h
 * Header of HAL level Hardware Driver
 *
 *  Created on: 2015/1/4
 *      Author: KH
 */

#ifndef HARDWAREDRIVER_H_
#define HARDWAREDRIVER_H_
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "PinAssignment.h"
#include "driverlib/pin_map.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "driverlib/ssi.h"
#include "driverlib/pwm.h"
#include "driverlib/adc.h"
#include "PINConfig.h"
#include "utils/uartstdio.h"

#define EPD_cs_high()			MAP_GPIOPinWrite(EPD_CS_PORT,EPD_CS_PIN,EPD_CS_PIN)
#define EPD_cs_low()			MAP_GPIOPinWrite(EPD_CS_PORT,EPD_CS_PIN,0)
#define EPD_flash_cs_high()		MAP_GPIOPinWrite(Flash_CS_PORT,Flash_CS_PIN,FlashCS_PIN)
#define EPD_flash_cs_low()		MAP_GPIOPinWrite(Flash_CS_PORT,Flash_CS_PIN,0)
#define EPD_rst_high()			MAP_GPIOPinWrite(EPD_BUSY_PORT,EPD_BUSY_PIN,EPD_BUSY_PIN)
#define EPD_rst_low()			MAP_GPIOPinWrite(EPD_BUSY_PORT,EPD_BUSY_PIN,0)
#define EPD_discharge_high()	MAP_GPIOPinWrite(EPD_DISCHARGE_PORT,EPD_DISCHARGE_PIN,EPD_DISCHARGE_PIN)
#define EPD_discharge_low()		MAP_GPIOPinWrite(EPD_DISCHARGE_PORT,EPD_DISCHARGE_PIN,0)
#define EPD_Vcc_turn_on()		MAP_GPIOPinWrite(EPD_PANELON_PORT,EPD_PANELON_PIN,EPD_PANELON_PIN)
#define EPD_Vcc_turn_off()		MAP_GPIOPinWrite(EPD_PANELON_PORT,EPD_PANELON_PIN,0)
#define EPD_border_high()		MAP_GPIOPinWrite(EPD_BORDER_PORT,EPD_BORDER_PIN,EPD_BORDER_PIN)
#define EPD_border_low()		MAP_GPIOPinWrite(EPD_BORDER_PORT,EPD_BORDER_PIN,0)
#define EPD_led_high()			MAP_GPIOPinWrite(EPD_LED_PORT,EPD_LED_PIN,EPD_LED_PIN)
#define EPD_led_low()			MAP_GPIOPinWrite(EPD_LED_PORT,EPD_LED_PIN,0)


#endif /* HARDWAREDRIVER_H_ */
