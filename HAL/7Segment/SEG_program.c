#include "StdTypes.h"
#include "Utils.h"
#include "GPIO_interface.h"

#include "SEG_interface.h"
#include "SEG_private.h"
#include "SEG_Config.h"




static void Delay_ms(u32 Copy_u32Time)
{
	for(u32 i=0; i<Copy_u32Time;i++)
		{
			for(u16 j=0;j<565;j++)
			{
				asm("NOP");
			}
		}

}

/*			Common Cathode number displaying array 0:F			*/
static const u8 SegNumbers[]={0x3F,0x06 , 0x5B ,0x4F , 0x66 ,0x6D,0x7D, 0x07 , 0x7F , 0x6F ,0x77,0x7C,0x39,0x5E,0x79,0x71};


#if 	(SEGMENT_COMMON==CATHODE && TOW_SEGMENTS==0 && MULTIBLEXED_SEGMENTS==0)
		/*	Displaying Decimal numbers 		*/
void SEG_voidDisplay_D(u8 Copy_u8_dispNum)
{
	u8 Local_u8_bit=0;
	DIO_WritePin( SEG1_MUX_LED_A, GET_BIT(SegNumbers[Copy_u8_dispNum],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_B, GET_BIT(SegNumbers[Copy_u8_dispNum],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_C, GET_BIT(SegNumbers[Copy_u8_dispNum],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_D, GET_BIT(SegNumbers[Copy_u8_dispNum],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_E, GET_BIT(SegNumbers[Copy_u8_dispNum],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_F, GET_BIT(SegNumbers[Copy_u8_dispNum],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_G, GET_BIT(SegNumbers[Copy_u8_dispNum],Local_u8_bit++));
}
		/*	Displaying Hexadecimal numbers 	*/
void SEG_voidDisplay_H(u8 Copy_u8_dispNum)
{
	u8 Local_u8_bit=0;
	DIO_WritePin( SEG1_MUX_LED_A, GET_BIT(SegNumbers[Copy_u8_dispNum],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_B, GET_BIT(SegNumbers[Copy_u8_dispNum],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_C, GET_BIT(SegNumbers[Copy_u8_dispNum],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_D, GET_BIT(SegNumbers[Copy_u8_dispNum],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_E, GET_BIT(SegNumbers[Copy_u8_dispNum],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_F, GET_BIT(SegNumbers[Copy_u8_dispNum],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_G, GET_BIT(SegNumbers[Copy_u8_dispNum],Local_u8_bit++));



}
#elif	(SEGMENT_COMMON==ANODE && TOW_SEGMENTS==0 && MULTIBLEXED_SEGMENTS==0)
void SEG_voidDisplay_D(u8 Copy_u8_dispNum)
{
	u8 Local_u8_bit=0;
	DIO_WritePin( SEG1_MUX_LED_A, ~GET_BIT(SegNumbers[Copy_u8_dispNum],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_B, ~GET_BIT(SegNumbers[Copy_u8_dispNum],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_C, ~GET_BIT(SegNumbers[Copy_u8_dispNum],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_D, ~GET_BIT(SegNumbers[Copy_u8_dispNum],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_E, ~GET_BIT(SegNumbers[Copy_u8_dispNum],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_F, ~GET_BIT(SegNumbers[Copy_u8_dispNum],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_G, ~GET_BIT(SegNumbers[Copy_u8_dispNum],Local_u8_bit++));

}
		/*	Displaying Hexadecimal numbers 	*/
void SEG_voidDisplay_H(u8 Copy_u8_dispNum)
{
	u8 Local_u8_bit=0;
	DIO_WritePin( SEG1_MUX_LED_A, ~GET_BIT(SegNumbers[Copy_u8_dispNum],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_B, ~GET_BIT(SegNumbers[Copy_u8_dispNum],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_C, ~GET_BIT(SegNumbers[Copy_u8_dispNum],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_D, ~GET_BIT(SegNumbers[Copy_u8_dispNum],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_E, ~GET_BIT(SegNumbers[Copy_u8_dispNum],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_F, ~GET_BIT(SegNumbers[Copy_u8_dispNum],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_G, ~GET_BIT(SegNumbers[Copy_u8_dispNum],Local_u8_bit++));


}
#elif	(SEGMENT_COMMON==CATHODE && TOW_SEGMENTS==1 && MULTIBLEXED_SEGMENTS==0)
void SEG_voidDisplay_D(u8 Copy_u8_dispNum)
{
	u8 Local_u8_bit=0;
	u8 Local_u8_low_digit=Copy_u8_dispNum%10;
	u8 Local_u8_high_digit=Copy_u8_dispNum/10;
	DIO_WritePin( SEG1_MUX_LED_A, GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_B, GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_C, GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_D, GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_E, GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_F, GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_G, GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	Local_u8_bit=0;
	DIO_WritePin( SEG2_LED_A, GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));
	DIO_WritePin( SEG2_LED_B, GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));
	DIO_WritePin( SEG2_LED_C, GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));
	DIO_WritePin( SEG2_LED_D, GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));
	DIO_WritePin( SEG2_LED_E, GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));
	DIO_WritePin( SEG2_LED_F, GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));
	DIO_WritePin( SEG2_LED_G, GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));

}
		/*	Displaying Hexadecimal numbers 	*/
void SEG_voidDisplay_H(u8 Copy_u8_dispNum)
{
	u8 Local_u8_bit=0;
	u8 Local_u8_low_digit=Copy_u8_dispNum%16;
	u8 Local_u8_high_digit=Copy_u8_dispNum/16;
	DIO_WritePin( SEG1_MUX_LED_A, GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_B, GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_C, GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_D, GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_E, GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_F, GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_G, GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	Local_u8_bit=0;
	DIO_WritePin( SEG2_LED_A, GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));
	DIO_WritePin( SEG2_LED_B, GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));
	DIO_WritePin( SEG2_LED_C, GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));
	DIO_WritePin( SEG2_LED_D, GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));
	DIO_WritePin( SEG2_LED_E, GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));
	DIO_WritePin( SEG2_LED_F, GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));
	DIO_WritePin( SEG2_LED_G, GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));

}
#elif	(SEGMENT_COMMON==ANODE && TOW_SEGMENTS==1 && MULTIBLEXED_SEGMENTS==0)

void SEG_voidDisplay_D(u8 Copy_u8_dispNum)
{
	u8 Local_u8_bit=0;
	u8 Local_u8_low_digit=Copy_u8_dispNum%10;
	u8 Local_u8_high_digit=Copy_u8_dispNum/10;
	DIO_WritePin( SEG1_MUX_LED_A,~GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_B,~GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_C,~GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_D,~GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_E,~GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_F,~GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_G,~GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	Local_u8_bit=0;
	DIO_WritePin( SEG2_LED_A,~GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));
	DIO_WritePin( SEG2_LED_B,~GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));
	DIO_WritePin( SEG2_LED_C,~GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));
	DIO_WritePin( SEG2_LED_D,~GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));
	DIO_WritePin( SEG2_LED_E,~GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));
	DIO_WritePin( SEG2_LED_F,~GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));
	DIO_WritePin( SEG2_LED_G,~GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));

}
		/*	Displaying Hexadecimal numbers 	*/
void SEG_voidDisplay_H(u8 Copy_u8_dispNum)
{
	u8 Local_u8_bit=0;
	u8 Local_u8_low_digit=Copy_u8_dispNum%16;
	u8 Local_u8_high_digit=Copy_u8_dispNum/16;
	DIO_WritePin( SEG1_MUX_LED_A,~GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_B,~GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_C,~GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_D,~GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_E,~GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_F,~GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_G,~GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	Local_u8_bit=0;
	DIO_WritePin( SEG2_LED_A,~GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));
	DIO_WritePin( SEG2_LED_B,~GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));
	DIO_WritePin( SEG2_LED_C,~GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));
	DIO_WritePin( SEG2_LED_D,~GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));
	DIO_WritePin( SEG2_LED_D,~GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));
	DIO_WritePin( SEG2_LED_E,~GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));
	DIO_WritePin( SEG2_LED_G,~GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));

}
#elif	(SEGMENT_COMMON==CATHODE && TOW_SEGMENTS==1 && MULTIBLEXED_SEGMENTS==1)

