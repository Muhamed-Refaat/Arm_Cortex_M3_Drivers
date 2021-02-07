/*
 * SEG_interface.h
 *
 *  Created on: Feb 7, 2021
 *      Author: Mohamed Allam
 */

#ifndef SEG_HEADERS_SEG_INTERFACE_H_
#define SEG_HEADERS_SEG_INTERFACE_H_

/* SEG1 Connected pins / Multiplexed 2 segments  */
#define			SEG1_MUX_LED_A 		PINA0
#define			SEG1_MUX_LED_B 		PINA1
#define			SEG1_MUX_LED_C 		PINA2
#define			SEG1_MUX_LED_D 		PINA3
#define			SEG1_MUX_LED_E 		PINA4
#define			SEG1_MUX_LED_F 		PINA5
#define			SEG1_MUX_LED_G 		PINA6
/*			SEG2_Pins							*/
#define			SEG2_LED_A 			PINA7
#define			SEG2_LED_B 			PINA8
#define			SEG2_LED_C 			PINA9
#define			SEG2_LED_D 			PINA10
#define			SEG2_LED_E 			PINA11
#define			SEG2_LED_F 			PINA12
#define			SEG2_LED_G 			PINA13

		/*	Displaying Decimal numbers 		*/
void SEG_voidDisplay_D(u8 Copy_u8_dispNum);
		/*	Displaying Hexadecimal numbers 	*/
void SEG_voidDisplay_H(u8 Copy_u8_dispNum) ;


#endif /* SEG_HEADERS_SEG_INTERFACE_H_ */
