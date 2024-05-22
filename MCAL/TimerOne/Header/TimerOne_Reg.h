/*
 * TimerOne_Reg.h
 *
 *  Created on: May 19, 2024
 *      Author: Toa Fekry
 */

#ifndef MCAL_TIMERONE_HEADER_TIMERONE_REG_H_
#define MCAL_TIMERONE_HEADER_TIMERONE_REG_H_

#include "../../../Common/Stdtype.h"

/*Timer1*/
/*TCCR1A*/
#define Timer1_TCCR1A     *((volatile u8 *)0X4F)

/*TCCR1B*/
#define Timer1_TCCR1B     *((volatile u8 *)0X4E)

/*TCNT1H and TCNT1L*/
#define Timer1_TCNT1L     *((volatile u8 *)0X27)

/*OCR1AL*/
#define Timer1_OCR1AL    *((volatile u8 *)0X4A)

/*OCR1BL*/
#define Timer1_OCR1BL    *((volatile u8 *)0X48)

/*ICR1L*/
#define Timer1_ICR1L     *((volatile u8 *)0X46)

/*TIMSK*/
#define Timer1Interrupt_TIMSK   *((volatile u8 *)0X59)

/*TIFR*/
#define Timer1InterruptFlag_TIFR  *((volatile u8 *)0X58)




#endif /* MCAL_TIMERONE_HEADER_TIMERONE_REG_H_ */
