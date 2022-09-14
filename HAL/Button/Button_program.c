/***********************************************************/
/***************** Author	: Kyrillos Adel	****************/
/***************** Date		: 11-9-2022    	****************/
/***************** Module	: BUTTON       	****************/
/***************** Version	: v1.0      	****************/
/***********************************************************/

#include "Button_int.h"
#include "../../MCAL/DIO/DIO_int.h"


/************************************************************************************************************/
/* Description: A function to Initialize the Button with the configurations set in config file				*/
/* Arguments: void																							*/
/* return: void																								*/
/************************************************************************************************************/
void Button_voidInit(void)
{
	/* Set PIN2 @ PORTA to be input */
	DIO_u8setPinDir(PORT_D, PIN_2, INPUT);

	/* Enable Pull up resistor */
	DIO_u8setPinVal(PORT_D, PIN_2, HIGH);
}
