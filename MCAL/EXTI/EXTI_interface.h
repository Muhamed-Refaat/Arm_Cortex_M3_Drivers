

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_


typedef enum{
	EXTI_L0=0,
	EXTI_L1,
	EXTI_L2,
	EXTI_L3,
	EXTI_L4,
	EXTI_L5,
	EXTI_L6,
	EXTI_L7,
	EXTI_L8,
	EXTI_L9,
	EXTI_L10,
	EXTI_L11,
	EXTI_L12,
	EXTI_L13,
	EXTI_L14,
	EXTI_L15,
	EXTI_TOTAL_LINES

}EXTI_LinetNum_type;

typedef enum {
	RAISING=3,
	FALLING=1,
	ANY_LOGIC_CHANGE=5,

}EXTI_Edgetype;

void EXTI_voidInit(void);
void EXTI_voidEnableLine(EXTI_LinetNum_type Copy_u8LineNum);
void EXTI_voidSetSignalLatch(EXTI_LinetNum_type Copy_u8LineNum, EXTI_Edgetype Copy_u8EdgeMode);
void EXTI_voidDisableLine(EXTI_LinetNum_type Copy_u8LineNum );
void EXTI_voidSetCallBack(EXTI_LinetNum_type Copy_u8LineNum,void (*pf) (void) );
void EXTI_voidSetSoftwareTrigger(EXTI_LinetNum_type Copy_u8LineNum );
#endif /* EXTI_INTERFACE_H_ */
