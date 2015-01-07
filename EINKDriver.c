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
void EINK8bModeStart(){
	while(SSIBusy(EINK_SSI));
	SSIDisable(EINK_SSI);
	SSIConfigSetExpClk(EINK_SSI, SysCtlClockGet(), SSI_FRF_MOTO_MODE_3,
	                       SSI_MODE_MASTER, 2000000, 8);
	SSIEnable(EINK_SSI);
}
void EINK8bModeEnd(){
	while(SSIBusy(EINK_SSI));
	SSIDisable(EINK_SSI);
	SSIConfigSetExpClk(EINK_SSI, SysCtlClockGet(), SSI_FRF_MOTO_MODE_3,
	                       SSI_MODE_MASTER, 2000000, 16);
	SSIEnable(EINK_SSI);
}
void EINKStartTrans(){
	SysCtlDelay(16*2);
	EINK_SSI_ENABLE();
	SysCtlDelay(16*7);
}
void EINKStopTrans(){
	SysCtlDelay(16*11);
	EINK_SSI_DISABLE();
	SysCtlDelay(16*6);
	while(!GPIOPinRead(EINK_BUSY_BASE,EINK_BUSY_PIN));
}

void EINKDisplayPtrReset(){
	uint32_t inBuf;
	uint32_t response;
	EINK8bModeStart();
	EINKStartTrans();
	SSIDataPut(EINK_SSI,0x20);SSIDataGet(EINK_SSI,&inBuf);
	SSIDataPut(EINK_SSI,0x00);SSIDataGet(EINK_SSI,&inBuf);
	SSIDataPut(EINK_SSI,0x00);SSIDataGet(EINK_SSI,&inBuf);
	EINKStopTrans();
	EINK8bModeEnd();
	EINKStartTrans();
	SSIDataPut(EINK_SSI,0x0000);SSIDataGet(EINK_SSI,&response);
	EINKStopTrans();
}
void EINK_DisplayUpdate(){
	uint32_t inBuf;
	uint32_t response;
	EINK8bModeStart();
	EINKStartTrans();
	SSIDataPut(EINK_SSI,0x20);SSIDataGet(EINK_SSI,&inBuf);
	SSIDataPut(EINK_SSI,0x01);SSIDataGet(EINK_SSI,&inBuf);
	SSIDataPut(EINK_SSI,0x00);SSIDataGet(EINK_SSI,&inBuf);
	EINKStopTrans();
	EINK8bModeEnd();
	EINKStartTrans();
	SSIDataPut(EINK_SSI,0x0000);SSIDataGet(EINK_SSI,&response);
	EINKStopTrans();
}
uint32_t EINKReadSensor(){
	uint32_t inBuf;
	uint32_t response;
	EINKStartTrans();
	SSIDataPut(EINK_SSI,0x0000);SSIDataGet(EINK_SSI,&response);
	SSIDataPut(EINK_SSI,0x0000);SSIDataGet(EINK_SSI,&response);
	EINKStopTrans();
	EINKStartTrans();
	SSIDataPut(EINK_SSI,0x0000);SSIDataGet(EINK_SSI,&inBuf);
	SSIDataPut(EINK_SSI,0x0000);SSIDataGet(EINK_SSI,&response);
	EINKStopTrans();
	return response == 0x9000 ? inBuf : 0;
}

/*
void EINK_SSI_8bMode(){

}
*/
