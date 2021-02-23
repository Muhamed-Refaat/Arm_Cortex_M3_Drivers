
#include "StdTypes.h"
#include "Utils.h"
#include "UART_interface.h"
#include "UART_private.h"
#include "UART_Config.h"


static void (*UART_pfCallBack[NUMBER_OF_UART_UNITS])(void) ={ NULL };


void UART_voidInit(UART_init_type * uart)
{
	/**********************************************************************************************
	 * Pre Configurations :-																	  *
	 * 				RCC ==> enable digital interface to UART prepherial .						  *
	 * 				GPIO==> TX pin must be configuard as Alternate function PP .				  *
	 * 					==> RX pin must be configuard as input floating / input pull up. 		  *
	 * ********************************************************************************************
	 */
	switch(uart->ID)
	{
	case ID_UART1 :

		/********Fill CR1 with required configuration (word lenght and parity ) *******/
		if(uart->parity==EVEN_PARITY)       UART1-> CR1 |= (uart->word<<12)|(uart->parity<<10);
		else			    				UART1-> CR1 |= (uart->word<<12)|(uart->parity<<9);
		/********Fill CR2 with required configuration (Stop bits) *******/
		UART1-> CR2 |= (uart->stop<<12);

		/********Fill CR3 with required configuration (DMAR And DMAT) *******/
		UART1-> CR3 |= (uart->dmaTx<<7)|(uart->dmaTx<<6);
		/*********            Set boudrate          **********************/
		UART1 -> BRR |= (uart->boudrate);
		/*************************Enable Uart***************************/
		/* Enable RX */
		SET_BIT(UART1->CR1,2);
		/* Enable Tx */
		SET_BIT(UART1->CR1,3);
		SET_BIT(UART1->CR1,13);

			/*******************END init ****************************/
		break;
	case ID_UART2 :

		/********Fill CR1 with required configuration (word lenght and parity ) *******/
		if(uart->parity==EVEN_PARITY)   UART2-> CR1 |= (uart->word<<12)|(uart->parity<<10);
		else							UART2-> CR1 |= (uart->word<<12)|(uart->parity<<9);
		/********Fill CR2 with required configuration (Stop bits) *******/
		UART2-> CR2 |= (uart->stop<<12);

		/********Fill CR3 with required configuration (DMAR And DMAT) *******/
		UART2-> CR3 |= (uart->dmaTx<<7)|(uart->dmaTx<<6);
		/*********            Set boudrate          **********************/
		UART2 -> BRR |= (uart->boudrate);
		/*************************Enable Uart***************************/
		/* Enable RX */
		SET_BIT(UART2->CR1,2);
		/* Enable Tx and UE */
		SET_BIT(UART2->CR1,3);
		SET_BIT(UART2->CR1,13);
		/*******************END init ****************************/
		break;
	case ID_UART3 :

		/********Fill CR1 with required configuration (word lenght and parity ) *******/
		if(uart->parity==EVEN_PARITY)       UART3-> CR1 |= (uart->word<<12)|(uart->parity<<10);
		else								UART3-> CR1 |= (uart->word<<12)|(uart->parity<<9);
		/********Fill CR2 with required configuration (Stop bits) *******/
		UART3-> CR2 |= (uart->stop<<12);

		/********Fill CR3 with required configuration (DMAR And DMAT) *******/
		UART3-> CR3 |= (uart->dmaTx<<7)|(uart->dmaTx<<6);
		/*********            Set boudrate          **********************/
		UART3 -> BRR |= (uart->boudrate);
		/*************************Enable Uart***************************/
		/* Enable RX */
		SET_BIT(UART3->CR1,2);
		/* Enable Tx and UE*/
		SET_BIT(UART3->CR1,3);

		SET_BIT(UART3->CR1,13);
		/*******************END init ****************************/
		break;

	default:;

	}

}