void SEG_voidDisplay_D(u8 Copy_u8_dispNum)
{
	u8 Local_u8_bit=0;
	u8 Local_u8_low_digit=Copy_u8_dispNum%10;
	u8 Local_u8_high_digit=Copy_u8_dispNum/10;
	DIO_WritePin(SEG1_MUX_EN,LOW);
	DIO_WritePin(SEG2_MUX_EN,HIGH);
	DIO_WritePin( SEG1_MUX_LED_A,GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_B,GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_C,GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_D,GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_E,GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_F,GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_G,GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	Local_u8_bit=0;
	/*		 	50:60 frame per second				*/
	Delay_ms(10);
	DIO_WritePin(SEG1_MUX_EN,HIGH);
	DIO_WritePin(SEG2_MUX_EN,LOW);
	DIO_WritePin( SEG1_MUX_LED_A,GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_B,GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_C,GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_D,GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_E,GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_F,GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_G,GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));
	Delay_ms(10);

}
		/*	Displaying Hexadecimal numbers 	*/
void SEG_voidDisplay_H(u8 Copy_u8_dispNum)
{
	u8 Local_u8_bit=0;
	u8 Local_u8_low_digit=Copy_u8_dispNum%16;
	u8 Local_u8_high_digit=Copy_u8_dispNum/16;
	DIO_WritePin(SEG1_MUX_EN,LOW);
	DIO_WritePin(SEG2_MUX_EN,HIGH);
	DIO_WritePin( SEG1_MUX_LED_A,GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_B,GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_C,GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_D,GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_E,GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_F,GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_G,GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	Local_u8_bit=0;
	/*		 	50:60 frame per second				*/
	Delay_ms(10);
	DIO_WritePin(SEG1_MUX_EN,HIGH);
	DIO_WritePin(SEG2_MUX_EN,LOW);
	DIO_WritePin( SEG1_MUX_LED_A,GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_B,GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_C,GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_D,GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_E,GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_F,GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_G,GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));
	Delay_ms(10);

}
#elif	(SEGMENT_COMMON==ANODE && TOW_SEGMENTS==1 && MULTIBLEXED_SEGMENTS==1)


