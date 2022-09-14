/***********************************************************/
/***************** Author	: Kyrillos Adel	****************/
/***************** Date		: 11-9-2022    	****************/
/***************** Module	: Timer      	****************/
/***************** Version	: v1.0      	****************/
/***********************************************************/

#ifndef _MCAL_TIMER_TIMER_REG_H_
#define _MCAL_TIMER_TIMER_REG_H_

#define TCCR0				*((volatile u8*)0x53)
#define TCCR0_WGM00			6
#define TCCR0_WGM01			3
#define TCCR0_CS02			2
#define TCCR0_CS01			1
#define TCCR0_CS00			0

#define OCR0				*((volatile u8*)0x5C)

#define	TIMSK				*((volatile u8*)0x59)
#define TIMSK_OCIE0			1
#define TIMSK_TOIE0			0

#define TIFR				*((volatile u8*)0x58)
#define TIFR_TOV0			0
#define TIFR_OCF0			1





#endif /* MCAL_TIMER_TIMER_REG_H_ */
