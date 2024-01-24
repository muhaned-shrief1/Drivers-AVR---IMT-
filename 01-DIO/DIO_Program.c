/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/
/****************************************************/
/* Header files Inclusions						    */
/****************************************************/
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/DIO/DIO_Private.h"
#include "MCAL/DIO/DIO_Config.h"

/*********************************************************************************/
/* Function: DIO_voidSetPinValue	                        				    **/
/* I/P Parameters: Port ID,  Pin ID, Pin Value				          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Sets the Value of a specefic pin				       	    **/
/*********************************************************************************/
/* Copy_u8PortId Options: DIO_u8_PORTA, DIO_u8_PORTB, DIO_u8_PORTC, DIO_u8_PORTD**/
/* Copy_u8PinId  Options: DIO_u8_PIN0 --> DIO_u8_PIN7                           **/
/* Copy_u8Value  Options: DIO_u8_LOW, DIO_u8_HIGH                               **/
/*********************************************************************************/
void DIO_voidSetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Value)
{
    //Input Validation
    if( (Copy_u8PortId > DIO_u8_PORTD) || (Copy_u8PinId > DIO_u8_PIN7))
    {

    }
    else
    {
        switch(Copy_u8PortId)   //Check on port id
        {
            case DIO_u8_PORTA:  switch(Copy_u8Value)    //check on value
                                {
                                    case  DIO_u8_LOW:   CLR_BIT(DIO_u8_PORTA_REG,Copy_u8PinId);     break;  //set pin's value as low
                                    case  DIO_u8_HIGH:  SET_BIT(DIO_u8_PORTA_REG,Copy_u8PinId);     break;  //set pin's value as high 
                                }                            
                                break;
            case DIO_u8_PORTB:  switch(Copy_u8Value)
                                {       
                                    case  DIO_u8_LOW:   CLR_BIT(DIO_u8_PORTB_REG,Copy_u8PinId);     break;
                                    case  DIO_u8_HIGH:  SET_BIT(DIO_u8_PORTB_REG,Copy_u8PinId);     break;
                                }                            
                                break;
            case DIO_u8_PORTC:  switch(Copy_u8Value)
                                {
                                    case  DIO_u8_LOW:   CLR_BIT(DIO_u8_PORTC_REG,Copy_u8PinId);     break;
                                    case  DIO_u8_HIGH:  SET_BIT(DIO_u8_PORTC_REG,Copy_u8PinId);     break;
                                }                            
                                break;
            case DIO_u8_PORTD:  switch(Copy_u8Value)
                                {
                                    case  DIO_u8_LOW:   CLR_BIT(DIO_u8_PORTD_REG,Copy_u8PinId);     break;
                                    case  DIO_u8_HIGH:  SET_BIT(DIO_u8_PORTD_REG,Copy_u8PinId);     break;
                                }                            
                                break;
            
        }
    }
}

/*********************************************************************************/
/* Function: DIO_voidSetPinDirection	                        				**/
/* I/P Parameters: Copy_u8PortId,  Copy_u8PinId, Copy_u8Direction  			    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Sets the Direction of a specefic pin     		       	    **/
/*********************************************************************************/
/* Copy_u8PortId Options: DIO_u8_PORTA, DIO_u8_PORTB, DIO_u8_PORTC, DIO_u8_PORTD**/
/* Copy_u8PinId  Options: DIO_u8_PIN0 --> DIO_u8_PIN7                           **/
/* Copy_u8Value  Options: DIO_u8_INPUT, DIO_u8_OUTPUT                           **/
/*********************************************************************************/
void DIO_voidSetPinDirection(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Direction)
{
    //Input Validation
    if( (Copy_u8PortId > DIO_u8_PORTD) || (Copy_u8PinId > DIO_u8_PIN7))
    {

    }
    else
    {
        switch(Copy_u8PortId)   //Check on port id
        {
            case DIO_u8_PORTA:  switch(Copy_u8Direction)    //check on direction
                                {
                                    case  DIO_u8_INPUT:   CLR_BIT(DIO_u8_DDRA_REG,Copy_u8PinId);     break;  //set pin's direction as input
                                    case  DIO_u8_OUTPUT:  SET_BIT(DIO_u8_DDRA_REG,Copy_u8PinId);     break;  //set pin's direction as output 
                                }                            
                                break;
            case DIO_u8_PORTB:  switch(Copy_u8Direction)
                                {       
                                    case  DIO_u8_INPUT:   CLR_BIT(DIO_u8_DDRB_REG,Copy_u8PinId);     break;
                                    case  DIO_u8_OUTPUT:  SET_BIT(DIO_u8_DDRB_REG,Copy_u8PinId);     break;
                                }                            
                                break;
            case DIO_u8_PORTC:  switch(Copy_u8Direction)
                                {
                                    case  DIO_u8_INPUT:   CLR_BIT(DIO_u8_DDRC_REG,Copy_u8PinId);     break;
                                    case  DIO_u8_OUTPUT:  SET_BIT(DIO_u8_DDRC_REG,Copy_u8PinId);     break;
                                }                            
                                break;
            case DIO_u8_PORTD:  switch(Copy_u8Direction)
                                {
                                    case  DIO_u8_INPUT:   CLR_BIT(DIO_u8_DDRD_REG,Copy_u8PinId);     break;
                                    case  DIO_u8_OUTPUT:  SET_BIT(DIO_u8_DDRD_REG,Copy_u8PinId);     break;
                                }                            
                                break;
            
        }
    }
}

