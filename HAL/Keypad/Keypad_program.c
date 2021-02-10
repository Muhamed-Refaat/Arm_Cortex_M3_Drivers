#include "StdTypes.h"
#include "Utils.h"

#include "GPIO_interface.h"
#include "Keypad_interface.h"
#include "Keypad_private.h"
#include "Keypad_Config.h"



u8 Keypad_u8_GetKey(void)
{
	 u8 r,c,key=NO_KEY;
	 u32 Local_u32_TimeOut=0;
/*  OUTPUT Leads Must be connected next to each other	*/
	 DIO_InitPin(FIRST_OUTPUT , DIO_E_OUTPUT_2MHZ_PUSH);
	 DIO_InitPin(FIRST_OUTPUT+1,DIO_E_OUTPUT_2MHZ_PUSH);
	 DIO_InitPin(FIRST_OUTPUT+2,DIO_E_OUTPUT_2MHZ_PUSH);
	 DIO_InitPin(FIRST_OUTPUT+3,DIO_E_OUTPUT_2MHZ_PUSH);

/*	INPUT Leads Must be connected next to each other  */
	 DIO_InitPin(FIRST_INPUT,  DIO_E_INPUT_PULL_UP);
	 DIO_InitPin(FIRST_INPUT+1, DIO_E_INPUT_PULL_UP);
	 DIO_InitPin(FIRST_INPUT+2, DIO_E_INPUT_PULL_UP);
	 DIO_InitPin(FIRST_INPUT+3, DIO_E_INPUT_PULL_UP);
	 for(r=0;r<4;r++)
		{
		 	 /*Set first output RoW*/
			DIO_WritePin(FIRST_OUTPUT+r,LOW);
			for(c=0;c<4;c++)
			{
				if(!DIO_ReadPin(FIRST_INPUT+c))
				{
					key=keys[r][c];
					while((!DIO_ReadPin(FIRST_INPUT+c)) && (Local_u32_TimeOut!=10000))
					{
						Local_u32_TimeOut++;
					}
				}
			}
			DIO_WritePin(FIRST_OUTPUT+r,HIGH);

		}
		return key;

}
