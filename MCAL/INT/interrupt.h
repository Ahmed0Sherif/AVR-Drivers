/*
 * interrupt.h
 *
 * Created: 9/14/2022 12:39:57 PM
 *  Author: hp
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_
#include "../../Utilities/registers.h"


//External Interrupt request 0						
#define INT0_vect __vector_1

//External Interrupt request 1
#define INT1_vect __vector_2

//External Interrupt request 2
#define INT2_vect __vector_3

	
enum intSense
{fall, rise, any, low
};

enum int_R
{INT0, INT1, INT2
};
								
void intSense0_1 (uint8_t intrupt, uint8_t sense);
void intSense2 (uint8_t sense);

void intEN(uint8_t intrupt);

#define sei() 	__asm__ __volatile__ ("sei":::"memory")

#define cli() 	__asm__ __volatile__ ("cli":::"memory")

#define ISR(INT_VECT) void INT_VECT(void) __attribute__ ((signal, used));\
void INT_VECT(void)
					
#endif /* INTERRUPT_H_ */