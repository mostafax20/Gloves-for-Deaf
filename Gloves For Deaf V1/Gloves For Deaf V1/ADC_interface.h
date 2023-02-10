/*
 * ADC_interface.h
 *
 * Created: 9/24/2022 11:21:09 AM
 *  Author: LEGION
 */ 
/*utilities*/

#include "BIT_MATH.h"
#include "DATA_TYPES.h"
#include "ATMEGA32_REG.h"



/*Channel Numbers*/
#define ADC_CHANNEL_0        0
#define	ADC_CHANNEL_1        1
#define	ADC_CHANNEL_2        2
#define	ADC_CHANNEL_3        3
#define	ADC_CHANNEL_4        4
#define	ADC_CHANNEL_5        5
#define	ADC_CHANNEL_6        6
#define ADC_CHANNEL_7        7


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_
void ADC_init(void);
void ADC_getDigitalValue(u16*digitalValue,u8 channelNumber);





#endif /* ADC_INTERFACE_H_ */