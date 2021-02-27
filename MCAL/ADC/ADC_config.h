/*
 * ADC_config.h
 *
 *  Created on: Feb 13, 2021
 *      Author: Eslam
 */

#ifndef ADC_ADC_CONFIG_H_
#define ADC_ADC_CONFIG_H_


/*    ADC_RIGHT_ALIGN
      ADC_LEFT_ALIGN     */
#define ADC_DATAA_ALIGN    ADC_RIGHT_ALIGN


/*       ADC_INDEPENDENT_MODE
         ADC_DUAL_MODE          */
#define ADC_MODE     ADC_INDEPENDENT_MODE


/* this number from 1 to 10 channel */
#define ADC_CHANNELS_NUMBER       1


 /*ADC_COUNTINUOUS_CON_MODE_DISABLE
   ADC_COUNTINUOUS_CON_MODE_ENABLE   */
#define   ADC_COUNTINUOUS_CON_MODE ADC_SINGEL_CONVERSION


/*CHANNEL Sequence */

#define      SEQUENCE_0        CHANNEL_0
#define      SEQUENCE_1        CHANNEL_1
#define      SEQUENCE_2        CHANNEL_2
#define      SEQUENCE_3        CHANNEL_3
#define      SEQUENCE_4        CHANNEL_4
#define      SEQUENCE_5        CHANNEL_5
#define      SEQUENCE_6        CHANNEL_6
#define      SEQUENCE_7        CHANNEL_7
#define      SEQUENCE_8        CHANNEL_8
#define      SEQUENCE_9        CHANNEL_9


#endif /* ADC_ADC_CONFIG_H_ */
