
#ifndef _LIB_BITMATH_H_
#define _LIB_BITMATH_H_

#include "stdtypes.h"

#define CLR_BIT(Copy_u8reg,Copy_u8pin) 		Copy_u8reg &= ~(1<<(Copy_u8pin))
#define SET_BIT(Copy_u8reg,Copy_u8pin) 		Copy_u8reg |= (1<<(Copy_u8pin))
#define TOGGLE_BIT(Copy_u8reg,Copy_u8pin)	Copy_u8reg ^= (1<<(Copy_u8pin))
#define GET_BIT(Copy_u8reg,Copy_u8pin)		((Copy_u8reg>>Copy_u8pin)&0x01)

#endif /* LIB_BITMATH_H_ */
