
#include "StdTypes.h" /*Must be above other includes 34an used fehom*/
#include "Utils.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

#if 	DIO_FUNCTION_MODE_SELECT==PREPROCESSOR

/*void	DIO_voidSetPinDirection(port,pin,mode);*/
void	DIO_voidSetPinDirection(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8Mode)
{
	/*		Range Check							*/
	if( (Copy_u8PortID<3) && (Copy_u8PinID<16) )
	{
		switch(Copy_u8PortID)
		{
		case DIO_U8_PORTA:
			/*		LOW PORT				*/
			if( Copy_u8PinID < 8 )
			{
				/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
				GPIOA_CRL &= ~((u32)(0b1111)<<(Copy_u8PinID * 4));
				GPIOA_CRL |=  ((u32)(Copy_u8Mode)<<(Copy_u8PinID * 4));
			}
			/*		HIGH PORT				*/
			else
			{
				Copy_u8PinID -= 8 ;
				/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
				GPIOA_CRH &= ~((u32)(0b1111)<<(Copy_u8PinID * 4));
				GPIOA_CRH |=  ((u32)(Copy_u8Mode)<<(Copy_u8PinID * 4));
			}
			break;
		case DIO_U8_PORTB:
			if( Copy_u8PinID < 8 )
			{
				/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
				GPIOB_CRL &= ~((u32)(0b1111)<<(Copy_u8PinID * 4));
				GPIOB_CRL |=  ((u32)(Copy_u8Mode)<<(Copy_u8PinID * 4));
			}
			/*		HIGH PORT				*/
			else
			{
				Copy_u8PinID -= 8 ;
				/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
				GPIOB_CRH &= ~((u32)(0b1111)<<(Copy_u8PinID * 4));
				GPIOB_CRH |=  ((u32)(Copy_u8Mode)<<(Copy_u8PinID * 4));
			}
			break;
		case DIO_U8_PORTC:
			if( Copy_u8PinID < 8 )
			{
				/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
				GPIOC_CRL &= ~((u32)(0b1111)<<(Copy_u8PinID * 4));
				GPIOC_CRL |=  ((u32)(Copy_u8Mode)<<(Copy_u8PinID * 4));
			}
			/*		HIGH PORT				*/
			else
			{
				Copy_u8PinID -= 8 ;
				/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
				GPIOC_CRH &= ~((u32)(0b1111)<<(Copy_u8PinID * 4));
				GPIOC_CRH |=  ((u32)(Copy_u8Mode)<<(Copy_u8PinID * 4));
			}
			break;
		}
	}else{/*	Return ERROR	*/}

}
/*		if Pin is Output (High or Low)	*/
void	DIO_voidSetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8Value)
{
#if 	DIO_U8_SINGLE_ASSMPLY_INSTRUCTION==0
	/*		Range Check							*/
	if( (Copy_u8PortID<3) && (Copy_u8PinID<16) )
	{
		switch(Copy_u8PortID)
		{
		case DIO_U8_PORTA:
			switch(Copy_u8Value)
			{
			case DIO_U8_HIGH:	SET_BIT(GPIOA_ODR , Copy_u8PinID);	break;
			case DIO_U8_LOW	:	CLR_BIT(GPIOA_ODR , Copy_u8PinID);	break;
			default:;	/*		Return ERROR		*/
			}
			break;
			case DIO_U8_PORTB:
				switch(Copy_u8Value)
				{
				case DIO_U8_HIGH:	SET_BIT(GPIOB_ODR , Copy_u8PinID);	break;
				case DIO_U8_LOW	:	CLR_BIT(GPIOB_ODR , Copy_u8PinID);	break;
				default:;	/*		Return ERROR		*/
				}
				break;
				case DIO_U8_PORTC:
					switch(Copy_u8Value)
					{
					case DIO_U8_HIGH:	SET_BIT(GPIOC_ODR , Copy_u8PinID);	break;
					case DIO_U8_LOW	:	CLR_BIT(GPIOC_ODR , Copy_u8PinID);	break;
					default:;	/*		Return ERROR		*/
					}
					break;
		}
	}else{/*	Return ERROR	*/}
#else
	/*		Range Check		NOTE CHECK DATA SHEET		*/
	if( (Copy_u8PortID<3) && (Copy_u8PinID<16) )
	{
		switch(Copy_u8PortID)
		{
		case DIO_U8_PORTA:
			switch(Copy_u8Value)
			{
			case DIO_U8_HIGH:		GPIOA_BSRR= Copy_u8PinID;	break;
			case DIO_U8_LOW	:		GPIOA_BRR=  Copy_u8PinID; 	break;
			default:;	/*		Return ERROR		*/
			}
			break;
			case DIO_U8_PORTB:
				switch(Copy_u8Value)
				{
				case DIO_U8_HIGH:		GPIOB_BSRR= Copy_u8PinID;	break;
				case DIO_U8_LOW	:		GPIOB_BRR=  Copy_u8PinID; 	break;
				default:;	/*		Return ERROR		*/
				}
				break;
				case DIO_U8_PORTC:
					switch(Copy_u8Value)
					{
					case DIO_U8_HIGH:		GPIOC_BSRR= Copy_u8PinID;	break;
					case DIO_U8_LOW	:		GPIOC_BRR=  Copy_u8PinID; 	break;
					default:;	/*		Return ERROR		*/
					}
					break;
		}
	}else{/*	Return ERROR	*/}

#endif
}
/*		if Pin is Input (Return High or Low)	*/
u8		DIO_u8GetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID)
{
	u8 Local_u8Value = 0XFF;
	/*		Range Check							*/
	if( (Copy_u8PortID<3) && (Copy_u8PinID<16) )
	{

		switch(Copy_u8PortID)
		{
		case DIO_U8_PORTA:	Local_u8Value = GET_BIT(GPIOA_IDR , Copy_u8PinID);	break;
		case DIO_U8_PORTB:	Local_u8Value = GET_BIT(GPIOB_IDR , Copy_u8PinID);	break;
		case DIO_U8_PORTC:	Local_u8Value = GET_BIT(GPIOC_IDR , Copy_u8PinID);	break;

		}
	}else{/*	Return ERROR	*/}

	return Local_u8Value;
}

