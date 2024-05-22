/*
 * TimerOne_Private.h
 *
 *  Created on: May 19, 2024
 *      Author: Toa Fekry
 */

#ifndef MCAL_TIMERONE_HEADER_TIMERONE_PRIVATE_H_
#define MCAL_TIMERONE_HEADER_TIMERONE_PRIVATE_H_

/*Timer1*/
/*TCCR1A*/
#define COM1A1 7
#define COM1A0 6
#define COM1B1 5
#define COM1B0 4
#define FOC1A  3
#define FOC1B  2
#define WGM11  1
#define WGM10  0

/*TCCR1B*/
#define ICNC1 7
#define ICES1 6
#define WGM13 4
#define WGM12 3
#define CS12  2
#define CS11  1
#define CS10  0

/*TIMSK*/
#define TICIE1 5
#define OCIE1A 4
#define OCIE1B 3
#define TOIE1  2

/*TIFR*/
#define ICF1  5
#define OCF1A 4
#define OCF1B 3
#define TOV1  2

#endif /* MCAL_TIMERONE_HEADER_TIMERONE_PRIVATE_H_ */
