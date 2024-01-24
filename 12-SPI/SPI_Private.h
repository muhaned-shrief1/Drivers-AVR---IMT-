/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/
#ifndef		SPI_PRIVATE_H
#define		SPI_PRIVATE_H

#define		SPI_u8_SPDR_REG			*((volatile u8 *)(0x2F))			// SPI Data Register

#define		SPI_u8_SPCR_REG			*((volatile u8 *)(0x2D))			// SPI Control Register
#define     SPI_u8_SPCR_SPR0		0									// SPI Prescaler Bit0
#define     SPI_u8_SPCR_SPR1		1									// SPI Prescaler Bit1
#define     SPI_u8_SPCR_CPHA		2									// Clock Phase
#define     SPI_u8_SPCR_CPOL		3									// Clock Polarity
#define     SPI_u8_SPCR_MSTR		4									// MASTER bit
#define     SPI_u8_SPCR_DORD		5									// Data OverRun
#define     SPI_u8_SPCR_SPE		    6									// SPI Enable
#define     SPI_u8_SPCR_SPIE		7									// SPI Interrupt Enable

#define		SPI_u8_SPSR_REG			*((volatile u8 *)(0x2E))			// SPI Status Register
#define		SPI_u8_SPSR_SPI2X		0									// SPI Prescaler Bit2
#define		SPI_u8_SPSR_WCOL		6									// SPI Write Collision Flag
#define		SPI_u8_SPSR_SPIF		7									// SPI Interrupt Flag


#endif