/*		SET PORT DIRECTION											*/
void	DIO_voidSetPortDirection(u8 Copy_u8PortID,u32 Copy_u32Mode)
{
	if(Copy_u8PortID<3)
	{
		switch(Copy_u8PortID)
		{
		case DIO_U8_PORTA:
			GPIOA_CRL=	Copy_u32Mode;
			GPIOA_CRH=	Copy_u32Mode;
			break;
		case DIO_U8_PORTB:
			GPIOB_CRL=	Copy_u32Mode;
			GPIOB_CRH=	Copy_u32Mode;
			break;
		case DIO_U8_PORTC:
			GPIOC_CRL=	Copy_u32Mode;
			GPIOC_CRH=	Copy_u32Mode;
			break;
		}
	}
	else{/*ERROR*/}


}
/*		SET PORT VALUE												*/
void	DIO_voidSetPortValue(u8 Copy_u8PortID,u16 Copy_u16Value)
{


	if(Copy_u8PortID<3)
	{
		switch(Copy_u8PortID)
		{
		case DIO_U8_PORTA:
			GPIOA_ODR= Copy_u16Value;	break;
		case DIO_U8_PORTB:
			GPIOB_ODR= Copy_u16Value;	break;
		case DIO_U8_PORTC:
			GPIOC_ODR= Copy_u16Value;	break;
		}
	}
	else{/*Error*/}
}



void	DIO_voidTogglePin(u8 Copy_u8PortID,u8 Copy_u8PinID)
{
	/*Range Check*/
	if((Copy_u8PortID<3) &&	(Copy_u8PinID<16))
	{
		switch(Copy_u8PortID)
		{
		case DIO_U8_PORTA:
			if(DIO_u8GetPinValue(GPIOA_IDR,Copy_u8PinID))
				DIO_voidSetPinValue(DIO_U8_PORTA, Copy_u8PinID, DIO_U8_LOW);
			else				DIO_voidSetPinValue(DIO_U8_PORTA, Copy_u8PinID, DIO_U8_HIGH);

				break;
		case DIO_U8_PORTB:
			if(DIO_u8GetPinValue(GPIOB_IDR,Copy_u8PinID))
				DIO_voidSetPinValue(DIO_U8_PORTB, Copy_u8PinID, DIO_U8_LOW);
			else  				DIO_voidSetPinValue(DIO_U8_PORTB, Copy_u8PinID, DIO_U8_HIGH);

				break;
		case DIO_U8_PORTC:
			if(DIO_u8GetPinValue(GPIOC_IDR,Copy_u8PinID))
				DIO_voidSetPinValue(DIO_U8_PORTC, Copy_u8PinID, DIO_U8_LOW);
			else   				DIO_voidSetPinValue(DIO_U8_PORTC, Copy_u8PinID, DIO_U8_HIGH);

				break;

		}
	}
	else {/*return error*/}
}

