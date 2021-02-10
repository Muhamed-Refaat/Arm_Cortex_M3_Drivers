/*
 * Keypad_Config.h
 *
 *  Created on: Feb 9, 2021
 *      Author: Mohamed Allam
 */

#ifndef KEYPAD_HEADERS_KEYPAD_CONFIG_H_
#define KEYPAD_HEADERS_KEYPAD_CONFIG_H_

/****************************************************************************
 *   1)  The user may pick which char to get after pressing a certain key	*
 *      from the Keys Array.												*
 *      																	*
 *   2)  The pins of the keypad input/output must be next to each other.	*
 *  																		*
 *   																.		*
 ****************************************************************************
 */

#define   FIRST_INPUT    PINA8
#define   FIRST_OUTPUT   PINB4

static  const u8 keys[4][4]={{'7','8','9','/'},
							{'4','5','6','*'},
							{'1','2','3','-'},
							{'c','0','=','+'}};



#endif /* KEYPAD_HEADERS_KEYPAD_CONFIG_H_ */
