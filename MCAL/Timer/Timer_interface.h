/*
 * Timer_interface.h
 *
 *  Created on: Feb 20, 2021
 *      Author: Mohamed Allam
 */

#ifndef TIMER_HEADERS_TIMER_INTERFACE_H_
#define TIMER_HEADERS_TIMER_INTERFACE_H_

typedef enum {

	_TIM1,
	_TIM2,
	_TIM3,
	_TIM4,
	_TOTLA_USED_TIMERS
}Timer_ID_type;


typedef enum {
	/* CR1 bit 7*/
	AUTO_RELOAD,
	PRELOAD
}Loading_type;

typedef enum {
	/* CR1 bit 4,5,6*/
	UPCOUNTER,
	DOWNCOUNTER,
	/* CR1 bit 5,6*/
	CENTER_ALIIGNED_MODE1=1,
	CENTER_ALIIGNED_MODE2,
	CENTER_ALIIGNED_MODE3,

}TimerMode_type;

typedef enum {
	/* CR1 bit 3*/
	DISABLE,
	ENABLE
}OnePulseMode_type;

typedef enum {
	TIM_UIE,   /* UPDATE INTERRYUPT ENABLE*/
	TIM_CC1IE,
	TIM_CC2IE,
	TIM_CC3IE,
	TIM_CC4IE,
	TIM_TIE=6, /* trigger interrupt enable*/
	TIM_UDE=8, /* Update DMA request enable*/
	TIM_CC1DE, /* Capteure/Compare1 DMA request enable */
	TIM_CC2DE, /* Capteure/Compare2 DMA request enable */
	TIM_CC3DE, /* Capteure/Compare3 DMA request enable */
	TIM_CC4DE, /* Capteure/Compare4 DMA request enable */
	TIM_TDE=14, /*Trigger DMA request enable	*/
}Interrupt_ID;

typedef enum {
	TIM_UG, /* UPDATE Generation */
	TIM_CC1G, /* Capture/Compare Event  */
	TIM_CC2G,  /*Capture/Compare Event */
	TIM_CC3G,  /*Capture/Compare Event*/
	TIM_CC4G,  /*Capture/Compare Event*/
	TIM_TG=6,  /*Trigger Generation */

}GenerateEvents_ID;

/* External Trigger config*/


typedef enum {
	/* SMCR bit 15*/
	ACTIVE_HIGH,
	ACTIVE_LOW
}External_trigger_polarity;


//typedef enum {
//	/* SMCR bit 15*/
//	EXACTIVE_HIGH,
//	ACTIVE_LOW
//}External_trigger_polarity;

typedef enum {
	/* SMCR bit 12 ,13 */
	PRESCALE_OFF,
	ETRP_DIV2,
	ETRP_DIV4,
	ETRP_DIV8, /*After clicking 8 times count 1 */
}External_trigger_prescaler;

typedef enum {
	/* SMCR bit 8 :11 */
    No_filter, /*sampling is done at fDTS*/
   fSAMPLING_fCK_INT_N2,
   fSAMPLING_fCK_INT_N4,
   fSAMPLING_fCK_INT_N8,
   fSAMPLING_fDTS_DIV2_N6,
   fSAMPLING_fDTS_DIV2_N8,
   fSAMPLING_fDTS_DIV4_N6,
   fSAMPLING_fDTS_DIV4_N8,
   fSAMPLING_fDTS_DIV8_N6,
   fSAMPLING_fDTS_DIV8_N8,
  fSAMPLING_fDTS_DIV16_N5,
   fSAMPLING_fDTS_DIV16_N6,
   fSAMPLING_fDTS_DIV16_N8,
   fSAMPLING_fDTS_DIV32_N5,
   fSAMPLING_fDTS_DIV32_N6,
   fSAMPLING_fDTS_DIV32_N8,
}External_trigger_filter;

	/*Slave timer Config */
typedef enum {
	/* SMCR bit 4:6 */
	Internal_Trigger_0,      /*(ITR0).*/
	Internal_Trigger_1,      /*(ITR1).*/
	Internal_Trigger_2,      /*(ITR2).*/
	Internal_Trigger_3,      /*(ITR3).*/
	TI1_Edge_Detector,      /* (TI1F_ED)*/
	Filtered_Timer_Input_1,/* (TI1FP1)*/
	Filtered_Timer_Input_2,/*(TI2FP2)*/
	External_Trigger_input, /*(ETRF)*/
}Trigger_selection;

typedef enum {
	/* SMCR bit 0:2 */
	SLAVE_MODE_DISABLED,
	RESET_MODE=4,
	GATED_MODE,
	TRIGGER_MODE,
	EXTERNAL_CLOCK_MODE_1,
	EXTERNAL_CLOCK_MODE_2
}Slave_mode_selection;

/*	Capture unit  OUTPUT  config */

typedef enum {
	CHANNEL1,
	CHANNEL2,

}Channel_ID_type;

typedef enum {
	TIM_CHANNEL1,
	TIM_CHANNEL2,
	TIM_CHANNEL3,
	TIM_CHANNEL4,

}Capture_Mode_type;

typedef enum {
	MODE1_START_HIGH=6,
	MODE2_START_LOW,

}PWM_Mode;
typedef enum {
	EDGE_ALIGN,
	CENTER_ALIGN_UP,
	CENTER_ALIGN_DOWN,
	CENTER_ALIGN_UPDOWN,

}PWM_type;




/*DMA Config*/
////////////////////////////////
#if        TIMERS_DEPENDANCY==INDEPENDENT
typedef struct {
	/*Base unit config*/
	Timer_ID_type    ID ;
	Loading_type    LOADING;
	TimerMode_type    MODE;
	OnePulseMode_type  ONEPULSE ;
	u16  preScaler ;
	/* Capture unit config*/

}Timer_Config_type;
#else










#endif


typedef struct {

	Timer_ID_type         ID ;
	Capture_Mode_type    chaannel;
	PWM_type             PWMtype ;
	PWM_Mode		     PWMmode;
	u16					 TickTime; /* in us */
	u32                   Freq ; /*based on tick time *//* Hz*/
	u8				       duty ; /*  0:100 */


}PWM_Config_type;



void TimerInit(Timer_Config_type* timer);

/* This API doesnt Restart counter .. the counter keep going then loaded with anther value */
/*  this value can be Auto loaded or Preloaded depending on counter config in init api    */
void Timer_voidSetCounter(Timer_ID_type id , u16 count);


u16 Timer_u16GetCounts(Timer_ID_type id);

/*  This Api rest counter and prescaller counter it start over again (No update event)*/
void Timer_voidReLoadingNoUVE(Timer_ID_type id  ,u16 count ,u16 prescaler );




void timer_voidGPWM(PWM_Config_type * PWM );

void Timer_voidEventGenerate(Timer_ID_type id  , GenerateEvents_ID event);
void Timer_SetCallBack( Timer_ID_type id ,void(*pf)(void));
void Timer_InterruptEnable(Timer_ID_type id ,Interrupt_ID  interrupt);
void Timer_InterruptDisable(Timer_ID_type id ,Interrupt_ID  interrupt);
#endif /* TIMER_HEADERS_TIMER_INTERFACE_H_ */
