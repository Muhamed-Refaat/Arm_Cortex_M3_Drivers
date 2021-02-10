/*
 * LCD_interface.h
 *
 *  Created on: Feb 9, 2021
 *      Author: Mohamed Allam
 */

#ifndef LCD_HEADERS_LCD_INTERFACE_H_
#define LCD_HEADERS_LCD_INTERFACE_H_


typedef enum {
	MAN=0,
	HAPPY_MAN,
	DEAD_MAN_right,
	ARROW,
	DAMAGE,
	RECT,
	KA,
	ALPH,
	SHARTA,
	NOON,
	DAL,
	SEEN,
	TAA,
	A3een,
	SMILE,
	MUSIC,
	BILL,
	HEART,
	HOLO_HART,
}Custom_Char_type;

/* location 0,1,2, ...,7 (only 8 valid empty locations to create char in them) */
void LCD_CreateChar(Custom_Char_type patt,u8 location);
void LCD_Init(void);
void LCD_WriteChar(u8 ch);
void LCD_WriteString(u8*str);
void LCD_WriteNumber(s64 num);
void LCD_SetCursor(u8 line ,u8 cell);
void LCD_WriteNumberBinary(u16 num);
void LCD_WriteNumberBinary_16D(u16 num);
void LCD_WriteNumberBinary_8D(u8 num);
void LCD_WriteNumberHex(u8 num);
void LCD_WriteNumber_4D( u16 num);
void LCD_Clear(void);
void LCD_WriteCharXY(u8 line,u8 cell,u8 ch);
void LCD_WriteStringXY(u8 line,u8 cell,u8* str);
void LCD_WriteNumberXY(u8 line,u8 cell,s64 num );

#endif /* LCD_HEADERS_LCD_INTERFACE_H_ */