void UART_voidSendChar(UART_init_type * uart, u8  data)
{
	switch(uart->ID)
	{
	case ID_UART1:
		/*wait till data is Ready to be send */
		while(!GET_BIT(UART1->SR,6));
		/*Write data in DR register */
		UART1-> DR = data;
		break;
	case ID_UART2:
		/*wait till data is Ready to be send */
		while(!GET_BIT(UART2->SR,7));
		/*Write data in DR register */
		UART2-> DR = data;
		break;
	case ID_UART3:
		/*wait till data is Ready to be send */
		while(!GET_BIT(UART3->SR,7));
		/*Write data in DR register */
		UART3-> DR = data;
		break;
	default :;
	}

}

u8 UART_u8ReciveChar(UART_init_type * uart)
{
	switch(uart->ID)
		{
		case ID_UART1:
		/* wiat Received data is ready to be read.*/
		while(GET_BIT(UART1->SR,5));
		/* Read data form data Register  */
		return UART1->DR;
		break;
		case ID_UART2:
		/* wiat Received data is ready to be read.  */
		while(GET_BIT(UART2->SR,5));
		/* Read data form data Register */
		return UART2->DR;
		break;
		case ID_UART3:
		/* wiat Received data is ready to be read.*/
		while(GET_BIT(UART3->SR,5));
		/* Read data form data Register */
		return UART3->DR;
		break;

		default : ;
		}
	return 1;
}

u8 UART_u8ReciveCharPeriodic(UART_init_type * uart, u8* data)
{
	u8 Local_u8_check =0 ;

	switch(uart->ID)
	{
	case ID_UART1 :
		if (GET_BIT(UART1->SR,5))
			{
				*data=UART1->DR;
				Local_u8_check =1 ;
			}

		break;
	case ID_UART2 :
		if (GET_BIT(UART2->SR,5))
			{
				*data=UART2->DR;
				Local_u8_check =1 ;
			}

		break;
	case ID_UART3 :
		if (GET_BIT(UART3->SR,5))
			{
				*data=UART3->DR;
				Local_u8_check =1 ;
			}

		break;
	default :;
	}


	return Local_u8_check ;
}


void UART_voidSendString(UART_init_type * uart, u8 * str)
{
#if (MAX_STRING_SIZE==1)
	 u8 i = 0 ;
#elif  (MAX_STRING_SIZE==2)
	 u16 i = 0 ;
#else
	 u32 i = 0 ;
#endif

	switch(uart->ID)
		{
		case ID_UART1:
			for(i ; str[i] !='\0' ; i++)
			{
				UART_voidSendChar(uart, str[i] );
				/*NULL pointer is not transimeted */
			}
			break;
		case ID_UART2:
			for(i ; str[i]!='\0' ; i++)
			{
				UART_voidSendChar(uart, str[i] );
			}
			break;
		case ID_UART3:
			for(i ; str[i]!='\0' ; i++)
			{
				UART_voidSendChar(uart, str[i] );
			}
			break;
		default : ;


		}

}

void UART_voidReciveString(UART_init_type * uart, u8 * str)
{
#if (MAX_STRING_SIZE==1)
	 u8 i = 0 ;
#elif  (MAX_STRING_SIZE==2)
	 u16 i = 0 ;
#else
	 u32 i = 0 ;
#endif
	 switch(uart->ID)
	 		{
	 		case ID_UART1:

	 			str[i]=UART_u8ReciveChar(uart);
	 			while((str[i] !=13) && (str[i] != 10)) /* Sended char not equal  enter */
	 			{
	 					i++;
	 					str[i]=UART_u8ReciveChar(uart);
	 			}
	 			str[i]=0; //null terminator of string Lock on buffer after reciveing \n or \r or both
	 		    break;
	 		case ID_UART2:

	 			str[i]=UART_u8ReciveChar(uart);
	 			while((str[i] !=13) && (str[i] != 10)) /* Sended char not equal  enter */
	 			{
	 					i++;
	 					str[i]=UART_u8ReciveChar(uart);
	 			}
	 			str[i]=0; //null terminator of string
	 		    break;
	 		case ID_UART3:

	 			str[i]=UART_u8ReciveChar(uart);
	 			while((str[i] !=13) && (str[i] != 10)) /* Sended/Recived char not equal  enter */
	 			{
	 					i++;
	 					str[i]=UART_u8ReciveChar(uart);
	 			}
	 			str[i]=0; //null terminator of string
	 		    break;

	 			default : ;
	 		}


}




