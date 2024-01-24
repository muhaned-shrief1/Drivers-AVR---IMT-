/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "MCAL/TWI/TWI_interface.h"
#include "MCAL/TWI/TWI_private.h"
#include "MCAL/TWI/TWI_config.h"

/*********************************************************************************/
/* Function: TWI_voidInitMaster			                       				    **/
/* I/P Parameters: Copy_u8Address							          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function initialize Two wire interface (I2C) as Master Node		**/
/*********************************************************************************/
/* Copy_u8Address:Assign the address of the Master Node							**/
/*********************************************************************************/
void TWI_voidInitMaster(u8 Copy_u8Address)
{
	/*Enable Acknowledge Bit*/
	SET_BIT(TWI_u8_TWCR_REG, TWI_u8_TWCR_TWEA);

	/*Set SCL frequency to 100KHz, with 8MHz system frequency*/
	/*1- Set TWI_u8_TWBR = 2*/
	TWI_u8_TWBR_REG = 2;
	/*2- Clear The Prescaler bit (TWPS0 - TWPS1)*/
	CLR_BIT(TWI_u8_TWSR_REG, TWI_u8_TWSR_TWPS0);
	CLR_BIT(TWI_u8_TWSR_REG, TWI_u8_TWSR_TWPS1);

	/*Check if the master node will be addressed or not*/
	if(Copy_u8Address == 0)
	{
		/*Do Nothing*/
	}
	else
	{
		/*Set The Required Address to The Master*/
		TWI_u8_TWAR_REG = (Copy_u8Address << 1);
	}

	/*Enable TWI*/
	SET_BIT(TWI_u8_TWCR_REG, TWI_u8_TWCR_TWEN);
}

/*********************************************************************************/
/* Function: TWI_voidInitSlave			                       				    **/
/* I/P Parameters: Copy_u8Address							          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function initialize Two wire interface (I2C) as Slave Node			**/
/*********************************************************************************/
/* Copy_u8Address:Assign the address of the Slave Node							**/
/*********************************************************************************/
void TWI_voidInitSlave(u8 Copy_u8Address)
{
	/*Set The Required Address to The Slave*/
	TWI_u8_TWAR_REG = Copy_u8Address << 1;

	/*Enable Acknowledge Bit*/
	SET_BIT(TWI_u8_TWCR_REG, TWI_u8_TWCR_TWEA);

	/*Enable TWI*/
	SET_BIT(TWI_u8_TWCR_REG, TWI_u8_TWCR_TWEN);
}

/*********************************************************************************/
/* Function: TWI_ErrorStatusSendStartConditionWithACK	    				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns TWI_ErrorStatus_t                        				    **/
/* Desc:This Function Send Start Condition With ACK								**/
/*********************************************************************************/
TWI_ErrorStatus_t TWI_ErrorStatusSendStartConditionWithACK(void)
{
	TWI_ErrorStatus_t Local_ErrorStatus = NoError;
//	TWI_u8_TWCR |= (1 << TWI_u8_TWCR_TWINT) | (1 << TWI_u8_TWCR_TWSTA) | (1 << TWI_u8_TWCR_TWEN);
	/*Send Start Condition Bit*/
		SET_BIT(TWI_u8_TWCR_REG, TWI_u8_TWCR_TWSTA);

	/*Clear The TWINT Flag*/
	SET_BIT(TWI_u8_TWCR_REG, TWI_u8_TWCR_TWINT);

	/*wait until the operation finishes and the flag is raised again*/
	while(GET_BIT(TWI_u8_TWCR_REG, TWI_u8_TWCR_TWINT) == 0 );

	if((TWI_u8_TWSR_REG & STATUS_BIT_MASK) != START_ACK)
	{
		Local_ErrorStatus = StartConditionError;
	}
	else
	{
		/*Do Nothing*/
	}
	return Local_ErrorStatus;
}

