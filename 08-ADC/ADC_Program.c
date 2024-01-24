/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/
/****************************************************/
/* Header files Inclusions						    */
/****************************************************/
#include <util/delay.h>
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "MCAL/DIO/DIO_Interface.h"

#include "MCAL/ADC/ADC_Interface.h"
#include "MCAL/ADC/ADC_Private.h"
#include "MCAL/ADC/ADC_Config.h"

/*Indicator for ADC Busy or not*/
u8 ADC_u8BusyFlag = NOTBUSY;

u16 ADC_u16Result;

//Pointer to function
void (*ADC_pvNotificationFunction)(void) = NULL;

/*********************************************************************************/
/* Function: ADC_voidInit			                        				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function initializes ADC								       	    **/
/*********************************************************************************/
void ADC_voidInit(void)
{
	/*Configure the direction of PORTA pins as I/P*/
	DIO_voidSetPortDirection(DIO_u8_PORTA,DIO_u8_INPUT);

	/*Set Reference Voltage*/
	#if		ADC_REFVOLT == ADC_AREF
		CLR_BIT(ADC_u8_ADMUX_REG, ADC_u8_ADMUX_REFS0);
		CLR_BIT(ADC_u8_ADMUX_REG, ADC_u8_ADMUX_REFS1);
	#elif   ADC_REFVOLT == ADC_AVCC
		SET_BIT(ADC_u8_ADMUX_REG, ADC_u8_ADMUX_REFS0);
		CLR_BIT(ADC_u8_ADMUX_REG, ADC_u8_ADMUX_REFS1);
	#elif   ADC_REFVOLT == ADC_INTERNAL
		SET_BIT(ADC_u8_ADMUX_REG, ADC_u8_ADMUX_REFS0);
		SET_BIT(ADC_u8_ADMUX_REG, ADC_u8_ADMUX_REFS1);
	#else
		#error "Error in ADC Reference volt configuration"
	#endif
	
	
	/*Activate The Left Adjust*/
	#if	ADC_ADJUST_CTRL == LEFT
		SET_BIT(ADC_u8_ADMUX_REG, ADC_u8_ADMUX_ADLAR);
	#elif ADC_ADJUST_CTRL == RIGHT
		CLR_BIT(ADC_u8_ADMUX_REG, ADC_u8_ADMUX_ADLAR);
	#else
		#error "Error in ADC_ADJUST_CTRL Configuration"
	#endif
	
	/*Set The Prescalar Configuration*/
	ADC_u8_ADCSRA_REG &= ADC_PRES_MASK;
	ADC_u8_ADCSRA_REG |= ADC_PRESCALAR_VAL;
	
	/*Enable the ADC Peripheral*/
	SET_BIT(ADC_u8_ADCSRA_REG, ADC_u8_ADCSRA_ADEN);
}

/*********************************************************************************/
/* Function: ADC_u16ReadSynchronus	                        				    **/
/* I/P Parameters: Copy_u8ChannelNum						          		    **/
/* Returns:it returns u16	                                				    **/
/* Desc:This Function reads a specific ADC Channel						       	**/
/*********************************************************************************/
/* Copy_u8ChannelNum Options: 	ADC_CHANNEL_0 --> ADC_CHANNEL_7					**/
/*********************************************************************************/
u16 ADC_u16ReadSynchronus(u8 Copy_u8ChannelNum)
{
	if(ADC_u8BusyFlag == BUSY)
	{
		return BUSY;
	}
	else
	{
		ADC_u8BusyFlag = BUSY;
		/*Set the required channel into the MUX bits in ADMUX Register*/
		ADC_u8_ADMUX_REG &= ADC_CHANNEL_MASK;			//Clearing the 5 LSB
		ADC_u8_ADMUX_REG |= Copy_u8ChannelNum;

		/*Start Conversion*/
		SET_BIT(ADC_u8_ADCSRA_REG, ADC_u8_ADCSRA_ADSC);

		/*Polling (Busy Waiting) until the conversion is complete*/
		while(GET_BIT(ADC_u8_ADCSRA_REG, ADC_u8_ADCSRA_ADIF) == 0);

		/*Conversion completed*/
		/*Clear the flag for the incoming conversions*/
		SET_BIT(ADC_u8_ADCSRA_REG, ADC_u8_ADCSRA_ADIF);
		_delay_us(10);

		ADC_u8BusyFlag = NOTBUSY;
		/*Return the reading*/
		return ADC_u16_ADC_REG;
	}
}

/*********************************************************************************/
/* Function: ADC_u16ReadAsynchronus	                        				    **/
/* I/P Parameters: Copy_u8ChannelNum, void (*Copy_pvCallBackFunctionPtr)(void)	**/
/* Returns:it returns u16	                                				    **/
/* Desc:This Function reads a specific ADC Channel						       	**/
/*********************************************************************************/
/* Copy_u8ChannelNum Options: 	ADC_CHANNEL_0 --> ADC_CHANNEL_7					**/
/* *Copy_pvCallBackFunctionPtr: Address of the Function to be executed			**/
/*********************************************************************************/
u16 ADC_u16ReadAsynchronus(u8 Copy_u8ChannelNum, void (*Copy_pvCallBackFunctionPtr)(void))
{
	if(  (ADC_u8BusyFlag == BUSY) || (Copy_pvCallBackFunctionPtr == NULL)  )
	{
		return 0;
	}
	else
	{
		ADC_u8BusyFlag = BUSY;
		/*Set the required channel into the MUX bits in ADMUX Register*/
		ADC_u8_ADMUX_REG &= ADC_CHANNEL_MASK;			// Bit Masking
		ADC_u8_ADMUX_REG |= Copy_u8ChannelNum;

		/*Set the Callback function*/
		ADC_pvNotificationFunction = Copy_pvCallBackFunctionPtr;

		/*Start Conversion*/
		SET_BIT(ADC_u8_ADCSRA_REG, ADC_u8_ADCSRA_ADSC);

		/*ADC interrupt Enable*/
		SET_BIT(ADC_u8_ADCSRA_REG, ADC_u8_ADCSRA_ADIE);

		return ADC_u16Result;
	}
}


/***********************************ADC ISR***********************************/
void __vector_16 (void)   __attribute__((signal));
void __vector_16 (void)
{

	/*Read ADC Result*/
	ADC_u16Result = ADC_u16_ADC_REG;

	/*Make The ADC State to be NOTBUSY because it's completed*/
	ADC_u8BusyFlag = NOTBUSY;

	/*Invoke the callback function*/
	ADC_pvNotificationFunction();

	/*Disable ADC conversion complete interrupt*/
	CLR_BIT(ADC_u8_ADCSRA_REG, ADC_u8_ADCSRA_ADIE);
}





