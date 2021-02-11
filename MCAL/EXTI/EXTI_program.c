

#include "StdTypes.h"
#include "Utils.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

#ifndef		NULL
#define 	NULL		(void *)0
#endif

static void (*EXTI_pfCallBack[EXTI_TOTAL_LINES])(void) ={ NULL };


void EXTI_voidInit(void)
{
	/*		Select all Edge Modes for All Lines		*/
#if			EXTI_LINE0 == EXTI_FALLING
			SET_BIT(EXTI -> FTSR , 0);
#elif		EXTI_LINE0 == EXTI_RISING
			SET_BIT(EXTI -> RTSR , 0);
#elif		EXTI_LINE0 == EXTI_IOC
			SET_BIT(EXTI -> RTSR , 0);
			SET_BIT(EXTI -> FTSR , 0);
#else
#error		"Wrong Choice of edge mode for line0 !"
#endif

#if			EXTI_LINE1 == EXTI_FALLING
			SET_BIT(EXTI -> FTSR , 1);
#elif		EXTI_LINE1 == EXTI_RISING
			SET_BIT(EXTI -> RTSR , 1);
#elif		EXTI_LINE1 == EXTI_IOC
			SET_BIT(EXTI -> RTSR , 1);
			SET_BIT(EXTI -> FTSR , 1);
#else
#error		"Wrong Choice of edge mode for line1 !"
#endif

#if			EXTI_LINE2 == EXTI_FALLING
			SET_BIT(EXTI -> FTSR , 2);
#elif		EXTI_LINE2 == EXTI_RISING
			SET_BIT(EXTI -> RTSR , 2);
#elif		EXTI_LINE2 == EXTI_IOC
			SET_BIT(EXTI -> RTSR , 2);
			SET_BIT(EXTI -> FTSR , 2);
#else
#error		"Wrong Choice of edge mode for line2 !"
#endif
	/*		Disable all EXTI lines		 			*/
			EXTI -> IMR = 0;
	/*		Clear All Pending BITs					*/
			EXTI -> PR 	= 0xFFFFFFFF;
}

void EXTI_voidEnableLine(EXTI_LinetNum_type Copy_u8LineNum)
{
	SET_BIT(EXTI -> IMR , Copy_u8LineNum);
}
void EXTI_voidSetSignalLatch(EXTI_LinetNum_type Copy_u8LineNum, EXTI_Edgetype Copy_u8EdgeMode)
{
	if(Copy_u8LineNum < 16)
	{
		/*			Avoid any logic change sensing  mode		*/
		CLR_BIT(EXTI -> FTSR , Copy_u8LineNum );
		CLR_BIT(EXTI -> RTSR , Copy_u8LineNum );
		switch(Copy_u8EdgeMode)
		{
			case EXTI_RISING 	: 	SET_BIT(EXTI -> RTSR , Copy_u8LineNum ); 	break;
			case EXTI_FALLING 	:	SET_BIT(EXTI -> FTSR , Copy_u8LineNum ); 	break;
			case EXTI_IOC 		: 	SET_BIT(EXTI -> RTSR , Copy_u8LineNum );
									SET_BIT(EXTI -> FTSR , Copy_u8LineNum );	break;
		}
	}
}
void EXTI_voidDisableLine(EXTI_LinetNum_type Copy_u8LineNum )
{
	CLR_BIT(EXTI -> IMR , Copy_u8LineNum);
}
void EXTI_voidSetCallBack(EXTI_LinetNum_type Copy_u8LineNum, void (*pf) (void))
{
	if(pf != NULL)
	{
		EXTI_pfCallBack[Copy_u8LineNum]=pf;
	}
}

void EXTI_voidSetSoftwareTrigger(EXTI_LinetNum_type Copy_u8LineNum )
{
	/*		Task								*/
}

