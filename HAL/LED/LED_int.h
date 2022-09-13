/***********************************************************/
/***************** Author	: Kyrillos Adel	****************/
/***************** Date		: 11-9-2022    	****************/
/***************** Module	: LED         	****************/
/***************** Version	: v1.0      	****************/
/***********************************************************/

#ifndef _LED_INT_H_
#define _LED_INT_H_

#include "../../Libs/stdtypes.h"

#define CAR_LED_PORT                        	PORT_A
#define CAR_LED_RED_PIN                  		PIN_0
#define CAR_LED_YELLOW_PIN                  	PIN_1
#define CAR_LED_GREEN_PIN                  		PIN_2

#define PED_LED_PORT                        	PORT_B
#define PED_LED_RED_PIN                   		PIN_0
#define PED_LED_YELLOW_PIN                  	PIN_1
#define PED_LED_GREEN_PIN                     	PIN_2

u8 LED_u8LedOn(u8 copy_u8LedPort, u8 copy_u8LedPin);

u8 LED_u8LedOff(u8 copy_u8LedPort, u8 copy_u8LedPin);

u8 LED_u8LedToggle(u8 copy_u8LedPort, u8 copy_u8LedPin);
#endif
