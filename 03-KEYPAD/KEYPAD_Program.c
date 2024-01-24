/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/

/****************************************************/
/* Header files Inclusions						    */
/****************************************************/
#include "util/delay.h"

#include "HAL/KEYPAD/KEYPAD_Config.h"
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/DIO/DIO_Private.h"
#include "MCAL/DIO/DIO_Config.h"

#include "HAL/KEYPAD/KEYPAD_Interface.h"
#include "HAL/KEYPAD/KEYPAD_Private.h"
#include "HAL/KEYPAD/KEYPAD_Config.h"

u8 KEYPAD_Au8Keys [KEYPAD_u8_ROW_NUM][KEYPAD_u8_COL_NUM] = KEYPAD_Au8_KEYS;

u8 KEYPAD_Au8RowsPins[KEYPAD_u8_ROW_NUM] = KEYPAD_Au8ROWs;
u8 KEYPAD_Au8ColsPins[KEYPAD_u8_COL_NUM] = KEYPAD_Au8Cols;

/*********************************************************************************/
/* Function: KPD_voidInit			                        				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function initialize KEYPAD								       	    **/
/*********************************************************************************/
void KPD_voidInit(void)
{
	/*Set Columns pins to be output & Rows pins to be input*/
	//DDRB  = 0b00001111;
	DIO_voidSetPinDirection(KEYPAD_u8_PORT,DIO_u8_PIN0,DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(KEYPAD_u8_PORT,DIO_u8_PIN1,DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(KEYPAD_u8_PORT,DIO_u8_PIN2,DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(KEYPAD_u8_PORT,DIO_u8_PIN3,DIO_u8_INPUT);
	DIO_voidSetPinDirection(KEYPAD_u8_PORT,DIO_u8_PIN4,DIO_u8_INPUT);
	DIO_voidSetPinDirection(KEYPAD_u8_PORT,DIO_u8_PIN5,DIO_u8_INPUT);
	DIO_voidSetPinDirection(KEYPAD_u8_PORT,DIO_u8_PIN6,DIO_u8_INPUT);
	DIO_voidSetPinDirection(KEYPAD_u8_PORT,DIO_u8_PIN7,DIO_u8_INPUT);
	//Set Columns Pins to be high & Rows Pins to be pulled up.
	//And deactivate all columns by putting ones.
	//PORTB = 0b01111111;
	DIO_voidSetPortValue(KEYPAD_u8_PORT,0xff);
}

/*********************************************************************************/
/* Function: KPD_u8GetPressedKey	                        				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns u8	                                				    **/
/* Desc:This Function used to get the value of the pressed key		       	    **/
/*********************************************************************************/
u8 KPD_u8GetPressedKey (void)
{
	u8 local_u8RowCounter,
	   local_u8ColCounter,
	   local_u8PinValue,
	   local_u8KeyValue=KEYPAD_KEY_NOT_PRESSED,
	   local_u8Flag= KEYPAD_u8_FLAG_DOWN;

	for (local_u8ColCounter=0; local_u8ColCounter < KEYPAD_u8_COL_NUM; local_u8ColCounter++ )
	{
		DIO_voidSetPinValue(KEYPAD_u8_PORT,KEYPAD_Au8ColsPins[local_u8ColCounter],DIO_u8_LOW); //Activate Column by Setting 0 at output

		for (local_u8RowCounter=0; local_u8RowCounter < KEYPAD_u8_ROW_NUM; local_u8RowCounter++)
		{
			local_u8PinValue= DIO_voidGetPinValue(KEYPAD_u8_PORT, KEYPAD_Au8RowsPins[local_u8RowCounter]); //Get row value

			if (local_u8PinValue == DIO_u8_LOW)  //check for row value (if true --> switch is pressed)
			{
				//_delay_ms(KEYPAD_u8_DEBOUNCING_MS); //Delay for De-bouncing Effect
				local_u8PinValue= DIO_voidGetPinValue(KEYPAD_u8_PORT, KEYPAD_Au8RowsPins[local_u8RowCounter]); //Get row value

				while (local_u8PinValue == DIO_u8_LOW)
				{
					local_u8PinValue= DIO_voidGetPinValue(KEYPAD_u8_PORT, KEYPAD_Au8RowsPins[local_u8RowCounter]); //Get row value
				}
				local_u8KeyValue = KEYPAD_Au8Keys [local_u8RowCounter][local_u8ColCounter]; //Read
				local_u8Flag = KEYPAD_u8_FLAG_UP;
				break;
			}
		}
		DIO_voidSetPinValue(KEYPAD_u8_PORT,KEYPAD_Au8ColsPins[local_u8ColCounter],DIO_u8_HIGH); //De-Activate column by Setting 1 at output
		if (local_u8Flag==KEYPAD_u8_FLAG_UP)
		{
			break;
		}
	}
	return local_u8KeyValue;
}
