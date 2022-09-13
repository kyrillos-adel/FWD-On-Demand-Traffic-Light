/***********************************************************/
/***************** Author	: Kyrillos Adel	****************/
/***************** Date		: 11-9-2022    	****************/
/***************** Module	: LED         	****************/
/***************** Version	: v1.0      	****************/
/***********************************************************/
#include "../../Libs/stdtypes.h"
#include "../../libs/stderrors.h"
#include "../../MCAL/DIO/DIO_int.h"


u8 LED_u8LedOn(u8 copy_u8LedPort, u8 copy_u8LedPin)
{
	u8 status = RT_NOK;

	DIO_u8setPinDir(copy_u8LedPort, copy_u8LedPin, OUTPUT);
    DIO_u8setPinVal(copy_u8LedPort, copy_u8LedPin, HIGH);

    status = RT_OK;
    return status;
}

u8 LED_u8LedOff(u8 copy_u8LedPort, u8 copy_u8LedPin)
{
	u8 status = RT_NOK;

    DIO_u8setPinDir(copy_u8LedPort, copy_u8LedPin, OUTPUT);
    DIO_u8setPinVal(copy_u8LedPort, copy_u8LedPin, LOW);

    status = RT_OK;
    return status;
}

// u8 LED_u8LedToggle(u8 copy_u8LedPort, u8 copy_u8LedPin, u8 copy_u8Duration)
// {
// 	u8 status = RT_NOK;

//     DIO_u8setPinDir(copy_u8LedPort, copy_u8LedPin, OUTPUT);
//     DIO_u8setPinVal(copy_u8LedPort, copy_u8LedPin, HIGH);

//     status = RT_OK;
//     return status;
// }
