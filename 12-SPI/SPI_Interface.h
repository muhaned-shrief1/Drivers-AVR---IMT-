/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/
#ifndef		SPI_INTERFACE_H
#define		SPI_INTERFACE_H

/*********************************************************************************/
/* Function: SPI_voidMasterInit			                       				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function initialize MC as Master Node					       	    **/
/*********************************************************************************/
void SPI_voidMasterInit(void);

/*********************************************************************************/
/* Function: SPI_voidSlaveInit			                       				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function initialize MC as Slave Node					       	    **/
/*********************************************************************************/
void SPI_voidSlaveInit(void);

/*********************************************************************************/
/* Function: SPI_voidSlaveInit			                       				    **/
/* I/P Parameters: Copy_u8Data								          		    **/
/* Returns:it returns u8        	                        				    **/
/* Desc:This Function Transmit/recieve data							       	    **/
/*********************************************************************************/
/* Copy_u8Data Options:	Data assigned directly						       	    **/
/*********************************************************************************/
u8 SPI_u8Tranceive(u8 Copy_u8Data);



#endif
