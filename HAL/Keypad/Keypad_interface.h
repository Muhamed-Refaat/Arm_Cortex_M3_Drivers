/*
 * Keypad_interface.h
 *
 *  Created on: Feb 9, 2021
 *      Author: Mohamed Allam
 */

#ifndef KEYPAD_HEADERS_KEYPAD_INTERFACE_H_
#define KEYPAD_HEADERS_KEYPAD_INTERFACE_H_

  /*  the No key or default return key when  No key is pressed '$' */
#define   NO_KEY     	  '$'

u8 Keypad_u8_GetKey(void);

#endif /* KEYPAD_HEADERS_KEYPAD_INTERFACE_H_ */
