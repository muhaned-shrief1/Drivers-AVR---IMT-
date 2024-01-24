/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/
#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

/*Private Macros*/
#define EXTI_u8_EXTI0                0
#define EXTI_u8_EXTI1                1
#define EXTI_u8_EXTI2                2
// MACRO TO SELECT EDGE WANT ISR 
#define EXTI_u8_LOW_LEVEL            0
#define EXTI_u8_ANY_LOGICAL_CHANGE   1
#define EXTI_u8_FALLING_EDGE         2 
#define EXTI_u8_RISING_EDGE          3

/*Registers & their Pins Macros*/
#define EXTI_u8_MCUCR_REG            *((volatile u8*)0x55)
#define EXTI_u8_MCUCR_ISC00          0
#define EXTI_u8_MCUCR_ISC01          1
#define EXTI_u8_MCUCR_ISC10          2
#define EXTI_u8_MCUCR_ISC11          3

#define EXTI_u8_MCUCSR_REG           *((volatile u8*)0x54)
#define EXTI_u8_MCUCSR_ISC2          6

#define EXTI_u8_GICR_REG             *((volatile u8*)0x5B)
#define EXTI_u8_GICR_INT2            5
#define EXTI_u8_GICR_INT0            6
#define EXTI_u8_GICR_INT1            7

#define EXTI_u8_GIFR_REG             *((volatile u8*)0x5A)

#endif
