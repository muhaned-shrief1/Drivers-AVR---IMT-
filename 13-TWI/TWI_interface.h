/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/
#ifndef TWI_INTERFACE_H
#define TWI_INTERFACE_H

typedef enum
{
	NoError,
	StartConditionError,
	RepeatedStartError,
	SlaveAddressWithWriteError,
	SlaveAddressWithReadError,
	MasterWriteByteWithACKError,
	MasterReadByteWithACKError,
}TWI_ErrorStatus_t;

/*********************************************************************************/
/* Function: TWI_voidInitMaster			                       				    **/
/* I/P Parameters: Copy_u8Address							          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function initialize Two wire interface (I2C) as Master Node		**/
/*********************************************************************************/
/* Copy_u8Address:Assign the address of the Master Node							**/
/*********************************************************************************/
void TWI_voidInitMaster(u8 Copy_u8Address);

/*********************************************************************************/
/* Function: TWI_voidInitSlave			                       				    **/
/* I/P Parameters: Copy_u8Address							          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function initialize Two wire interface (I2C) as Slave Node			**/
/*********************************************************************************/
/* Copy_u8Address:Assign the address of the Slave Node							**/
/*********************************************************************************/
void TWI_voidInitSlave(u8 Copy_u8Address);

/*********************************************************************************/
/* Function: TWI_ErrorStatusSendStartConditionWithACK	    				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns TWI_ErrorStatus_t                        				    **/
/* Desc:This Function Send Start Condition With ACK								**/
/*********************************************************************************/
TWI_ErrorStatus_t TWI_ErrorStatusSendStartConditionWithACK(void);

/*********************************************************************************/
/* Function: TWI_ErrorStatusSendRepeatedStartConditionWithACK				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns TWI_ErrorStatus_t                        				    **/
/* Desc:This Function Send repeated Start Condition With ACK					**/
/*********************************************************************************/
TWI_ErrorStatus_t TWI_ErrorStatusSendRepeatedStartConditionWithACK(void);

/*********************************************************************************/
/* Function: TWI_ErrorStatusSendSlaveAddressWithWriteACK					    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns TWI_ErrorStatus_t                        				    **/
/* Desc:This Function Send Slave Address With Write ACK							**/
/*********************************************************************************/
TWI_ErrorStatus_t TWI_ErrorStatusSendSlaveAddressWithWriteACK(u8 Copy_u8SlaveAddress);

/*********************************************************************************/
/* Function: TWI_ErrorStatusSendSlaveAddressWithReadACK						    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns TWI_ErrorStatus_t                        				    **/
/* Desc:This Function Send Slave Address With Read ACK							**/
/*********************************************************************************/
TWI_ErrorStatus_t TWI_ErrorStatusSendSlaveAddressWithReadACK(u8 Copy_u8SlaveAddress);

/*********************************************************************************/
/* Function: TWI_ErrorStatusMasterWriteDataByteWithACK						    **/
/* I/P Parameters: Copy_u8DataByte							          		    **/
/* Returns:it returns TWI_ErrorStatus_t                        				    **/
/* Desc:This Function allows master to write byte of data With ACK				**/
/*********************************************************************************/
/* Copy_u8DataByte options: Byte of data to be sent			          		    **/
/*********************************************************************************/
TWI_ErrorStatus_t TWI_ErrorStatusMasterWriteDataByteWithACK(u8 Copy_u8DataByte);

/*********************************************************************************/
/* Function: TWI_ErrorStatusMasterReadDataByteWithACK						    **/
/* I/P Parameters: *Copy_pu8ReceivedByte					          		    **/
/* Returns:it returns TWI_ErrorStatus_t                        				    **/
/* Desc:This Function allows master to recieve byte of data With ACK			**/
/*********************************************************************************/
/* *Copy_pu8ReceivedByte options: Address of variable to store the recieved byte**/
/*********************************************************************************/
TWI_ErrorStatus_t TWI_ErrorStatusMasterReadDataByteWithACK(u8 * Copy_pu8ReceivedByte);

/*********************************************************************************/
/* Function: TWI_voidSendStopCondition	                       				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Sends a stop condition to the bus							**/
/*********************************************************************************/
void TWI_voidSendStopCondition(void);


#endif
