
//*****************************************************************************
//
// project.c - Simple project to use as a starting point for more complex
//             projects.
//
// Copyright (c) 2013 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
//
//   Redistribution and use in source and binary forms, with or without
//   modification, are permitted provided that the following conditions
//   are met:
//
//   Redistributions of source code must retain the above copyright
//   notice, this list of conditions and the following disclaimer.
//
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the
//   documentation and/or other materials provided with the
//   distribution.
//
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// This is part of revision 2.0.1.11577 of the Tiva Firmware Development Package.
//
//*****************************************************************************
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "EINK2Pin.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "inc/hw_gpio.h"
#include "inc/hw_ssi.h"
#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom_map.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/ssi.h"
#include "driverlib/udma.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "utils/uartstdio.h"
//*****************************************************************************
//
//! \addtogroup example_list
//! <h1>Simple Project (project)</h1>
//!
//! A very simple example that can be used as a starting point for more complex
//! projects.  Most notably, this project is fully TI BSD licensed, so any and
//! all of the code (including the startup code) can be used as allowed by that
//! license.
//!
//! The provided code simply toggles a GPIO using the Tiva Peripheral Driver
//! Library.
//
//*****************************************************************************

//*****************************************************************************
//
// The error routine that is called if the driver library encounters an error.
//
//*****************************************************************************
#ifdef DEBUG
void
__error__(char *pcFilename, uint32_t ui32Line)
{
}
#endif

void initSystem(void);
void initSystem(){
	PortFunctionInit();
	//Init SSI
	SSIClockSourceSet (EINK_SSI, SSI_CLOCK_SYSTEM);
	SSIConfigSetExpClk(EINK_SSI, SysCtlClockGet(), SSI_FRF_MOTO_MODE_3,
                       SSI_MODE_MASTER, 2000000, 16);

    //
    // Enable the SSI0 module.
    //
	SSIEnable(EINK_SSI);
	EINK_SSI_DISABLE();
	//Init UART
	MAP_UARTClockSourceSet(EINK_UART,UART_CLOCK_PIOSC);
	UARTStdioConfig(0,115200,SysCtlClockGet());
	return;
}
int
main(void)
{
	int i;
	uint32_t dataBuf;
	SysCtlClockSet(SYSCTL_SYSDIV_1|SYSCTL_XTAL_16MHZ|SYSCTL_USE_OSC|SYSCTL_OSC_MAIN);
	initSystem();
	SysCtlDelay(16000);
	//GPIOPinWrite(EINK_EN_BASE,EINK_EN_PIN,0);
	SysCtlDelay(16000*300);//	initSystem();

	//while(GPIOPinRead(EINK_BUSY_BASE,EINK_BUSY_PIN));
	//while(!GPIOPinRead(EINK_BUSY_BASE,EINK_BUSY_PIN));
    //
    // Loop forever.
    //
	while(1){
	EINK_SSI_ENABLE();	SysCtlDelay(320);
	SSIDataPut(EINK_SSI,0x24);SSIDataGet(EINK_SSI,&dataBuf);
	SSIDataPut(EINK_SSI,0x01);SSIDataGet(EINK_SSI,&dataBuf);
	SSIDataPut(EINK_SSI,0x00);SSIDataGet(EINK_SSI,&dataBuf);
	SysCtlDelay(320);
	EINK_SSI_DISABLE();
	SysCtlDelay(320);
	while(!GPIOPinRead(EINK_BUSY_BASE,EINK_BUSY_PIN));
	EINK_SSI_ENABLE();	SysCtlDelay(320);
	for(i=0;i<2;i++){
		SSIDataPut(EINK_SSI,0x00);SSIDataGet(EINK_SSI,&dataBuf);
		UARTprintf("%02X ",dataBuf);
	}
	//SSIDataPut(EINK_SSI,0x00);SSIDataGet(EINK_SSI,&dataBuf);
	SysCtlDelay(320);EINK_SSI_DISABLE();SysCtlDelay(320);
	UARTprintf("END\n");
	}

	while(1);
    {
    	SSIDataPut(EINK_SSI,0x0000);
    	SSIDataGet(EINK_SSI,&dataBuf);
		UARTprintf("%x\n",dataBuf);

    }
	EINK_SSI_DISABLE();
	UARTprintf("END\n");
	while (1);



}