/*********************************************************************************/
/* Function: TWI_ErrorStatusSendRepeatedStartConditionWithACK				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns TWI_ErrorStatus_t                        				    **/
/* Desc:This Function Send repeated Start Condition With ACK					**/
/*********************************************************************************/
TWI_ErrorStatus_t TWI_ErrorStatusSendRepeatedStartConditionWithACK(void)
{
	TWI_ErrorStatus_t Local_ErrorStatus = NoError;
	TWI_u8_TWCR_REG |= (1 << TWI_u8_TWCR_TWINT) | (1 << TWI_u8_TWCR_TWSTA) | (1 << TWI_u8_TWCR_TWEN);
	/*Send Start Condition Bit*/
	//	SET_BIT(TWI_u8_TWCR, TWI_u8_TWCR_TWSTA);

	/*Clear The TWINT Flag*/
	//	SET_BIT(TWI_u8_TWCR, TWI_u8_TWCR_TWINT);

	/*wait until the operation finishes and the flag is raised again*/
	while(GET_BIT(TWI_u8_TWCR_REG, TWI_u8_TWCR_TWINT) == 0 );

	/*Check For The Condition Status Code*/
	if((TWI_u8_TWSR_REG & STATUS_BIT_MASK) != REP_START_ACK)
	{
		Local_ErrorStatus = RepeatedStartError;
	}
	return Local_ErrorStatus;
}

/*********************************************************************************/
/* Function: TWI_ErrorStatusSendSlaveAddressWithWriteACK					    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns TWI_ErrorStatus_t                        				    **/
/* Desc:This Function Send Slave Address With Write ACK							**/
/*********************************************************************************/
TWI_ErrorStatus_t TWI_ErrorStatusSendSlaveAddressWithWriteACK(u8 Copy_u8SlaveAddress)
{
	TWI_ErrorStatus_t Local_ErrorStatus = NoError;
	u8 Local_u8TWI_u8_TWCRValue = 0;

	/*Set 7 bits slave address to the bus*/
	TWI_u8_TWDR_REG = (Copy_u8SlaveAddress << 1);

	/*Set The Write Request in the LSB in the data Register*/
	CLR_BIT(TWI_u8_TWDR_REG, TWI_u8_TWDR_TWD0);

	/*Clear The Start Condition Bit*/
	CLR_BIT(TWI_u8_TWCR_REG, TWI_u8_TWCR_TWSTA);

	/*Clear The TWINT Flag*/
	SET_BIT(TWI_u8_TWCR_REG, TWI_u8_TWCR_TWINT);

	/*wait until the operation finishes and the flag is raised again*/
	while(GET_BIT(TWI_u8_TWCR_REG, TWI_u8_TWCR_TWINT) == 0 );

	/*Check For The Condition Status Code*/
	if((TWI_u8_TWSR_REG & STATUS_BIT_MASK) != SLAVE_ADD_AND_WR_ACK)
	{
		Local_ErrorStatus = SlaveAddressWithWriteError;
	}
	return Local_ErrorStatus;
}


/*********************************************************************************/
/* Function: TWI_ErrorStatusSendSlaveAddressWithReadACK						    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns TWI_ErrorStatus_t                        				    **/
/* Desc:This Function Send Slave Address With Read ACK							**/
/*********************************************************************************/
TWI_ErrorStatus_t TWI_ErrorStatusSendSlaveAddressWithReadACK(u8 Copy_u8SlaveAddress)
{
	TWI_ErrorStatus_t Local_ErrorStatus = NoError;

	/*Set 7 bits slave address to the bus*/
	TWI_u8_TWDR_REG = Copy_u8SlaveAddress << 1;

	/*Set The Read Request in the LSB in the data Register*/
	SET_BIT(TWI_u8_TWDR_REG, TWI_u8_TWDR_TWD0);

	/*Clear The Start Condition Bit*/
	CLR_BIT(TWI_u8_TWCR_REG, TWI_u8_TWCR_TWSTA);

	/*Clear The TWINT Flag*/
	SET_BIT(TWI_u8_TWCR_REG, TWI_u8_TWCR_TWINT);

	/*wait until the operation finishes and the flag is raised again*/
	while(GET_BIT(TWI_u8_TWCR_REG, TWI_u8_TWCR_TWINT) == 0 );

	/*Check For The Condition Status Code*/
	if((TWI_u8_TWSR_REG & STATUS_BIT_MASK) != SLAVE_ADD_AND_RD_ACK)
	{
		Local_ErrorStatus = SlaveAddressWithReadError;
	}
	return Local_ErrorStatus;
}



