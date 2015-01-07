//*****************************************************************************
// Copyright (c) 2014 Texas Instruments Incorporated.  All rights reserved.
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
// This file was automatically generated by the Tiva C Series PinMux Utility
// Version: 1.0.4
//
//*****************************************************************************

#ifndef __EINK2_H__
#define __EINK2_H__

#define EINK_EN_BASE	GPIO_PORTB_BASE
#define EINK_EN_PIN		GPIO_PIN_3
#define EINK_BUSY_BASE	GPIO_PORTB_BASE
#define EINK_BUSY_PIN	GPIO_PIN_2
#define EINK_CSN_BASE	GPIO_PORTA_BASE
#define EINK_CSN_PIN	GPIO_PIN_3
#define EINK_SSI		SSI0_BASE
#define EINK_UART		UART0_BASE
#define EINK_SSI_ENABLE()	GPIOPinWrite(EINK_CSN_BASE,EINK_CSN_PIN,0)
#define EINK_SSI_DISABLE()	GPIOPinWrite(EINK_CSN_BASE,EINK_CSN_PIN,EINK_CSN_PIN)

extern void PortFunctionInit(void);
//extern void PortFunctionInit_AllGPIO(void);


#endif //  __EINK2_H__
