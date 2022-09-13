/***********************************************************/
/***************** Author	: Kyrillos Adel	****************/
/***************** Date		: 11-9-2022    	****************/
/***************** Module	: EXTI      	****************/
/***************** Version	: v1.0      	****************/
/***********************************************************/

#include "../../Libs/stdtypes.h"
#include "../../Libs/bitmath.h"
#include "../../Libs/stderrors.h"

#include "EXTI_int.h"
#include "EXTI_private.h"
#include "EXTI_reg.h"
#include "EXTI_config.h"

/* global pointer to function to save the address of the call back function */
void (*Callback)(void) = NULL;

u8 EXTI_u8Int0SetCallback(void (*copy_pvInt0Func)(void))
{
    u8 status = RT_OK;

    if(copy_pvInt0Func != NULL)
    {
        Callback = copy_pvInt0Func;
    }

    else
    {
        status = RT_NOK;
    }

    return status;
}


void __vector_1 (void) __attribute__((signal,used));
void __vector_1 (void)
{
    Callback();
}

void enableGlobalInterrupt(void)
{
    SET_BIT(SREG, SREG_I);
}

void disableGlobalInterrupt(void)
{
    CLR_BIT(SREG, SREG_I);
}

void EXTI_voidInt0Init(void)
{
    /* Check sense control*/
#if INT0_SENSE == LOW_LEVEL
    CLR_BIT(MCUCR, MCUCR_ISC00);
    CLR_BIT(MCUCR, MCUCR_ISC01);

#elif INT0_SENSE == ON_CHANGE
    SET_BIT(MCUCR, MCUCR_ISC00);
    CLR_BIT(MCUCR, MCUCR_ISC01);

#elif INT0_SENSE == FALLING_EDGE
    CLR_BIT(MCUCR, MCUCR_ISC00);
    SET_BIT(MCUCR, MCUCR_ISC01);

#elif INT0_SENSE == RISING_EDGE
    SET_BIT(MCUCR, MCUCR_ISC00);
    SET_BIT(MCUCR, MCUCR_ISC01);

#else
    #error "Wrong INT0_SENSE option"

#endif


    /*Peripheral interrupt enable */
#if INT0_INTERRUPT_ENABLE ==  ENABLED
    SET_BIT(GICR, GICR_INT0);

#elif INT0_INTERRUPT_ENABLE == DISABLED
    CLR_BIT(GICR, GICR_INT0);

#else
    #error "Wrong INT0_INTERRUPT_ENABLE option"

#endif
}

void EXTI_voidInt1Init(void)
{

}

void EXTI_voidInt2Init(void)
{

}

/* Set sense control of INT0
    Input options:
                    LOW_LEVEL
                    ON_CHANGE
                    FALLING_EDGE
                    RISING_EDGE 
                                */
u8 EXTI_u8Int0SetSenseControl(u8 copy_u8Sense)
{
    u8 status = RT_OK;

    switch(copy_u8Sense)
    {
        case LOW_LEVEL:
            CLR_BIT(MCUCR, MCUCR_ISC00);
            CLR_BIT(MCUCR, MCUCR_ISC01);
            break;

        case ON_CHANGE:
            SET_BIT(MCUCR, MCUCR_ISC00);
            CLR_BIT(MCUCR, MCUCR_ISC01);
            break;

        case FALLING_EDGE:
            CLR_BIT(MCUCR, MCUCR_ISC00);
            SET_BIT(MCUCR, MCUCR_ISC01);
            break;

        case RISING_EDGE:
            SET_BIT(MCUCR, MCUCR_ISC00);
            SET_BIT(MCUCR, MCUCR_ISC01);
            break;
        
        default:
            status = RT_NOK;
            break;

    }

    return status;
}
