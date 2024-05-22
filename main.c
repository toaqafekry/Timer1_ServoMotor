/*
 * main.c
 *
 *  Created on: Apr 5, 2024
 *      Author: Toa Fekry
 */




#include "MCAL/DIO/Header/DIO_Interface.h"
#include "HAL/LED/Header/Led_Interface.h"
#include "MCAL/TimerZero/Header/Timer_Interface.h"
#include "MCAL/TimerOne/Header/TimeOne_Interface.h"



void main()
{
	Timer1_Init();
	Servo_Motor(90);

	while(1)
	{

	}
}













/*
void main()
{
	CompareMatch_PWMInit();

	while(1)
	{
		Timer0_UpdateDutycycle();
	}

}*/



/*void Action();
void main()
{

   Enable Global Interrupt
    GIE_Enable();
    Call Back FN
	Timer_CallBack(Action);
	Timer0 NormalMode
	Timer0_Init();
}

void Action()
{

	Led_Toggle(DIO_GroupC,Led1);

}*/











