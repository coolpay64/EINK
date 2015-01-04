/*
 * systemInit.h
 *
 *  Created on: 2015/1/4
 *      Author: KH
 */

#ifndef SYSTEMINIT_H_
#define SYSTEMINIT_H_
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
#include "utils/uartstdio.h"

#include "PINConfig.h"
#include "hardwareDriver.h"

extern void initSystem();
extern int getTemperature();
extern void EPD_display_hardware_init(void);




#endif /* SYSTEMINIT_H_ */
