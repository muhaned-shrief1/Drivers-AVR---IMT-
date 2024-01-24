/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/
#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

/*UART Control and status register A*/
#define UCSRnA 				*((volatile u8*)0x2B)

/*UART Control and status register B*/
#define UCSRnB 				*((volatile u8*)0x2A)

/*UART Control and status register C*/
#define UCSRnC 				*((volatile u8*)0x40)

/*UART I/O register*/
#define UDR 				*((volatile u8*)0x2C)

/*UART BAUDRATE registers*/
#define UBRRL 				*((volatile u8*)0x29)
#define UBRRH 				*((volatile u8*)0x40)

/* The equation to calculate the UBBR value */
#define MyUBRR 				(FOCS/16/BaudRate-1)

#endif
