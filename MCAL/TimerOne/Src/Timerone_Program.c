/*
 * Timerone_Program.c
 *
 *  Created on: May 19, 2024
 *      Author: Toa Fekry
 */

#include "../../../Common/BitMath.h"
#include "../../../Common/Stdtype.h"
#include "../../DIO/Header/DIO_Interface.h"
#include "../Header/TimeOne_Interface.h"

static u8 Timer1_Prescaller=PrescallerValue;
void Timer1_Init()
{
	/*TCCR1A PWM Mode 14 ICR*/
	/*Prescaller=8MHZ
	Freq.=8MHZ
	TickTime=Prescaler/Freq.
	TickTime=1microSec
	Time=20000ms
	Time=TickTime*Value
	Value= 20000;*/

	Timer1_ICR1L=20000;
	ClrBit(Timer1_TCCR1A,WGM10);
	SetBit(Timer1_TCCR1A,WGM11);
	SetBit(Timer1_TCCR1A,WGM12);
	SetBit(Timer1_TCCR1A,WGM13);

	/*OCR1AL*/
	/*Non Inverting Mode*/
	/*Dutycycle/100=CompareValue/2^n
	CompareValue=(Dutycyle*2^n)/100*/

	u8 CompareValue;
	u8 DutyValue=CompareValue/65536;
	CompareValue=(DutyValue*20000)/100;
	Timer1_OCR1AL=CompareValue;

	/*Prescaller=8*/
	Timer1_Prescaller&=0b00000111;
	Timer1_TCCR1A&=0b11111000;
	Timer1_TCCR1A|=Timer1_Prescaller;



}
void Servo_Motor(u8 Angle)
{
	/*PIN*/
	DIO_SetDirectionForPin(DIO_GroupD,DIO_Pin5,DIO_High);

	/*Output*/
	DIO_SetOutputForPin(DIO_GroupD,DIO_Pin5,DIO_Output);

	Angle=Timer1_OCR1AL;

}
