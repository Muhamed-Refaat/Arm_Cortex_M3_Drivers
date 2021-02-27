/*
 * ADC_interface.h
 *
 *  Created on: Feb 13, 2021
 *      Author: Eslam
 */

#ifndef ADC_ADC_INTERFACE_H_
#define ADC_ADC_INTERFACE_H_

void ADC_voidInit(void);
void ADC_voidChannelSample(u8 Copy_u8Chanel,u8 Copy_u8SampleTime);
u16 ADC_u16GetValue(u8 chanel);

u32 POT_VoltReadPercent(u8 chanel);

u32 POT_PercentRead(u8 chanel);

u16 LDR_RatioRead(u8 chanel);

u32 LDR_PercentRead(u8 chanel);



#endif /* ADC_ADC_INTERFACE_H_ */
