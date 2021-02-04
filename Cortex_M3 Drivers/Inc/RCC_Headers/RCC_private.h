/*
 * RCC_private.h
 *
 *  Created on: Feb 2, 2021
 *      Author: Boon
 */
/*		File Guard											*/
#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

/*			Base Address For RCC							*/
#define		RCC_BASE_ADD		(0x40021000)

/*			RCC Registers		(BASE ADD + Offset)			*/
#define 	RCC_CR				*((u32 * )(RCC_BASE_ADD + 0x00))
#define 	RCC_CFGR			*((u32 * )(RCC_BASE_ADD + 0x04))
#define 	RCC_CIR				*((u32 * )(RCC_BASE_ADD + 0x08))
#define 	RCC_APB2RSTR		*((u32 * )(RCC_BASE_ADD + 0x0C))
#define 	RCC_APB1RSTR		*((u32 * )(RCC_BASE_ADD + 0x10))
#define 	RCC_AHBENR			*((u32 * )(RCC_BASE_ADD + 0x14))
#define 	RCC_APB2ENR			*((u32 * )(RCC_BASE_ADD + 0x18))
#define 	RCC_APB1ENR			*((u32 * )(RCC_BASE_ADD + 0x1C))
#define 	RCC_BDCR			*((u32 * )(RCC_BASE_ADD + 0x20))
#define 	RCC_CSR				*((u32 * )(RCC_BASE_ADD + 0x24))

#define 	RCC_HSI 		1
#define 	RCC_HSE 		3
#define 	RCC_PLL 		5
#define		RCC_HSE_2		6
#define     RCC_CRYSTAL		1
#define     RCC_RC			3
/*************************************************************************
 * *********************Important Hotkeys*********************************
 *  																	 *
 * Zoom in -> ctrl+ shift+ +											 *
 * Zoom out -> ctrl+ shift + -											 *
 * Autocomplete -> ctrl+ space (content assistant feature )  			 *
 * copy line and paste -> ctrl+ E  									  	 *
 * cut line -> ctrl+ X 													 *
 * comment/ uncomment -> ctrl+ shift+ C
 * Alternate Corser -> Alt+ Shift + A									 *
 * Align Text 	-> Ctrl+ i												 *
 *************************************************************************/

/*///////////////////////////////////////////////////////////////////////////////////
 *..............Developer notes...........................
 * 34an 23mel driver le prepheral 2wel 7aga nfaker feha hya
 * eh el wazyef bta3et el prepheral da aw bnsta5emo leh
 * b3d ked bn3mel el APi`s 34an  n5ly aw nesahel el user y4t3`al bel driver
 *  wywazef el prepherial da bmzago
 * ...........................................................................
 *  M3 el Arm lazem 2wel 7aga n4of el preipheral da 3la anho BUS AHB or APB1 ,etc
 *  Then get its base address and Register offset  remeber to init all 34an
 *  kol el prepherials has RCC level control
 *  1-Privte file  All register addresses and Developer designs
 *  2- Interface file  function prototypes seen by user (Go for Naming convention)
 *  3- config file to allow user set configurations                         */



#endif /* RCC_PRIVATE_H_ */
