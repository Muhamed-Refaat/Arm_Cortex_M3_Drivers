/*
 * DMA_private.h
 *
 *  Created on: Feb 14, 2021
 *      Author: Mohamed Allam
 */

#ifndef DMA_HEADERS_DMA_PRIVATE_H_
#define DMA_HEADERS_DMA_PRIVATE_H_

typedef struct {

 volatile u32 ISR;
 volatile u32 IFCR;
 volatile u32 CCR1;
 volatile u32 CNDTR1;
 volatile u32 CPAR1;
 volatile u32 CMAR1;
 volatile u32 RESERVED1;
 volatile u32 CCR2;
 volatile u32 CNDTR2;
 volatile u32 CPAR2;
 volatile u32 CMAR2;
 volatile u32 RESERVED2;
 volatile u32 CCR3;
 volatile u32 CNDTR3;
 volatile u32 CPAR3;
 volatile u32 CMAR3;
 volatile u32 RESERVED3;
 volatile u32 CCR4;
 volatile u32 CNDTR4;
 volatile u32 CPAR4;
 volatile u32 CMAR4;
 volatile u32 RESERVED4;
 volatile u32 CCR5;
 volatile u32 CNDTR5;
 volatile u32 CPAR5;
 volatile u32 CMAR5;
 volatile u32 RESERVED5;
 volatile u32 CCR6;
 volatile u32 CNDTR6;
 volatile u32 CPAR6;
 volatile u32 CMAR6;
 volatile u32 RESERVED6;
 volatile u32 CCR7;
 volatile u32 CNDTR7;
 volatile u32 CPAR7;
 volatile u32 CMAR7;
 volatile u32 RESERVED7;



}DMA_1_type;


#define				DMA    ((DMA_1_type *)0x40020000)

#endif /* DMA_HEADERS_DMA_PRIVATE_H_ */
