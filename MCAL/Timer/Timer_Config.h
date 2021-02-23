/*
 * Timer_Config.h
 *
 *  Created on: Feb 20, 2021
 *      Author: Mohamed Allam
 */

#ifndef TIMER_HEADERS_TIMER_CONFIG_H_
#define TIMER_HEADERS_TIMER_CONFIG_H_

/*
 *  TIMERS_DEPENDANCY can be :
 *  							1- INDPENDANT
 *  							2- DEPENDANT
 */


#define           TIMERS_DEPENDANCY							INDPENDANT

/*Timers type :-
 * 				1- Advanced control timers :- TIM1 and TIM8
 * 				2- General  purpose timers :- TIM2 : TIM5 , TIM9 : TIM14
 * 				2- Basic  timers :- TIM6 and TIM7
 *
 *
 * 	Note :- Each timer has 4 independent channels used for :-
 *
 * 			Input capture
 * 		    Output compare
 *			PWM generation (Edge- and Center-aligned modes)
 *			One-pulse mode output
 *
 *
 */




#endif /* TIMER_HEADERS_TIMER_CONFIG_H_ */
