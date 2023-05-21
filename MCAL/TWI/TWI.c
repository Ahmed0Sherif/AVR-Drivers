/*
 * TWI.c
 *
 * Created: 12/23/2022 10:55:02 PM
 *  Author: hp
 */ 
#include "TWI.h"

void TWI_init(void)
{
	TWSR = 0x00; //Where state codes are stored.
	TWBR = BITRATE(TWSR); //Setting Bit Rate
}

uint8_t TWI_start(void)
{
	TWCR = (1<<2)|(1<<5)|(1<<7);
	/*
	* TWI is enabled for bit 2 (TWEN).
	* TWI start condition is activated from pin 5 (TWSTA).
	* TWI interrupt flag is cleared by setting  pin 7 (TWINT).
	*/
	while (!(TWCR &(1<<7)));
	if ((TWSR & 0xF8) != START_STATE)
		return START_NOT_SENT;
	else
		return EVENT_OK;
}

uint8_t TWI_repeated_start(void)
{
	TWCR = (1<<2)|(1<<5)|(1<<7);
	/*
	* TWI is enabled for bit 2 (TWEN).
	* TWI start condition is activated from pin 5 (TWSTA).
	* TWI interrupt flag is cleared by setting  pin 7 (TWINT).
	*/
	while (!(TWCR &(1<<7))); //Checking bit  TWINT
	if ((TWSR & 0xF8) != REPEATED_START_STATE)
		return REPEATED_START_STATE;
	else
		return EVENT_OK;
}

uint8_t TWI_address_select (uint8_t address, uint8_t rw)
{
	uint8_t status;
	if (rw == WRITE)
		TWDR  = address + 0;
	else if (rw == READ)
		TWDR = address + 1;
	else
	{
	}
	/*N.B. For Correct operation for the TWI, data is written on the TWDR before setting the TWINT bit*/
	TWCR = (1<<2)|(1<<7); /*Enable TWI and clear INT flag*/
	while (!(TWCR &(1<<7))); //Checking bit  TWINT, when the TWI finishes it job
	status =  TWSR & 0xf8; //Reading the status register.
	/*Checking the status stats*/
	if (status == SLA_W_ACK_STATE)
		return SLA_W_ACK_SENT;
		
	else if (status == SLA_W_NACK_STATE)
		return SLA_W_NACK_SENT;
		
	else if (status == SLA_R_ACK_STATE)
	return SLA_R_ACK_SENT;
	
	else if (status == SLA_R_NACK_STATE)
	return SLA_R_NACK_SENT;
	
	else
		return SLA_RW_FAILED;
	}


uint8_t TWI_data_event (uint8_t *data, uint8_t rw, uint8_t ack)
{
	uint8_t status;
	if (rw == WRITE)
	{
		TWDR = *data;
		TWCR = (1<<2)|(1<<7); /*Enable TWI and clear INT flag*/
		while (!(TWCR &(1<<7))); //Checking bit  TWINT, when the TWI finishes it job
		status = TWSR & 0xf8;
		
		if (status == DATA_WRITE_ACK_STATE)
			return DATA_WRITE_ACK_SENT;
		else if (status == DATA_WRITE_NACK_STATE)
			return DATA_WRITE_NACK_SENT;
		else
			return DATA_WRITE_FAILED;
	}
	else if (rw == READ)
	{
		if (ack == ACK) /*READ W_ACK --> Master */
			TWCR = (1<<2)|(1<<6)|(1<<7);
			/*TWI is enabled for bit 2 (TWEN).
			* TWI acknowledge bit (bit 6) is activated (TWEA).
			* TWI interrupt flag is cleared by setting  pin 7 (TWINT).
			*/
		else if (ack == NACK)
			TWCR = (1<<2)|(1<<7);
		while (!(TWCR &(1<<7))); //Checking bit  TWINT, when the TWI finishes it job
		*data = TWDR;
		status = TWSR & 0xf8;
		if (status == DATA_READ_ACK_STATE)
			return DATA_READ_ACK_SENT;
		else if (status == DATA_READ_NACK_STATE)
			return DATA_READ_NACK_SENT;
		else
			return DATA_READ_FAILED;	
	}
	else{
		return DATA_READ_FAILED;
	}
	
}

void TWI_stop (void)
{
	TWCR = (1<<2)|(1<<4)|(1<<7);
	/*
	* TWI is enabled for bit 2 (TWEN).
	* TWI stop condition is activated from pin 4 (TWSTO).
	* TWI interrupt flag is cleared by setting  pin 7 (TWINT).
	*/
	while (TWCR & (1<<4)); /*Wait until the stop condition is executed. */
}