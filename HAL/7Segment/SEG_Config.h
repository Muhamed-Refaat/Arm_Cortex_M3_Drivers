/*
 * SEG_Config.h
 *
 *  Created on: Feb 7, 2021
 *      Author: Mohamed Allam
 */

#ifndef SEG_HEADERS_SEG_CONFIG_H_
#define SEG_HEADERS_SEG_CONFIG_H_

/****************************************************************
 *	Select if the segment used are common CATHODE or ANODE	 	*
 * 	Put 1 to active  0 to de_active the configuration			*
 * 	if there are tow Segments & multiplexed segments			*						 	*
 * **************************************************************
 */
#define			SEGMENT_COMMON					   	 CATHODE
#define			TOW_SEGMENTS							0
#define 		MULTIBLEXED_SEGMENTS					0


/* SEG1 Connected pins / Multiplexed 2 segments  */
#define			SEG1_MUX_LED_A 		PINA0
#define			SEG1_MUX_LED_B 		PINA1
#define			SEG1_MUX_LED_C 		PINA2
#define			SEG1_MUX_LED_D 		PINA3
#define			SEG1_MUX_LED_E 		PINA4
#define			SEG1_MUX_LED_F 		PINA5
#define			SEG1_MUX_LED_G 		PINA6
#define			SEG1_MUX_EN 		PINB4
#define			SEG2_MUX_EN 		PINA15

/*				SEG2_Pins						*/
#define			SEG2_LED_A 			PINA7
#define			SEG2_LED_B 			PINA8
#define			SEG2_LED_C 			PINA9
#define			SEG2_LED_D 			PINA10
#define			SEG2_LED_E 			PINA11
#define			SEG2_LED_F 			PINA12
#define			SEG2_LED_G 			PINA13


#endif /* SEG_HEADERS_SEG_CONFIG_H_ */