void UART_SendNumber(UART_init_type * uart ,u32 num)
{
	  switch(uart->ID)
	  {
	  case ID_UART1:
		    UART_voidSendChar(uart,(u8)num); //lowers byte
		  	UART_voidSendChar(uart,(u8)(num>>8));
		  	UART_voidSendChar(uart,(u8)(num>>16));
		  	UART_voidSendChar(uart,(u8)(num>>24));
		  break;
	  case ID_UART2:
		    UART_voidSendChar(uart,(u8)num); //lowers byte
		  	UART_voidSendChar(uart,(u8)(num>>8));
		  	UART_voidSendChar(uart,(u8)(num>>16));
		  	UART_voidSendChar(uart,(u8)(num>>24));
		  break;
	  case ID_UART3:
		    UART_voidSendChar(uart,(u8)num); //lowers byte
		  	UART_voidSendChar(uart,(u8)(num>>8));
		  	UART_voidSendChar(uart,(u8)(num>>16));
		  	UART_voidSendChar(uart,(u8)(num>>24));
		  break;

	  default:;
	  }

}


 u32 UART_RecivNumber(UART_init_type * uart )
{
	 u8 b0=0 ;
	 u8 b1=0 ;
	 u8 b2=0 ;
	 u8 b3=0 ;

	  switch(uart->ID)
	  {
	  case ID_UART1:
		 b0 = UART_u8ReciveChar(uart);
		 b1 = UART_u8ReciveChar(uart);
		 b2 = UART_u8ReciveChar(uart);
		 b3 = UART_u8ReciveChar(uart);
		 return ((u32)b3<<24)|((u32)b2<<16)|(b1<<8) | b0 ;
		  break;
	  case ID_UART2:
		 b0 = UART_u8ReciveChar(uart);
		 b1 = UART_u8ReciveChar(uart);
		 b2 = UART_u8ReciveChar(uart);
		 b3 = UART_u8ReciveChar(uart);
		 return ((u32)b3<<24)|((u32)b2<<16)|(b1<<8) | b0 ;
		  break;
	  case ID_UART3:
		 b0 = UART_u8ReciveChar(uart);
		 b1 = UART_u8ReciveChar(uart);
		 b2 = UART_u8ReciveChar(uart);
		 b3 = UART_u8ReciveChar(uart);
		 return (((u32)b3<<24)|((u32)b2<<16)|(b1<<8) | b0) ;
		  break;

	  default:;
	  }
return 0 ;
}

// void UART_voidSendStringCheckSum(UART_init_type * uart ,u8 *str); // my protocole
// u8 UART_voidReciveStringCheckSum(UART_init_type * uart , u8 *str);