/*********************************************************************************/
/* Function: DIO_voidGetPinValue	                        				    **/
/* I/P Parameters: Copy_u8PortId, Copy_u8PinId				          		    **/
/* Returns:it returns u8                                				        **/
/* Desc:This Function gets the Value of a given pin					       	    **/
/*********************************************************************************/
/* Copy_u8PortId Options: DIO_u8_PORTA, DIO_u8_PORTB, DIO_u8_PORTC, DIO_u8_PORTD**/
/* Copy_u8PinId  Options: DIO_u8_PIN0 --> DIO_u8_PIN7                           **/
/*********************************************************************************/
u8 DIO_voidGetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId)
{
    //Any initial value except 0,1
    u8 Local_u8PinValue = 5;
    //Input Validation
    if( (Copy_u8PortId > DIO_u8_PORTD) || (Copy_u8PinId > DIO_u8_PIN7))
    {

    }
    else
    {
        switch(Copy_u8PortId)   //Check on port id
        {
            case DIO_u8_PORTA:  Local_u8PinValue = GET_BIT(DIO_u8_PINA_REG,Copy_u8PinId);  break;   //Getting the value of the pin
            case DIO_u8_PORTB:  Local_u8PinValue = GET_BIT(DIO_u8_PINB_REG,Copy_u8PinId);  break;
            case DIO_u8_PORTC:  Local_u8PinValue = GET_BIT(DIO_u8_PINC_REG,Copy_u8PinId);  break;
            case DIO_u8_PORTD:  Local_u8PinValue = GET_BIT(DIO_u8_PIND_REG,Copy_u8PinId);  break;
        }
    }
    return Local_u8PinValue;    //return it
}

/*********************************************************************************/
/* Function: DIO_voidSetPortValue	                        				    **/
/* I/P Parameters: Copy_u8PortId, u8 Copy_u8Value                               **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Sets the Value of a specefic port				       	    **/
/*********************************************************************************/
/* Copy_u8PortId Options: DIO_u8_PORTA, DIO_u8_PORTB, DIO_u8_PORTC, DIO_u8_PORTD**/
/* Copy_u8Value  Options:  Value assigned directly                              **/
/*********************************************************************************/
void DIO_voidSetPortValue(u8 Copy_u8PortId, u8 Copy_u8Value)
{
    //Input Validation
    if( (Copy_u8PortId > DIO_u8_PORTD))
    {

    }
    else
    {
        switch(Copy_u8PortId)   //Check on port id
        {
            case DIO_u8_PORTA:  DIO_u8_PORTA_REG = Copy_u8Value;  break;    //Assigning the required value to the target register 
            case DIO_u8_PORTB:  DIO_u8_PORTB_REG = Copy_u8Value;  break;
            case DIO_u8_PORTC:  DIO_u8_PORTC_REG = Copy_u8Value;  break;
            case DIO_u8_PORTD:  DIO_u8_PORTD_REG = Copy_u8Value;  break;
        };
    }
}

/*********************************************************************************/
/* Function: DIO_voidSetPortDirection                        				    **/
/* I/P Parameters: Copy_u8PortId, u8 Copy_u8Direction                           **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Sets the Direction of a specefic port			       	    **/
/*********************************************************************************/
/* Copy_u8PortId Options: DIO_u8_PORTA, DIO_u8_PORTB, DIO_u8_PORTC, DIO_u8_PORTD**/
/* Copy_u8Value  Options:  Value assigned directly                              **/
/*********************************************************************************/
void DIO_voidSetPortDirection(u8 Copy_u8PortId, u8 Copy_u8Direction)
{
    //Input Validation
    if( (Copy_u8PortId > DIO_u8_PORTD))
    {

    }
    else
    {
        switch(Copy_u8PortId)   //Check on port id
        {
            case DIO_u8_PORTA:  DIO_u8_DDRA_REG = Copy_u8Direction;  break;
            case DIO_u8_PORTB:  DIO_u8_DDRB_REG = Copy_u8Direction;  break;
            case DIO_u8_PORTC:  DIO_u8_DDRC_REG = Copy_u8Direction;  break;
            case DIO_u8_PORTD:  DIO_u8_DDRD_REG = Copy_u8Direction;  break;
        };
    }
}

/*********************************************************************************/
/* Function: DIO_voidGetPortValue	                        				    **/
/* I/P Parameters: Copy_u8PortId                                                **/
/* Returns:it returns   u8                                     				    **/
/* Desc:This Function Sets the Value of a specefic port				       	    **/
/*********************************************************************************/
/* Copy_u8PortId Options: DIO_u8_PORTA, DIO_u8_PORTB, DIO_u8_PORTC, DIO_u8_PORTD**/
/* Copy_u8Value  Options:  Value assigned directly                              **/
/*********************************************************************************/
u8 DIO_voidGetPortValue(u8 Copy_u8PortId)
{
    u8 Local_u8PortValue;
    //Input Validation
    if( (Copy_u8PortId > DIO_u8_PORTD))
    {

    }
    else
    {
        switch(Copy_u8PortId)   //Check on port id
        {
            case DIO_u8_PORTA:  Local_u8PortValue = DIO_u8_PINA_REG;  break;    //Getting Port Value
            case DIO_u8_PORTB:  Local_u8PortValue = DIO_u8_PINB_REG;  break;
            case DIO_u8_PORTC:  Local_u8PortValue = DIO_u8_PINC_REG;  break;
            case DIO_u8_PORTD:  Local_u8PortValue = DIO_u8_PIND_REG;  break;
        };
    }
    return Local_u8PortValue;   //return it
}
