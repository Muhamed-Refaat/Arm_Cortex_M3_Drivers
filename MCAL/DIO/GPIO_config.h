
#ifndef GPIO_CONFIG_H_
#define GPIO_CONFIG_H_

/*
 * ********************************************************
 * Function mode could be : 							  *
 * 							1- ENUM						  *
 * 							2-PREPROCESSOR				  *
 * ************************** *****************************
 */
#define  DIO_FUNCTION_MODE_SELECT			ENUM
/*************************************************************/
/*					PINS INITIALIZATION ARRAY				*/
/******************************************************************
 * Each Pin can be settled to one of the following states:-       *
 *      	1-	DIO_E_INPUT_ANALOG      	                      *
 *			2-  DIO_E_INPUT_FLOATING                              *
 *			3-  DIO_E_INPUT_PULL_UP                               *
 *			4-  DIO_E_INPUT_PULL_DOWN                             *
 *			5-  DIO_E_OUTPUT_2MHZ_PUSH                            *
 *			6-  DIO_E_OUTPUT_2MHZ_PULL                            *
 *			7-  DIO_E_OUTPUT_2MHZ_OD	                          *
 *			8-  DIO_E_OUTPUT_2MHZ_AF_PP                           *
 *			9-  DIO_E_OUTPUT_2MHZ_AF_OD                           *
 *			10- DIO_E_OUTPUT_10MHZ_PUSH                           *
 *			11- DIO_E_OUTPUT_10MHZ_PULL                           *
 *			15- DIO_E_OUTPUT_10MHZ_OD                             *
 *			16- DIO_E_OUTPUT_10MHZ_AF_P                           *
 *			17- DIO_E_OUTPUT_10MHZ_AF_O                           *
 *			18- DIO_E_OUTPUT_50MHZ_PUSH                           *
 *			19- DIO_E_OUTPUT_50MHZ_PULL                           *
 *			20- DIO_E_OUTPUT_50MHZ_OD                             *
 *			21- DIO_E_OUTPUT_50MHZ_AF_P                           *
 *			22-DIO_E_OUTPUT_50MHZ_AF_O							  *
 *			output with LOW port A                             						  *
 *			PINB4 , PINA15 ON board
 * index is pen number and values are statues                     *
 * ****************************************************************
 */
const DIO_PinStatus_type  PinsStatusArray[TOTAL_PINS]={
	DIO_E_OUTPUT_2MHZ_PUSH,          /* Port A Pin 0  */
	DIO_E_OUTPUT_2MHZ_PUSH,         /* Port A Pin 1  */
	DIO_E_OUTPUT_2MHZ_PUSH,         /* Port A Pin 2  */
	DIO_E_OUTPUT_2MHZ_PUSH,         /* Port A Pin 3  */
	DIO_E_OUTPUT_2MHZ_PUSH,         /* Port A Pin 4  */
	DIO_E_OUTPUT_2MHZ_PUSH,         /* Port A Pin 5  */
	DIO_E_OUTPUT_2MHZ_PUSH,          /* Port A Pin 6  */
	DIO_E_OUTPUT_2MHZ_PUSH,         /* Port A Pin 7  */
	DIO_E_OUTPUT_2MHZ_PUSH,         /* Port A Pin 8  */
	DIO_E_OUTPUT_2MHZ_PUSH,         /* Port A Pin 9  */
	DIO_E_OUTPUT_2MHZ_PUSH,         /* Port A Pin 10 */
	DIO_E_OUTPUT_2MHZ_PUSH,         /* Port A Pin 11 */
	DIO_E_OUTPUT_2MHZ_PUSH,         /* Port A Pin 12 */
	DIO_E_OUTPUT_2MHZ_PUSH,         /* Port A Pin 13 */
	DIO_E_OUTPUT_2MHZ_PUSH,         /* Port A Pin 14 */
	DIO_E_OUTPUT_2MHZ_PULL,         /* Port A Pin 15 */
	DIO_E_OUTPUT_2MHZ_PUSH,         /* Port B Pin 0  */
	DIO_E_OUTPUT_2MHZ_PUSH,         /* Port B Pin 1  */
	DIO_E_OUTPUT_2MHZ_PUSH,	        /* Port B Pin 2  */
	DIO_E_OUTPUT_2MHZ_PUSH,	        /* Port B Pin 3  */
	DIO_E_OUTPUT_2MHZ_PULL,	        /* Port B Pin 4  */
	DIO_E_OUTPUT_2MHZ_PUSH,	        /* Port B Pin 5  */
	DIO_E_OUTPUT_2MHZ_PUSH,	        /* Port B Pin 6  */
	DIO_E_OUTPUT_2MHZ_PUSH,	        /* Port B Pin 7  */
	DIO_E_OUTPUT_2MHZ_PUSH,         /* Port B Pin 8  */
	DIO_E_OUTPUT_2MHZ_PUSH,         /* Port B Pin 9  */
	DIO_E_OUTPUT_2MHZ_PUSH,	        /* Port B Pin 10 */
	DIO_E_OUTPUT_2MHZ_PUSH,	        /* Port B Pin 11 */
	DIO_E_OUTPUT_2MHZ_PUSH,	        /* Port B Pin 12 */
	DIO_E_OUTPUT_2MHZ_PUSH,	        /* Port B Pin 13 */
	DIO_E_OUTPUT_2MHZ_PUSH,	        /* Port B Pin 14 */
	DIO_E_OUTPUT_2MHZ_PUSH,	        /* Port B Pin 15 */
	DIO_E_OUTPUT_2MHZ_PUSH,	        /* Port C Pin 0  */
	DIO_E_OUTPUT_2MHZ_PUSH,	        /* Port C Pin 1  */
	DIO_E_OUTPUT_2MHZ_PUSH,	        /* Port C Pin 2  */
	DIO_E_OUTPUT_2MHZ_PUSH,	        /* Port C Pin 3  */
	DIO_E_OUTPUT_2MHZ_PUSH,	        /* Port C Pin 4  */
	DIO_E_OUTPUT_2MHZ_PUSH,	        /* Port C Pin 5  */
	DIO_E_OUTPUT_2MHZ_PUSH,	        /* Port C Pin 6  */
	DIO_E_OUTPUT_2MHZ_PUSH,	        /* Port C Pin 7  */
	DIO_E_OUTPUT_2MHZ_PUSH,	        /* Port C Pin 8  */
	DIO_E_OUTPUT_2MHZ_PUSH,	        /* Port C Pin 9  */
	DIO_E_OUTPUT_2MHZ_PUSH,	        /* Port C Pin 10 */
	DIO_E_OUTPUT_2MHZ_PUSH,	        /* Port C Pin 11 */
	DIO_E_OUTPUT_2MHZ_PUSH,	        /* Port C Pin 12 */
	DIO_E_OUTPUT_2MHZ_PUSH,	        /* Port C Pin 13 */
	DIO_E_OUTPUT_2MHZ_PULL,	        /* Port C Pin 14 */
	DIO_E_OUTPUT_2MHZ_PUSH,	        /* Port C Pin 15 */
};


#endif /* GPIO_CONFIG_H_ */