#elif 	DIO_FUNCTION_MODE_SELECT==ENUM

void	DIO_InitPin(DIO_Pin_type pin,DIO_PinStatus_type status)
{
	u8 					Local_Pin_num=pin%16;
	DIO_Port_type		Local_PORT_num=pin/16;

		/*		Range Check			*/
		if(pin<TOTAL_PINS)
		{
			switch(Local_PORT_num)
			{
			case DIO_PORTA:
				if( Local_Pin_num < 8 )
				{
					if(status==DIO_E_INPUT_PULL_DOWN)
					{
						status=DIO_E_INPUT_PULL_UP;
						GPIOA_CRL &= ~((u32)(0b1111)<<(Local_Pin_num * 4));
						GPIOA_CRL |=  ((u32)(status)<<(Local_Pin_num * 4));
						CLR_BIT(GPIOA_ODR,Local_Pin_num);
					}
					else if(status==DIO_E_INPUT_PULL_UP)
					{
						GPIOA_CRL &= ~((u32)(0b1111)<<(Local_Pin_num * 4));
						GPIOA_CRL |=  ((u32)(status)<<(Local_Pin_num * 4));
						SET_BIT(GPIOA_ODR,Local_Pin_num);
					}
					else if(status==DIO_E_OUTPUT_2MHZ_PULL)
					{
						status =DIO_E_OUTPUT_2MHZ_PUSH;
						/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
						GPIOA_CRL &= ~((u32)(0b1111)<<(Local_Pin_num * 4));
						GPIOA_CRL |=  ((u32)(status)<<(Local_Pin_num * 4));
						CLR_BIT(GPIOA_ODR,Local_Pin_num);
					}
					else if(status==DIO_E_OUTPUT_2MHZ_PUSH)
					{

						/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
						GPIOA_CRL &= ~((u32)(0b1111)<<(Local_Pin_num * 4));
						GPIOA_CRL |=  ((u32)(status)<<(Local_Pin_num * 4));
						SET_BIT(GPIOA_ODR,Local_Pin_num);
					}
					else if(status==DIO_E_OUTPUT_10MHZ_PULL)
					{
						status =DIO_E_OUTPUT_10MHZ_PUSH;
						/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
						GPIOA_CRL &= ~((u32)(0b1111)<<(Local_Pin_num * 4));
						GPIOA_CRL |=  ((u32)(status)<<(Local_Pin_num * 4));
						CLR_BIT(GPIOA_ODR,Local_Pin_num);
					}
					else if(status==DIO_E_OUTPUT_10MHZ_PUSH)
					{

						/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
						GPIOA_CRL &= ~((u32)(0b1111)<<(Local_Pin_num * 4));
						GPIOA_CRL |=  ((u32)(status)<<(Local_Pin_num * 4));
						SET_BIT(GPIOA_ODR,Local_Pin_num);
					}
					else if(status==DIO_E_OUTPUT_50MHZ_PULL)
					{
						status =DIO_E_OUTPUT_50MHZ_PUSH;
						/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
						GPIOA_CRL &= ~((u32)(0b1111)<<(Local_Pin_num * 4));
						GPIOA_CRL |=  ((u32)(status)<<(Local_Pin_num * 4));
						CLR_BIT(GPIOA_ODR,Local_Pin_num);
					}
					else if(status==DIO_E_OUTPUT_50MHZ_PUSH)
					{

						/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
						GPIOA_CRL &= ~((u32)(0b1111)<<(Local_Pin_num * 4));
						GPIOA_CRL |=  ((u32)(status)<<(Local_Pin_num * 4));
						SET_BIT(GPIOA_ODR,Local_Pin_num);
					}
					else
					{
						GPIOA_CRL &= ~((u32)(0b1111)<<(Local_Pin_num * 4));
						GPIOA_CRL |=  ((u32)(status)<<(Local_Pin_num * 4));
					}


				}
				/*		HIGH PORT				*/
				else
				{
					Local_Pin_num -=8 ;
					if(status==DIO_E_INPUT_PULL_DOWN)
						{
							status=DIO_E_INPUT_PULL_UP;
							GPIOA_CRH &= ~((u32)(0b1111)<<(Local_Pin_num * 4));
							GPIOA_CRH |=  ((u32)(status)<<(Local_Pin_num * 4));
							CLR_BIT(GPIOA_ODR,(Local_Pin_num+8));
						}
						else if(status==DIO_E_INPUT_PULL_UP)
						{
							GPIOA_CRH &= ~((u32)(0b1111)<<(Local_Pin_num * 4));
							GPIOA_CRH |=  ((u32)(status)<<(Local_Pin_num * 4));
							SET_BIT(GPIOA_ODR,(Local_Pin_num+8));
						}
						else if(status==DIO_E_OUTPUT_2MHZ_PULL)
						{
							status =DIO_E_OUTPUT_2MHZ_PUSH;
							/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
							GPIOA_CRH &= ~((u32)(0b1111)<<(Local_Pin_num * 4));
							GPIOA_CRH |=  ((u32)(status)<<(Local_Pin_num * 4));
							CLR_BIT(GPIOA_ODR,(Local_Pin_num+8));
						}
						else if(status==DIO_E_OUTPUT_2MHZ_PUSH)
						{

							/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
							GPIOA_CRH &= ~((u32)(0b1111)<<(Local_Pin_num * 4));
							GPIOA_CRH |=  ((u32)(status)<<(Local_Pin_num * 4));
							SET_BIT(GPIOA_ODR,(Local_Pin_num+8));
						}
						else if(status==DIO_E_OUTPUT_10MHZ_PULL)
						{
							status =DIO_E_OUTPUT_10MHZ_PUSH;
							/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
							GPIOA_CRH &= ~((u32)(0b1111)<<(Local_Pin_num * 4));
							GPIOA_CRH |=  ((u32)(status)<<(Local_Pin_num * 4));
							CLR_BIT(GPIOA_ODR,(Local_Pin_num+8));
						}
						else if(status==DIO_E_OUTPUT_10MHZ_PUSH)
						{

							/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
							GPIOA_CRH &= ~((u32)(0b1111)<<(Local_Pin_num * 4));
							GPIOA_CRH |=  ((u32)(status)<<(Local_Pin_num * 4));
							SET_BIT(GPIOA_ODR,(Local_Pin_num+8));
						}
						else if(status==DIO_E_OUTPUT_50MHZ_PULL)
						{
							status =DIO_E_OUTPUT_50MHZ_PUSH;
							/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
							GPIOA_CRH &= ~((u32)(0b1111)<<(Local_Pin_num * 4));
							GPIOA_CRH |=  ((u32)(status)<<(Local_Pin_num * 4));
							CLR_BIT(GPIOA_ODR,(Local_Pin_num+8));
						}
						else if(status==DIO_E_OUTPUT_50MHZ_PUSH)
						{

							/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
							GPIOA_CRH &= ~((u32)(0b1111)<<(Local_Pin_num * 4));
							GPIOA_CRH |=  ((u32)(status)<<(Local_Pin_num * 4));
							SET_BIT(GPIOA_ODR,(Local_Pin_num+8));
						}
						else
						{
							GPIOA_CRH &= ~((u32)(0b1111)<<(Local_Pin_num * 4));
							GPIOA_CRH |=  ((u32)(status)<<(Local_Pin_num * 4));
						}


					}
				break;
			case DIO_PORTB:
				if( Local_Pin_num < 8 )
				{
					if(status==DIO_E_INPUT_PULL_DOWN)
					{
						status=DIO_E_INPUT_PULL_UP;
						GPIOB_CRL &= ~((u32)(0b1111)<<(Local_Pin_num * 4));
						GPIOB_CRL |=  ((u32)(status)<<(Local_Pin_num * 4));
						CLR_BIT(GPIOB_ODR,Local_Pin_num);
					}
					else if(status==DIO_E_INPUT_PULL_UP)
					{
						GPIOB_CRL &= ~((u32)(0b1111)<<(Local_Pin_num * 4));
						GPIOB_CRL |=  ((u32)(status)<<(Local_Pin_num * 4));
						SET_BIT(GPIOB_ODR,Local_Pin_num);
					}
					else if(status==DIO_E_OUTPUT_2MHZ_PULL)
					{
						status =DIO_E_OUTPUT_2MHZ_PUSH;
						/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
						GPIOB_CRL &= ~((u32)(0b1111)<<(Local_Pin_num * 4));
						GPIOB_CRL |=  ((u32)(status)<<(Local_Pin_num * 4));
						CLR_BIT(GPIOB_ODR,Local_Pin_num);
					}
					else if(status==DIO_E_OUTPUT_2MHZ_PUSH)
					{

						/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
						GPIOB_CRL &= ~((u32)(0b1111)<<(Local_Pin_num * 4));
						GPIOB_CRL |=  ((u32)(status)<<(Local_Pin_num * 4));
						SET_BIT(GPIOB_ODR,Local_Pin_num);
					}
					else if(status==DIO_E_OUTPUT_10MHZ_PULL)
					{
						status =DIO_E_OUTPUT_10MHZ_PUSH;
						/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
						GPIOB_CRL &= ~((u32)(0b1111)<<(Local_Pin_num * 4));
						GPIOB_CRL |=  ((u32)(status)<<(Local_Pin_num * 4));
						CLR_BIT(GPIOB_ODR,Local_Pin_num);
					}
					else if(status==DIO_E_OUTPUT_10MHZ_PUSH)
					{

						/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
						GPIOB_CRL &= ~((u32)(0b1111)<<(Local_Pin_num * 4));
						GPIOB_CRL |=  ((u32)(status)<<(Local_Pin_num * 4));
						SET_BIT(GPIOB_ODR,Local_Pin_num);
					}
					else if(status==DIO_E_OUTPUT_50MHZ_PULL)
					{
						status =DIO_E_OUTPUT_50MHZ_PUSH;
						/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
						GPIOB_CRL &= ~((u32)(0b1111)<<(Local_Pin_num * 4));
						GPIOB_CRL |=  ((u32)(status)<<(Local_Pin_num * 4));
						CLR_BIT(GPIOB_ODR,Local_Pin_num);
					}
					else if(status==DIO_E_OUTPUT_50MHZ_PUSH)
					{

						/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
						GPIOB_CRL &= ~((u32)(0b1111)<<(Local_Pin_num * 4));
						GPIOB_CRL |=  ((u32)(status)<<(Local_Pin_num * 4));
						SET_BIT(GPIOB_ODR,Local_Pin_num);
					}
					else
					{
						GPIOB_CRL &= ~((u32)(0b1111)<<(Local_Pin_num * 4));
						GPIOB_CRL |=  ((u32)(status)<<(Local_Pin_num * 4));
					}


				}
				/*		HIGH PORT				*/
				else
				{
					Local_Pin_num -=8 ;
					if(status==DIO_E_INPUT_PULL_DOWN)
						{
							status=DIO_E_INPUT_PULL_UP;
							GPIOB_CRH &= ~((u32)(0b1111)<<(Local_Pin_num * 4));
							GPIOB_CRH |=  ((u32)(status)<<(Local_Pin_num * 4));
							CLR_BIT(GPIOB_ODR,(Local_Pin_num+8));
						}
						else if(status==DIO_E_INPUT_PULL_UP)
						{
							GPIOB_CRH &= ~((u32)(0b1111)<<(Local_Pin_num * 4));
							GPIOB_CRH |=  ((u32)(status)<<(Local_Pin_num * 4));
							SET_BIT(GPIOB_ODR,(Local_Pin_num+8));
						}
						else if(status==DIO_E_OUTPUT_2MHZ_PULL)
						{
							status =DIO_E_OUTPUT_2MHZ_PUSH;
							/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
							GPIOB_CRH &= ~((u32)(0b1111)<<(Local_Pin_num * 4));
							GPIOB_CRH |=  ((u32)(status)<<(Local_Pin_num * 4));
							CLR_BIT(GPIOB_ODR,(Local_Pin_num+8));
						}
						else if(status==DIO_E_OUTPUT_2MHZ_PUSH)
						{

							/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
							GPIOB_CRH &= ~((u32)(0b1111)<<(Local_Pin_num * 4));
							GPIOB_CRH |=  ((u32)(status)<<(Local_Pin_num * 4));
							SET_BIT(GPIOB_ODR,(Local_Pin_num+8));
						}
						else if(status==DIO_E_OUTPUT_10MHZ_PULL)
						{
							status =DIO_E_OUTPUT_10MHZ_PUSH;
							/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
							GPIOB_CRH &= ~((u32)(0b1111)<<(Local_Pin_num * 4));
							GPIOB_CRH |=  ((u32)(status)<<(Local_Pin_num * 4));
							CLR_BIT(GPIOB_ODR,(Local_Pin_num+8));
						}
						else if(status==DIO_E_OUTPUT_10MHZ_PUSH)
						{

							/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
							GPIOB_CRH &= ~((u32)(0b1111)<<(Local_Pin_num * 4));
							GPIOB_CRH |=  ((u32)(status)<<(Local_Pin_num * 4));
							SET_BIT(GPIOB_ODR,(Local_Pin_num+8));
						}
						else if(status==DIO_E_OUTPUT_50MHZ_PULL)
						{
							status =DIO_E_OUTPUT_50MHZ_PUSH;
							/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
							GPIOB_CRH &= ~((u32)(0b1111)<<(Local_Pin_num * 4));
							GPIOB_CRH |=  ((u32)(status)<<(Local_Pin_num * 4));
							CLR_BIT(GPIOB_ODR,(Local_Pin_num+8));
						}
						else if(status==DIO_E_OUTPUT_50MHZ_PUSH)
						{

							/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
							GPIOB_CRH &= ~((u32)(0b1111)<<(Local_Pin_num * 4));
							GPIOB_CRH |=  ((u32)(status)<<(Local_Pin_num * 4));
							SET_BIT(GPIOB_ODR,(Local_Pin_num+8));
						}
						else
						{
							GPIOB_CRH &= ~((u32)(0b1111)<<(Local_Pin_num * 4));
							GPIOB_CRH |=  ((u32)(status)<<(Local_Pin_num * 4));
						}


					}
				break;
			case DIO_PORTC:
				if( Local_Pin_num < 8 )
				{
					if(status==DIO_E_INPUT_PULL_DOWN)
					{
						status=DIO_E_INPUT_PULL_UP;
						GPIOC_CRL &= ~((u32)(0b1111)<<(Local_Pin_num * 4));
						GPIOC_CRL |=  ((u32)(status)<<(Local_Pin_num * 4));
						CLR_BIT(GPIOC_ODR,Local_Pin_num);
					}
					else if(status==DIO_E_INPUT_PULL_UP)
					{
						GPIOC_CRL &= ~((u32)(0b1111)<<(Local_Pin_num * 4));
						GPIOC_CRL |=  ((u32)(status)<<(Local_Pin_num * 4));
						SET_BIT(GPIOC_ODR,Local_Pin_num);
					}
					else if(status==DIO_E_OUTPUT_2MHZ_PULL)
					{
						status =DIO_E_OUTPUT_2MHZ_PUSH;
						/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
						GPIOC_CRL &= ~((u32)(0b1111)<<(Local_Pin_num * 4));
						GPIOC_CRL |=  ((u32)(status)<<(Local_Pin_num * 4));
						CLR_BIT(GPIOC_ODR,Local_Pin_num);
					}
					else if(status==DIO_E_OUTPUT_2MHZ_PUSH)
					{

						/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
						GPIOC_CRL &= ~((u32)(0b1111)<<(Local_Pin_num * 4));
						GPIOC_CRL |=  ((u32)(status)<<(Local_Pin_num * 4));
						SET_BIT(GPIOC_ODR,Local_Pin_num);
					}
					else if(status==DIO_E_OUTPUT_10MHZ_PULL)
					{
						status =DIO_E_OUTPUT_10MHZ_PUSH;
						/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
						GPIOC_CRL &= ~((u32)(0b1111)<<(Local_Pin_num * 4));
						GPIOC_CRL |=  ((u32)(status)<<(Local_Pin_num * 4));
						CLR_BIT(GPIOC_ODR,Local_Pin_num);
					}
					else if(status==DIO_E_OUTPUT_10MHZ_PUSH)
					{

						/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
						GPIOC_CRL &= ~((u32)(0b1111)<<(Local_Pin_num * 4));
						GPIOC_CRL |=  ((u32)(status)<<(Local_Pin_num * 4));
						SET_BIT(GPIOC_ODR,Local_Pin_num);
					}
					else if(status==DIO_E_OUTPUT_50MHZ_PULL)
					{
						status =DIO_E_OUTPUT_50MHZ_PUSH;
						/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
						GPIOC_CRL &= ~((u32)(0b1111)<<(Local_Pin_num * 4));
						GPIOC_CRL |=  ((u32)(status)<<(Local_Pin_num * 4));
						CLR_BIT(GPIOC_ODR,Local_Pin_num);
					}
					else if(status==DIO_E_OUTPUT_50MHZ_PUSH)
					{

						/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
						GPIOC_CRL &= ~((u32)(0b1111)<<(Local_Pin_num * 4));
						GPIOC_CRL |=  ((u32)(status)<<(Local_Pin_num * 4));
						SET_BIT(GPIOC_ODR,Local_Pin_num);
					}
					else
					{
						GPIOC_CRL &= ~((u32)(0b1111)<<(Local_Pin_num * 4));
						GPIOC_CRL |=  ((u32)(status)<<(Local_Pin_num * 4));
					}


				}
				/*		HIGH PORT				*/
				else
				{
					Local_Pin_num =Local_Pin_num-8 ;
					if(status==DIO_E_INPUT_PULL_DOWN)
						{
							status=DIO_E_INPUT_PULL_UP;
							GPIOC_CRH &= ~((u32)(0b1111)<<(Local_Pin_num * 4));
							GPIOC_CRH |=  ((u32)(status)<<(Local_Pin_num * 4));
							CLR_BIT(GPIOC_ODR,(Local_Pin_num+8));
						}
						else if(status==DIO_E_INPUT_PULL_UP)
						{
							GPIOC_CRH &= ~((u32)(0b1111)<<(Local_Pin_num * 4));
							GPIOC_CRH |=  ((u32)(status)<<(Local_Pin_num * 4));
							SET_BIT(GPIOC_ODR,(Local_Pin_num+8));
						}
						else if(status==DIO_E_OUTPUT_2MHZ_PULL)
						{
							status =DIO_E_OUTPUT_2MHZ_PUSH;
							/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
							GPIOC_CRH &= ~((u32)(0b1111)<<(Local_Pin_num * 4));
							GPIOC_CRH |=  ((u32)(status)<<(Local_Pin_num * 4));
							CLR_BIT(GPIOC_ODR,(Local_Pin_num+8));
						}
						else if(status==DIO_E_OUTPUT_2MHZ_PUSH)
						{

							/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
							GPIOC_CRH &= ~((u32)(0b1111)<<(Local_Pin_num * 4));
							GPIOC_CRH |=  ((u32)(status)<<(Local_Pin_num * 4));
							SET_BIT(GPIOC_ODR,(Local_Pin_num+8));
						}
						else if(status==DIO_E_OUTPUT_10MHZ_PULL)
						{
							status =DIO_E_OUTPUT_10MHZ_PUSH;
							/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
							GPIOC_CRH &= ~((u32)(0b1111)<<(Local_Pin_num * 4));
							GPIOC_CRH |=  ((u32)(status)<<(Local_Pin_num * 4));
							CLR_BIT(GPIOC_ODR,(Local_Pin_num+8));
						}
						else if(status==DIO_E_OUTPUT_10MHZ_PUSH)
						{

							/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
							GPIOC_CRH &= ~((u32)(0b1111)<<(Local_Pin_num * 4));
							GPIOC_CRH |=  ((u32)(status)<<(Local_Pin_num * 4));
							SET_BIT(GPIOC_ODR,(Local_Pin_num+8));
						}
						else if(status==DIO_E_OUTPUT_50MHZ_PULL)
						{
							status =DIO_E_OUTPUT_50MHZ_PUSH;
							/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
							GPIOC_CRH &= ~((u32)(0b1111)<<(Local_Pin_num * 4));
							GPIOC_CRH |=  ((u32)(status)<<(Local_Pin_num * 4));
							CLR_BIT(GPIOC_ODR,(Local_Pin_num+8));
						}
						else if(status==DIO_E_OUTPUT_50MHZ_PUSH)
						{

							/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
							GPIOC_CRH &= ~((u32)(0b1111)<<(Local_Pin_num * 4));
							GPIOC_CRH |=  ((u32)(status)<<(Local_Pin_num * 4));
							SET_BIT(GPIOC_ODR,(Local_Pin_num+8));
						}
						else
						{
							GPIOC_CRH &= ~((u32)(0b1111)<<(Local_Pin_num * 4));
							GPIOC_CRH |=  ((u32)(status)<<(Local_Pin_num * 4));
						}


					}

				break;
			}
		}
		else{/*ERORR*/}

}



