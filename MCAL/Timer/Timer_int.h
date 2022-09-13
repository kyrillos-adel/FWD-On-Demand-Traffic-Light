/*
 * Timer_int.h
 *
 *  Created on: Sep 13, 2022
 *      Author: Kero Adel
 */

#ifndef _MCAL_TIMER_TIMER_INT_H_
#define _MCAL_TIMER_TIMER_INT_H_

#include "../../Libs/stdtypes.h"

void Timer_u8Timer0Init(void);

u8 Timer_u8SetTimer0BusyWait_ms(u16 copy_u8Time_ms);



#endif /* MCAL_TIMER_TIMER_INT_H_ */
