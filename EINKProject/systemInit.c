/*
 * systemInit.c
 *
 *  Created on: 2015/1/4
 *      Author: KH
 */

#include "systemInit.h"
#define PWMFREQ	200000

void EPD_display_hardware_init(void) {
	//EPD_initialize_gpio();
	EPD_Vcc_turn_off();
	//epd_spi_init();
	//initialize_temperature();
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
    FPULazyStackingEnable();
	SysCtlClockSet(SYSCTL_SYSDIV_1|SYSCTL_XTAL_16MHZ|SYSCTL_USE_OSC|SYSCTL_OSC_MAIN);
	//Init GPIOs
	PortFunctionInit();
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
	PWMGenEnable(PWM0_BASE, PWM_GEN_0);
	//Init SSI
	SSIConfigSetExpClk(EINK_SPI, SysCtlClockGet(), SSI_FRF_MOTO_MODE_0,
	                       SSI_MODE_MASTER, 8000000, 8);
	SSIEnable(EINK_SPI);
	//Init UART
	UARTClockSourceSet(EINK_UART,UART_CLOCK_PIOSC);
	UARTStdioConfig(EINK_UART,115200,SysCtlClockGet());
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
	return 0;
}
