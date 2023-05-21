#include "interrupt.h"

void intSense0_1 (uint8_t intrupt, uint8_t sense)
{
	switch(intrupt)
	{
		case 0: //INT0
		switch (sense)
		{
			case fall:
			MCUCR |= (1<<1) ;
			break;
			case rise:
			MCUCR |= (1<<1) | (1<<0);
			break;
			case any:
			MCUCR |= (1<<0);
			break;
			case low:
			MCUCR &= ~((1<<1) | (1<<0));
			break;
		}
		case 1: //INT1
		switch (sense)
		{
			case fall:
			MCUCR |= (1<<3) ;
			break;
			case rise:
			MCUCR |= (1<<3) | (1<<2);
			break;
			case any:
			MCUCR |= (1<<2);
			break;
			case low:
			MCUCR &= ~((1<<3) | (1<<2));
			break;
		}
	}
}

void intSense2 (uint8_t sense)
{
	switch (sense)
	{
		case 0: //falling
		MCUCSR &= ~(1<<6);
		break;
		case 1://rising
		MCUCSR |= (1<<6);
		break;
	}
}

void intEN (uint8_t intrupt)
{
	switch(intrupt)
	{
		case INT0:
		GICR |= (1<<6);
		break;
		
		case INT1:
		GICR |= (1<<7);
		break;
		
		case INT2:
		GICR |= (1<<5);
		break;
	}	
}
