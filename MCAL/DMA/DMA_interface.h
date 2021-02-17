/*
 * DMA_interface.h
 *
 *  Created on: Feb 14, 2021
 *      Author: Mohamed Allam
 */

#ifndef DMA_HEADERS_DMA_INTERFACE_H_
#define DMA_HEADERS_DMA_INTERFACE_H_

typedef enum {
	DMA_CHANNEL1,
	DMA_CHANNEL2,
	DMA_CHANNEL3,
	DMA_CHANNEL4,
	DMA_CHANNEL5,
	DMA_CHANNEL6,
	DMA_CHANNEL7,
	DMA_TOTAL_CHANNELS
}DMA_Channel_type;

typedef enum {
	DMA_LOW=0,
    DMA_MEDIUM,
    DMA_HIGH,
    DMA_VERY_HIGH,
}DMA_ChannelPriorityLevl_type;


typedef enum {
	DMA_8BITS=0,
	DMA_16BITS,
	DMA_32BITS,

}DMA_PrephMemorySize_type;

typedef enum {
	DMA_INCREMENT_DISABLE=0,
	DMA_INCREMENT_ENABLE,
}DMA_PrephMemoryIncMode_type;


typedef enum {
	DMA_CIRCULAR_DISABLE=0,
	DMA_CIRCULAR_ENABLE,
}DMA_CircularMode_type;


typedef enum {
	DMA_MEMORY_TO_MEMORY=0,
	DMA_MEMORY_TO_PREPHERIAL,
	DMA_PREPHERIAL_TO_PREPHERIAL,
	DMA_PREPHERIAL_TO_MEMORY,
}DMA_SetDirection_type;



void DMA_voidChannelInit(DMA_Channel_type channel ,DMA_ChannelPriorityLevl_type periority, DMA_PrephMemorySize_type prephsize , DMA_PrephMemorySize_type memsize, DMA_PrephMemoryIncMode_type prephinc, DMA_PrephMemoryIncMode_type MemInc, DMA_CircularMode_type  Circular);
void DMA_voidSetSourceDestinationAddresses(DMA_Channel_type channel,DMA_SetDirection_type direction,u32*  Ref_u32_SourceAddress,u32* Ref_u32_DestinationAddress ,u16 Copy_u16_NumberOfItems );
void DMA_voidChannelEnable(DMA_Channel_type channel);
void DMA_voidChannelReconfigurePeriority(DMA_Channel_type channel,DMA_ChannelPriorityLevl_type periority);
void DMA_voidChannelDisable(DMA_Channel_type channel);
void DMA_voidInit(void);
/******************************* STABLE APIs *****************************************/
void DMA_voidSetCallBack(DMA_Channel_type channel , void(*pf)(void));
void DMA_voidHTIFEnable(DMA_Channel_type channel);
void DMA_voidHTIFDisable(DMA_Channel_type channel);
void DMA_voidTCIFEnable(DMA_Channel_type channel);
void DMA_voidTCIFDisable(DMA_Channel_type channel);
void DMA_voidTEIFEnable(DMA_Channel_type channel);
void DMA_voidTEIFDisable(DMA_Channel_type channel);
/************************************************************************************/

#endif /* DMA_HEADERS_DMA_INTERFACE_H_ */