void SEG_voidDisplay_D(u8 Copy_u8_dispNum)
{
	u8 Local_u8_bit=0;
	u8 Local_u8_low_digit=Copy_u8_dispNum%10;
	u8 Local_u8_high_digit=Copy_u8_dispNum/10;
	DIO_WritePin(SEG1_MUX_EN,LOW);
	DIO_WritePin(SEG2_MUX_EN,HIGH);
	DIO_WritePin( SEG1_MUX_LED_A,~GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_B,~GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_C,~GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_D,~GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_E,~GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_F,~GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_G,~GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	Local_u8_bit=0;
	/*		 	50:60 frame per second				*/
	Delay_ms(10);
	DIO_WritePin(SEG1_MUX_EN,HIGH);
	DIO_WritePin(SEG2_MUX_EN,LOW);
	DIO_WritePin( SEG1_MUX_LED_A,~GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_B,~GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_C,~GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_D,~GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_E,~GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_F,~GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_G,~GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));
	Delay_ms(10);

}
		/*	Displaying Hexadecimal numbers 	*/
void SEG_voidDisplay_H(u8 Copy_u8_dispNum)
{
	u8 Local_u8_bit=0;
	u8 Local_u8_low_digit=Copy_u8_dispNum%16;
	u8 Local_u8_high_digit=Copy_u8_dispNum/16;
	DIO_WritePin(SEG1_MUX_EN,LOW);
	DIO_WritePin(SEG2_MUX_EN,HIGH);
	DIO_WritePin( SEG1_MUX_LED_A,~GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_B,~GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_C,~GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_D,~GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_E,~GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_F,~GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_G,~GET_BIT(SegNumbers[Local_u8_low_digit],Local_u8_bit++));
	Local_u8_bit=0;
	/*		 	50:60 frame per second				*/
	Delay_ms(10);
	DIO_WritePin(SEG1_MUX_EN,HIGH);
	DIO_WritePin(SEG2_MUX_EN,LOW);
	DIO_WritePin( SEG1_MUX_LED_A,~GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_B,~GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_C,~GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_D,~GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_E,~GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_F,~GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));
	DIO_WritePin( SEG1_MUX_LED_G,~GET_BIT(SegNumbers[Local_u8_high_digit],Local_u8_bit++));
	Delay_ms(10);

}

#endif



