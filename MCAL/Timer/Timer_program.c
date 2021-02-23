
#include "StdTypes.h"
#include "Utils.h"
#include "Timer_interface.h"
#include "Timer_private.h"
#include "Timer_Config.h"

static void (*TIM_pfCallBack[_TOTLA_USED_TIMERS])(void) ={ NULL };


void TimerInit(Timer_Config_type* timer)
{
	/* Pre config  Enable RCC and GPIO */
	switch(timer->ID)
	{
	case _TIM2:
		/*Auto or preload*/
		TIM2->CR1 |= (timer->LOADING << 7) ;
		/*Timer mode*/
		if((timer->MODE==UPCOUNTER) ||(timer->MODE==DOWNCOUNTER))  TIM2->CR1 |= (timer->MODE << 4) ;
		else   TIM2->CR1 |= (timer->MODE << 5) ;
		/*One Pulse mode*/
		TIM2->CR1 |= (timer->ONEPULSE << 3) ;
		/*Timer clock */
		TIM2->PSC =(timer->preScaler-1);
		break;
	case _TIM3:
		/*Auto or preload*/
		TIM3->CR1 |= (timer->LOADING << 7) ;
		/*Timer mode*/
		if((timer->MODE==UPCOUNTER) ||(timer->MODE==DOWNCOUNTER))  TIM3->CR1 |= (timer->MODE << 4) ;
		else   TIM3->CR1 |= (timer->MODE << 5) ;
		/*One Pulse mode*/
		TIM3->CR1 |= (timer->ONEPULSE << 3) ;
		/*Timer clock */
		TIM3->PSC =(timer->preScaler-1);
		break;
	case _TIM4:
		/*Auto or preload*/
		TIM4->CR1 |= (timer->LOADING << 7) ;
		/*Timer mode*/
		if((timer->MODE==UPCOUNTER) ||(timer->MODE==DOWNCOUNTER))  TIM4->CR1 |= (timer->MODE << 4) ;
		else   TIM4->CR1 |= (timer->MODE << 5) ;
		/*One Pulse mode*/
		TIM4->CR1 |= (timer->ONEPULSE << 3) ;
		/*Timer clock */
		TIM4->PSC =(timer->preScaler-1);
		break;
	case _TIM1:
		/*Auto or preload*/
		TIM1->CR1 |= (timer->LOADING << 7) ;
		/*Timer mode*/
		if((timer->MODE==UPCOUNTER) ||(timer->MODE==DOWNCOUNTER))  TIM1->CR1 |= (timer->MODE << 4) ;
		else   TIM1->CR1 |= (timer->MODE << 5) ;
		/*One Pulse mode*/
		TIM1->CR1 |= (timer->ONEPULSE << 3) ;
		/*Timer clock */
		TIM1->PSC =(timer->preScaler-1);
		break;
	default:;

	}
}

void Timer_voidSetCounter(Timer_ID_type id , u16 count)
{
	switch(id)
		{
		case _TIM2:
			/* Load count */
			TIM2->ARR = count;
			/*Start timer */
			SET_BIT(TIM2->CR1,0);
			break;
		case _TIM3:
			/* Load count */
			TIM3->ARR = count;
			/*Start timer */
			SET_BIT(TIM3->CR1,0);
			break;
		case _TIM4:
			/* Load count */
			TIM4->ARR = count;
			/*Start timer */
			SET_BIT(TIM4->CR1,0);
			break;
		case _TIM1:
			/* Load count */
			TIM1->ARR = count;
			/*Start Counter */
			SET_BIT(TIM1->CR1,0);
			break;
		default:;
		}
}

u16 Timer_u16GetCounts(Timer_ID_type id)
{
	u16 read=0;
	switch(id)
	{
	case _TIM2:
		read= (TIM2->CNT);
		break;
	case _TIM3:
		read= (TIM3->CNT);
		break;
	case _TIM4:
		read= (TIM4->CNT);
		break;
	case _TIM1:
		read= (TIM1->CNT);
		break;
	default:;
	}
	return read ;
}

void  Timer_voidReLoadingNoUVE(Timer_ID_type id  ,u16 count ,u16 prescaler )
{
	/* Disable  */

	switch(id)
		{
		case _TIM1:
			/*  Disable Update Event Wirte only in preload registers   */
			SET_BIT(TIM1->CR1 ,1);
			/*Update Request source only counter overflow or underflow*/
			SET_BIT(TIM1->CR1 ,2);
			/* Load new values*/
			TIM1->ARR = count;
			TIM1->PSC =(prescaler-1);
			/* Enable Update Event generation and Start count from 0 or new loaded value ==> Mode */
			CLR_BIT(TIM1->CR1 ,1);
			SET_BIT(TIM1->EGR,0);
		break;
		case _TIM2:
			/*  Disable Update Event Wirte only in preload registers   */
			SET_BIT(TIM2->CR1 ,1);
			/*Update Request source only counter overflow or underflow*/
			SET_BIT(TIM2->CR1 ,2);
			/* Load new values*/
			TIM2->ARR = count;
			TIM2->PSC =(prescaler-1);
			/* Enable Update Event generation and Start count from 0 or new loaded value ==> Mode */
			CLR_BIT(TIM2->CR1 ,1);
			SET_BIT(TIM2->EGR,0);
		break;
		case _TIM3:
			/*  Disable Update Event Wirte only in preload registers   */
			SET_BIT(TIM3->CR1 ,1);
			/*Update Request source only counter overflow or underflow*/
			SET_BIT(TIM3->CR1 ,3);
			/* Load new values*/
			TIM3->ARR = count;
			TIM3->PSC =(prescaler-1);
			/* Enable Update Event generation and Start count from 0 or new loaded value ==> Mode */
			CLR_BIT(TIM3->CR1 ,1);
			SET_BIT(TIM3->EGR,0);
		break;
		case _TIM4:
			/*  Disable Update Event Wirte only in preload registers   */
			SET_BIT(TIM4->CR1 ,1);
			/*Update Request source only counter overflow or underflow*/
			SET_BIT(TIM4->CR1 ,2);
			/* Load new values*/
			TIM4->ARR = count;
			TIM4->PSC =(prescaler-1);
			/* Enable Update Event generation and Start count from 0 or new loaded value ==> Mode */
			CLR_BIT(TIM4->CR1 ,1);
			SET_BIT(TIM4->EGR,0);
		break;
		default : ;
		}
}


