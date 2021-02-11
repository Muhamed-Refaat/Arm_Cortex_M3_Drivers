

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_


typedef enum {

	WWDG=0,
	PVD,
	TAMPER,
	RTC,
	FLASH,
	RCC,
	EXTI0,
	EXTI1,
	EXTI2,
	EXTI3,
	EXTI4,
	DMA1_CHANNEL1,
	DMA1_CHANNEL2,
	DMA1_CHANNEL3,
	DMA1_CHANNEL4,
	DMA1_CHANNEL5,
	DMA1_CHANNEL6,
	DMA1_CHANNEL7,
	ADC1_2,
	USB_HP_CAN_TX,
	USB_LP_CAN_RX0,
	CAN_RX1,
	CAN_SCE,
	EXTI9_5,
	TIM1_BRK ,
	TIM1_UP  ,
	TIM1_TRG_COM ,
	TIM1_CC  ,
	TIM2 ,
	TIM3 ,
	TIM4  ,
	I2C1_EV ,
	I2C1_ER ,
	I2C2_EV ,
	I2C2_ER ,
	SPI1 ,
	SPI2 ,
	USART1 ,
	USART2 ,
	USART3,
	EXTI15_10,
	RTCAlarm,
	USBWakeup,
	TIM8_BRK,
	TIM8_UP,
	TIM8_TRG_COM,
	TIM8_CC,
	ADC3,
	FSMC,
	SDIO,
	TIM5,
	SPI3,
	UART4,
	UART5,
	TIM6,
	TIM7,
	DMA2_Channel1,
	DMA2_Channel2,
	DMA2_Channel3,
	DMA2_Channel4_5

}NVIC_Prephiral_InterruptID_type;









void NVIC_voidInit(void);

void NVIC_voidEnableInterrupt(NVIC_Prephiral_InterruptID_type Copy_u8InterruptNum);
void NVIC_voidDisableInterrupt(NVIC_Prephiral_InterruptID_type Copy_u8InterruptNum);

void NVIC_voidSetPendingFlag(NVIC_Prephiral_InterruptID_type Copy_u8InterruptNum);
void NVIC_voidClearPendingFlag(NVIC_Prephiral_InterruptID_type Copy_u8InterruptNum);

u8	 NVIC_u8GetActiveFlag(NVIC_Prephiral_InterruptID_type Copy_u8InterruptNum);

void NVIC_voidSetPriority(NVIC_Prephiral_InterruptID_type Copy_u8InterruptNum , u8 Copy_u8PerPriority);

#endif /* NVIC_INTERFACE_H_ */
