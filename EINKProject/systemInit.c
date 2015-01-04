/*
 * systemInit.c
 *
 *  Created on: 2015/1/4
 *      Author: KH
 */

#include "systemInit.h"
#define PWMFREQ	200000

void initSystem(){
	int temperature;
	//Init System Clock
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
	//Init UART
	//Create Default Output
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
