/***********************************************************/
/***************** Author	: Kyrillos Adel	****************/
/***************** Date		: 11-9-2022    	****************/
/***************** Module	: APP         	****************/
/***************** Version	: v1.0      	****************/
/***********************************************************/

#include "../Libs/stdtypes.h"
#include "../HAL/Button/Button_int.h"
#include "../HAL/LED/LED_int.h"
#include "../MCAL/EXTI/EXTI_int.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/Timer/Timer_int.h"
#include "APP_int.h"

#define LED_ON			1
#define LED_OFF			0

/* Two global variables to indicate LED green/red On or Off */
u8 APP_u8CarGreenLedState = LED_OFF;
u8 APP_u8CarRedLedState = LED_OFF;
u8 APP_u8CarYellowLedState = LED_OFF;

void carGreenOnOff(u8 state);
void carRedOnOff(u8 state);
void carBlinkYellowLed(void);
void pedBlinkYellowLed(void);
void pedAndCarBlinkYellowLed(void);


/* arguments:
 * 				LED_OFF:
 * 				LED_ON
 * 						*/
void carGreenOnOff(u8 state)
{
	if(state == LED_ON)
	{
		LED_u8LedOn(CAR_LED_PORT, CAR_LED_GREEN_PIN);
	}
	else if(state == LED_OFF)
	{
		LED_u8LedOff(CAR_LED_PORT, CAR_LED_GREEN_PIN);
	}
	/* Set led state */
	APP_u8CarGreenLedState = state;
}

/* arguments:
 * 				LED_OFF:
 * 				LED_ON
 * 						*/
void carRedOnOff(u8 state)
{
	if(state == LED_ON)
	{
		LED_u8LedOn(CAR_LED_PORT, CAR_LED_RED_PIN);
	}
	else if(state == LED_OFF)
	{
		LED_u8LedOff(CAR_LED_PORT, CAR_LED_RED_PIN);
	}

	/* Set led state */
	APP_u8CarRedLedState = state;
}

void carBlinkYellowLed(void)
{
	APP_u8CarYellowLedState = LED_ON;

	LED_u8LedOff(CAR_LED_PORT, CAR_LED_GREEN_PIN);

	for(u8 i=0; i<5; i++)
	{
		LED_u8LedOn(CAR_LED_PORT, CAR_LED_YELLOW_PIN);
		Timer_u8SetTimer0BusyWait_ms(500);
		LED_u8LedOff(CAR_LED_PORT, CAR_LED_YELLOW_PIN);
		Timer_u8SetTimer0BusyWait_ms(500);
	}
	APP_u8CarYellowLedState = LED_OFF;
}

void pedBlinkYellowLed(void)
{
	for(u8 i=0; i<5; i++)
	{
		LED_u8LedOn(PED_LED_PORT, PED_LED_YELLOW_PIN);
		Timer_u8SetTimer0BusyWait_ms(500);
		LED_u8LedOff(PED_LED_PORT, PED_LED_YELLOW_PIN);
		Timer_u8SetTimer0BusyWait_ms(500);
	}
}

void pedAndCarBlinkYellowLed(void)
{
	for(u8 i=0; i<5; i++)
	{
		LED_u8LedOn(PED_LED_PORT, PED_LED_YELLOW_PIN);
		LED_u8LedOn(CAR_LED_PORT, CAR_LED_YELLOW_PIN);
		Timer_u8SetTimer0BusyWait_ms(500);
		LED_u8LedOff(PED_LED_PORT, PED_LED_YELLOW_PIN);
		LED_u8LedOff(CAR_LED_PORT, CAR_LED_YELLOW_PIN);
		Timer_u8SetTimer0BusyWait_ms(500);
	}
}

void APP_voidNormalMode(void)
{
	carRedOnOff(LED_ON);
	Timer_u8SetTimer0BusyWait_ms(5000);
	carRedOnOff(LED_OFF);

	carBlinkYellowLed();
	
	carGreenOnOff(LED_ON);
	Timer_u8SetTimer0BusyWait_ms(5000);
	carGreenOnOff(LED_OFF);

	carBlinkYellowLed();
}

/********************************************************************************************************************/
/*Change from normal mode to pedestrian mode when the pedestrian button is pressed. (EXTI from INT0 -the button-)	*/
/********************************************************************************************************************/
void APP_voidPedestrianMode(void)
{
	/* If pressed when the cars' Red LED is on, the pedestrian's Green LED and the cars' Red LEDs will be on for five seconds,
	 * this means that pedestrians can cross the street while the pedestrian's Green LED is on. */
	if(APP_u8CarRedLedState == LED_ON)
	{
		LED_u8LedOn(PED_LED_PORT, PED_LED_GREEN_PIN);
		// LED_u8LedOn(CAR_LED_PORT, CAR_LED_RED_PIN);
		Timer_u8SetTimer0BusyWait_ms(5000);
		LED_u8LedOff(CAR_LED_PORT, CAR_LED_RED_PIN);
		pedAndCarBlinkYellowLed();
		LED_u8LedOff(PED_LED_PORT, PED_LED_GREEN_PIN);
		LED_u8LedOn(PED_LED_PORT, PED_LED_RED_PIN);
		LED_u8LedOn(CAR_LED_PORT, CAR_LED_GREEN_PIN);
		Timer_u8SetTimer0BusyWait_ms(5000);
//		carBlinkYellowLed();
//		LED_u8LedOn(CAR_LED_PORT, CAR_LED_RED_PIN);
	}

	/* If pressed when the cars' Green LED is on or the cars' Yellow LED is blinking, the pedestrian Red LED will be on
	 * then both Yellow LEDs start to blink for five seconds,
	 * then the cars' Red LED and pedestrian Green LEDs are on for five seconds,
	 * this means that pedestrian must wait until the Green LED is on. */
	else if(APP_u8CarGreenLedState == LED_ON || APP_u8CarYellowLedState == LED_ON)
	{
		LED_u8LedOff(PED_LED_PORT, PED_LED_GREEN_PIN);
		LED_u8LedOn(PED_LED_PORT, PED_LED_RED_PIN);

		pedAndCarBlinkYellowLed();

		LED_u8LedOff(PED_LED_PORT, PED_LED_RED_PIN);
		LED_u8LedOn(PED_LED_PORT, PED_LED_GREEN_PIN);

		LED_u8LedOn(CAR_LED_PORT, CAR_LED_RED_PIN);
		LED_u8LedOff(CAR_LED_PORT, CAR_LED_GREEN_PIN);
		Timer_u8SetTimer0BusyWait_ms(5000);

		LED_u8LedOff(CAR_LED_PORT, CAR_LED_RED_PIN);
		pedAndCarBlinkYellowLed();
		LED_u8LedOff(PED_LED_PORT, PED_LED_GREEN_PIN);
		LED_u8LedOn(PED_LED_PORT, PED_LED_RED_PIN);
		LED_u8LedOn(CAR_LED_PORT, CAR_LED_GREEN_PIN);

//		Timer_u8SetTimer0BusyWait_ms(5);
//		carBlinkYellowLed();
//		LED_u8LedOn(CAR_LED_PORT, CAR_LED_RED_PIN);
//		carBlinkYellowLed();
	}
}

void APP_voidAppInit()
{
	Button_voidInit();
	EXTI_voidInt0Init();
	EXTI_u8Int0SetCallback(&APP_voidPedestrianMode);
	enableGlobalInterrupt();

	while(1)
	{
		APP_voidNormalMode();
	}
}


