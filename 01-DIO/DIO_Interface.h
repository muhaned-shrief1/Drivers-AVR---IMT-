/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/
//File guard 
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

//Registers macros
#define DIO_u8_PORTA      0
#define DIO_u8_PORTB      1
#define DIO_u8_PORTC      2
#define DIO_u8_PORTD      3

//Pins macros
#define DIO_u8_PIN0       0
#define DIO_u8_PIN1       1
#define DIO_u8_PIN2       2
#define DIO_u8_PIN3       3
#define DIO_u8_PIN4       4
#define DIO_u8_PIN5       5
#define DIO_u8_PIN6       6
#define DIO_u8_PIN7       7

//Other macros
#define DIO_u8_LOW        0
#define DIO_u8_HIGH       1
 
#define DIO_u8_INPUT      0
#define DIO_u8_OUTPUT     1

/*********************************************************************************/
/* Function: DIO_voidSetPinValue	                        				    **/
/* I/P Parameters: Port ID,  Pin ID, Pin Value				          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Sets the Value of a specific pin				       	    **/
/*********************************************************************************/
/* Copy_u8PortId Options: DIO_u8_PORTA, DIO_u8_PORTB, DIO_u8_PORTC, DIO_u8_PORTD**/
/* Copy_u8PinId  Options: DIO_u8_PIN0 --> DIO_u8_PIN7                           **/
/* Copy_u8Value  Options: DIO_u8_LOW, DIO_u8_HIGH                               **/
/*********************************************************************************/
void DIO_voidSetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Value);

/*********************************************************************************/
/* Function: DIO_voidSetPinDirection	                        				**/
/* I/P Parameters: Copy_u8PortId,  Copy_u8PinId, Copy_u8Direction  			    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Sets the Direction of a specific pin     		       	    **/
/*********************************************************************************/
/* Copy_u8PortId Options: DIO_u8_PORTA, DIO_u8_PORTB, DIO_u8_PORTC, DIO_u8_PORTD**/
/* Copy_u8PinId  Options: DIO_u8_PIN0 --> DIO_u8_PIN7                           **/
/* Copy_u8Value  Options: DIO_u8_INPUT, DIO_u8_OUTPUT                           **/
/*********************************************************************************/
void DIO_voidSetPinDirection(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Direction);

/*********************************************************************************/
/* Function: DIO_voidGetPinValue	                        				    **/
/* I/P Parameters: Copy_u8PortId, Copy_u8PinId				          		    **/
/* Returns:it returns u8                                				        **/
/* Desc:This Function gets the Value of a given pin					       	    **/
/*********************************************************************************/
/* Copy_u8PortId Options: DIO_u8_PORTA, DIO_u8_PORTB, DIO_u8_PORTC, DIO_u8_PORTD**/
/* Copy_u8PinId  Options: DIO_u8_PIN0 --> DIO_u8_PIN7                           **/
/*********************************************************************************/
u8 DIO_voidGetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId);

/*********************************************************************************/
/* Function: DIO_voidSetPortValue	                        				    **/
/* I/P Parameters: Copy_u8PortId, u8 Copy_u8Value                               **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Sets the Value of a specific port				       	    **/
/*********************************************************************************/
/* Copy_u8PortId Options: DIO_u8_PORTA, DIO_u8_PORTB, DIO_u8_PORTC, DIO_u8_PORTD**/
/* Copy_u8Value  Options:  Value assigned directly                              **/
/*********************************************************************************/
void DIO_voidSetPortValue(u8 Copy_u8PortId, u8 Copy_u8Value);

/*********************************************************************************/
/* Function: DIO_voidSetPortDirection                        				    **/
/* I/P Parameters: Copy_u8PortId, u8 Copy_u8Direction                           **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Sets the Direction of a specific port			       	    **/
/*********************************************************************************/
/* Copy_u8PortId Options: DIO_u8_PORTA, DIO_u8_PORTB, DIO_u8_PORTC, DIO_u8_PORTD**/
/* Copy_u8Value  Options:  Value assigned directly                              **/
/*********************************************************************************/
void DIO_voidSetPortDirection(u8 Copy_u8PortId, u8 Copy_u8Direction);

/*********************************************************************************/
/* Function: DIO_voidGetPortValue	                        				    **/
/* I/P Parameters: Copy_u8PortId                                                **/
/* Returns:it returns   u8                                     				    **/
/* Desc:This Function Sets the Value of a specific port				       	    **/
/*********************************************************************************/
/* Copy_u8PortId Options: DIO_u8_PORTA, DIO_u8_PORTB, DIO_u8_PORTC, DIO_u8_PORTD**/
/* Copy_u8Value  Options:  Value assigned directly                              **/
/*********************************************************************************/
u8 DIO_voidGetPortValue(u8 Copy_u8PortId);

#endif