void timer_voidGPWM(PWM_Config_type * PWM )
{
	u16 autoReload=0 , Compare=0;
	switch(PWM->ID)
	{
	case _TIM1:
		/*Update Request source from UG or Counter overflow/underflow*/
		CLR_BIT(TIM1->CR1 ,2);
		/* PWM type  Edge align or center align */
		if(PWM->PWMtype == EDGE_ALIGN)	 TIM1->CR1 |= (PWM->PWMtype << 4) ;
		else 							 TIM1->CR1 |= (PWM->PWMtype << 5) ;
		/*Check on Channel wanted to output the PWM*/
		if(PWM->chaannel==TIM_CHANNEL1)
		{
			/*Channel is configuerd as output */
			CLR_BIT(TIM1->CCMR1,0);
			CLR_BIT(TIM1->CCMR1,1);
			/*  PWM Mode Start High or LOW Then Toggle at  compare Event mode1 or mode 2 toggel at overflow or under flow event*/
			TIM1->CCMR1 |= (PWM->PWMmode<<4);
			/*Enable preload of CCR1 To get valid behavior when writing on this register */
			SET_BIT(TIM1->CCMR1,3);
			/*Enable Auto Reload Register AAR*/
			SET_BIT(TIM1->CR1,7);
			/*Adjust Fequency and Duty cycle of the PWM Signal */

			/*Evaluate Frequancy in Auto Reload Register :
			 *
			 * PeriodicTime of Output Signal = (Auto Reload ARR * TickTime)
			 * PWM frequency  = 1 / PeriodicTime
			 * Then  ARR = 1 / PWM frequency * TickTime of the counter
			 *
			 * note: the higher the ticktime the lower frequancy you can get .
			 */
			autoReload= 1000000/(u32)(PWM->Freq)*(PWM->TickTime);
			TIM1->ARR=(u16)autoReload;

			/*Evaluate Duty Cycle in CCR Register  (mode1) :
			 *
			 * PWM output DutyCycle = ( CCR / ARR  ) * 100 // (Ton/Ttotal) *100
			 * Then CCR = (DutyCycle  *  ARR ) /100
			 *
			 * Evaluate Duty Cycle in CCR Register  (mode2) :
			 * PWM output DutyCycle = ( (ARR-CCR) / ARR  ) * 100  // Ton/Ttotal or   Ttotal-Toff/Ttotal  *100
			 * Then CCR =  ARR - ( (DutyCycle  *  ARR ) /100)
			 *
			 *
			 */
			if(PWM->PWMmode==MODE1_START_HIGH)
			{
				 Compare = (u32)((PWM->duty) * autoReload)/100 ;
				 TIM1->CCR1 = Compare ;
			}
			else
			{
				 Compare = autoReload-(((u32)(PWM->duty)* autoReload)/100) ;
				 TIM1->CCR1 = Compare ;
			}


			/* Enable Update Event generation and Start count from 0 or new loaded value ==> Mode */
			SET_BIT(TIM1->EGR,0);
			/* Chose polarity of enabling Channel as active High , Enable output Channel  */
			CLR_BIT(TIM1->CCER,1);
			SET_BIT(TIM1->CCER,0);
			/*Start Counter*/
			SET_BIT(TIM1->CR1,0);
		}

	  else if(PWM->chaannel==TIM_CHANNEL2)
		{
			/*Channel is configuerd as output */
			 CLR_BIT(TIM1->CCMR1,8);
			 CLR_BIT(TIM1->CCMR1,9);
			/*  PWM Mode Start High or LOW Then Toggle at  compare Event mode1 or mode 2 toggel at overflow or under flow event*/
			TIM1->CCMR1 |= (PWM->PWMmode<<12);
			/*Enable preload of CCR1 To get valid behavior when writing on this register */
			SET_BIT(TIM1->CCMR1,11);
			/*Enable Auto Reload Register AAR*/
			SET_BIT(TIM1->CR1,7);
			/*Adjust Fequency and Duty cycle of the PWM Signal */

			/*Evaluate Frequancy in Auto Reload Register :
			 *
			 * PeriodicTime of Output Signal = (Auto Reload ARR * TickTime)
			 * PWM frequency  = 1 / PeriodicTime
			 * Then  ARR = 1 / PWM frequency * TickTime of the counter
			 *
			 * note: the higher the ticktime the lower frequancy you can get .
			 */
			autoReload=  1000000/((PWM->Freq)*(PWM->TickTime));
			TIM1->ARR=autoReload;

			/*Evaluate Duty Cycle in CCR Register  (mode1) :
			 *
			 * PWM output DutyCycle = ( CCR / ARR  ) * 100 // (Ton/Ttotal) *100
			 * Then CCR = (DutyCycle  *  ARR ) /100
			 *
			 * Evaluate Duty Cycle in CCR Register  (mode2) :
			 * PWM output DutyCycle = ( (ARR-CRR) / ARR  ) * 100  // Ton/Ttotal or   Ttotal-Toff/Ttotal  *100
			 * Then CCR =  ARR - ( (DutyCycle  *  ARR ) /100)
			 *
			 *
			 */
			if(PWM->PWMmode==MODE1_START_HIGH)
			{
				 Compare = (u32)((PWM->duty) * autoReload)/100 ;
				 TIM1->CCR2 = Compare ;
			}
			else
			{
				 Compare = autoReload-(((u32)(PWM->duty) * autoReload)/100) ;
				 TIM1->CCR2 = Compare ;
			}


			/* Enable Update Event generation and Start count from 0 or new loaded value ==> Mode */
			SET_BIT(TIM1->EGR,0);
			/* Chose polarity of enabling Channel as active High , Enable output Channel  */
			CLR_BIT(TIM1->CCER,5);
			SET_BIT(TIM1->CCER,4);
			/*Start Counter*/
			SET_BIT(TIM1->CR1,0);
		}

	  else if(PWM->chaannel==TIM_CHANNEL3)
		{
			/*Channel is configuerd as output */
			CLR_BIT(TIM1->CCMR2,0);
			CLR_BIT(TIM1->CCMR2,1);
			/*  PWM Mode Start High or LOW Then Toggle at  compare Event mode1 or mode 2 toggel at overflow or under flow event*/
			TIM1->CCMR2 |= (PWM->PWMmode<<4);
			/*Enable preload of CCR1 To get valid behavior when writing on this register */
			SET_BIT(TIM1->CCMR2,3);
			/*Enable Auto Reload Register AAR*/
			SET_BIT(TIM1->CR1,7);
			/*Adjust Fequency and Duty cycle of the PWM Signal */

			/*Evaluate Frequancy in Auto Reload Register :
			 *
			 * PeriodicTime of Output Signal = (Auto Reload ARR * TickTime)
			 * PWM frequency  = 1 / PeriodicTime
			 * Then  ARR = 1 / PWM frequency * TickTime of the counter
			 *
			 * note: the higher the ticktime the lower frequancy you can get .
			 */
			autoReload=  1000000/((PWM->Freq)*(PWM->TickTime));
			TIM1->ARR=autoReload;

			/*Evaluate Duty Cycle in CCR Register  (mode1) :
			 *
			 * PWM output DutyCycle = ( CCR / ARR  ) * 100 // (Ton/Ttotal) *100
			 * Then CCR = (DutyCycle  *  ARR ) /100
			 *
			 * Evaluate Duty Cycle in CCR Register  (mode2) :
			 * PWM output DutyCycle = ( (ARR-CCR) / ARR  ) * 100  // Ton/Ttotal or   Ttotal-Toff/Ttotal  *100
			 * Then CCR =  ARR - ( (DutyCycle  *  ARR ) /100)
			 *
			 *
			 */
			if(PWM->PWMmode==MODE1_START_HIGH)
			{
				 Compare = (u32)((PWM->duty) * autoReload)/100 ;
				 TIM1->CCR3 = Compare ;
			}
			else
			{
				 Compare = autoReload-(((u32)(PWM->duty) * autoReload)/100) ;
				 TIM1->CCR3 = Compare ;
			}


			/* Enable Update Event generation and Start count from 0 or new loaded value ==> Mode */
			CLR_BIT(TIM1->CR1 ,1);
			SET_BIT(TIM1->EGR,0);
			/* Chose polarity of enabling Channel as active High , Enable output Channel  */
			CLR_BIT(TIM1->CCER,9);
			SET_BIT(TIM1->CCER,8);
			/*Start Counter*/
			SET_BIT(TIM1->CR1,0);
		}

	  else if(PWM->chaannel==TIM_CHANNEL4)
		{
			/*Channel is configuerd as output */
			 CLR_BIT(TIM1->CCMR2,8);
			 CLR_BIT(TIM1->CCMR2,9);
			/*  PWM Mode Start High or LOW Then Toggle at  compare Event mode1 or mode 2 toggel at overflow or under flow event*/
			TIM1->CCMR2 |= (PWM->PWMmode<<12);
			/*Enable preload of CCR1 To get valid behavior when writing on this register */
			SET_BIT(TIM1->CCMR2,11);
			/*Enable Auto Reload Register AAR*/
			SET_BIT(TIM1->CR1,7);
			/*Adjust Fequency and Duty cycle of the PWM Signal */

			/*Evaluate Frequancy in Auto Reload Register :
			 *
			 * PeriodicTime of Output Signal = (Auto Reload ARR * TickTime)
			 * PWM frequency  = 1 / PeriodicTime
			 * Then  ARR = 1 / PWM frequency * TickTime of the counter
			 *
			 * note: the higher the ticktime the lower frequancy you can get .
			 */
			autoReload=  1000000/((PWM->Freq)*(PWM->TickTime));
			TIM1->ARR=autoReload;

			/*Evaluate Duty Cycle in CCR Register  (mode1) :
			 *
			 * PWM output DutyCycle = ( CCR / ARR  ) * 100 // (Ton/Ttotal) *100
			 * Then CCR = (DutyCycle  *  ARR ) /100
			 *
			 * Evaluate Duty Cycle in CCR Register  (mode2) :
			 * PWM output DutyCycle = ( (ARR-CRR) / ARR  ) * 100  // Ton/Ttotal or   Ttotal-Toff/Ttotal  *100
			 * Then CCR =  ARR - ( (DutyCycle  *  ARR ) /100)
			 *
			 *
			 */
			if(PWM->PWMmode==MODE1_START_HIGH)
			{
				 Compare = (u32)((PWM->duty) * autoReload)/100 ;
				 TIM1->CCR4 = Compare ;
			}
			else
			{
				 Compare = autoReload-(((u32)(PWM->duty) * autoReload)/100) ;
				 TIM1->CCR4 = Compare ;
			}


			/* Enable Update Event generation and Start count from 0 or new loaded value ==> Mode */
			SET_BIT(TIM1->EGR,0);
			/* Chose polarity of enabling Channel as active High , Enable output Channel  */
			CLR_BIT(TIM1->CCER,13);
			SET_BIT(TIM1->CCER,12);
			/*Start Counter*/
			SET_BIT(TIM1->CR1,0);
		}

		break;
	case _TIM2:

		/*Update Request source from UG or Counter overflow/underflow*/
		CLR_BIT(TIM2->CR1 ,2);
		/* PWM type  Edge align or center align */
		if(PWM->PWMtype == EDGE_ALIGN)	 TIM2->CR1 |= (PWM->PWMtype << 4) ;
		else 							 TIM2->CR1 |= (PWM->PWMtype << 5) ;
		/*Check on Channel wanted to output the PWM*/
		if(PWM->chaannel==TIM_CHANNEL1)
		{
			/*Channel is configuerd as output */
			CLR_BIT(TIM2->CCMR1,0);
			CLR_BIT(TIM2->CCMR1,1);
			/*  PWM Mode Start High or LOW Then Toggle at  compare Event mode1 or mode 2 toggel at overflow or under flow event*/
			TIM2->CCMR1 |= (PWM->PWMmode<<4);
			/*Enable preload of CCR1 To get valid behavior when writing on this register */
			SET_BIT(TIM2->CCMR1,3);
			/*Enable Auto Reload Register AAR*/
			SET_BIT(TIM2->CR1,7);
			/*Adjust Fequency and Duty cycle of the PWM Signal */

			/*Evaluate Frequancy in Auto Reload Register :
			 *
			 * PeriodicTime of Output Signal = (Auto Reload ARR * TickTime)
			 * PWM frequency  = 1 / PeriodicTime
			 * Then  ARR = 1 / PWM frequency * TickTime of the counter
			 *
			 * note: the higher the ticktime the lower frequancy you can get .
			 */
			autoReload=  1000000/((PWM->Freq)*(PWM->TickTime));
			TIM2->ARR=autoReload;

			/*Evaluate Duty Cycle in CCR Register  (mode1) :
			 *
			 * PWM output DutyCycle = ( CCR / ARR  ) * 100 // (Ton/Ttotal) *100
			 * Then CCR = (DutyCycle  *  ARR ) /100
			 *
			 * Evaluate Duty Cycle in CCR Register  (mode2) :
			 * PWM output DutyCycle = ( (ARR-CCR) / ARR  ) * 100  // Ton/Ttotal or   Ttotal-Toff/Ttotal  *100
			 * Then CCR =  ARR - ( (DutyCycle  *  ARR ) /100)
			 *
			 *
			 */
			if(PWM->PWMmode==MODE1_START_HIGH)
			{
				Compare = ((PWM->duty) * autoReload)/100 ;
				 TIM2->CCR1 = Compare ;
			}
			else
			{
				 Compare = autoReload-(((u32)(PWM->duty) * autoReload)/100) ;
				 TIM2->CCR1 = Compare ;
			}


			/* Enable Update Event generation and Start count from 0 or new loaded value ==> Mode */
			SET_BIT(TIM2->EGR,0);
			/* Chose polarity of enabling Channel as active High , Enable output Channel  */
			CLR_BIT(TIM2->CCER,1);
			SET_BIT(TIM2->CCER,0);
			/*Start Counter*/
			SET_BIT(TIM2->CR1,0);
		}

	  else if(PWM->chaannel==TIM_CHANNEL2)
		{
			/*Channel is configuerd as output */
			 CLR_BIT(TIM2->CCMR1,8);
			 CLR_BIT(TIM2->CCMR1,9);
			/*  PWM Mode Start High or LOW Then Toggle at  compare Event mode1 or mode 2 toggel at overflow or under flow event*/
			TIM2->CCMR1 |= (PWM->PWMmode<<12);
			/*Enable preload of CCR1 To get valid behavior when writing on this register */
			SET_BIT(TIM2->CCMR1,11);
			/*Enable Auto Reload Register AAR*/
			SET_BIT(TIM2->CR1,7);
			/*Adjust Fequency and Duty cycle of the PWM Signal */

			/*Evaluate Frequancy in Auto Reload Register :
			 *
			 * PeriodicTime of Output Signal = (Auto Reload ARR * TickTime)
			 * PWM frequency  = 1 / PeriodicTime
			 * Then  ARR = 1 / PWM frequency * TickTime of the counter
			 *
			 * note: the higher the ticktime the lower frequancy you can get .
			 */
			autoReload=  1000000/((PWM->Freq)*(PWM->TickTime));
			TIM2->ARR=autoReload;

			/*Evaluate Duty Cycle in CCR Register  (mode1) :
			 *
			 * PWM output DutyCycle = ( CCR / ARR  ) * 100 // (Ton/Ttotal) *100
			 * Then CCR = (DutyCycle  *  ARR ) /100
			 *
			 * Evaluate Duty Cycle in CCR Register  (mode2) :
			 * PWM output DutyCycle = ( (ARR-CRR) / ARR  ) * 100  // Ton/Ttotal or   Ttotal-Toff/Ttotal  *100
			 * Then CCR =  ARR - ( (DutyCycle  *  ARR ) /100)
			 *
			 *
			 */
			if(PWM->PWMmode==MODE1_START_HIGH)
			{
				 Compare = (u32)((PWM->duty) * autoReload)/100 ;
				 TIM2->CCR2 = Compare ;
			}
			else
			{
				 Compare = autoReload-(((u32)(PWM->duty) * autoReload)/100) ;
				 TIM2->CCR2 = Compare ;
			}


			/* Enable Update Event generation and Start count from 0 or new loaded value ==> Mode */

			SET_BIT(TIM2->EGR,0);
			/* Chose polarity of enabling Channel as active High , Enable output Channel  */
			CLR_BIT(TIM2->CCER,5);
			SET_BIT(TIM2->CCER,4);
			/*Start Counter*/
			SET_BIT(TIM2->CR1,0);
		}
	  else if(PWM->chaannel==TIM_CHANNEL3)
		{
			/*Channel is configuerd as output */
			CLR_BIT(TIM2->CCMR2,0);
			CLR_BIT(TIM2->CCMR2,1);
			/*  PWM Mode Start High or LOW Then Toggle at  compare Event mode1 or mode 2 toggel at overflow or under flow event*/
			TIM2->CCMR2 |= (PWM->PWMmode<<4);
			/*Enable preload of CCR1 To get valid behavior when writing on this register */
			SET_BIT(TIM2->CCMR2,3);
			/*Enable Auto Reload Register AAR*/
			SET_BIT(TIM2->CR1,7);
			/*Adjust Fequency and Duty cycle of the PWM Signal */

			/*Evaluate Frequancy in Auto Reload Register :
			 *
			 * PeriodicTime of Output Signal = (Auto Reload ARR * TickTime)
			 * PWM frequency  = 1 / PeriodicTime
			 * Then  ARR = 1 / PWM frequency * TickTime of the counter
			 *
			 * note: the higher the ticktime the lower frequancy you can get .
			 */
			autoReload=  1000000/((PWM->Freq)*(PWM->TickTime));
			TIM2->ARR=autoReload;

			/*Evaluate Duty Cycle in CCR Register  (mode1) :
			 *
			 * PWM output DutyCycle = ( CCR / ARR  ) * 100 // (Ton/Ttotal) *100
			 * Then CCR = (DutyCycle  *  ARR ) /100
			 *
			 * Evaluate Duty Cycle in CCR Register  (mode2) :
			 * PWM output DutyCycle = ( (ARR-CCR) / ARR  ) * 100  // Ton/Ttotal or   Ttotal-Toff/Ttotal  *100
			 * Then CCR =  ARR - ( (DutyCycle  *  ARR ) /100)
			 *
			 *
			 */
			if(PWM->PWMmode==MODE1_START_HIGH)
			{
				 Compare = (u32)((PWM->duty) * autoReload)/100 ;
				 TIM2->CCR3 = Compare ;
			}
			else
			{
				Compare = autoReload-(((u32)(PWM->duty) * autoReload)/100) ;
				 TIM2->CCR3 = Compare ;
			}


			/* Enable Update Event generation and Start count from 0 or new loaded value ==> Mode */
			SET_BIT(TIM2->EGR,0);
			/* Chose polarity of enabling Channel as active High , Enable output Channel  */
			CLR_BIT(TIM2->CCER,9);
			SET_BIT(TIM2->CCER,8);
			/*Start Counter*/
			SET_BIT(TIM2->CR1,0);
		}

	  else if(PWM->chaannel==TIM_CHANNEL4)
		{
			/*Channel is configuerd as output */
			 CLR_BIT(TIM2->CCMR2,8);
			 CLR_BIT(TIM2->CCMR2,9);
			/*  PWM Mode Start High or LOW Then Toggle at  compare Event mode1 or mode 2 toggel at overflow or under flow event*/
			TIM2->CCMR2 |= (PWM->PWMmode<<12);
			/*Enable preload of CCR1 To get valid behavior when writing on this register */
			SET_BIT(TIM2->CCMR2,11);
			/*Enable Auto Reload Register AAR*/
			SET_BIT(TIM2->CR1,7);
			/*Adjust Fequency and Duty cycle of the PWM Signal */

			/*Evaluate Frequancy in Auto Reload Register :
			 *
			 * PeriodicTime of Output Signal = (Auto Reload ARR * TickTime)
			 * PWM frequency  = 1 / PeriodicTime
			 * Then  ARR = 1 / PWM frequency * TickTime of the counter
			 *
			 * note: the higher the ticktime the lower frequancy you can get .
			 */
			autoReload=  1000000/((PWM->Freq)*(PWM->TickTime));
			TIM2->ARR=autoReload;

			/*Evaluate Duty Cycle in CCR Register  (mode1) :
			 *
			 * PWM output DutyCycle = ( CCR / ARR  ) * 100 // (Ton/Ttotal) *100
			 * Then CCR = (DutyCycle  *  ARR ) /100
			 *
			 * Evaluate Duty Cycle in CCR Register  (mode2) :
			 * PWM output DutyCycle = ( (ARR-CRR) / ARR  ) * 100  // Ton/Ttotal or   Ttotal-Toff/Ttotal  *100
			 * Then CCR =  ARR - ( (DutyCycle  *  ARR ) /100)
			 *
			 *
			 */
			if(PWM->PWMmode==MODE1_START_HIGH)
			{
				 Compare = (u32)((PWM->duty) * autoReload)/100 ;
				 TIM2->CCR4 = Compare ;
			}
			else
			{
				 Compare = autoReload-(((u32)(PWM->duty) * autoReload)/100) ;
				 TIM2->CCR4 = Compare ;
			}


			/* Enable Update Event generation and Start count from 0 or new loaded value ==> Mode */
			SET_BIT(TIM2->EGR,0);
			/* Chose polarity of enabling Channel as active High , Enable output Channel  */
			CLR_BIT(TIM2->CCER,13);
			SET_BIT(TIM2->CCER,12);
			/*Start Counter*/
			SET_BIT(TIM2->CR1,0);
		}

		break;
	case _TIM3:
		/*Update Request source from UG or Counter overflow/underflow*/
		CLR_BIT(TIM3->CR1 ,2);
		/* PWM type  Edge align or center align */
		if(PWM->PWMtype == EDGE_ALIGN)	 TIM3->CR1 |= (PWM->PWMtype << 4) ;
		else 							 TIM3->CR1 |= (PWM->PWMtype << 5) ;
		/*Check on Channel wanted to output the PWM*/
		if(PWM->chaannel==TIM_CHANNEL1)
		{
			/*Channel is configuerd as output */
			CLR_BIT(TIM3->CCMR1,0);
			CLR_BIT(TIM3->CCMR1,1);
			/*  PWM Mode Start High or LOW Then Toggle at  compare Event mode1 or mode 2 toggel at overflow or under flow event*/
			TIM3->CCMR1 |= (PWM->PWMmode<<4);
			/*Enable preload of CCR1 To get valid behavior when writing on this register */
			SET_BIT(TIM3->CCMR1,3);
			/*Enable Auto Reload Register AAR*/
			SET_BIT(TIM3->CR1,7);
			/*Adjust Fequency and Duty cycle of the PWM Signal */

			/*Evaluate Frequancy in Auto Reload Register :
			 *
			 * PeriodicTime of Output Signal = (Auto Reload ARR * TickTime)
			 * PWM frequency  = 1 / PeriodicTime
			 * Then  ARR = 1 / PWM frequency * TickTime of the counter
			 *
			 * note: the higher the ticktime the lower frequancy you can get .
			 */
			autoReload=  1000000/((PWM->Freq)*(PWM->TickTime));
			TIM3->ARR=autoReload;

			/*Evaluate Duty Cycle in CCR Register  (mode1) :
			 *
			 * PWM output DutyCycle = ( CCR / ARR  ) * 100 // (Ton/Ttotal) *100
			 * Then CCR = (DutyCycle  *  ARR ) /100
			 *
			 * Evaluate Duty Cycle in CCR Register  (mode2) :
			 * PWM output DutyCycle = ( (ARR-CCR) / ARR  ) * 100  // Ton/Ttotal or   Ttotal-Toff/Ttotal  *100
			 * Then CCR =  ARR - ( (DutyCycle  *  ARR ) /100)
			 *
			 *
			 */
			if(PWM->PWMmode==MODE1_START_HIGH)
			{
				 Compare = (u32)((PWM->duty) * autoReload)/100 ;
				 TIM3->CCR1 = Compare ;
			}
			else
			{
				 Compare = autoReload-(((u32)(PWM->duty) * autoReload)/100) ;
				 TIM3->CCR1 = Compare ;
			}


			/* Enable Update Event generation and Start count from 0 or new loaded value ==> Mode */
			SET_BIT(TIM3->EGR,0);
			/* Chose polarity of enabling Channel as active High , Enable output Channel  */
			CLR_BIT(TIM3->CCER,1);
			SET_BIT(TIM3->CCER,0);
			/*Start Counter*/
			SET_BIT(TIM3->CR1,0);
		}

	  else if(PWM->chaannel==TIM_CHANNEL2)
		{
			/*Channel is configuerd as output */
			 CLR_BIT(TIM3->CCMR1,8);
			 CLR_BIT(TIM3->CCMR1,9);
			/*  PWM Mode Start High or LOW Then Toggle at  compare Event mode1 or mode 2 toggel at overflow or under flow event*/
			TIM3->CCMR1 |= (PWM->PWMmode<<12);
			/*Enable preload of CCR1 To get valid behavior when writing on this register */
			SET_BIT(TIM3->CCMR1,11);
			/*Enable Auto Reload Register AAR*/
			SET_BIT(TIM3->CR1,7);
			/*Adjust Fequency and Duty cycle of the PWM Signal */

			/*Evaluate Frequancy in Auto Reload Register :
			 *
			 * PeriodicTime of Output Signal = (Auto Reload ARR * TickTime)
			 * PWM frequency  = 1 / PeriodicTime
			 * Then  ARR = 1 / PWM frequency * TickTime of the counter
			 *
			 * note: the higher the ticktime the lower frequancy you can get .
			 */
			autoReload=  1000000/((PWM->Freq)*(PWM->TickTime));
			TIM3->ARR=autoReload;

			/*Evaluate Duty Cycle in CCR Register  (mode1) :
			 *
			 * PWM output DutyCycle = ( CCR / ARR  ) * 100 // (Ton/Ttotal) *100
			 * Then CCR = (DutyCycle  *  ARR ) /100
			 *
			 * Evaluate Duty Cycle in CCR Register  (mode2) :
			 * PWM output DutyCycle = ( (ARR-CRR) / ARR  ) * 100  // Ton/Ttotal or   Ttotal-Toff/Ttotal  *100
			 * Then CCR =  ARR - ( (DutyCycle  *  ARR ) /100)
			 *
			 *
			 */
			if(PWM->PWMmode==MODE1_START_HIGH)
			{
				Compare = (u32)((PWM->duty) * autoReload)/100 ;
				 TIM3->CCR2 = Compare ;
			}
			else
			{
				 Compare = autoReload-(((u32)(PWM->duty) * autoReload)/100) ;
				 TIM3->CCR2 = Compare ;
			}


			/* Enable Update Event generation and Start count from 0 or new loaded value ==> Mode */
			SET_BIT(TIM3->EGR,0);
			/* Chose polarity of enabling Channel as active High , Enable output Channel  */
			CLR_BIT(TIM3->CCER,5);
			SET_BIT(TIM3->CCER,4);
			/*Start Counter*/
			SET_BIT(TIM3->CR1,0);
		}
	  else if(PWM->chaannel==TIM_CHANNEL3)
		{
			/*Channel is configuerd as output */
			CLR_BIT(TIM3->CCMR2,0);
			CLR_BIT(TIM3->CCMR2,1);
			/*  PWM Mode Start High or LOW Then Toggle at  compare Event mode1 or mode 2 toggel at overflow or under flow event*/
			TIM3->CCMR2 |= (PWM->PWMmode<<4);
			/*Enable preload of CCR1 To get valid behavior when writing on this register */
			SET_BIT(TIM3->CCMR2,3);
			/*Enable Auto Reload Register AAR*/
			SET_BIT(TIM3->CR1,7);
			/*Adjust Fequency and Duty cycle of the PWM Signal */

			/*Evaluate Frequancy in Auto Reload Register :
			 *
			 * PeriodicTime of Output Signal = (Auto Reload ARR * TickTime)
			 * PWM frequency  = 1 / PeriodicTime
			 * Then  ARR = 1 / PWM frequency * TickTime of the counter
			 *
			 * note: the higher the ticktime the lower frequancy you can get .
			 */
			autoReload=  1000000/((PWM->Freq)*(PWM->TickTime));
			TIM3->ARR=autoReload;

			/*Evaluate Duty Cycle in CCR Register  (mode1) :
			 *
			 * PWM output DutyCycle = ( CCR / ARR  ) * 100 // (Ton/Ttotal) *100
			 * Then CCR = (DutyCycle  *  ARR ) /100
			 *
			 * Evaluate Duty Cycle in CCR Register  (mode2) :
			 * PWM output DutyCycle = ( (ARR-CCR) / ARR  ) * 100  // Ton/Ttotal or   Ttotal-Toff/Ttotal  *100
			 * Then CCR =  ARR - ( (DutyCycle  *  ARR ) /100)
			 *
			 *
			 */
			if(PWM->PWMmode==MODE1_START_HIGH)
			{
				Compare = (u32)((PWM->duty) * autoReload)/100 ;
				 TIM3->CCR3 = Compare ;
			}
			else
			{
				 Compare = autoReload-(((u32)(PWM->duty) * autoReload)/100) ;
				 TIM3->CCR3 = Compare ;
			}


			/* Enable Update Event generation and Start count from 0 or new loaded value ==> Mode */
			SET_BIT(TIM3->EGR,0);
			/* Chose polarity of enabling Channel as active High , Enable output Channel  */
			CLR_BIT(TIM3->CCER,9);
			SET_BIT(TIM3->CCER,8);
			/*Start Counter*/
			SET_BIT(TIM3->CR1,0);
		}

	  else if(PWM->chaannel==TIM_CHANNEL4)
		{
			/*Channel is configuerd as output */
			 CLR_BIT(TIM3->CCMR2,8);
			 CLR_BIT(TIM3->CCMR2,9);
			/*  PWM Mode Start High or LOW Then Toggle at  compare Event mode1 or mode 2 toggel at overflow or under flow event*/
			TIM3->CCMR2 |= (PWM->PWMmode<<12);
			/*Enable preload of CCR1 To get valid behavior when writing on this register */
			SET_BIT(TIM3->CCMR2,11);
			/*Enable Auto Reload Register AAR*/
			SET_BIT(TIM3->CR1,7);
			/*Adjust Fequency and Duty cycle of the PWM Signal */

			/*Evaluate Frequancy in Auto Reload Register :
			 *
			 * PeriodicTime of Output Signal = (Auto Reload ARR * TickTime)
			 * PWM frequency  = 1 / PeriodicTime
			 * Then  ARR = 1 / PWM frequency * TickTime of the counter
			 *
			 * note: the higher the ticktime the lower frequancy you can get .
			 */
			autoReload=  1000000/((PWM->Freq)*(PWM->TickTime));
			TIM3->ARR=autoReload;

			/*Evaluate Duty Cycle in CCR Register  (mode1) :
			 *
			 * PWM output DutyCycle = ( CCR / ARR  ) * 100 // (Ton/Ttotal) *100
			 * Then CCR = (DutyCycle  *  ARR ) /100
			 *
			 * Evaluate Duty Cycle in CCR Register  (mode2) :
			 * PWM output DutyCycle = ( (ARR-CRR) / ARR  ) * 100  // Ton/Ttotal or   Ttotal-Toff/Ttotal  *100
			 * Then CCR =  ARR - ( (DutyCycle  *  ARR ) /100)
			 *
			 *
			 */
			if(PWM->PWMmode==MODE1_START_HIGH)
			{
				 Compare = (u32)((PWM->duty) * autoReload)/100 ;
				 TIM3->CCR4 = Compare ;
			}
			else
			{
				 Compare = autoReload-(((u32)(PWM->duty) * autoReload)/100) ;
				 TIM3->CCR4 = Compare ;
			}


			/* Enable Update Event generation and Start count from 0 or new loaded value ==> Mode */
			SET_BIT(TIM3->EGR,0);
			/* Chose polarity of enabling Channel as active High , Enable output Channel  */
			CLR_BIT(TIM3->CCER,13);
			SET_BIT(TIM3->CCER,12);
			/*Start Counter*/
			SET_BIT(TIM3->CR1,0);
		}

	case _TIM4:
		/*Update Request source from UG or Counter overflow/underflow*/
		CLR_BIT(TIM4->CR1 ,2);
		/* PWM type  Edge align or center align */
		if(PWM->PWMtype == EDGE_ALIGN)	 TIM4->CR1 |= (PWM->PWMtype << 4) ;
		else 							 TIM4->CR1 |= (PWM->PWMtype << 5) ;
		/*Check on Channel wanted to output the PWM*/
		if(PWM->chaannel==TIM_CHANNEL1)
		{
			/*Channel is configuerd as output */
			CLR_BIT(TIM4->CCMR1,0);
			CLR_BIT(TIM4->CCMR1,1);
			/*  PWM Mode Start High or LOW Then Toggle at  compare Event mode1 or mode 2 toggel at overflow or under flow event*/
			TIM4->CCMR1 |= (PWM->PWMmode<<4);
			/*Enable preload of CCR1 To get valid behavior when writing on this register */
			SET_BIT(TIM4->CCMR1,3);
			/*Enable Auto Reload Register AAR*/
			SET_BIT(TIM4->CR1,7);
			/*Adjust Fequency and Duty cycle of the PWM Signal */

			/*Evaluate Frequancy in Auto Reload Register :
			 *
			 * PeriodicTime of Output Signal = (Auto Reload ARR * TickTime)
			 * PWM frequency  = 1 / PeriodicTime
			 * Then  ARR = 1 / PWM frequency * TickTime of the counter
			 *
			 * note: the higher the ticktime the lower frequancy you can get .
			 */
			autoReload=  1000000/((PWM->Freq)*(PWM->TickTime));
			TIM4->ARR=autoReload;

			/*Evaluate Duty Cycle in CCR Register  (mode1) :
			 *
			 * PWM output DutyCycle = ( CCR / ARR  ) * 100 // (Ton/Ttotal) *100
			 * Then CCR = (DutyCycle  *  ARR ) /100
			 *
			 * Evaluate Duty Cycle in CCR Register  (mode2) :
			 * PWM output DutyCycle = ( (ARR-CCR) / ARR  ) * 100  // Ton/Ttotal or   Ttotal-Toff/Ttotal  *100
			 * Then CCR =  ARR - ( (DutyCycle  *  ARR ) /100)
			 *
			 *
			 */
			if(PWM->PWMmode==MODE1_START_HIGH)
			{
				Compare = (u32)((PWM->duty) * autoReload)/100 ;
				 TIM4->CCR1 = Compare ;
			}
			else
			{
				 Compare = autoReload-(((u32)(PWM->duty) * autoReload)/100) ;
				 TIM4->CCR1 = Compare ;
			}


			/* Enable Update Event generation and Start count from 0 or new loaded value ==> Mode */
			SET_BIT(TIM4->EGR,0);
			/* Chose polarity of enabling Channel as active High , Enable output Channel  */
			CLR_BIT(TIM4->CCER,1);
			SET_BIT(TIM4->CCER,0);
			/*Start Counter*/
			SET_BIT(TIM4->CR1,0);
		}

	  else if(PWM->chaannel==TIM_CHANNEL2)
		{
			/*Channel is configuerd as output */
			 CLR_BIT(TIM4->CCMR1,8);
			 CLR_BIT(TIM4->CCMR1,9);
			/*  PWM Mode Start High or LOW Then Toggle at  compare Event mode1 or mode 2 toggel at overflow or under flow event*/
			TIM4->CCMR1 |= (PWM->PWMmode<<12);
			/*Enable preload of CCR1 To get valid behavior when writing on this register */
			SET_BIT(TIM4->CCMR1,11);
			/*Enable Auto Reload Register AAR*/
			SET_BIT(TIM4->CR1,7);
			/*Adjust Fequency and Duty cycle of the PWM Signal */

			/*Evaluate Frequancy in Auto Reload Register :
			 *
			 * PeriodicTime of Output Signal = (Auto Reload ARR * TickTime)
			 * PWM frequency  = 1 / PeriodicTime
			 * Then  ARR = 1 / PWM frequency * TickTime of the counter
			 *
			 * note: the higher the ticktime the lower frequancy you can get .
			 */
			autoReload=  1000000/((PWM->Freq)*(PWM->TickTime));
			TIM4->ARR=autoReload;

			/*Evaluate Duty Cycle in CCR Register  (mode1) :
			 *
			 * PWM output DutyCycle = ( CCR / ARR  ) * 100 // (Ton/Ttotal) *100
			 * Then CCR = (DutyCycle  *  ARR ) /100
			 *
			 * Evaluate Duty Cycle in CCR Register  (mode2) :
			 * PWM output DutyCycle = ( (ARR-CRR) / ARR  ) * 100  // Ton/Ttotal or   Ttotal-Toff/Ttotal  *100
			 * Then CCR =  ARR - ( (DutyCycle  *  ARR ) /100)
			 *
			 *
			 */
			if(PWM->PWMmode==MODE1_START_HIGH)
			{
				 Compare = (u32)((PWM->duty) * autoReload)/100 ;
				 TIM4->CCR2 = Compare ;
			}
			else
			{
				 Compare = autoReload-(((u32)(PWM->duty) * autoReload)/100) ;
				 TIM4->CCR2 = Compare ;
			}


			/* Enable Update Event generation and Start count from 0 or new loaded value ==> Mode */
			SET_BIT(TIM4->EGR,0);
			/* Chose polarity of enabling Channel as active High , Enable output Channel  */
			CLR_BIT(TIM4->CCER,5);
			SET_BIT(TIM4->CCER,4);
			/*Start Counter*/
			SET_BIT(TIM4->CR1,0);
		}
	  else if(PWM->chaannel==TIM_CHANNEL3)
		{
			/*Channel is configuerd as output */
			CLR_BIT(TIM4->CCMR2,0);
			CLR_BIT(TIM4->CCMR2,1);
			/*  PWM Mode Start High or LOW Then Toggle at  compare Event mode1 or mode 2 toggel at overflow or under flow event*/
			TIM4->CCMR2 |= (PWM->PWMmode<<4);
			/*Enable preload of CCR1 To get valid behavior when writing on this register */
			SET_BIT(TIM4->CCMR2,3);
			/*Enable Auto Reload Register AAR*/
			SET_BIT(TIM4->CR1,7);
			/*Adjust Fequency and Duty cycle of the PWM Signal */

			/*Evaluate Frequancy in Auto Reload Register :
			 *
			 * PeriodicTime of Output Signal = (Auto Reload ARR * TickTime)
			 * PWM frequency  = 1 / PeriodicTime
			 * Then  ARR = 1 / PWM frequency * TickTime of the counter
			 *
			 * note: the higher the ticktime the lower frequancy you can get .
			 */
			autoReload=  1000000/((PWM->Freq)*(PWM->TickTime));
			TIM4->ARR=autoReload;

			/*Evaluate Duty Cycle in CCR Register  (mode1) :
			 *
			 * PWM output DutyCycle = ( CCR / ARR  ) * 100 // (Ton/Ttotal) *100
			 * Then CCR = (DutyCycle  *  ARR ) /100
			 *
			 * Evaluate Duty Cycle in CCR Register  (mode2) :
			 * PWM output DutyCycle = ( (ARR-CCR) / ARR  ) * 100  // Ton/Ttotal or   Ttotal-Toff/Ttotal  *100
			 * Then CCR =  ARR - ( (DutyCycle  *  ARR ) /100)
			 *
			 *
			 */
			if(PWM->PWMmode==MODE1_START_HIGH)
			{
				 Compare = (u32)((PWM->duty) * autoReload)/100 ;
				 TIM4->CCR3 = Compare ;
			}
			else
			{
				 Compare = autoReload-(((u32)(PWM->duty) * autoReload)/100) ;
				 TIM4->CCR3 = Compare ;
			}


			/* Enable Update Event generation and Start count from 0 or new loaded value ==> Mode */
			SET_BIT(TIM4->EGR,0);
			/* Chose polarity of enabling Channel as active High , Enable output Channel  */
			CLR_BIT(TIM4->CCER,9);
			SET_BIT(TIM4->CCER,8);
			/*Start Counter*/
			SET_BIT(TIM4->CR1,0);
		}

	  else if(PWM->chaannel==TIM_CHANNEL4)
		{
			/*Channel is configuerd as output */
			 CLR_BIT(TIM4->CCMR2,8);
			 CLR_BIT(TIM4->CCMR2,9);
			/*  PWM Mode Start High or LOW Then Toggle at  compare Event mode1 or mode 2 toggel at overflow or under flow event*/
			TIM4->CCMR2 |= (PWM->PWMmode<<12);
			/*Enable preload of CCR1 To get valid behavior when writing on this register */
			SET_BIT(TIM4->CCMR2,11);
			/*Enable Auto Reload Register AAR*/
			SET_BIT(TIM4->CR1,7);
			/*Adjust Fequency and Duty cycle of the PWM Signal */

			/*Evaluate Frequancy in Auto Reload Register :
			 *
			 * PeriodicTime of Output Signal = (Auto Reload ARR * TickTime)
			 * PWM frequency  = 1 / PeriodicTime
			 * Then  ARR = 1 / PWM frequency * TickTime of the counter
			 *
			 * note: the higher the ticktime the lower frequancy you can get .
			 */
			autoReload=  1000000/((PWM->Freq)*(PWM->TickTime));
			TIM4->ARR=autoReload;

			/*Evaluate Duty Cycle in CCR Register  (mode1) :
			 *
			 * PWM output DutyCycle = ( CCR / ARR  ) * 100 // (Ton/Ttotal) *100
			 * Then CCR = (DutyCycle  *  ARR ) /100
			 *
			 * Evaluate Duty Cycle in CCR Register  (mode2) :
			 * PWM output DutyCycle = ( (ARR-CRR) / ARR  ) * 100  // Ton/Ttotal or   Ttotal-Toff/Ttotal  *100
			 * Then CCR =  ARR - ( (DutyCycle  *  ARR ) /100)
			 *
			 *
			 */
			if(PWM->PWMmode==MODE1_START_HIGH)
			{
				Compare = (u32)((PWM->duty) * autoReload)/100 ;
				 TIM4->CCR4 = Compare ;
			}
			else
			{
				 Compare = autoReload-(((u32)(PWM->duty) * autoReload)/100) ;
				 TIM4->CCR4 = Compare ;
			}


			/* Enable Update Event generation and Start count from 0 or new loaded value ==> Mode */
			SET_BIT(TIM4->EGR,0);
			/* Chose polarity of enabling Channel as active High , Enable output Channel  */
			CLR_BIT(TIM4->CCER,13);
			SET_BIT(TIM4->CCER,12);
			/*Start Counter*/
			SET_BIT(TIM4->CR1,0);
		}

		break;
	default:;
	}

}







