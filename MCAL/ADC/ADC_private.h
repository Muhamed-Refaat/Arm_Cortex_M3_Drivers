/*
 * ADC_private.h
 *
 *  Created on: Feb 13, 2021
 *      Author: Eslam
 */

#ifndef ADC_ADC_PRIVATE_H_
#define ADC_ADC_PRIVATE_H_

typedef struct
{
	volatile u32 	SR;
	volatile u32	CR1;
	volatile u32 	CR2;
	volatile u32	SMPR1;
	volatile u32 	SMPR2;
	volatile u32	JOFR1;
	volatile u32 	JOFR2;
	volatile u32	JOFR3;
	volatile u32 	JOFR4;
	volatile u32	HTR;
	volatile u32 	LTR;
	volatile u32	SQR1;
	volatile u32	SQR2;
	volatile u32	SQR3;
	volatile u32 	JSQR;
	volatile u32	JDR1;
	volatile u32 	JDR2;
	volatile u32	JDR3;
	volatile u32	JDR4;
	volatile u32	DR;

}ADC_Type;

#define 	ADC 		((ADC_Type *)0x40012400)    //APB2



#define  ADC_COUNTINUOUS_CONVERSION            1
#define  ADC_SINGEL_CONVERSION                 2


#define     ADC_RIGHT_ALIGN        2
#define     ADC_LEFT_ALIGN         1


#define ADC_INDEPENDENT_MODE       1
#define ADC_DUAL_MODE              2


#define      CHANNEL_0       0
#define      CHANNEL_1       1
#define      CHANNEL_2       2
#define      CHANNEL_3       3
#define      CHANNEL_4       4
#define      CHANNEL_5       5
#define      CHANNEL_6       6
#define      CHANNEL_7       7
#define      CHANNEL_8       8
#define      CHANNEL_9       9

#endif
