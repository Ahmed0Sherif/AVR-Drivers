/*
 * dio.c
 *
 * Created: 9/12/2022 10:27:41 AM
 *  Author: hp
 */ 
#include "dio.h"

//Implementation of DIO_INIT

void DIO_init(uint8_t portNumber, uint8_t pinNumber, uint8_t direction )
{
	switch(portNumber)
	{
		case portA:
		if (direction == IN)
		DDRA &= ~(1<<pinNumber);
		else if (direction == OUT)
		DDRA |= (1<<pinNumber);
		else
		{};
		break;
		
		case portB:
		if (direction == IN)
		DDRB &= ~(1<<pinNumber);
		else if (direction == OUT)
		DDRB |= (1<<pinNumber);
		else
		{};
		break;
		
		case portC:
		if (direction == IN)
		DDRC &= ~(1<<pinNumber);
		else if (direction == OUT)
		DDRC |= (1<<pinNumber);
		else
		{};
		break;
		
		case portD:
		if (direction == IN)
		DDRD &= ~(1<<pinNumber);
		else if (direction == OUT)
		DDRD |= (1<<pinNumber);
		else
		{};
		break;
	}
}

void DIO_write(uint8_t portNumber, uint8_t pinNumber, uint8_t value )
{
		switch(portNumber)
	{
		case portA:
		if (value == LOW)
		PORTA &= ~(1<<pinNumber);
		else if (value == HIGH)
		PORTA |= (1<<pinNumber);
		else
		{};
		break;
		
		case portB:
		if (value == LOW)
		PORTB &= ~(1<<pinNumber);
		else if (value == HIGH)
		PORTB |= (1<<pinNumber);
		else
		{};
		break;
		
		case portC:
		if (value == LOW)
		PORTC &= ~(1<<pinNumber);
		else if (value == HIGH)
		PORTC |= (1<<pinNumber);
		else
		{};
		break;
		
		case portD:
		if (value == LOW)
		PORTD &= ~(1<<pinNumber);
		else if (value == HIGH)
		PORTD |= (1<<pinNumber);
		else
		{};
		break;
	}
}

void DIO_read (uint8_t portNumber, uint8_t pinNumber, uint8_t* value)
{
			switch(portNumber)
	{
		case portA:
		*value = (PINA&(1<<pinNumber))>>pinNumber;
		break;
		
		case portB:
		*value = (PINB&(1<<pinNumber))>>pinNumber;
		break;
		
		case portC:
		*value = (PINC&(1<<pinNumber))>>pinNumber;
		break;
		
		case portD:
		*value = (PIND&(1<<pinNumber))>>pinNumber;
		break;
	}
}

void DIO_toggle(uint8_t portNumber, uint8_t pinNumber)
{
		switch(portNumber)
		{
			case portA:
			PORTA ^= (1<<pinNumber);
			break;
			
			case portB:
			PORTB ^= (1<<pinNumber);
			break;
			
			case portC:
			PORTC ^= (1<<pinNumber);	
			break;
			
			case portD:
			PORTD ^= (1<<pinNumber);
			break;
			
		}
}