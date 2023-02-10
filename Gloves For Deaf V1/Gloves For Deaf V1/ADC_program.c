/*
 * ADC_program.c
 *
 * Created: 9/24/2022 11:20:40 AM
 *  Author: LEGION
 */ 
/*utilities*/
#include "ATMEGA32_REG.h"
#include "BIT_MATH.h"
#include "DATA_TYPES.h"
/*MCAL*/
#include "ADC_interface.h"

void ADC_init(void)
{
		/*Reference volt AVCC (AREF (6=0,7=0) ,internal (6=1,7=1))*/
		SET_BIT(ADMUX,6);
		CLR_BIT(ADMUX,7);
		CLR_BIT(ADMUX,5);//select to the right adjust
		CLR_BIT(ADCSRA,5);//Disable Auto Trigger (single mode conversion)
		CLR_BIT(ADCSRA,3);//ADC interrupt Disable		
		/*ADC Prescaler 128 for 16MHZ (125KHZ)*/
		SET_BIT(ADCSRA,0);
		SET_BIT(ADCSRA,1);
		SET_BIT(ADCSRA,2);
		
		
		SET_BIT(ADCSRA,7);//ADC Enable
}
void ADC_getDigitalValue(u16*digitalValue,u8 channelNumber)
{ 
	if(channelNumber<32 && digitalValue!=NULL)
	{
		/*Select Channel */
		ADMUX &= 0B11100000;
		ADMUX |= channelNumber;
		/*Start Conversion*/
		SET_BIT(ADCSRA,6);	
		/*wait for the flag*/
		while(!GET_BIT(ADCSRA,4));
		/*Clear Flag */
		SET_BIT(ADCSRA,4);
		/*Read Digital Value */
		*digitalValue=ADC_u16;		
	}
	
}
