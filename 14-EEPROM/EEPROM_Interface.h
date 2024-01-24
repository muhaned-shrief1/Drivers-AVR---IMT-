/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/
#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

/*********************************************************************************/
/* Function: EEPROM_voidSendDataByte	                       				    **/
/* I/P Parameters: u16 Copy_u16LocationAddress, u8 Copy_u8DataByte   		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function sends byte of data to eeprom								**/
/*********************************************************************************/
/* Copy_u16LocationAddress:the address of the location you want to write on		**/
/* Copy_u8DataByte:Assign the Data you want to send								**/
/*********************************************************************************/
void EEPROM_voidSendDataByte(u16 Copy_u16LocationAddress, u8 Copy_u8DataByte);

/*********************************************************************************/
/* Function: EEPROM_u8ReadDataByte  	                       				    **/
/* I/P Parameters: u16 Copy_u16LocationAddress						  		    **/
/* Returns:it returns u8	                                				    **/
/* Desc:This Function reads a byte of data from eeprom							**/
/*********************************************************************************/
/* Copy_u16LocationAddress:the address of the location you want to read from	**/
/*********************************************************************************/
u8 EEPROM_u8ReadDataByte(u16 Copy_u16LocationAddress);


#endif
