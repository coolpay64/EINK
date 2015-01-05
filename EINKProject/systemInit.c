/*
 * systemInit.c
 *
 *  Created on: 2015/1/4
 *      Author: KH
 */

#include "systemInit.h"
#include "inc/hw_types.h"
#include "inc/hw_ssi.h"
#define PWMFREQ	20000

void EPD_display_hardware_init(void) {
	//EPD_initialize_gpio();
	EPD_Vcc_turn_off();
	//epd_spi_init();
	//initialize_temperature();
	EPD_flash_cs_low();
	EPD_cs_low();
	//EPD_pwm_low();
	EPD_rst_low();
	EPD_discharge_low();
	EPD_border_low();
	//initialize_EPD_timer();
}

void initSystem(){
	int temperature;
	//Init System Clock and Stack
    //FPULazyStackingEnable();
	SysCtlClockSet(SYSCTL_SYSDIV_1|SYSCTL_XTAL_16MHZ|SYSCTL_USE_OSC|SYSCTL_OSC_MAIN);
	//Init GPIOs
	PortFunctionInit();
	//Init SysTick
	SysTickPeriodSet(16000000/1000);
	SysTickEnable();


	//Init ADC
	ADCSequenceConfigure(EINK_ADC_BASE,EINK_ADC_SEQ,ADC_TRIGGER_PROCESSOR,0);
	ADCSequenceStepConfigure(EINK_ADC_BASE,EINK_ADC_SEQ,EINK_ADC_STEP,EINK_ADC_CH|ADC_CTL_IE|ADC_CTL_END);
	ADCSequenceEnable(EINK_ADC_BASE,EINK_ADC_SEQ);
	ADCIntClear(EINK_ADC_BASE,EINK_ADC_SEQ);
	//Init PWM
	SysCtlPWMClockSet(SYSCTL_PWMDIV_1);
	PWMGenConfigure(EINK_PWM_BASE,EINK_PWM_GEN,PWM_GEN_MODE_UP_DOWN|PWM_GEN_MODE_GEN_SYNC_LOCAL);
	PWMGenPeriodSet(EINK_PWM_BASE,EINK_PWM_GEN,SysCtlClockGet()/PWMFREQ);
	PWMPulseWidthSet(EINK_PWM_BASE,EINK_PWM_OUT,PWMGenPeriodGet(EINK_PWM_BASE,EINK_PWM_GEN)/2);
	//PWMGenEnable(EINK_PWM_BASE, EINK_PWM_GEN);
	//Init SSI
	SSIConfigSetExpClk(EINK_SPI, SysCtlClockGet(), SSI_FRF_MOTO_MODE_0,
	                       SSI_MODE_MASTER, 8000000, 8);
	HWREG(EINK_SPI + SSI_O_CR1) |= SSI_CR1_EOT; // EoT interrupt allowed

	//
	// Testing function for SSI Loop Back
	//
	//HWREG(EINK_SPI + SSI_O_CR1) |= SSI_CR1_LBM;

	SSIEnable(EINK_SPI);
	//Init UART
	UARTClockSourceSet(EINK_UART,UART_CLOCK_PIOSC);
	UARTStdioConfig(0,115200,SysCtlClockGet());

	//Create Default Output
	EPD_display_hardware_init();
	//Get Temperature
	temperature=getTemperature();
	//Create Temperature Dependent Output
}
int getTemperature(){
	uint32_t adcResult;
	ADCIntClear(EINK_ADC_BASE,EINK_ADC_SEQ);
	ADCProcessorTrigger(EINK_ADC_BASE,EINK_ADC_SEQ);
	while(!ADCIntStatus(EINK_ADC_BASE,EINK_ADC_SEQ, false));
	ADCIntClear(EINK_ADC_BASE,EINK_ADC_SEQ);
	ADCSequenceDataGet(EINK_ADC_BASE,EINK_ADC_SEQ,&adcResult);
	return 0; //TODO: Update Temperature Output
}
static void SSIHandler(){ //TODO: This SSI Handler is dummy
	static int i=101;
	static int j=0;
	uint32_t SSIStatus;
	uint32_t SSIBuf;
	SSIStatus = SSIIntStatus(EINK_SPI,1);
	//UARTprintf("SSI INT: %x\n",SSIStatus);

	if(SSIStatus & SSI_RXFF){
		SSIIntClear(EINK_SPI,SSI_RXFF);
		while(SSIDataGetNonBlocking(EINK_SPI,&SSIBuf)){
			if(SSIBuf==0){
				UARTprintf("Cycle: %d\n",j++);
			}
		}
	}
	if(!SSIBusy(EINK_SPI)){
		SSIDataPutNonBlocking(EINK_SPI,i);
		i++;
	}
	return;
}
void initInterrupt(){
	//SSI
	//SSIIntRegister(EINK_SPI,SSIHandler); //TODO: SSI Interrupt Handler
	//SSIIntEnable(EINK_SPI,SSI_RXFF|SSI_TXFF);
	//SSIIntEnable(EINK_SPI,SSI_TXFF);

	//UART
	//UARTIntRegister(EINK_UART,0); //TODO: UART Interrupt Handler
	//UARTIntEnable(EINK_UART,UART_INT_RX);
	//IntMasterEnable();
	return;
}
