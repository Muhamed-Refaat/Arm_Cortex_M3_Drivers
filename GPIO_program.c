
#include "StdTypes.h" /*Must be above other includes 34an used fehom*/
#include "Utils.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"



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
	/*		Range Check							*/
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
void	DIO_voidSetPortValue(u8 Copy_u8PortID,u8 Copy_u8Value)
{
#if 	DIO_U8_SINGLE_ASSMPLY_INSTRUCTION==0

	if(Copy_u8PortID<3)
	{
		switch(Copy_u8PortID)
		{
		case DIO_U8_PORTA:
			switch(Copy_u8Value)
			{
			case DIO_U8_HIGH:	GPIOA_ODR= 0x0000FFFF;	break;
			case DIO_U8_LOW	:	GPIOA_ODR= 0x00000000 ;	break;
			default:;	/*		Return ERROR		*/
			}
			break;
		case DIO_U8_PORTB:
			switch(Copy_u8Value)
			{
			case DIO_U8_HIGH:	GPIOB_ODR= 0x0000FFFF;	break;
			case DIO_U8_LOW	:	GPIOB_ODR= 0x00000000 ;	break;
			default:;	/*		Return ERROR		*/
			}
			break;
		case DIO_U8_PORTC:
			switch(Copy_u8Value)
			{
			case DIO_U8_HIGH:	GPIOC_ODR= 0x0000FFFF;	break;
			case DIO_U8_LOW	:	GPIOC_ODR= 0x00000000 ;	break;
			default:;	/*		Return ERROR		*/
			}
			break;
		}
	}
	else{/*Error*/}
#else
	if(Copy_u8PortID<3)
	{
		switch(Copy_u8PortID)
		{
		case DIO_U8_PORTA:
			switch(Copy_u8Value)
			{
			case DIO_U8_HIGH:	GPIOA_BSRR= 0x0000FFFF;	break;
			case DIO_U8_LOW	:	GPIOA_BRR= 0x00000000 ;	break;
			default:;	/*		Return ERROR		*/
			}
			break;
		case DIO_U8_PORTB:
			switch(Copy_u8Value)
			{
			case DIO_U8_HIGH:	GPIOB_BSRR= 0x0000FFFF;	break;
			case DIO_U8_LOW	:	GPIOB_BRR= 0x00000000 ;	break;
			default:;	/*		Return ERROR		*/
			}
			break;
		case DIO_U8_PORTC:
			switch(Copy_u8Value)
			{
			case DIO_U8_HIGH:	GPIOC_BSRR= 0x0000FFFF;	break;
			case DIO_U8_LOW	:	GPIOC_BRR= 0x00000000 ;	break;
			default:;	/*		Return ERROR		*/
			}
			break;
		}
	}
	else{/*Error*/}
#endif

}
