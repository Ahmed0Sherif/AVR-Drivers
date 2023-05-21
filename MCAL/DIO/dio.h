/*
 * dio.h
 *
 * Created: 9/12/2022 10:27:52 AM
 *  Author: hp
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "../../Utilities/registers.h"


/************************************************************************/
/*Defining Macros & Enums                                                        */
/************************************************************************/
#define portA 'A'
#define portB 'B'
#define portC 'C'
#define portD 'D'

enum dir
{	IN,
	OUT
};

enum out
{	LOW,
	HIGH,
};

/************************************************************************/
/*Function Prototypes                                                                      */
/************************************************************************/
void DIO_init(uint8_t portNumber, uint8_t pinNumber, uint8_t direction);
void DIO_write(uint8_t portNumber, uint8_t pinNumber, uint8_t value);
void DIO_read (uint8_t portNumber, uint8_t pinNumber, uint8_t* value);
void DIO_toggle(uint8_t portNumber, uint8_t pinNumber);

#endif /* DIO_H_ */