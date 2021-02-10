/*
 * LCD_private.h
 *
 *  Created on: Feb 9, 2021
 *      Author: Mohamed Allam
 */

#ifndef LCD_HEADERS_LCD_PRIVATE_H_
#define LCD_HEADERS_LCD_PRIVATE_H_

#define   BYTE           1
#define   NAPLE          2

//0x0f,0x0e display ,cursor

#define  DISPLAY_COURSOR        0x0f
#define  NO_COURSOR      	    0x0c

#define  SET_SCREEN				//8 bit mode,font5*7,2 lines To Be cont


unsigned char Sadman_pattren[8]= {0x0e,0x0e,0x04,0x04,0x1f,0x04,0x0a,0x0a};
unsigned char HappyMman_Pattern[8]= {0x0e,0x0e,0x15,0x0e,0x04,0x04,0x0a,0x11};


u8 dead_man_right_pattren[8]={         // 2 pattrens
	(0b0011000),
	(0b01011000),
	(0b00101111),
	(0b00111101),
	(0b00101111),
	(0b01011000),
	(0b00110000)
};
u8 arrow_pattren[8]={
	(0b00000000),
	(0b00011100),
	(0b00001110),
	(0b00000111),
	(0b00001110),
	(0b00011100),
	(0b00000000)
};
u8 damage_pattren[8]={
	(0b00000000),
	(0b00001100),
	(0b00011011),
	(0b00010001),
	(0b00001010),
	(0b00001100),
	(0b00010100)
};

u8 rect_pattren[8]={
	(0b00011111),
	(0b00011111),
	(0b00011111),
	(0b00011111),
	(0b00011111),
	(0b00011111),
	(0b00011111),
	(0b00011111)
};


u8 HoloHeart_pattren[8] = { 0x00, 0x0A, 0x15, 0x11, 0x0A, 0x04, 0x00, 0x00 };  /* Custom char set for alphanumeric LCD Module */
u8 Phone_pattren[8] = { 0x04, 0x1F, 0x11, 0x11, 0x1F, 0x1F, 0x1F, 0x1F };
u8 Bill_pattren[8] = { 0x04, 0x0E, 0x0E, 0x0E, 0x1F, 0x00, 0x04, 0x00 };
u8 Speaker_pattren[8] = { 0x01, 0x03, 0x07, 0x1F, 0x1F, 0x07, 0x03, 0x01 };
u8 Music_pattren[8] = { 0x01, 0x03, 0x05, 0x09, 0x09, 0x0B, 0x1B, 0x18 };
u8 Fesha_pattren[8] = { 0x0A, 0x0A, 0x1F, 0x11, 0x11, 0x0E, 0x04, 0x04 };
u8 Smile_pattren[8] = { 0x00, 0x00, 0x0A, 0x00, 0x04, 0x11, 0x0E, 0x00 };
u8  Hreat_pattern[8] = { 0x00, 0x0A, 0x1F, 0x1F, 0x0E, 0x04, 0x00, 0x00 };


u8 Ka_pattren[8]={

	(0b00000110),
	(0b00000000),
	(0b00000000),
	(0b00001111),
	(0b00001111),
	(0b00000001),
	(0b00011111),
	(0b00000000)

};
u8 Aa_pattren[8]={

	(0b00000011),
	(0b00000011),
	(0b00000011),
	(0b00000011),
	(0b00000011),
	(0b00000011),
	(0b00000011),
	(0b00000000)

};
u8 Sharta_pattren[8]={

	(0b00000000),
	(0b00000000),
	(0b00000000),
	(0b00000000),
	(0b00000000),
	(0b00000000),
	(0b00011111),
	(0b00000000)

};
u8 Noon_pattren[8]={

	(0b00000110),
	(0b00000000),
	(0b00000000),
	(0b00010001),
	(0b00010001),
	(0b00010001),
	(0b00011111),
	(0b00000000)

};
u8 Seen_pattren[8]={

	(0b00000000),
	(0b00000000),
	(0b00000000),
	(0b00010101),
	(0b00010101),
	(0b00010101),
	(0b00011111),
	(0b00000000)

};
u8 a3_pattren[8]={

	(0b00000000),
	(0b00000000),
	(0b00000000),
	(0b00011111),
	(0b00010000),
	(0b00010000),
	(0b00011111),
	(0b00000000)

};

u8 Dal_pattren[8]={

	(0b00000000),
	(0b00000000),
	(0b00000000),
	(0b00000011),
	(0b00000011),
	(0b00000011),
	(0b00011111),
	(0b00000000)

};
u8 Taa_pattren[8]={

	(0b00011011),
	(0b00000000),
	(0b00000000),
	(0b00011111),
	(0b00011011),
	(0b00011011),
	(0b00011111),
	(0b00000000)

};


#endif /* LCD_HEADERS_LCD_PRIVATE_H_ */
