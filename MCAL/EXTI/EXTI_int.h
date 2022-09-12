/***********************************************************/
/***************** Author	: Kyrillos Adel	****************/
/***************** Date		: 11-9-2022    	****************/
/***************** Module	: EXTI      	****************/
/***************** Version	: v1.0      	****************/
/***********************************************************/

#ifndef _EXTI_INT_H_
#define _EXTI_INT_H_

#define LOW_LEVEL               1
#define ON_CHANGE               2
#define FALLING_EDGE            3
#define RISING_EDGE             4

void enableGlobalInterrupt(void);
void disableGlobalInterrupt(void);


void EXTI_voidInt0Init(void);
void EXTI_voidInt1Init(void);
void EXTI_voidInt2Init(void);

u8 EXTI_u8Int0SetCallback(void (*copy_pvInt0Func)(void));

u8 EXTI_u8Int0SetSenseControl(u8 copy_u8Sense);





#endif