/*
 * LCD_Config.h
 *
 *  Created on: Feb 9, 2021
 *      Author: Mohamed Allam
 */

#ifndef LCD_HEADERS_LCD_CONFIG_H_
#define LCD_HEADERS_LCD_CONFIG_H_

/*************************************************************************
 * LCD MODE can be   NAPLE   if LCD is connected via 4 data Leads(D4:D7) *
 * either it can be   BYTE   if LCD is connected via 8 data Leads(D0:D7) *
 * 																		 *
 * ***********************************************************************
 */


#define  MODE_LCD   NAPLE

/***********************PIN Config for BYTE mode ***********************************/
#if MODE_LCD == BYTE
#define  LCD_PORT	  DIO_PORTA

#define  RS       		PINB1
#define  E        		PINB0
/**********************PIN Config for NAPLE mode ***********************************/
#else
#define  D4				PINA3
#define  D5				PINA4
#define  D6				PINA5
#define  D7				PINA6
#define  RS				PINA1
#define  E				PINA2
#endif
/***************************END*****************************************************/



#endif /* LCD_HEADERS_LCD_CONFIG_H_ */
