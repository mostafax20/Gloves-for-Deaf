/*
 * ProjectTest.c
 *
 * Created: 12/5/2022 3:30:43 AM
 * Author : LEGION
 */ 


/*utilities*/
#include "ATMEGA32_REG.h"
#include "BIT_MATH.h"
#include "DATA_TYPES.h"
/*MCAL*/
#include "ADC_interface.h"
#include "DIO_Interface.h"
/* HAL */
#include "LCD_cofig.h"
#include "LCD_interface.h"

int main(void)

{
	/*ADC PINS*/
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN1,DIO_PIN_INPUT);
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN0,DIO_PIN_INPUT);
	
	DIO_SetPinDirection(DIO_PORTC,DIO_PIN2,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTC,DIO_PIN7,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTD,DIO_PIN3,DIO_PIN_OUTPUT);
	
	 DIO_SetPinDirection(DIO_PORTA,DIO_PIN4,DIO_PIN_OUTPUT);
	 DIO_SetPinDirection(DIO_PORTA,DIO_PIN5,DIO_PIN_OUTPUT);
	 DIO_SetPinDirection(DIO_PORTA,DIO_PIN6,DIO_PIN_OUTPUT);
	 DIO_SetPinDirection(DIO_PORTA,DIO_PIN7,DIO_PIN_OUTPUT);
	 DIO_SetPinDirection(DIO_PORTB,DIO_PIN1,DIO_PIN_OUTPUT);
	 DIO_SetPinDirection(DIO_PORTB,DIO_PIN2,DIO_PIN_OUTPUT);
	 DIO_SetPinDirection(DIO_PORTB,DIO_PIN3,DIO_PIN_OUTPUT);
	 LCD_init();
	 ADC_init();
	 u16 digitalValue1=0;
	 u16 digitalValue2=0;
	 u32 number=80;
		ADC_getDigitalValue(&digitalValue1,ADC_CHANNEL_1);
		u16 analogValue1=(u32)(digitalValue1*5000UL/1024);
	LCD_goToSpecificPosition(LCD_LINE_ONE,0);
	LCD_display("value1=");
	LCD_goToSpecificPosition(LCD_LINE_ONE,7);
	LCD_writeNumber(analogValue1);
	ADC_getDigitalValue(&digitalValue2,ADC_CHANNEL_0);
	u16 analogValue2=(u32)(digitalValue2*5000UL/1024);
	LCD_goToSpecificPosition(LCD_LINE_TWO,0);
	LCD_display("value2=");
	LCD_goToSpecificPosition(LCD_LINE_TWO,7);
	LCD_writeNumber(analogValue2);
    /* Replace with your application code */
    while (1) 
    {
	
		
		
    }
}

