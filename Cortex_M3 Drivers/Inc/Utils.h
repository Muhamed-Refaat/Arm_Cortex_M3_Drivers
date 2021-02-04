/*
 * Utils.h
 *
 * Created: 01/12/2020 11:20:21 ص
 *  Author: Mohamed Allam
 */ 


#ifndef UTILS_H_
#define UTILS_H_



#define  GET_BIT(reg,bit) ((reg>>bit)&1)
#define  SET_BIT(reg,bit) (reg= ((reg | (1<<bit))))
#define  CLR_BIT(reg,bit)  reg=(reg & (~(1<<bit)))
#define  TOG_BIT(reg,bit) (reg= ((reg ^ (1<<bit))))
#define  WRITE_BIT(reg,bit ,value)  reg= ((reg & (~(1<<bit))) | (value<<bit))  //make sure the bitth is zero and then ored with value if 0 be 0 and if value 1 be 1

#define  WRITE_ARM_PIN(reg,pin,value)	 	\
(reg=((reg &(~((u32)0xF<<(pin * 4)))) | ((u32)value<<(pin *4)))) /* pin =0:8 */





#endif /* UTILS_H_ */
