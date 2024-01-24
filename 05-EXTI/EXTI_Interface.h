/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

/*  Copy_u8EXTINo Options: EXTI_u8_INT0, EXTI_u8_INT1, EXTI_u8_INT2
    Copy_u8Sense  Options: EXTI_u8_FALLING_EDGE, EXTI_u8_RISING_EDGE, EXTI_u8_ANY_LOGICAL_CHANGE*/
void EXTI_voidEXTIEnable(u8 Copy_u8EXTINo, u8 Copy_u8EXTISense);

void EXTI_voidEXTIDisable(u8 Copy_u8EXTINo);

void EXTI_voidSetCallBack( void(*Copy_PtrToFunc)(void), u8 Copy_u8EXTIIndex);

#endif
