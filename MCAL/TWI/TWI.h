/*
 * TWI.h
 *
 * Created: 12/23/2022 10:55:17 PM
 *  Author: hp
 */ 


#ifndef TWI_H_
#define TWI_H_
#include <math.h>
#include "../../Utilities/registers.h"

#define F_CPU 1000000U
#define SCL_CLK 1000000U

#define BITRATE(TWSR) ((F_CPU/SCL_CLK)-16)/(2*pow(4,(TWSR&((1<<0)|(1<<1)))))

#define WRITE 0
#define READ 1

#define ACK 0
#define NACK 1

/*States*/
#define START_STATE				0x08
#define	REPEATED_START_STATE	0x10
#define	SLA_W_ACK_STATE			0x18
#define SLA_W_NACK_STATE		0x20
#define SLA_R_ACK_STATE			0x40
#define SLA_R_NACK_STATE		0x48
#define DATA_WRITE_ACK_STATE	0x28
#define DATA_WRITE_NACK_STATE	0x30
#define DATA_READ_ACK_STATE		0x50
#define DATA_READ_NACK_STATE	0x58

/*returns*/
#define EVENT_OK				0
#define	START_NOT_SENT			1
#define	REPEATED_START_NOT_SENT	2
#define SLA_W_ACK_SENT			3
#define SLA_W_NACK_SENT			4
#define SLA_R_ACK_SENT			5
#define SLA_R_NACK_SENT			6
#define	SLA_RW_FAILED			7
#define	DATA_WRITE_ACK_SENT		8
#define DATA_WRITE_NACK_SENT	9
#define DATA_WRITE_FAILED		10
#define	DATA_READ_ACK_SENT		11
#define DATA_READ_NACK_SENT		12
#define DATA_READ_FAILED		13


void TWI_init();
uint8_t TWI_start(void);
uint8_t TWI_repeated_start(void);
uint8_t TWI_address_select (uint8_t address, uint8_t rw);
uint8_t TWI_data_event (uint8_t *data, uint8_t rw, uint8_t ack); /*The data argument is an input/output argument
																   The function can receive data from this argument
																   or can return data through the same argument
																   hence, the pointer. */
void TWI_stop (void);

#endif /* TWI_H_ */