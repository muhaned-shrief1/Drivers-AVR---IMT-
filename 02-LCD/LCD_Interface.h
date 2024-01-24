/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/
//File guard 
#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

/*********************************************************************************/
/* Function: LCD_voidInit			                        				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function initialize LCD								       	    **/
/*********************************************************************************/
void LCD_voidInit(void);

/*********************************************************************************/
/* Function: LCD_voidSendInstruction                        				    **/
/* I/P Parameters: Copy_u8instruction						          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Send a command "an instruction" to LCD			       	**/
/*********************************************************************************/
/* Copy_u8instruction Options: Instruction value assigned directly				**/
/*********************************************************************************/
void LCD_voidSendInstruction(u8 Copy_u8instruction);

/*********************************************************************************/
/* Function: LCD_voidWriteChar		                        				    **/
/* I/P Parameters: Copy_u8Data								          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function writes a character "data" on LCD					       	**/
/*********************************************************************************/
/* Copy_u8Data Options: Character assigned directly								**/
/*********************************************************************************/
void LCD_voidWriteChar(u8 Copy_u8Data);

/*********************************************************************************/
/* Function: LCD_voidWriteString	                        				    **/
/* I/P Parameters: *Copy_u8String, Copy_u8Size				          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function writes a string "array of characters" on LCD		       	**/
/*********************************************************************************/
/* *Copy_u8String Options: Passing the name of the Array directly				**/
/* Copy_u8Size Options: Size of the passed array								**/
/*********************************************************************************/
void LCD_voidWriteString(u8 *Copy_u8String, u8 Copy_u8Size);

/*********************************************************************************/
/* Function: LCD_voidGotoXY			                        				    **/
/* I/P Parameters: Copy_u8Row, Copy_u8Column				          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Goes to a specific location (r,c) on LCD			       	**/
/*********************************************************************************/
/* Copy_u8Row Options: 1 - 2													**/
/* Copy_u8Column Options: 0 --> 15												**/
/*********************************************************************************/
void LCD_voidGotoXY(u8 Copy_u8Row, u8 Copy_u8Column);

/*********************************************************************************/
/* Function: LCD_voidClearDisplay	                        				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns Nothing                                				    **/
/* Desc:This Function Clears the whole LCD display						       	**/
/*********************************************************************************/
void LCD_voidClearDisplay();

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
void LCD_voidWriteSpecialChar(u8 *Copy_u8Pattern, u8 Copy_u8PatternNumber ,u8 Copy_u8Row, u8 Copy_u8Column);

#endif
