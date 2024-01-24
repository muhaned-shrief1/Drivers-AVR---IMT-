/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/
#ifndef F_CPU
#define F_CPU 8000000UL
#endif

/****************************************************/
/* Header files Inclusions						    */
/****************************************************/
#include <util/delay.h>
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/DIO/DIO_Private.h"
#include "MCAL/DIO/DIO_Config.h"

#include "HAL/STEPPER/Stepper_Interface.h"
#include "HAL/STEPPER/Stepper_Config.h"

/*********************************************************************************/
/* Function: LCD_voidInit			                        				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function initialize LCD								       	    **/
/*********************************************************************************/
void STP_voidInit()
{
	//Configure Direction of pins as O/P
	DIO_voidSetPortDirection(STP_u8_PORT,0xff);
	//Initialize their values with high
	DIO_voidSetPortValue(STP_u8_PORT, 0xff);
}

/*********************************************************************************/
/* Function: STP_voidMove			                        				    **/
/* I/P Parameters: Copy_u8Direction							          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function moves the stepper motor in clockwise & counter clockwise  **/
/*********************************************************************************/
/* Copy_u8Direction Options: CLOCKWISE_DIRECTION, COUNTER_CLOCKWISE_DIRECTION	**/
/*********************************************************************************/
void STP_voidMove(u8 Copy_u8Direction)
{
	switch(Copy_u8Direction)
	{
	   case	COUNTER_CLOCKWISE_DIRECTION:
		   //Step1
			DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_LOW);
			DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN1,DIO_u8_HIGH);
			DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN2,DIO_u8_HIGH);
			DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN3,DIO_u8_HIGH);
			_delay_ms(10);
			//Step2
			DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_HIGH);
			DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN1,DIO_u8_LOW);
			DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN2,DIO_u8_HIGH);
			DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN3,DIO_u8_HIGH);
			_delay_ms(10);
			//Step3
			DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_HIGH);
			DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN1,DIO_u8_HIGH);
			DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN2,DIO_u8_LOW);
			DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN3,DIO_u8_HIGH);
			_delay_ms(10);
			//Step4
			DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_HIGH);
			DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN1,DIO_u8_HIGH);
			DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN2,DIO_u8_HIGH);
			DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN3,DIO_u8_LOW);
			_delay_ms(10);
			break;

	   case	CLOCKWISE_DIRECTION:
		   //Step4
		    DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_HIGH);
		    DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN1,DIO_u8_HIGH);
		    DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN2,DIO_u8_HIGH);
		    DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN3,DIO_u8_LOW);
			_delay_ms(10);
			//Step3
			DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_HIGH);
			DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN1,DIO_u8_HIGH);
			DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN2,DIO_u8_LOW);
			DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN3,DIO_u8_HIGH);
			_delay_ms(10);
			//Step2
			DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_HIGH);
			DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN1,DIO_u8_LOW);
			DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN2,DIO_u8_HIGH);
			DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN3,DIO_u8_HIGH);
			_delay_ms(10);
			//Step1
			DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_LOW);
			DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN1,DIO_u8_HIGH);
			DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN2,DIO_u8_HIGH);
			DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN3,DIO_u8_HIGH);
			_delay_ms(10);
			break;
	}

}

