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
#include "inc/hw_memmap.h"
#include "inc/hw_ssi.h"
#include "inc/hw_types.h"
#include "PinAssignment.h"
#include "driverlib/pin_map.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/systick.h"
#include "driverlib/uart.h"
#include "driverlib/ssi.h"
#include "driverlib/pwm.h"
#include "driverlib/adc.h"

#include "utils/uartstdio.h"

#include "hardwareDriver.h"
#include "PINConfig.h"
#include "systemInit.h"

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

//*****************************************************************************
//
// E-Paper Display Driving Kit
//
//*****************************************************************************
void EPDSPISend(uint32_t addr, const uint32_t *dataIn, uint32_t len);
void EPDDisplayCOGON(void);
void EPDDisplayCOGOFF(void);
void EPD_WriteBoarderLine(void);
void EPDInitSession(void);
void EPDLoop(void);
void EPD_WriteBlackFrame(void);
void EPD_WriteWhiteFrame(void);
void EPD_WriteNoneFrame(void);
int
main(void)
{
	uint32_t dataBuf;
	//
	// Initialize Hardware System
	//
	initSystem();
	EPD_Vcc_turn_off();

	//
	// Initialize Interrupts
	//
	initInterrupt();

	//
	// Initialize EPD
	//
	EPDInitSession();

	//
	// Test Function, SSI Single Transmission.
	//
	//UARTCharPut(EINK_UART,'a');
	//UARTCharPut(EINK_UART,'\n');
	//while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPutNonBlocking(EINK_SPI,100);


	//EPD_led_high();

	//
    // Loop forever.
    //
    while(1)
    {
    	EPDLoop();
    }
}
static void EPDSPISend(uint32_t addr, const uint32_t dataIn[], uint32_t len){
	int i;
	EPD_cs_low();
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x70);
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,addr);
	EPD_cs_high();
	SysCtlDelay(160);
	EPD_cs_low();
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x72);
	for(i=0;i<len;i++)
		while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,dataIn[i]);
	EPD_cs_high();
	SysCtlDelay(160);
	return;
}
void EPDDisplayCOGON(void){
	// EPD Power On
	EPD_discharge_low();
	EPD_cs_low();
	EPD_border_low();
	EPD_rst_low();	SysCtlDelay(16000*10);

	PWMGenEnable(EINK_PWM_BASE,EINK_PWM_GEN);
	SysCtlDelay(16000*5);
	PWMGenDisable(EINK_PWM_BASE,EINK_PWM_GEN);
	EPD_Vcc_turn_on();
	PWMGenEnable(EINK_PWM_BASE,EINK_PWM_GEN);
	SysCtlDelay(16000*10);
	PWMGenDisable(EINK_PWM_BASE,EINK_PWM_GEN);
	EPD_cs_high();
	EPD_border_high();
	EPD_rst_high();
	PWMGenEnable(EINK_PWM_BASE,EINK_PWM_GEN);
	SysCtlDelay(16000*5);
	PWMGenDisable(EINK_PWM_BASE,EINK_PWM_GEN);
	EPD_rst_low();
	PWMGenEnable(EINK_PWM_BASE,EINK_PWM_GEN);
	SysCtlDelay(16000*5);
	PWMGenDisable(EINK_PWM_BASE,EINK_PWM_GEN);
	EPD_rst_high();
	PWMGenEnable(EINK_PWM_BASE,EINK_PWM_GEN);
	SysCtlDelay(16000*5);
	PWMGenDisable(EINK_PWM_BASE,EINK_PWM_GEN);


	//Check Busy
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN))
		SysCtlDelay(16);

	// Init End

	// Init COG Driver
	// CHannel Select
	EPD_cs_low();
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x70);
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x01);
	EPD_cs_high();
	SysCtlDelay(160);
	EPD_cs_low();
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x72);
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x00);
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x00);
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x00);
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x0F);
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0xFF);
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x00);
	EPD_cs_high();
	SysCtlDelay(160);
	// DCDC Freq
	EPD_cs_low();
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x70);
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x06);
	EPD_cs_high();
	SysCtlDelay(160);
	EPD_cs_low();
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x72);
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0xFF);
	EPD_cs_high();
	SysCtlDelay(160);
	// High Power Mode Osc Setting
	EPD_cs_low();
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x70);
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x07);
	EPD_cs_high();
	SysCtlDelay(160);
	EPD_cs_low();
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x72);
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x9D);
	EPD_cs_high();
	SysCtlDelay(160);
	// ADC Disable
	EPD_cs_low();
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x70);
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x08);
	EPD_cs_high();
	SysCtlDelay(160);
	EPD_cs_low();
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x72);
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x00);
	EPD_cs_high();
	SysCtlDelay(160);

	// Set Vcom Level
	EPD_cs_low();
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x70);
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x09);
	EPD_cs_high();
	SysCtlDelay(160);
	EPD_cs_low();
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x72);
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0xD0);
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x00);
	EPD_cs_high();
	SysCtlDelay(160);

	// Set Gate Source Voltage Level
	EPD_cs_low();
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x70);
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x04);
	EPD_cs_high();
	SysCtlDelay(160);
	EPD_cs_low();
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x72);
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x03);
	EPD_cs_high();
	SysCtlDelay(160);
	PWMGenEnable(EINK_PWM_BASE,EINK_PWM_GEN);
	SysCtlDelay(16000*5);
	PWMGenDisable(EINK_PWM_BASE,EINK_PWM_GEN);

	// Set Driver latch on

	EPD_cs_low();
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x70);
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x03);
	EPD_cs_high();
	SysCtlDelay(160);
	EPD_cs_low();
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x72);
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x01);
	EPD_cs_high();
	SysCtlDelay(160);

	// Set Driver latch off
	EPD_cs_low();
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x70);
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x03);
	EPD_cs_high();
	SysCtlDelay(160);
	EPD_cs_low();
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x72);
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x00);
	EPD_cs_high();
	SysCtlDelay(160);

	// Set +ve Charge Pump
	EPD_cs_low();
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x70);
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x05);
	EPD_cs_high();
	SysCtlDelay(160);
	EPD_cs_low();
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x72);
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x01);
	EPD_cs_high();
	SysCtlDelay(160);
	PWMGenEnable(EINK_PWM_BASE,EINK_PWM_GEN);
	SysCtlDelay(16000*30);
	PWMGenDisable(EINK_PWM_BASE,EINK_PWM_GEN);

	// Set -ve Charge Pump
	EPD_cs_low();
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x70);
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x05);
	EPD_cs_high();
	SysCtlDelay(160);
	EPD_cs_low();
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x72);
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x03);
	EPD_cs_high();
	SysCtlDelay(160);
	SysCtlDelay(16000*30);

	// Set Vcom Charge Pump
	EPD_cs_low();
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x70);
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x05);
	EPD_cs_high();
	SysCtlDelay(160);
	EPD_cs_low();
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x72);
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x0F);
	EPD_cs_high();
	SysCtlDelay(160);
	SysCtlDelay(16000*30);

	// Disable Output
	EPD_cs_low();
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x70);
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x02);
	EPD_cs_high();
	SysCtlDelay(160);
	EPD_cs_low();
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x72);
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x24);
	EPD_cs_high();
	SysCtlDelay(160);

	return;
}
void EPDDisplayCOGOFF(void){
	const uint32_t addr[10]={
			0x03,
			0x02,
			0x05,
			0x05,
			0x04,
			0x05,
			0x07,
			0x04,
			0x04,
			0x04,
	};
	const uint32_t setupData[10][1]={
			{0x01,},
			{0x05,},
			{0x0E,},
			{0x02,},
			{0x0C,},
			{0x00,},
			{0x0D,},
			{0x50,},
			{0xA0,},
			{0x00,}
	};
	int i;
	EPD_WriteBoarderLine();
	SysCtlDelay(16000*300);
	for(i=0;i<5;i++)
			EPDSPISend(addr[i],setupData[i],1);
	for(i=5;i<10;i++){
			EPDSPISend(addr[i],setupData[i],1);
			SysCtlDelay(16000*150);
	}
	EPD_border_low();

	EPD_cs_low();
	EPD_rst_low();
	EPD_Vcc_turn_off();
	EPD_discharge_high();
	SysCtlDelay(16000*150);
	EPD_discharge_low();
	return;
}
void EPD_WriteBoarderLine(void){
	const uint32_t data[2][1]={
				{0x03},
				{0x2F}
	};
	int i,y;
	EPDSPISend(0x04,data[0],1);
	EPD_cs_low();
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x70);
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x0A);
	EPD_cs_high();
	SysCtlDelay(160);
	EPD_cs_low();
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x72);
	while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0xAA);
	for(i=0;i<16;i++)
		while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x55);
	for(i=0;i<24;i++){
		while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x00);
	}
	for(i=0;i<16;i++)
			while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x55);
	EPD_cs_high();
	SysCtlDelay(160);
	EPDSPISend(0x02,data[1],1);
	return;
}
void EPD_WriteBlackFrame(void){
	const uint32_t dataStart=0x03;
	const uint32_t dataEnd  =0x2F;

	int i,y;
	for(y=0;y<96;y++){
		EPDSPISend(0x04,&dataStart,1);
		EPD_cs_low();
		while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x70);
		while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x0A);
		EPD_cs_high();
		SysCtlDelay(160);
		EPD_cs_low();
		while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x72);
		while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x00);
		for(i=0;i<16;i++)
			while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0xFF);
		for(i=0;i<24;i++){
			if(i==y>>2){
				switch(y%4){
				case 0:
					while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0xC0);
					break;
				case 1:
					while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x30);
					break;
				case 2:
					while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x0C);
					break;
				case 3:
					while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x03);
					break;
				}
			}else{
				while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x00);
			}
		}
		for(i=0;i<16;i++)
				while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0xFF);
		EPD_cs_high();
		SysCtlDelay(160);
		EPDSPISend(0x02,&dataEnd,1);
	}
	return;
}
void EPD_WriteWhiteFrame(void){
	const uint32_t dataStart=0x03;
	const uint32_t dataEnd  =0x2F;

	int i,y;
	for(y=0;y<96;y++){
		EPDSPISend(0x04,&dataStart,1);
		EPD_cs_low();
		while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x70);
		while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x0A);
		EPD_cs_high();
		SysCtlDelay(160);
		EPD_cs_low();
		while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x72);
		while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x00);
		for(i=0;i<16;i++)
			while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0xAA);
		for(i=0;i<24;i++){
			if(i==y>>2){
				switch(y%4){
				case 0:
					while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0xC0);
					break;
				case 1:
					while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x30);
					break;
				case 2:
					while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x0C);
					break;
				case 3:
					while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x03);
					break;
				}
			}else{
				while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x00);
			}
		}
		for(i=0;i<16;i++)
				while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0xAA);
		EPD_cs_high();
		SysCtlDelay(160);
		EPDSPISend(0x02,&dataEnd,1);
	}
	return;
}
void EPD_WriteNoneFrame(void){
	const uint32_t dataStart=0x03;
	const uint32_t dataEnd  =0x2F;

	int i,y;
	for(y=0;y<96;y++){
		EPDSPISend(0x04,&dataStart,1);
		EPD_cs_low();
		while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x70);
		while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x0A);
		EPD_cs_high();
		SysCtlDelay(160);
		EPD_cs_low();
		while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x72);
		while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x00);
		for(i=0;i<16;i++)
			while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x00);
		for(i=0;i<24;i++){
			if(i==y>>2){
				switch(y%4){
				case 0:
					while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0xC0);
					break;
				case 1:
					while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x30);
					break;
				case 2:
					while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x0C);
					break;
				case 3:
					while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x03);
					break;
				}
			}else{
				while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x00);
			}
		}
		for(i=0;i<16;i++)
				while(GPIOPinRead(EPD_BUSY_PORT,EPD_BUSY_PIN)); SSIDataPut(EINK_SPI,0x00);
		EPD_cs_high();
		SysCtlDelay(160);
		EPDSPISend(0x02,&dataEnd,1);
	}
	return;
}

void EPDInitSession(void){
	return;
}
void EPDLoop(void){
	EPDDisplayCOGON();
	EPD_WriteBlackFrame();
	SysCtlDelay(16000000);
	EPD_WriteWhiteFrame();
	SysCtlDelay(16000000);
	EPD_WriteNoneFrame();
	SysCtlDelay(16000000);
	EPDDisplayCOGOFF();
	return;
}
