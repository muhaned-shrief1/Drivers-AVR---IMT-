/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/
#ifndef		ADC_INTERFACE_H
#define		ADC_INTERFACE_H

#define     ADC_PRESCALAR_BY_2         1
#define     ADC_PRESCALAR_BY_4         2
#define     ADC_PRESCALAR_BY_8         3
#define     ADC_PRESCALAR_BY_16        4
#define     ADC_PRESCALAR_BY_32        5
#define     ADC_PRESCALAR_BY_64        6
#define     ADC_PRESCALAR_BY_128       7


#define		ADC_CHANNEL_0				0
#define		ADC_CHANNEL_1				1
#define		ADC_CHANNEL_2				2
#define		ADC_CHANNEL_3				3
#define		ADC_CHANNEL_4				4
#define		ADC_CHANNEL_5				5
#define		ADC_CHANNEL_6				6
#define		ADC_CHANNEL_7				7


/*********************************************************************************/
/* Function: ADC_voidInit			                        				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function initializes ADC								       	    **/
/*********************************************************************************/
void ADC_voidInit(void);

/*********************************************************************************/
/* Function: ADC_u16ReadSynchronus	                        				    **/
/* I/P Parameters: Copy_u8ChannelNum						          		    **/
/* Returns:it returns u16	                                				    **/
/* Desc:This Function reads a specific ADC Channel						       	**/
/*********************************************************************************/
/* Copy_u8ChannelNum Options: 	ADC_CHANNEL_0 --> ADC_CHANNEL_7					**/
/*********************************************************************************/
u16 ADC_u16ReadSynchronus(u8 Copy_u8ChannelNum);

/*********************************************************************************/
/* Function: ADC_u16ReadAsynchronus	                        				    **/
/* I/P Parameters: Copy_u8ChannelNum, void (*Copy_pvCallBackFunctionPtr)(void)	**/
/* Returns:it returns u16	                                				    **/
/* Desc:This Function reads a specific ADC Channel						       	**/
/*********************************************************************************/
/* Copy_u8ChannelNum Options: 	ADC_CHANNEL_0 --> ADC_CHANNEL_7					**/
/* *Copy_pvCallBackFunctionPtr: Address of the Function to be executed			**/
/*********************************************************************************/
u16 ADC_u16ReadAsynchronus(u8 Copy_u8ChannelNum, void (*Copy_pvCallBackFunctionPtr)(void));

#endif
