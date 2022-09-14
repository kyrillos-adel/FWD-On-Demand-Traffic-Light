/***********************************************************/
/***************** Author	: Kyrillos Adel	****************/
/***************** Date		: 11-9-2022    	****************/
/***************** Module	: Timer      	****************/
/***************** Version	: v1.0      	****************/
/***********************************************************/

#include "Timer_config.h"
#include "Timer_private.h"
#include "Timer_int.h"
#include "Timer_reg.h"
#include "../EXTI/EXTI_int.h"
#include "../../Libs/bitmath.h"
#include "../../Libs/stderrors.h"
#include "../../Libs/stdtypes.h"


f32 Timer0_overflowTime = ((f32)TIMER0_PRESCALAR/(f32)CPU_FREQ)*(f32)265;


//void __vector_11 (void) __attribute__((signal,used));
//void __vector_11 (void)
//{
//    Timer0_overflowCounter++;
//}


/************************************************************************************************************/
/* Description: A function to initialize the timer according the configurations in the config file			*/
/* Arguments: void																							*/
/* return: void																								*/
/************************************************************************************************************/
void Timer_u8Timer0Init(void)
{
//	enableGlobalInterrupt();
//	SET_BIT(TIMSK, TIMSK_TOIE0);

#if TIMER0_PRESCALAR == 1
	TCCR0 |= (0b001<<0);

#elif TIMER0_PRESCALAR == 8
	TCCR0 |= (0b010<<0);

#elif TIMER0_PRESCALAR == 64
	TCCR0 |= (0b011<<0);

#elif TIMER0_PRESCALAR == 256
	TCCR0 |= (0b100<<0);

#elif TIMER0_PRESCALAR == 1024
	TCCR0 |= (0b101<<0);

#else
#error "Wrong prescalar!"

#endif
}


/************************************************************************************************************/
/* Description: A function to set busy wait (delay)															*/
/* Arguments: input: copy_u16Time_ms  (Time in ms)															*/
/* return: u8																								*/
/*																											*/
/* flow: it calculates the required number of overflows then poll on the TOV0 flag (Timer0 Overflow)		*/
/* and increment the overflow counter till the required number												*/
/************************************************************************************************************/
u8 Timer_u8SetTimer0BusyWait_ms(u16 copy_u16Time_ms)
{
	u8 status = RT_OK;

	u32 overflowCounter = 0;

	u32 overflowNo = 1+((f32)copy_u16Time_ms / (1000*Timer0_overflowTime));


	Timer_u8Timer0Init();

	while(overflowCounter < overflowNo)
	{
		while(GET_BIT(TIFR, TIFR_TOV0) != 1);
		SET_BIT(TIFR, TIFR_TOV0);
		overflowCounter++;
	}

	overflowCounter = 0;

	return status;
}

