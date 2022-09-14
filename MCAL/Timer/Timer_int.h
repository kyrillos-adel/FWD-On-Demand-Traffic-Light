/***********************************************************/
/***************** Author	: Kyrillos Adel	****************/
/***************** Date		: 11-9-2022    	****************/
/***************** Module	: Timer      	****************/
/***************** Version	: v1.0      	****************/
/***********************************************************/

#ifndef _MCAL_TIMER_TIMER_INT_H_
#define _MCAL_TIMER_TIMER_INT_H_

#include "../../Libs/stdtypes.h"

void Timer_u8Timer0Init(void);

u8 Timer_u8SetTimer0BusyWait_ms(u16 copy_u16Time_ms);



#endif /* MCAL_TIMER_TIMER_INT_H_ */
