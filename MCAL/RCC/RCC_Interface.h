/*
 * RCC_Interface.h
 *
 *  Created on: Feb 2, 2021
 *      Author: Mohamed Allam
 */

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_
	/*				BUSES IDs					*/
#define	    RCC_AHB			0
#define 	RCC_APB1		1
#define 	RCC_APB2		2
//////////////////////////////////////////////////////////
	/*		BUSES	peripherals IDs				*/
///////////////////////////////////////////////////////////
typedef enum {
/*AHB peripherals IDs*/
	AHB_DMA1=0,
	AHB_DMA2,
	AHB_SRAM,
	AHB_FLITF=4,
	AHB_CRC	=6,
	AHB_OTGFS=12,
	AHB_ETHMAC=14,
	AHB_ETHMACTX,
	AHB_ETHMACRX,
/*APB2 peripherals IDs*/
	APB2_AFIO=0,
	APB2_GPIOPA=2,
	APB2_GPIOPB,
	APB2_GPIOPC,
	APB2_GPIOPD,
	APB2_GPIOPE,
	APB2_ADC1=9,
	APB2_ADC2,
	APB2_TIM1,
	APB2_SPI1,
	APB2_USART1=14,
/*APB1 peripherals IDs*/
	APB1_TIM2=0,
	APB1_TIM3,
	APB1_TIM4,
	APB1_TIM5,
	APB1_TIM6,
	APB1_TIM7,
	APB1_WWDG=11,
	APB1_SPI2=14,
	APB1_SPI3,
	APB1_USART2=17,
	APB1_USART3,
	APB1_UART4,
	APB1_UART5,
	APB1_I2C1,
	APB1_I2C2,
	APB1_CAN1=25,
	APB1_CAN2,
	APB1_BKP,
	APB1_PWR,
	APB1_DAC,
	ALL_PREPHERIALS=40
}Prephiral_Id_type;

/* Function prototypes or API's prototype ely */
void RCC_voidInit(void);
void RCC_voidEnablePeripheralClock(u8 Copy_u8BusID,Prephiral_Id_type Copy_u8PeripheralID);
void RCC_voidDisblePeripheralClock(u8 Copy_u8BusID,Prephiral_Id_type Copy_u8PeripheralID);

void RCC_voidEnablePeripheralClock_EntireBus(u8 Copy_u8BusID);
void RCC_voidDisblePeripheralClock_EntireBus(u8 Copy_u8BusID);
void RCC_voidEnablePeripheralClock_APreipherals(void); /*SET 3 Registers with 0xFFFFFFFF */
void RCC_voidDisblePeripheralClock_APreipherals(void);

#endif /* RCC_INTERFACE_H_ */
