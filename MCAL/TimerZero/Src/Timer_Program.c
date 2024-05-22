/*
 * Timer_Program.c
 *
 *  Created on: May 18, 2024
 *      Author: Toa Fekry
 */

#include "../../../Common/BitMath.h"
#include "../../../Common/Stdtype.h"
#include "../../TimerZero/Header/Timer_Interface.h"

/*Timer0*/
static u8 Timer0_Prescaller=PrescallerValue;
void Timer0_Init()
{
	/*Normal Mode*/
	/*TCCR0  Waveform Generation Mode*/
	ClrBit(Timer0_TCCR0,WGM01);
	ClrBit(Timer0_TCCR0,WGM00);

	/*TCNT0*/
	Timer0_TCNT0=PreloadValue;

	/*Enable Interrupt*/
	/*TIMSK*/
	SetBit(TimerInerrupt_TIMSK,TOIE0);

	/*Prescaller=8*/
	Timer0_Prescaller&= 0b00000111;
	Timer0_TCCR0&=  0b11111000;
	Timer0_TCCR0|=PrescallerValue;

}


void CompareMatch_Init()
{
	/*CTC*/
	/*TCCR0  Waveform Generation Mode*/
	ClrBit(Timer0_TCCR0,WGM00);
	ClrBit(Timer0_TCCR0,WGM00);
	SetBit(Timer0_TCCR0,WGM01);

	/*Toggle*/
	SetBit(Timer0_TCCR0,COM00);
	ClrBit(Timer0_TCCR0,COM01);

	/*TCNT0*/
	Compare_OCR0=CompareValue;

	/*Enable Interrupt*/
	/*TIMSK*/
	SetBit(TimerInerrupt_TIMSK,OCIE0);

	/*Prescaller=8*/
	Timer0_Prescaller&= 0b00000111;
	Timer0_TCCR0&=  0b11111000;
	Timer0_TCCR0|=PrescallerValue;


}

void CompareMatch_PWMInit(u8 PWMtype,u8 Outputmode,u8 Dutycycle)
{
	/*Type=Fast Mode*/
	/*TCCR0  Waveform Generation Mode*/
	SetBit(Timer0_TCCR0,WGM00);
	SetBit(Timer0_TCCR0,WGM01);

	/*Outputmode=InvertingMode*/
	SetBit(Timer0_TCCR0,COM00);
	SetBit(Timer0_TCCR0,COM01);

	/*Duty cycle*/
	u8 Compare_Value;
	Dutycycle/=100;
	Compare_Value=(1-Dutycycle)*256/100;

	/*OCR0 Reg*/
	Compare_OCR0=Compare_Value;   /* Put the value of compare in register ocro*/

	/*Prescaller=No Prescalling*/
	SetBit(Timer0_TCCR0,CS00);
	ClrBit(Timer0_TCCR0,CS01);
	ClrBit(Timer0_TCCR0,CS02);

}

void Timer0_UpdateDutycycle(u8 Dutycycle)
{
	/*Update The Dutycycle*/
	u8 Compare_Value;
	Dutycycle/=100;
	Compare_Value=(1-Dutycycle)*256/100;

	/*Update The OCRO*/
	Compare_OCR0=Compare_Value;

}


/*Normal Mode*/
/*Global Pointer to Function*/
static void (*Timer)(void)=Null;
void Timer_CallBack (void(*PF)(void))
{
	if(PF!=Null)
	{
		Timer=PF;
	}

}
/*ISR Vector Normal Mode*/
void __vector_11()
{
	static u16 counter=0;
	counter++;
	if(counter==NumberOfOVFCount)
	{
		/*Action*/
		if(Timer!=Null)
		{
			Timer();
		}
	}
	Timer0_TCNT0=PreloadValue;
	counter=0;

}


