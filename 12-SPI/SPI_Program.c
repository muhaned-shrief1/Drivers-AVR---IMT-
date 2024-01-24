/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"

#include "MCAL/SPI/SPI_Interface.h"
#include "MCAL/SPI/SPI_Private.h"
#include "MCAL/SPI/SPI_Config.h"


/*********************************************************************************/
/* Function: SPI_voidMasterInit			                       				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function initialize MC as Master Node					       	    **/
/*********************************************************************************/
void SPI_voidMasterInit(void)
{
	/*Set The Node To Be Master Node*/
	SET_BIT(SPI_u8_SPCR_REG, SPI_u8_SPCR_MSTR);
	/*Set The MSB to be sent first*/
	CLR_BIT(SPI_u8_SPCR_REG, SPI_u8_SPCR_DORD);

	/*Set The Leading Edge To be The Rising Edge*/
	CLR_BIT(SPI_u8_SPCR_REG, SPI_u8_SPCR_CPOL);

	/*Sample At Leading Edge*/
	CLR_BIT(SPI_u8_SPCR_REG, SPI_u8_SPCR_CPHA);

	/*Clock Prescaler, divide by 16*/
	SET_BIT(SPI_u8_SPCR_REG, SPI_u8_SPCR_SPR0);
	CLR_BIT(SPI_u8_SPCR_REG, SPI_u8_SPCR_SPR1);
	CLR_BIT(SPI_u8_SPSR_REG, SPI_u8_SPSR_SPI2X);
	/*Enable The SPI*/
	SET_BIT(SPI_u8_SPCR_REG, SPI_u8_SPCR_SPE);
}

/*********************************************************************************/
/* Function: SPI_voidSlaveInit			                       				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function initialize MC as Slave Node					       	    **/
/*********************************************************************************/
void SPI_voidSlaveInit(void)
{
	/*Set The Node To Be Salve Node*/
	CLR_BIT(SPI_u8_SPCR_REG, SPI_u8_SPCR_MSTR);
	/*Set The MSB to be sent first*/
	CLR_BIT(SPI_u8_SPCR_REG, SPI_u8_SPCR_DORD);

	/*Set The Leading Edge To be The Rising Edge*/
	CLR_BIT(SPI_u8_SPCR_REG, SPI_u8_SPCR_CPOL);

	/*Sample At Leading Edge*/
	CLR_BIT(SPI_u8_SPCR_REG, SPI_u8_SPCR_CPHA);
	/*Enable The SPI*/
	SET_BIT(SPI_u8_SPCR_REG, SPI_u8_SPCR_SPE);
}

/*********************************************************************************/
/* Function: SPI_voidSlaveInit			                       				    **/
/* I/P Parameters: Copy_u8Data								          		    **/
/* Returns:it returns u8        	                        				    **/
/* Desc:This Function Transmit/receive data							       	    **/
/*********************************************************************************/
/* Copy_u8Data Options:	Data assigned directly						       	    **/
/*********************************************************************************/
u8 SPI_u8Tranceive(u8 Copy_u8Data)
{
	/*Set The Data in SPI_u8_SPDR Register To Send*/
	SPI_u8_SPDR_REG = Copy_u8Data;

	/*Polling (Busy Waiting) until the transfer complete*/
	while(GET_BIT(SPI_u8_SPSR_REG, SPI_u8_SPSR_SPIF) == 0);

	/*Clear The Flag*/
	SET_BIT(SPI_u8_SPSR_REG, SPI_u8_SPSR_SPIF);

	/*Get The Exchanged Data*/
	return SPI_u8_SPDR_REG;
}








