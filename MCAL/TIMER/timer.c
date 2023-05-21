#include "timer.h"

void T_init (uint8_t timerNumber, uint8_t state, uint32_t exponent)
{
	switch (timerNumber)
	{
		case 0:
			switch (state)
			{
				case 0 : //Normal
				TCCR0 &= ~(1<<6);
				TCCR0 &= ~(1<<3);
				break;
				
				case 1: //pPWM
				TCCR0 |= (1<<6);
				TCCR0 &= ~(1<<3);
				break;		 
				
				case 2: //CTC
				TCCR0 &= ~(1<<6);
				TCCR0 |= (1<<3);
				break;
				
				case 3: //fPWM
				TCCR0 |= (1<<6);
				TCCR0 |= (1<<3);
				break;						
			}
			
			switch (exponent)
			{
				case one:
				TCCR0 |= (1<<0);
				break;
				
				case eight:
				TCCR0 |= (1<<1);
				break;
				
				case sixFour:
				TCCR0 |= (1<<1) | (1<<0);
				break;
				
				case twoFiveSix:
				TCCR0 |= (1<<2);
				break;
				
				case tenTwoFour:
				TCCR0 |= (1<<2) | (1<<0);
				break;
				
				default:
				TCCR0 = 0x00;
			}
			
			break;
		case 2:
			switch (state)
			{
				case 0 : //Normal
				TCCR2 &= ~(1<<6);
				TCCR2 &= ~(1<<3);
				break;
				
				case 1: //pPWM
				TCCR2 |= (1<<6);
				TCCR2 &= ~(1<<3);
				break;		 
				
				case 2: //CTC
				TCCR2 &= ~(1<<6);
				TCCR2 |= (1<<3);
				break;
				
				case 3: //fPWM
				TCCR2 |= (1<<6);
				TCCR2 |= (1<<3);
				break;						
			}
			
			switch (exponent)
			{
				case one:
				TCCR2 |= (1<<0);
				break;
				
				case eight:
				TCCR2 |= (1<<1);
				break;
				
				case threeTwo:
				TCCR2 |= (1<<1) | (1<<0);
				break;
				
				case sixFour:
				TCCR2 |= (1<<2);
				break;
				
				case oneTwoEight:
				TCCR2 |= (1<<2) | (1<<0);
				break;
				
				case twoFiveSix:
				TCCR2 |= (1<<2) | (1<<1);
				break;
				
				case tenTwoFour:
				TCCR2 |= (1<<2) | (1<<1) | (1<<0);
				default:
				TCCR2 = 0x00;
			}	
			break;
		}			
	}
	
	void T_delay(uint8_t timerNumber, uint8_t state, uint32_t exponent, uint32_t interrupts, uint8_t CNT)
	{
		i = 0;
		j = 0;
		T_init(timerNumber, state,exponent);
		while (i < interrupts)
		{
			TCNT0 = CNT;
			while ((TIFR & (1<<0)) == 0);
			TIFR |= (1<<0);
			i++;
		}
		T_stop(timerNumber);
		//Time has stopped
		i = 0;
		j = 0;
	}

void T_stop(uint8_t timerNumber)
{
switch (timerNumber)
	{
		case 0:
		TCCR0 = 0x00;
		break;
		case 2:
		TCCR2 = 0x00;
		break;
	}	
}
