
#include "StdTypes.h" /*Must be above other includes 34an used fehom*/
#include "Utils.h"

#include "RCC_Interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


void RCC_voidInit(void)
{
	u32 Local_u32TimeOut= 0 ;
	#if			CLOCK_TYPE == RCC_HSI
		/*			HSI ON			*/
			SET_BIT(RCC_CR,0);
		/*		HSI is Ready ?	//POLLING	*/
			while(!GET_BIT(RCC_CR,1) && Local_u32TimeOut !=10000)
			{
				Local_u32TimeOut++;
			}
	#elif		CLOCK_TYPE == RCC_HSE
		/*	System Clock Switch		*/
			SET_BIT(RCC_CFGR,0);
			CLR_BIT(RCC_CFGR,1);
		/*	HSE is Crystal or RC   */
		#if		RCC_HSE_SOURCE== RCC_CRYSTAL
			/*0 dont bypass crystal*/
				CLR_BIT(RCC_CR,18);
		#elif  RCC_HSE_SOURCE== RCC_RC
				/*1 bypass crystal*/
				SET_BIT(RCC_CR,18);
		#endif
/*			HSE ON		Check on BYPASS BIT	*/
				SET_BIT(RCC_CR,16);

		/*		HSE is Ready ?	//POLLING	*/
			while(!GET_BIT(RCC_CR,17) && Local_u32TimeOut !=10000)
			{
				Local_u32TimeOut++;
			}
			/*       POLLING ON SWS			 */ Local_u32TimeOut=0;
			while(!GET_BIT(RCC_CFGR,2) && GET_BIT(RCC_CFGR,3)&&Local_u32TimeOut !=10000)
			{
				Local_u32TimeOut++;
			}

	#elif		CLOCK_TYPE == RCC_PLL
		#if 	(RCC_PLL_SOURCE== RCC_HSI )
			/*			HSI ON	/configure HSI/2 as PLL source 	*/
					SET_BIT(RCC_CR,0);
					CLR_BIT(RCC_CFGR,16);
					while(!GET_BIT(RCC_CR,1) && Local_u32TimeOut !=10000)
					{
						Local_u32TimeOut++;
					}

		#elif	 ( RCC_PLL_SOURCE== RCC_HSE || RCC_PLL_SOURCE== RCC_HSE_2 )
			/*		HSE ON	/ Select HSI AS the PLL Clock Source/ HSE is Ready? 	*/
					SET_BIT(RCC_CR,16);
					SET_BIT(RCC_CFGR,16);
					while(!GET_BIT(RCC_CR,17) && Local_u32TimeOut !=10000)
					{
						Local_u32TimeOut++;
					}
			#if  RCC_PLL_SOURCE== RCC_HSE
					CLR_BIT(RCC_CFGR,17);
			#else
					SET_BIT(RCC_CFGR,17);
			#endif

			/*	System Clock Switch	..Select PLL as system clk 	*/
				CLR_BIT(RCC_CFGR,0);
				SET_BIT(RCC_CFGR,1);
			/*       POLLING ON SWS			 */ Local_u32TimeOut=0;
				while(!GET_BIT(RCC_CFGR,2) && GET_BIT(RCC_CFGR,3)&&Local_u32TimeOut !=10000)
				{
					Local_u32TimeOut++;
				}
			/*			PLL ON				*/
				SET_BIT(RCC_CR,24);
			/*	POLLING ON PLL READY  		*/ Local_u32TimeOut=0;
				while(!GET_BIT(RCC_CR,25) && Local_u32TimeOut !=10000)
				{
						Local_u32TimeOut++;
				}
		#endif

	#else
				#error "Wrong clock system choice!"

	#endif
}

void RCC_voidEnablePeripheralClock(u8 Copy_u8BusID,Prephiral_Id_type Copy_u8PeripheralID)
{
	/*	Range Check	*/
	if(Copy_u8PeripheralID < 32)
	{
		switch(Copy_u8BusID)
		{
			case RCC_AHB :	SET_BIT( RCC_AHBENR,Copy_u8PeripheralID);	break;
			case RCC_APB1:	SET_BIT( RCC_APB1ENR,Copy_u8PeripheralID);	break;
			case RCC_APB2:	SET_BIT( RCC_APB2ENR,Copy_u8PeripheralID);	break;
		}
	}
	else{/*		Return ERROR	*/}
}
void RCC_voidDisablePeripheralClock(u8 Copy_u8BusID,Prephiral_Id_type Copy_u8PeripheralID)
{
	/*	Range Check	*/
	if(Copy_u8PeripheralID < 32)
	{
		switch(Copy_u8BusID)
		{
			case RCC_AHB :	CLR_BIT(RCC_AHBENR,Copy_u8PeripheralID);	break;
			case RCC_APB1:	CLR_BIT(RCC_APB1ENR,Copy_u8PeripheralID);	break;
			case RCC_APB2:	CLR_BIT(RCC_APB2ENR,Copy_u8PeripheralID);	break;
		}
	}
	else{/*		Return ERROR	*/}
}
/*Update by placing Hexa in the EN Register*/
void RCC_voidEnablePeripheralClock_EntireBus(u8 Copy_u8BusID)
{
	if(Copy_u8BusID<3)
	{
		switch(Copy_u8BusID)
		{
		case RCC_AHB:
			for(Prephiral_Id_type i=AHB_FIRST_PREPHERIAL;i<=AHB_TOTAL;i++)
				SET_BIT( RCC_AHBENR,AHB_Bus_On_Off_Array[i]);
			break;

		case RCC_APB2:
			for(Prephiral_Id_type i=APB2_FIRST_PREPHERIAL;i<=APB2_TOTAL;i++)
				SET_BIT( RCC_APB2ENR,APB2_Bus_On_Off_Array[i]);
			break;

		case RCC_APB1:
			for(Prephiral_Id_type i=APB1_FIRST_PREPHERIAL;i<=APB1_TOTAL;i++)
				SET_BIT( RCC_APB1ENR,APB1_Bus_On_Off_Array[i]);
			break;


		}
	}
	else{/*Error*/}


}


void RCC_voidDisblePeripheralClock_EntireBus(u8 Copy_u8BusID)
{
	if(Copy_u8BusID <3)
	{
		switch(Copy_u8BusID)
		{
		case RCC_AHB:
			for(Prephiral_Id_type i=AHB_FIRST_PREPHERIAL;i<=AHB_TOTAL;i++)
				CLR_BIT( RCC_AHBENR,AHB_Bus_On_Off_Array[i]);
			break;

		case RCC_APB2:
			for(Prephiral_Id_type i=APB2_FIRST_PREPHERIAL;i<=APB2_TOTAL;i++)
				CLR_BIT( RCC_APB2ENR,APB2_Bus_On_Off_Array[i]);
			break;

		case RCC_APB1:
			for(Prephiral_Id_type i=APB1_FIRST_PREPHERIAL;i<=APB1_TOTAL;i++)
				CLR_BIT( RCC_APB1ENR,APB1_Bus_On_Off_Array[i]);
			break;


		}
	}
	else{/*Error*/}
}