void Timer_voidEventGenerate(Timer_ID_type id ,  GenerateEvents_ID event)
{
	switch(id)
		{
		case _TIM1:     SET_BIT(TIM1->EGR,event);   break;
		case _TIM2:     SET_BIT(TIM2->EGR,event);   break;
		case _TIM3:     SET_BIT(TIM3->EGR,event);   break;
		case _TIM4:     SET_BIT(TIM4->EGR,event);   break;
		default:;
		}

}

void Timer_SetCallBack(Timer_ID_type id ,void(*pf)(void))
{
	switch(id)
	{
	case _TIM1:
		TIM_pfCallBack[_TIM1] = pf ;
		break;
	case _TIM2:
		TIM_pfCallBack[_TIM2] = pf ;
		break;
	case _TIM3:
		TIM_pfCallBack[_TIM3] = pf ;
		break;
	case _TIM4:
		TIM_pfCallBack[_TIM4] = pf ;
		break;
	default :;

	}

}

void Timer_InterruptEnable(Timer_ID_type id  , Interrupt_ID  interrupt)
{
	switch(id)
		{
		case _TIM1:   SET_BIT(TIM1->DIER,interrupt); 	break;
		case _TIM2:   SET_BIT(TIM2->DIER,interrupt); 	break;
		case _TIM3:   SET_BIT(TIM3->DIER,interrupt); 	break;
		case _TIM4:   SET_BIT(TIM4->DIER,interrupt); 	break;
		default:;
		}

}
void Timer_InterruptDisable(Timer_ID_type id  , Interrupt_ID  interrupt)
{
	switch(id)
		{
		case _TIM1:   CLR_BIT(TIM1->DIER,interrupt); 	break;
		case _TIM2:   CLR_BIT(TIM2->DIER,interrupt); 	break;
		case _TIM3:   CLR_BIT(TIM3->DIER,interrupt); 	break;
		case _TIM4:   CLR_BIT(TIM4->DIER,interrupt); 	break;
		default:;
		}
}
/**************************************IRQ****************************************/
void TIM1_BRK_IRQHandler(void)
{
	/*   Clear PIF to ReEnter IRQ   */
	TIM_pfCallBack[_TIM1]();
}

