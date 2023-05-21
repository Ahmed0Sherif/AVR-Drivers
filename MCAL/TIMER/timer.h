/*
 * timer.h
 *
 * Created: 9/14/2022 12:40:06 PM
 *  Author: hp
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../../Utilities/registers.h"

#define Time0 '0'
#define Time2 '2'

//StateT
#define Norm '0'
#define pPWM '1'
#define CTC  '2'
#define fPWM '3'

enum prescalar
{	one,
	eight,
	threeTwo,
	sixFour,
	oneTwoEight,
	twoFiveSix,
	tenTwoFour,
};

void T_init (uint8_t timerNumber, uint8_t state, uint32_t exponent);//Initializes timers. Used within a function to start action (i.e. T_delay)
void T_stop (uint8_t timerNumber); //Stops Timers. Used within functions (fo)
void T_delay(uint8_t timerNumber, uint8_t state, uint32_t exponent, uint32_t interrupts, uint8_t CNT);





#endif /* TIMER_H_ */