void UART_voidInterruptEnable(UART_init_type * uart, Interrupt_type interrupt)
{


	switch(uart->ID)
		{
		case ID_UART1:
			switch(interrupt)
			{
			case PE    :       SET_BIT(UART1->CR1,8);		break;
			case TXE   :       SET_BIT(UART1->CR1,7);					break;
			case TC    :       SET_BIT(UART1->CR1,6);					break;
			case RXNE  :       SET_BIT(UART1->CR1,5);					break;
			case IDLE  :       SET_BIT(UART1->CR1,4);					break;
			case  NE   :
			case  ORE  :
			case  FR   : 	   SET_BIT(UART1->CR3,0);					break;
			default :;
			}

			break;
		case ID_UART2:
			switch(interrupt)
			{
			case PE    :       SET_BIT(UART2->CR1,8);					break;
			case TXE   :       SET_BIT(UART2->CR1,7);					break;
			case TC    :       SET_BIT(UART2->CR1,6);					break;
			case RXNE  :       SET_BIT(UART2->CR1,5);					break;
			case IDLE  :       SET_BIT(UART2->CR1,4);					break;
			case  NE   :
			case  ORE  :
			case  FR   : 	   SET_BIT(UART2->CR3,0);					break;
			default : ;
			}

			break;
		case ID_UART3:
			switch(interrupt)
			{
			case PE    :       SET_BIT(UART3->CR1,8);					break;
			case TXE   :       SET_BIT(UART3->CR1,7);					break;
			case TC    :       SET_BIT(UART3->CR1,6);					break;
			case RXNE  :       SET_BIT(UART3->CR1,5);					break;
			case IDLE  :       SET_BIT(UART3->CR1,4);					break;
			case  NE   :
			case  ORE  :
			case  FR   : 	   SET_BIT(UART3->CR3,0);					break;
			default : ;
			}

			break;

			default :;

		}
}
void UART_voidInterruptDisable(UART_init_type * uart, Interrupt_type interrupt)
{
	switch(uart->ID)
			{
			case ID_UART1:
				switch(interrupt)
				{
				case PE    :       CLR_BIT(UART1->CR1,8);					break;
				case TXE   :       CLR_BIT(UART1->CR1,7);					break;
				case TC    :       CLR_BIT(UART1->CR1,6);					break;
				case RXNE  :       CLR_BIT(UART1->CR1,5);					break;
				case IDLE  :       CLR_BIT(UART1->CR1,4);					break;
				case  NE   :
				case  ORE  :
				case  FR   : 	   CLR_BIT(UART1->CR3,0);					break;
				default :;
				}

				break;
			case ID_UART2:
				switch(interrupt)
				{
				case PE    :       CLR_BIT(UART2->CR1,8);					break;
				case TXE   :       CLR_BIT(UART2->CR1,7);					break;
				case TC    :       CLR_BIT(UART2->CR1,6);					break;
				case RXNE  :       CLR_BIT(UART2->CR1,5);					break;
				case IDLE  :       CLR_BIT(UART2->CR1,4);					break;
				case  NE   :
				case  ORE  :
				case  FR   : 	   CLR_BIT(UART2->CR3,0);					break;
				default : ;
				}

				break;
			case ID_UART3:
				switch(interrupt)
				{
				case PE    :       CLR_BIT(UART3->CR1,8);					break;
				case TXE   :       CLR_BIT(UART3->CR1,7);					break;
				case TC    :       CLR_BIT(UART3->CR1,6);					break;
				case RXNE  :       CLR_BIT(UART3->CR1,5);					break;
				case IDLE  :       CLR_BIT(UART3->CR1,4);					break;
				case  NE   :
				case  ORE  :
				case  FR   : 	   CLR_BIT(UART3->CR3,0);					break;
				default : ;
				}

				break;

				default :;

			}
}
void UART_voidUartDisable(UART_init_type * uart)
{
	switch(uart->ID)
	{
	case ID_UART1:
		/* before disabling the USART or causing the microcontroller to enter the low-power mode */
		while(!GET_BIT(UART1->SR,6));
		/* Disable UART but keep its configuration saved in Registers */
		CLR_BIT(UART1->CR1,2);
		CLR_BIT(UART1->CR1,3);
		CLR_BIT(UART1->CR1,13);
		break;
	case ID_UART2:
		/* before disabling the USART or causing the microcontroller to enter the low-power mode */
		while(!GET_BIT(UART2->SR,6));
		/* Disable UART but keep its configuration saved in Registers */
		CLR_BIT(UART2->CR1,2);
		CLR_BIT(UART2->CR1,3);
		CLR_BIT(UART2->CR1,13);
		break;
	case ID_UART3:
		/* before disabling the USART or causing the microcontroller to enter the low-power mode */
		while(!GET_BIT(UART3->SR,6));
		/* Disable UART but keep its configuration saved in Registers */
		CLR_BIT(UART3->CR1,2);
		CLR_BIT(UART3->CR1,3);
		CLR_BIT(UART3->CR1,13);
		break;
	}
}

void UART_voidUartEnable(UART_init_type * uart)
{
	switch(uart->ID)
		{
		case ID_UART1:
			SET_BIT(UART1->CR1,2);
			SET_BIT(UART1->CR1,3);
			SET_BIT(UART1->CR1,13);
			break ;
		case ID_UART2:
			SET_BIT(UART2->CR1,2);
			SET_BIT(UART2->CR1,3);
			SET_BIT(UART2->CR1,13);
			break ;
		case ID_UART3:
			SET_BIT(UART3->CR1,2);
			SET_BIT(UART3->CR1,3);
			SET_BIT(UART3->CR1,13);
			break ;

		}

}

