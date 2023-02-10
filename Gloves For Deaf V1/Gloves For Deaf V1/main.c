/*
 * Glove for deaf.c
 *
 * Created: 2/7/2023 2:53:05 PM
 * Author : Ziad Elbouriny
 */ 
#define F_CPU 16000000UL
#include <util/delay.h>

#include "ATMEGA32_REG.h"
#include "BIT_MATH.h"
#include "DATA_TYPES.h"
/*MCAL*/
#include "ADC_interface.h"
#include "DIO_Interface.h"
#include "I2C_interface.h"
/* HAL */
#include "LCD_cofig.h"
#include "LCD_interface.h"
#include "EEPROM_interface.h"

int main(void)

{
	/*ADC PINS*/
	//DIO_SetPinDirection(DIO_PORTA,DIO_PIN0,DIO_PIN_INPUT);
	//DIO_SetPinDirection(DIO_PORTA,DIO_PIN1,DIO_PIN_INPUT);
	//DIO_SetPinDirection(DIO_PORTA,DIO_PIN2,DIO_PIN_INPUT);
	//DIO_SetPinDirection(DIO_PORTA,DIO_PIN3,DIO_PIN_INPUT);
	//DIO_SetPinDirection(DIO_PORTA,DIO_PIN4,DIO_PIN_INPUT);
	/*LCD PINS*/
	 DIO_SetPinDirection(DIO_PORTC,DIO_PIN4,DIO_PIN_OUTPUT);
	 DIO_SetPinDirection(DIO_PORTC,DIO_PIN5,DIO_PIN_OUTPUT);
	 DIO_SetPinDirection(DIO_PORTC,DIO_PIN6,DIO_PIN_OUTPUT);
	 DIO_SetPinDirection(DIO_PORTC,DIO_PIN7,DIO_PIN_OUTPUT);
	 DIO_SetPinDirection(DIO_PORTB,DIO_PIN1,DIO_PIN_OUTPUT);
	 DIO_SetPinDirection(DIO_PORTB,DIO_PIN2,DIO_PIN_OUTPUT);
	 DIO_SetPinDirection(DIO_PORTB,DIO_PIN3,DIO_PIN_OUTPUT);
	
	
	u32 readed=0;
	LCD_init();
	
	TWI_initMaster();
	
	EEPROM_writeByte(1,3);
	LCD_goToSpecificPosition(LCD_LINE_ONE,0);
LCD_display("value1=");
	//EEPROM_writeByte(2,' ');
	//EEPROM_writeByte(3,'L');
	//EEPROM_writeByte(4,'o');
	//EEPROM_writeByte(5,'v');
	//EEPROM_writeByte(6,'e');
	//EEPROM_writeByte(7,' ');
	//EEPROM_writeByte(8,'Y');
	//EEPROM_writeByte(9,'o');
	//EEPROM_writeByte(10,'u');
	 readed = EEPROM_readByte(1);

	//if(readed == 6)
	//{
		
		LCD_writeNumber(readed);
		
	//}
	
	//ADC_init();
	//u16 digitalValue1=0;
	//u16 digitalValue2=0;
	//u32 number=80;
	//ADC_getDigitalValue(&digitalValue1,ADC_CHANNEL_1);
	//u16 analogValue1=(u32)(digitalValue1*5000UL/1024);
	//LCD_goToSpecificPosition(LCD_LINE_ONE,0);
	//LCD_display("value1=");
	//LCD_goToSpecificPosition(LCD_LINE_ONE,7);
	//LCD_writeNumber(analogValue1);
	//ADC_getDigitalValue(&digitalValue2,ADC_CHANNEL_0);
	//u16 analogValue2=(u32)(digitalValue2*5000UL/1024);
	//LCD_goToSpecificPosition(LCD_LINE_TWO,0);
	//LCD_display("value2=");
	//LCD_goToSpecificPosition(LCD_LINE_TWO,7);
	//LCD_writeNumber(analogValue2);
	/* Replace with your application code */
	while (1)
	{
		
		
		
	}
}