void TIM1_UP_IRQHandler(void)
{
	 CLR_BIT(TIM1->SR,0);
	TIM_pfCallBack[_TIM1]();
}
 void TIM1_TRG_COM_IRQHandler(void)
 {
	 CLR_BIT(TIM1->SR,6);
	 TIM_pfCallBack[_TIM1]();
 }

 void TIM1_CC_IRQHandler(void)
 {
	 if(GET_BIT(TIM1->SR,1))
		 {
			 /* CC1IF */
			 CLR_BIT(TIM1->SR,1);
		 }
		 if(GET_BIT(TIM1->SR,2))
		 {
			 /* CC2IF */
			 CLR_BIT(TIM1->SR,2);

		 }
		 if(GET_BIT(TIM1->SR,3))
		 {
			 /* CC3IF */
			 CLR_BIT(TIM1->SR,3);

		 }
		 if(GET_BIT(TIM1->SR,4))
		 {
			 /* CC4IF */
			 CLR_BIT(TIM1->SR,4);

		 }
		  if(GET_BIT(TIM1->SR,9))
			  {
			 	 /*DMA*/
			 	 CLR_BIT(TIM1->SR,9);

			  }
			  if(GET_BIT(TIM1->SR,10))
			  {
			 	 CLR_BIT(TIM1->SR,10);
			  }
			  if(GET_BIT(TIM1->SR,11))
			  {
			 	 CLR_BIT(TIM1->SR,11);
			  }
			  if(GET_BIT(TIM1->SR,12))
			  {
			 	 CLR_BIT(TIM1->SR,12);
			  }
	 TIM_pfCallBack[_TIM1]();
 }

 void TIM2_IRQHandler(void)
 {
	 if(GET_BIT(TIM2->SR,0))
	 		 {
	 	 /* Update interrupt flag */
	 	 CLR_BIT(TIM2->SR,0);
	  }
	  if(GET_BIT(TIM2->SR,1))
	  {
	 	 /* CC1IF */
	 	 CLR_BIT(TIM2->SR,1);
	  }
	  if(GET_BIT(TIM2->SR,2))
	  {
	 	 /* CC2IF */
	 	 CLR_BIT(TIM2->SR,2);

	  }
	  if(GET_BIT(TIM2->SR,3))
	  {
	 	 /* CC3IF */
	 	 CLR_BIT(TIM2->SR,3);

	  }
	  if(GET_BIT(TIM2->SR,4))
	  {
	 	 /* CC4IF */
	 	 CLR_BIT(TIM2->SR,4);

	  }
	  if(GET_BIT(TIM2->SR,6))
	  {
	 	 /* TIF */
	 	 CLR_BIT(TIM2->SR,6);
	  }
	  if(GET_BIT(TIM2->SR,9))
	  {
	 	 /*DMA*/
	 	 CLR_BIT(TIM2->SR,9);

	  }
	  if(GET_BIT(TIM2->SR,10))
	  {
	 	 CLR_BIT(TIM2->SR,10);
	  }
	  if(GET_BIT(TIM2->SR,11))
	  {
	 	 CLR_BIT(TIM2->SR,11);
	  }
	  if(GET_BIT(TIM2->SR,12))
	  {
	 	 CLR_BIT(TIM2->SR,12);
	  }
	 TIM_pfCallBack[_TIM2]();
 }


 void TIM3_IRQHandler(void)
 {
	if(GET_BIT(TIM3->SR,0))
		 {
			 /* Update interrupt flag */
			 CLR_BIT(TIM3->SR,0);
		 }
		 if(GET_BIT(TIM3->SR,1))
		 {
			 /* CC1IF */
			 CLR_BIT(TIM3->SR,1);
		 }
		 if(GET_BIT(TIM3->SR,2))
		 {
			 /* CC2IF */
			 CLR_BIT(TIM3->SR,2);

		 }
		 if(GET_BIT(TIM3->SR,3))
		 {
			 /* CC3IF */
			 CLR_BIT(TIM3->SR,3);

		 }
		 if(GET_BIT(TIM3->SR,4))
		 {
			 /* CC4IF */
			 CLR_BIT(TIM3->SR,4);

		 }
		 if(GET_BIT(TIM3->SR,6))
		 {
			 /* TIF */
			 CLR_BIT(TIM3->SR,6);
		 }
		 if(GET_BIT(TIM3->SR,9))
		 {
			 /*DMA*/
			 CLR_BIT(TIM3->SR,9);

		 }
		 if(GET_BIT(TIM3->SR,10))
		 {
			 CLR_BIT(TIM3->SR,10);
		 }
		 if(GET_BIT(TIM3->SR,11))
		 {
			 CLR_BIT(TIM3->SR,11);
		 }
		 if(GET_BIT(TIM3->SR,12))
		 {
			 CLR_BIT(TIM3->SR,12);
		 }
	 TIM_pfCallBack[_TIM3]();
 }

 void TIM4_IRQHandler(void)
 {
	 if(GET_BIT(TIM4->SR,0))
	 {
		 /* Update interrupt flag */
		 CLR_BIT(TIM4->SR,0);
	 }
	 if(GET_BIT(TIM4->SR,1))
	 {
		 /* CC1IF */
		 CLR_BIT(TIM4->SR,1);
	 }
	 if(GET_BIT(TIM4->SR,2))
	 {
		 /* CC2IF */
		 CLR_BIT(TIM4->SR,2);

	 }
	 if(GET_BIT(TIM4->SR,3))
	 {
		 /* CC3IF */
		 CLR_BIT(TIM4->SR,3);

	 }
	 if(GET_BIT(TIM4->SR,4))
	 {
		 /* CC4IF */
		 CLR_BIT(TIM4->SR,4);

	 }
	 if(GET_BIT(TIM4->SR,6))
	 {
		 /* TIF */
		 CLR_BIT(TIM4->SR,6);
	 }
	 if(GET_BIT(TIM4->SR,9))
	 {
		 /*DMA*/
		 CLR_BIT(TIM4->SR,9);

	 }
	 if(GET_BIT(TIM4->SR,10))
	 {
		 CLR_BIT(TIM4->SR,10);
	 }
	 if(GET_BIT(TIM4->SR,11))
	 {
		 CLR_BIT(TIM4->SR,11);
	 }
	 if(GET_BIT(TIM4->SR,12))
	 {
		 CLR_BIT(TIM4->SR,12);
	 }
	 TIM_pfCallBack[_TIM4]();
 }

