/*
 * Timer_private.h
 *
 *  Created on: Feb 20, 2021
 *      Author: Mohamed Allam
 */

#ifndef TIMER_HEADERS_TIMER_PRIVATE_H_
#define TIMER_HEADERS_TIMER_PRIVATE_H_

typedef struct {
	volatile u32 CR1  ;
	volatile u32 CR2  ;
	volatile u32 SMCR ;
	volatile u32 DIER ;
	volatile u32 SR   ;
	volatile u32 EGR  ;
	volatile u32 CCMR1 ;
	volatile u32 CCMR2 ;
	volatile u32 CCER  ;
	volatile u32 CNT  ;
	volatile u32 PSC  ;
	volatile u32 ARR ;
	volatile u32 RCR   ;
	volatile u32 CCR1  ;
	volatile u32 CCR2 ;
	volatile u32 CCR3 ;
	volatile u32 CCR4  ;
	volatile u32 BDTR  ;
	volatile u32 DCR  ;
	volatile u32 DMAR  ;


}GeneralPurposeTimers_type;  /*General TIM2:TIM5*/

			/* General */
#define     TIM1 		((GeneralPurposeTimers_type*)0x40012C00)
#define     TIM2 		((GeneralPurposeTimers_type*)0x40000000)
#define     TIM3 		((GeneralPurposeTimers_type*)0x40000400)
#define     TIM4 		((GeneralPurposeTimers_type*)0x40000800)

#define                 INDPENDANT 					2
#define                 DEPENDANT  					3




/*************************************Advanced control timers TIM1 , TIM8 *************************/
/**********************************General Purpose Timers TIM9 : TIM14 *************************************/
/********************************** Basic Timers TIM6 : TIM17 *************************************/





#endif /* TIMER_HEADERS_TIMER_PRIVATE_H_ */