/*******************************External Interrupt ISR*****************************************/
void EXTI0_IRQHandler(void)
{
	if(NULL!=EXTI_pfCallBack[EXTI_L0])
	{
		EXTI_pfCallBack[EXTI_L0]();
		/*  Clear Pending flag of this ISR  */
		SET_BIT(EXTI->PR,EXTI_L0);
	}
}
void EXTI1_IRQHandler(void)
{
	if(NULL!=EXTI_pfCallBack[EXTI_L1])
	{
		EXTI_pfCallBack[EXTI_L1]();
		/*  Clear Pending flag of this ISR  */
		SET_BIT(EXTI->PR,EXTI_L1);
	}
}
void EXTI2_IRQHandler(void)
{
	if(NULL!=EXTI_pfCallBack[EXTI_L2])
	{
		EXTI_pfCallBack[EXTI_L2]();
		/*  Clear Pending flag of this ISR  */
		SET_BIT(EXTI->PR,EXTI_L2);
	}
}
void EXTI3_IRQHandler(void)
{
	if(NULL!=EXTI_pfCallBack[EXTI_L3])
	{
		EXTI_pfCallBack[EXTI_L3]();
		/*  Clear Pending flag of this ISR  */
		SET_BIT(EXTI->PR,EXTI_L3);
	}
}
void EXTI4_IRQHandler(void)
{
	if(NULL!=EXTI_pfCallBack[EXTI_L4])
	{
		EXTI_pfCallBack[EXTI_L4]();
		/*  Clear Pending flag of this ISR  */
		SET_BIT(EXTI->PR,EXTI_L4);
	}
}
void EXTI9_5_IRQHandler(void)
{

	if(GET_BIT(EXTI-> PR,EXTI_L5))
	{
		EXTI_pfCallBack[EXTI_L5]();
		/*  Clear Pending flag of this ISR  */
		SET_BIT(EXTI->PR,EXTI_L5);
	}
	if(GET_BIT(EXTI-> PR,EXTI_L6))
	{
		EXTI_pfCallBack[EXTI_L6]();
		/*  Clear Pending flag of this ISR  */
		SET_BIT(EXTI->PR,EXTI_L6);
	}
	if(GET_BIT(EXTI-> PR,EXTI_L7))
	{
		EXTI_pfCallBack[EXTI_L7]();
		/*  Clear Pending flag of this ISR  */
		SET_BIT(EXTI->PR,EXTI_L7);
	}
	if(GET_BIT(EXTI-> PR,EXTI_L8))
	{
		EXTI_pfCallBack[EXTI_L8]();
		/*  Clear Pending flag of this ISR  */
		SET_BIT(EXTI->PR,EXTI_L8);
	}
	if(GET_BIT(EXTI-> PR,EXTI_L9))
	{
		EXTI_pfCallBack[EXTI_L9]();
		/*  Clear Pending flag of this ISR  */
		SET_BIT(EXTI->PR,EXTI_L9);
	}

}
void EXTI15_10_IRQHandler(void)
{
	if(GET_BIT(EXTI-> PR,EXTI_L10))
	{
		EXTI_pfCallBack[EXTI_L10]();
		/*  Clear Pending flag of this ISR  */
		SET_BIT(EXTI->PR,EXTI_L10);
	}
	if(GET_BIT(EXTI-> PR,EXTI_L11))
	{
		EXTI_pfCallBack[EXTI_L11]();
		/*  Clear Pending flag of this ISR  */
		SET_BIT(EXTI->PR,EXTI_L11);
	}
	if(GET_BIT(EXTI-> PR,EXTI_L12))
	{
		EXTI_pfCallBack[EXTI_L12]();
		/*  Clear Pending flag of this ISR  */
		SET_BIT(EXTI->PR,EXTI_L12);
	}
	if(GET_BIT(EXTI-> PR,EXTI_L13))
	{
		EXTI_pfCallBack[EXTI_L13]();
		/*  Clear Pending flag of this ISR  */
		SET_BIT(EXTI->PR,EXTI_L13);
	}
	if(GET_BIT(EXTI-> PR,EXTI_L14))
	{
		EXTI_pfCallBack[EXTI_L14]();
		/*  Clear Pending flag of this ISR  */
		SET_BIT(EXTI->PR,EXTI_L14);
	}
	if(GET_BIT(EXTI-> PR,EXTI_L15))
	{
		EXTI_pfCallBack[EXTI_L15]();
		/*  Clear Pending flag of this ISR  */
		SET_BIT(EXTI->PR,EXTI_L15);
	}
}






