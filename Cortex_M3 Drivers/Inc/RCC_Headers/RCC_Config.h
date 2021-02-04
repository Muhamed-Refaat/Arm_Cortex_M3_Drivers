/*
 * RCC_Config.h
 *
 *  Created on: Feb 2, 2021
 *      Author: Mohamed Allam
 */

#ifndef RCC_HEADERS_RCC_CONFIG_H_
#define RCC_HEADERS_RCC_CONFIG_H_

/* 	CLOCK_TYPE can be:
 * 						1-RCC_HSI
 * 						2-RCC_HSE
 * 						3-RCC_PLL
 *
 */
#define CLOCK_TYPE			RCC_PLL

#if		CLOCK_TYPE== RCC_HSE
/*		Can be RCC_CRYSTAL or RCC_RC */
#define  RCC_HSE_SOURCE		RCC_CRYSTAL
#endif

#if  	CLOCK_TYPE== RCC_PLL
/*	PLL Multiplication factor 1:16 	*/
#define RCC_PLL_MUL		    	1
/*		PLL Source (HSE/HSI/HSE_2)		*/
#define RCC_PLL_SOURCE		RCC_HSE_2
#endif
/////////////////////////////////////////////////////////////////////////
/************************************************************************
 * To Enable/Disable desired peripheral clk add it to the bus array
 *  then accumulate new total and First Peripheral id on bus
 *  .......................................................................
 * to Enable bus peripherals clk Without a certain peripheral
 * remove it from the array  then accumulate new total
 *  and First Peripheral id on bus
 ************************************************************************/

#define 		AHB_TOTAL					    	9
#define 		AHB_FIRST_PREPHERIAL	 		AHB_DMA1
const Prephiral_Id_type  AHB_Bus_On_Off_Array[AHB_TOTAL]={
			AHB_DMA1,
			AHB_DMA2,
			AHB_SRAM,
			AHB_FLITF,
			AHB_CRC	,
			AHB_OTGFS,
			AHB_ETHMAC,
			AHB_ETHMACTX,
			AHB_ETHMACRX,
};

#define 		APB2_TOTAL						11
#define 		APB2_FIRST_PREPHERIAL	 		APB2_AFIO
const Prephiral_Id_type  APB2_Bus_On_Off_Array[APB2_TOTAL]={
			APB2_AFIO,
			APB2_GPIOPA,
			APB2_GPIOPB,
			APB2_GPIOPC,
			APB2_GPIOPD,
			APB2_GPIOPE,
			APB2_ADC1,
			APB2_ADC2,
			APB2_TIM1,
			APB2_SPI1,
			APB2_USART1,

};
#define			APB1_TOTAL					20
#define 		APB1_FIRST_PREPHERIAL	 		APB1_TIM2
const Prephiral_Id_type  APB1_Bus_On_Off_Array[APB1_TOTAL]={
			APB1_TIM2,
			APB1_TIM3,
			APB1_TIM4,
			APB1_TIM5,
			APB1_TIM6,
			APB1_TIM7,
			APB1_WWDG,
			APB1_SPI2,
			APB1_SPI3,
			APB1_USART2,
			APB1_USART3,
			APB1_UART4,
			APB1_UART5,
			APB1_I2C1,
			APB1_I2C2,
			APB1_CAN1,
			APB1_CAN2,
			APB1_BKP,
			APB1_PWR,
			APB1_DAC,
};
//////////////////////////////////////////////////////////////////////////////////

#endif /* RCC_HEADERS_RCC_CONFIG_H_ */