/*********************************************************************************/
/* Function: TWI_ErrorStatusMasterWriteDataByteWithACK						    **/
/* I/P Parameters: Copy_u8DataByte							          		    **/
/* Returns:it returns TWI_ErrorStatus_t                        				    **/
/* Desc:This Function allows master to write byte of data With ACK				**/
/*********************************************************************************/
/* Copy_u8DataByte options: Byte of data to be sent			          		    **/
/*********************************************************************************/
TWI_ErrorStatus_t TWI_ErrorStatusMasterWriteDataByteWithACK(u8 Copy_u8DataByte)
{

	TWI_ErrorStatus_t Local_ErrorStatus = NoError;


	/*Set The Data To The TWI_u8_TWDR Register*/
	TWI_u8_TWDR_REG = Copy_u8DataByte;



	/*Clear The TWINT Flag*/
	SET_BIT(TWI_u8_TWCR_REG, TWI_u8_TWCR_TWINT);


	/*wait until the operation finishes and the flag is raised again*/
	while(GET_BIT(TWI_u8_TWCR_REG, TWI_u8_TWCR_TWINT) == 0 );

	/*Check For The Condition Status Code*/
	if((TWI_u8_TWSR_REG & STATUS_BIT_MASK) != MSTR_WR_BYTE_ACK)
	{
		Local_ErrorStatus = MasterWriteByteWithACKError;
	}
	return Local_ErrorStatus;
}

/*********************************************************************************/
/* Function: TWI_ErrorStatusMasterReadDataByteWithACK						    **/
/* I/P Parameters: *Copy_pu8ReceivedByte					          		    **/
/* Returns:it returns TWI_ErrorStatus_t                        				    **/
/* Desc:This Function allows master to recieve byte of data With ACK			**/
/*********************************************************************************/
/* *Copy_pu8ReceivedByte options: Address of variable to store the recieved byte**/
/*********************************************************************************/
TWI_ErrorStatus_t TWI_ErrorStatusMasterReadDataByteWithACK(u8 * Copy_pu8ReceivedByte)
{
	TWI_ErrorStatus_t Local_ErrorStatus = NoError;

	/*Clear The TWINT Flag, To Make The Slave To Send its Data*/
	SET_BIT(TWI_u8_TWCR_REG, TWI_u8_TWCR_TWINT);

	/*wait until the operation finishes and the flag is raised again*/
	while(GET_BIT(TWI_u8_TWCR_REG, TWI_u8_TWCR_TWINT) == 0 );

	/*Check For The Condition Status Code*/
	if((TWI_u8_TWSR_REG & STATUS_BIT_MASK) != MSTR_RD_BYTE_WITH_ACK)
	{
		Local_ErrorStatus = MasterReadByteWithACKError;
	}
	else
	{
		/*Read The Received Data*/
		*Copy_pu8ReceivedByte = TWI_u8_TWDR_REG;
	}

	return Local_ErrorStatus;

}

/*********************************************************************************/
/* Function: TWI_voidSendStopCondition	                       				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Sends a stop condition to the bus							**/
/*********************************************************************************/
void TWI_voidSendStopCondition(void)
{

	/*Send a stop condition on the bus*/
	SET_BIT(TWI_u8_TWCR_REG, TWI_u8_TWCR_TWSTO);

	/*Clear The TWINT Flag*/
	SET_BIT(TWI_u8_TWCR_REG, TWI_u8_TWCR_TWINT);
}