void 	DIO_WritePin(DIO_Pin_type pin,DIO_Voltage_type volt)
{
	u8 				Local_pin_num= pin %16;
	DIO_Port_type 	Local_port_num= pin /16;
	/*Range Check*/
	if(pin<TOTAL_PINS)
	{
		switch(Local_port_num)
		{
		case DIO_PORTA:
			switch(volt)
			{
			case HIGH:		SET_BIT(GPIOA_ODR,Local_pin_num); break;
			case LOW:		CLR_BIT(GPIOA_ODR,Local_pin_num); break;
			default:;
			}
			break;
		case DIO_PORTB:
			switch(volt)
			{
			case HIGH:		SET_BIT(GPIOB_ODR,Local_pin_num); break;
			case LOW:		CLR_BIT(GPIOB_ODR,Local_pin_num); break;
			default:;
			}
			break;
		case DIO_PORTC:
			switch(volt)
			{
			case HIGH:		SET_BIT(GPIOC_ODR,Local_pin_num); break;
			case LOW:		CLR_BIT(GPIOC_ODR,Local_pin_num); break;
			default:;
			}
			break;

		}


	}
	else {/*ERROR*/}
}

DIO_Voltage_type DIO_ReadPin(DIO_Pin_type pin)
{

	u8 				Local_pin_num= pin %16;
	DIO_Port_type 	Local_port_num= pin /16;
	DIO_Voltage_type volt=LOW;
	/*Range Check*/
	if(pin<TOTAL_PINS)
	{
		switch(Local_port_num)
		{
		case DIO_PORTA: 	volt= GET_BIT(GPIOA_IDR,Local_pin_num); break;
		case DIO_PORTB: 	volt= GET_BIT(GPIOB_IDR,Local_pin_num); break;
		case DIO_PORTC: 	volt= GET_BIT(GPIOC_IDR,Local_pin_num); break;
		}

	}
	else {/*ERROR*/}
	return volt;
}
void DIO_TogglePin(DIO_Pin_type pin)
{

	DIO_Port_type 	Local_port_num= pin /16;
	if(pin<TOTAL_PINS)
		{
			switch(Local_port_num)
			{
			case DIO_PORTA:
				if(DIO_ReadPin(pin))
					DIO_WritePin(pin, LOW);
				else
					DIO_WritePin(pin, HIGH);
				break;
			case DIO_PORTB:
				if(DIO_ReadPin(pin))
					DIO_WritePin(pin, LOW);
				else
					DIO_WritePin(pin, HIGH);
				break;
			case DIO_PORTC:
				if(DIO_ReadPin(pin))
					DIO_WritePin(pin, LOW);
				else
					DIO_WritePin(pin, HIGH);
				break;
			}
		}
	else{/*ERROR*/}
}

void DIO_WritePort(DIO_Port_type port,u16 data)
{
	if(port<3)
	{
		switch(port)
		{
		case DIO_PORTA: 	GPIOA_ODR=data; 	break;
		case DIO_PORTB: 	GPIOB_ODR=data; 	break;
		case DIO_PORTC: 	GPIOC_ODR=data; 	break;
		}
	}
	else{/*Error*/}
}

u16 DIO_ReadPort(DIO_Port_type port)
{
	u16 Local_u16_port_val=0;
	if(port<3)
		{
			switch(port)
			{
			case DIO_PORTA: 	Local_u16_port_val=GPIOA_IDR; 	break;
			case DIO_PORTB: 	Local_u16_port_val=GPIOB_IDR; 	break;
			case DIO_PORTC: 	Local_u16_port_val=GPIOC_IDR; 	break;

			}
		}
		else{/*Error*/}
	return Local_u16_port_val;
}

void DIO_Init(void)
{
	/*i is index pin number or pin name*/
 	DIO_Pin_type i ;
	for(i=PINA0;i<TOTAL_PINS;i++)
	{
	DIO_InitPin(i,PinsStatusArray[i]);
	}
}



#endif
