
#include "StdTypes.h"
#include "Utils.h"
#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_Config.h"
#include "STK_interface.h"




void ADC_voidInit(void)
{
	/*ADC1 Configration */
	/*Enable ADC*/
	SET_BIT(ADC -> CR2,0);
	/*ADC MODE */
#if ADC_MODE == ADC_INDEPENDENT_MODE

	CLR_BIT(ADC -> CR1 ,8);

#elif 	ADC_MODE ==  ADC_DUAL_MODE
	SET_BIT(ADC -> CR1 ,8);
#endif


	/*DATA ALIGN */
#if ADC_DATAA_ALIGN  == ADC_RIGHT_ALIGN
	CLR_BIT(ADC -> CR2 ,11);
#elif ADC_DATAA_ALIGN  == ADC_LEFT_ALIGN
	SET_BIT(ADC -> CR2 ,11);
#endif


	/*COUNTINUOUS OR SINGEL MODE*/
#if ADC_COUNTINUOUS_CON_MODE == ADC_SINGEL_CONVERSION
	CLR_BIT(ADC -> CR1 ,1);
#elif ADC_COUNTINUOUS_CON_MODE == ADC_COUNTINUOUS_CONVERSION
	SET_BIT(ADC -> CR1 ,1);
#endif

	/*CHANNEL Sequence */
/*
	ADC ->SQR3 &=0;
	ADC ->SQR2 &=0;
	ADC ->SQR3 = (SEQUENCE_5<<25)|(SEQUENCE_4<<20)|(SEQUENCE_3<<15)|(SEQUENCE_2<<10)|(SEQUENCE_1<<5)|(SEQUENCE_0);
	ADC ->SQR2 = (SEQUENCE_9<<15)|(SEQUENCE_8<<10)|(SEQUENCE_7<<5)|(SEQUENCE_6);
*/

	/*CHOSE Length of ADC Raglaer channels*/
	ADC->  SQR1  &=0xFF0FFFFF;
	ADC -> SQR1 |=( (ADC_CHANNELS_NUMBER-1) << 20 );




}


void ADC_voidChannelSample(u8 Copy_u8Chanel,u8 Copy_u8SampleTime)
{
	if(Copy_u8Chanel<9)
	{
		ADC -> SMPR2 |= (u32)Copy_u8SampleTime << (3 * Copy_u8Chanel);
	}
	else if (Copy_u8Chanel==9)
	{
		ADC -> SMPR1 |= (u32)Copy_u8SampleTime ;
	}

}

u16 ADC_u16GetValue(u8 chanel)
{
	u16 temp;
	/*Start Conv*/

	ADC ->SQR3 = chanel;
	SET_BIT(ADC -> CR2,0);
	SET_BIT(ADC -> CR2 ,22);

	while(GET_BIT(ADC -> SR,1)==0);
	temp =(u16)ADC -> DR;
	CLR_BIT(ADC -> SR,1);
	return temp;
}

u32 POT_VoltReadPercent(u8 chanel)
{
	u64 buffer;
	buffer=ADC_u16GetValue(chanel);
	buffer=((buffer*33)/4096);
	//buffer=(((buffer * 5000)/1024));        /*Change range from 0~1024 to 0~5000mv*/
	return buffer;
}
u32 POT_PercentRead(u8 chanel)
{
	    u16 adc=ADC_u16GetValue(chanel);
		u16 potPercent=(adc*100/4096); //not sure ???
		return potPercent;
}
u16 LDR_RatioRead(u8 chanel)
{
	u16 adc=ADC_u16GetValue(chanel);
	u16 LdrRatio=0;

	if(adc>=970)									LdrRatio=9;
	else if(adc<970 && adc>=930)					LdrRatio=8;
	else if(adc<930 && adc>=850)					LdrRatio=7;
	else if(adc<850 && adc>=680)					LdrRatio=6;
	else if(adc<680 && adc>=500)					LdrRatio=5;
	else if(adc<500 && adc>=460)					LdrRatio=4;
	else if(adc<460 && adc>=400)					LdrRatio=3;
	else if(adc<400 && adc>=300)					LdrRatio=2;
	else if(adc<300 && adc>=160)					LdrRatio=1;
	else if(adc<=150)								LdrRatio=0;
	return LdrRatio;
}
u32 LDR_PercentRead(u8 chanel)
{
	u16 adc=ADC_u16GetValue(chanel);
	u32 LdrPercent=(adc*100/4096);
	return LdrPercent;
}