void UART_voidSetCallBack(UART_init_type * uart , void(*pf)(void))
{
	switch(uart->ID)
	{
	case ID_UART1:
		UART_pfCallBack[0] = pf ;
		break;
	case ID_UART2:
		UART_pfCallBack[1] = pf ;
		break;
	case ID_UART3:
		UART_pfCallBack[2] = pf ;
		break;
	}


}
/****************************************IRQ***********************************/

void USART1_IRQHandler(void)
{
	if(GET_BIT(UART1->SR,0))
	{
		/* Clearing PIF by reading SR && W/R DR Register */

	}
	if(GET_BIT(UART1->SR,1))
	{
		/* Clearing PIF by reading SR && W/R DR Register */

	}
	if(GET_BIT(UART1->SR,2))
	{
		/* Clearing PIF by reading SR && W/R DR Register */

	}
	if(GET_BIT(UART1->SR,3))
	{
		/* Clearing PIF by reading SR && W/R DR Register */

	}
	if(GET_BIT(UART1->SR,4))
	{
		/* Clearing PIF by reading SR && W/R DR Register */

	}
	if(GET_BIT(UART1->SR,5))
	{
		/* Clearing PIF by reading SR && W/R DR Register */

	}
	if(GET_BIT(UART1->SR,6))
	{
		/* Clearing PIF by reading SR && W/R DR Register */

	}
	if(GET_BIT(UART1->SR,7))
	{
		/* Clearing PIF by reading SR && W/R DR Register */

	}
	/*   CLear PIF by reading data register     */
		UART1->DR;

	UART_pfCallBack[0]();

}

void USART2_IRQHandler(void)
{
	if(GET_BIT(UART2->SR,0))
		{
			/* Clearing PIF by reading SR && W/R DR Register */


		}
		if(GET_BIT(UART2->SR,1))
		{
			/* Clearing PIF by reading SR && W/R DR Register */

		}
		if(GET_BIT(UART2->SR,2))
		{
			/* Clearing PIF by reading SR && W/R DR Register */

		}
		if(GET_BIT(UART2->SR,3))
		{
			/* Clearing PIF by reading SR && W/R DR Register */

		}
		if(GET_BIT(UART2->SR,4))
		{
			/* Clearing PIF by reading SR && W/R DR Register */

		}
		if(GET_BIT(UART2->SR,5))
		{
			/* Clearing PIF by reading SR && W/R DR Register */

		}
		if(GET_BIT(UART2->SR,6))
		{
			/* Clearing PIF by reading SR && W/R DR Register */

		}
		if(GET_BIT(UART2->SR,7))
		{
			/* Clearing PIF by reading SR && W/R DR Register */

		}
	UART2->DR;
	UART_pfCallBack[1]();
}

void USART3_IRQHandler(void)
{
	   if(GET_BIT(UART3->SR,0))
	    {

		  /* Clearing PIF by reading SR && W/R DR Register */


	    }
		if(GET_BIT(UART3->SR,1))
		{
			/* Clearing PIF by reading SR && W/R DR Register */

		}
		if(GET_BIT(UART3->SR,2))
		{
			/* Clearing PIF by reading SR && W/R DR Register */

		}
		if(GET_BIT(UART3->SR,3))
		{
			/* Clearing PIF by reading SR && W/R DR Register */

		}
		if(GET_BIT(UART3->SR,4))
		{
			/* Clearing PIF by reading SR && W/R DR Register */

		}
		if(GET_BIT(UART3->SR,5))
		{
			/* Clearing PIF by reading SR && W/R DR Register */

		}
		if(GET_BIT(UART3->SR,6))
		{
			/* Clearing PIF by reading SR && W/R DR Register */

		}
		if(GET_BIT(UART3->SR,7))
		{
			/* Clearing PIF by reading SR && W/R DR Register */

		}
	UART3->DR;
	UART_pfCallBack[2]();
}
