/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/
/***************************************************/
/*              Header files Inclusions            */
/***************************************************/
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/DIO/DIO_Private.h"
#include "MCAL/DIO/DIO_Config.h"

#include "MCAL/UART/UART_Interface.h"
#include "MCAL/UART/UART_Private.h"
#include "MCAL/UART/UART_Config.h"

#define F_CPU   8000000UL

#include <util/delay.h>

/*********************************************************************************/
/* Function: UART_voidInit			                        				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function initialize UART									       	**/
/*********************************************************************************/
extern void UART_voidInit (void)
{

	/*  Store the low byte of the UBBR*/
	UBRRL =  (u8) MyUBRR;

	/*  Store the High byte of the UBBR*/
	UBRRH = (u8)((MyUBRR)>>8);

	/* Configuration of UCSRnA Register  */
	UCSRnA= ( (U2X<<1) | (MPCM<<0) );

	/* Enable Transmit bit(3) and Receive bit(4) in UCSRnC Register */
	UCSRnB = ( (RXEN<<4) | (TXEN<<3) | (UCSZ2<<2) );

	/* Configure UCRnC Register to make 8-bit data & 1 stop bit & no parity  Asynchronous Mode*/
	UCSRnC = ((URSEL << 7) | (UMSEL << 6) | (UPM1 << 5) | (UPM0 << 4)
			| (USBS << 3) | (UCSZ1 << 2) | (UCSZ0 << 1));

	//set_bit(SREG,7);
}

/*********************************************************************************/
/* Function: UART_TransmitData		                        				    **/
/* I/P Parameters: UART_DataToBeSent						          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Sends data 										       	**/
/*********************************************************************************/
/* UART_DataToBeSent Options: 1 byte data										**/
/*********************************************************************************/
extern void UART_TransmitData (u8 UART_DataToBeSent)
{
	/* So put data in the UDR Register */
	UDR=UART_DataToBeSent;

	 /* check the bit5 (UDRE) is a flag bit to figure that if the UDR register empty or not */
	while(GET_BIT(UCSRnA,5)==0);
	//while( ! (UCSRnA & (1<<6)) );
	//clear the transmit interrupt flag
	SET_BIT(UCSRnA,6);
}

/*********************************************************************************/
/* Function: UART_RecieveData		                        				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns u8	                                				    **/
/* Desc:This Function returns data to be received						       	**/
/*********************************************************************************/
extern u8 UART_RecieveData(void)
{
	//while ( ! (UCSRnA & (1<<7)) );
	while(GET_BIT(UCSRnA,7)==0);
	return UDR;

}

//====================================================================================================
extern void UART_voidPrintf(u8 Copy_u8PrintedData[])
{

	u8 iterator=0;

	for (iterator=0;Copy_u8PrintedData[iterator]!='\0';iterator++)
	{
		UART_TransmitData(Copy_u8PrintedData[ iterator]);

	}

}


//====================================================================================================

////////////////////////////////////////////////////////////////////////////////////////////////////
/*
extern void UART_TransmitDataFrames(u8 UART_Frames[])
{
	}
*/

////////////////////////////////////////////////////////////////////////////////////////////////////
/*
// interrupt for Rx Complete//
void __vector_13 (void)
{
	// Check the bit(7) (RxCn) is a flag to figure that if the receive operation is completed or not //
	UART_u8ReceivedFlag=1;
}
//==================================================================================================
// interrupt for Tx Complete//
void __vector_15 (void)
{
	// Check the bit(7) (RxCn) is a flag to figure that if the receive operation is completed or not //
	UART_u8TransmitFlag=1;
}
//====================================================================================================
extern u8 UART_u8GetReceivedFlag(void)
{
	return UART_u8ReceivedFlag;
}
extern void UART_voidClrReceivedFlag(void)
{
	UART_u8ReceivedFlag=0;
}
//======================================================================================================
extern u8 UART_u8GetTransmitFlag(void)
{
	return UART_u8TransmitFlag;
}
extern void UART_voidClrTransmitFlag(void)
{
	UART_u8TransmitFlag=0;
}
*/
