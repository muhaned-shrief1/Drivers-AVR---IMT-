/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/
//Including necessary header files from library layer

/****************************************************/
/* Header files Inclusions						    */
/****************************************************/
#include <util/delay.h>
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "MCAL/DIO/DIO_Interface.h"

#include "HAL/LCD/LCD_Interface.h"
#include "HAL/LCD/LCD_Private.h"
#include "HAL/LCD/LCD_Config.h"

/*********************************************************************************/
/* Function: LCD_voidInit			                        				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function initialize LCD								       	    **/
/*********************************************************************************/
void LCD_voidInit(void)
{
	//Configure the direction of all CONTROL pins is o/p
	DIO_voidSetPinDirection(LCD_u8_CTRL_PORT,LCD_u8_RSPIN,DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(LCD_u8_CTRL_PORT,LCD_u8_RWPIN,DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(LCD_u8_CTRL_PORT,LCD_u8_EPIN,DIO_u8_OUTPUT);

	//Configure the direction of data port
	DIO_voidSetPortDirection(LCD_u8_DATA_PORT,0xff);
	/*LCD Initialization*/
	_delay_ms(30);
	/*Fn Set*/
	LCD_voidSendInstruction(0b00111100);
	_delay_ms(2);
	/*Display ON/OFF*/
	LCD_voidSendInstruction(0b00001100);
	_delay_ms(2);
	/*Clear Display*/
	LCD_voidSendInstruction(0b00000001);
	_delay_ms(2);
	/*Entry Mode Set*/
	LCD_voidSendInstruction(0b00000110);
	_delay_ms(2);
}

/*********************************************************************************/
/* Function: LCD_voidSendInstruction                        				    **/
/* I/P Parameters: Copy_u8instruction						          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Send a command "an instruction" to LCD			       	**/
/*********************************************************************************/
/* Copy_u8instruction Options: Instruction value assigned directly				**/
/*********************************************************************************/
void LCD_voidSendInstruction(u8 Copy_u8instruction)
{
	//RS = 0 (Command), RW = 0 (Write), E = 1 (Enable)
	DIO_voidSetPinValue(LCD_u8_CTRL_PORT,LCD_u8_RSPIN,DIO_u8_LOW);
	DIO_voidSetPinValue(LCD_u8_CTRL_PORT,LCD_u8_RWPIN,DIO_u8_LOW);
	DIO_voidSetPinValue(LCD_u8_CTRL_PORT,LCD_u8_EPIN,DIO_u8_HIGH);

	//001,DL(8-bit data),N(2-lines),F(5*10 dots)
	DIO_voidSetPortValue(LCD_u8_DATA_PORT,Copy_u8instruction);

	//E (1 then 0 --> falling edge)
	DIO_voidSetPinValue(LCD_u8_CTRL_PORT,LCD_u8_EPIN,DIO_u8_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_u8_CTRL_PORT,LCD_u8_EPIN,DIO_u8_LOW);
}

/*********************************************************************************/
/* Function: LCD_voidWriteChar		                        				    **/
/* I/P Parameters: Copy_u8Data								          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function writes a character "data" on LCD					       	**/
/*********************************************************************************/
/* Copy_u8Data Options: Character assigned directly								**/
/*********************************************************************************/
void LCD_voidWriteChar(u8 Copy_u8Data)
{
	//RS = 0 (Data), RW = 0 (Write), E = 1 (Enable)
	DIO_voidSetPinValue(LCD_u8_CTRL_PORT,LCD_u8_RSPIN,DIO_u8_HIGH);
	DIO_voidSetPinValue(LCD_u8_CTRL_PORT,LCD_u8_RWPIN,DIO_u8_LOW);
	DIO_voidSetPinValue(LCD_u8_CTRL_PORT,LCD_u8_EPIN,DIO_u8_HIGH);

	//001,DL(8-bit data),N(2-lines),F(5*10 dots)
	DIO_voidSetPortValue(LCD_u8_DATA_PORT,Copy_u8Data);

	//E (1 then 0 --> falling edge)
	DIO_voidSetPinValue(LCD_u8_CTRL_PORT,LCD_u8_EPIN,DIO_u8_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_u8_CTRL_PORT,LCD_u8_EPIN,DIO_u8_LOW);
}

/*********************************************************************************/
/* Function: LCD_voidWriteString	                        				    **/
/* I/P Parameters: *Copy_u8String, Copy_u8Size				          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function writes a string "array of characters" on LCD		       	**/
/*********************************************************************************/
/* *Copy_u8String Options: Passing the name of the Array directly				**/
/* Copy_u8Size Options: Size of the passed array								**/
/*********************************************************************************/
void LCD_voidWriteString(u8 *Copy_u8String, u8 Copy_u8Size)
{
	//String is an array of characters
	for(u8 i=0; i<Copy_u8Size; i++)
	{
		LCD_voidWriteChar(Copy_u8String[i]);	//Write a char on each iteration
	}
}

//Another Way
/*
void LCD_voidSendString(char *Copy_u8String)
{
	u8 i =0;
	while( Copy_u8String[i] != '\0' )
	{
		LCD_voidWriteChar(Copy_u8String[i]);
		i++;
	}
}*/

/*********************************************************************************/
/* Function: LCD_voidGotoXY			                        				    **/
/* I/P Parameters: Copy_u8Row, Copy_u8Column				          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Goes to a specific location (r,c) on LCD			       	**/
/*********************************************************************************/
/* Copy_u8Row Options: 1 - 2													**/
/* Copy_u8Column Options: 0 --> 15												**/
/*********************************************************************************/
void LCD_voidGotoXY(u8 Copy_u8Row, u8 Copy_u8Column)
{
	if( (Copy_u8Row == 1) && (Copy_u8Column < 16) )		//Writing on Any grid resides on the 1st row
	{
		LCD_voidSendInstruction(0x80 + Copy_u8Column);	//0x80 is the address of the 1st location in the 1st row
	}
	else if( (Copy_u8Row == 2) && (Copy_u8Column < 16) )//Writing on Any grid resides on the 2nd row
	{
		LCD_voidSendInstruction(0xC0 + Copy_u8Column);	//0xC0 is the address of the 1st location in the 1st row
	}
	else
	{
		//Do Nothing
	}
}

/*********************************************************************************/
/* Function: LCD_voidClearDisplay	                        				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns Nothing                                				    **/
/* Desc:This Function Clears the whole LCD display						       	**/
/*********************************************************************************/
void LCD_voidClearDisplay()
{
	LCD_voidSendInstruction(0b00000001);	//sending Instruction to clear the whole display
}

/***********************************************************************************/
/* Function: LCD_voidWriteSpecialChar                        				      **/
/* I/P Parameters: *Copy_u8Pattern, Copy_u8PatternNumber ,Copy_u8Row,Copy_u8Column**/
/* Returns:it returns No thing                                				      **/
/* Desc:This Function writes a custom character on LCD					       	  **/
/***********************************************************************************/
/* Copy_u8Pattern Options: Character Pattern array								  **/
/* Copy_u8PatternNumber Options: Num of Pattern to be displayed					  **/
/* Copy_u8Row Options: 1 - 2													  **/
/* Copy_u8Column Options: 0 --> 15												  **/
/***********************************************************************************/
void LCD_voidWriteSpecialChar(u8 *Copy_u8Pattern, u8 Copy_u8PatternNumber ,u8 Copy_u8Row, u8 Copy_u8Column)
{
	/*Set CGRAM address */
	/*calculate the CGRAM address*/
	u8 Local_u8Adress=(Copy_u8PatternNumber*8);
	LCD_voidSendInstruction(Local_u8Adress+64);
	//                       address    +64th bit

	/*save the pattern in CGRAM address */
	/* or Write data to CGRAM or DDRAM */
	for (u8 i=0 ;i<8 ;i++)
	{
		LCD_voidWriteChar(Copy_u8Pattern[i]);
		//the address counter counter AC will auto increment the next address
	}

	/*Set DDRAM Address */
	/*or go back to DDRAM to display the pattern*/
	LCD_voidGotoXY(Copy_u8Row ,Copy_u8Column );

	/* Read data from CGRAM or DDRAM*/
	/*or display the pattern*/
	LCD_voidWriteChar(Copy_u8PatternNumber); //instead of ASCII letter in CGROM
}
