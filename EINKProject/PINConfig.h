/*
 * PINConfig.h
 *
 *  Created on: 2015/1/4
 *      Author: KH
 */

#ifndef PINCONFIG_H_
#define PINCONFIG_H_

#define Temper_PIN              GPIO_PIN_5
#define Temper_PORT             GPIO_PORTE_BASE       /**< LaunchPad PE.5 */

#define PWM_PIN                 GPIO_PIN_6
#define PWM_PORT                GPIO_PORTA_BASE       /**< LaunchPad PA.6  */


#define EPD_BUSY_PIN            GPIO_PIN_5
#define EPD_BUSY_PORT           GPIO_PORTA_BASE       /**< LaunchPad PA.5  */
#define EPD_RST_PIN             GPIO_PIN_7
#define EPD_RST_PORT            GPIO_PORTA_BASE       /**< LaunchPad PA.7 */
#define EPD_PANELON_PIN         GPIO_PIN_2
#define EPD_PANELON_PORT        GPIO_PORTA_BASE       /**< LaunchPad PA.2  */
#define EPD_DISCHARGE_PIN       GPIO_PIN_3
#define EPD_DISCHARGE_PORT      GPIO_PORTA_BASE       /**< LaunchPad PA.3  */
#define EPD_BORDER_PIN          GPIO_PIN_4
#define EPD_BORDER_PORT         GPIO_PORTA_BASE       /**< LaunchPad PA.4  */

#define Flash_CS_PIN            GPIO_PIN_0
#define Flash_CS_PORT           GPIO_PORTE_BASE       /**< LaunchPad PE.0  */
#define EPD_CS_PIN              GPIO_PIN_2
#define EPD_CS_PORT             GPIO_PORTB_BASE       /**< LaunchPad PB.2  */

#define SPICLK_PIN              GPIO_PIN_4
#define SPICLK_PORT             GPIO_PORTB_BASE       /**< LaunchPad PB.4 */
#define SPIMISO_PIN             GPIO_PIN_6
#define SPIMISO_PORT            GPIO_PORTB_BASE       /**< LaunchPad PB.6  */
#define SPIMOSI_PIN             GPIO_PIN_7
#define SPIMOSI_PORT            GPIO_PORTB_BASE       /**< LaunchPad PB.7  */

#define EINK_SPI				SSI2_BASE
#define EINK_UART				UART1_BASE
#define EINK_PWM_BASE			PWM1_BASE
#define EINK_PWM_GEN			PWM_GEN_1
#define EINK_PWM_OUT			PWM_OUT_2_BIT
#define EINK_ADC_BASE      		ADC0_BASE
#define EINK_ADC_CH      		ADC_CTL_CH8
#define EINK_ADC_SEQ      		3
#define EINK_ADC_STEP      		0




#endif /* PINCONFIG_H_ */
