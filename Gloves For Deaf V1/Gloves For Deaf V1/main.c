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

void savingSentences(void);

int main(void)

{
	/*ADC PINS*/
	DIO_SetPortDirection(DIO_PORTA,DIO_PORT_INPUT);
	
	/*LCD PINS*/
	 DIO_SetPinDirection(DIO_PORTC,DIO_PIN4,DIO_PIN_OUTPUT);
	 DIO_SetPinDirection(DIO_PORTC,DIO_PIN5,DIO_PIN_OUTPUT);
	 DIO_SetPinDirection(DIO_PORTC,DIO_PIN6,DIO_PIN_OUTPUT);
	 DIO_SetPinDirection(DIO_PORTC,DIO_PIN7,DIO_PIN_OUTPUT);
	 DIO_SetPinDirection(DIO_PORTB,DIO_PIN1,DIO_PIN_OUTPUT);
	 DIO_SetPinDirection(DIO_PORTB,DIO_PIN2,DIO_PIN_OUTPUT);
	 DIO_SetPinDirection(DIO_PORTB,DIO_PIN3,DIO_PIN_OUTPUT);
	
	LCD_init();
	savingSentences();
	
	u8 st[18];
	st[18] = '\0';
	for(u8 i = 0; i <= 16; i++)
	{
		st[i] = EEPROM_Read_Byte(i+30);
	};
	
	LCD_display(st);
	
	//LCD_sendChar(EEPROM_Read_Byte(68));
	//LCD_sendChar(EEPROM_Read_Byte(69));
	//LCD_sendChar(EEPROM_Read_Byte(70));
	//LCD_sendChar(EEPROM_Read_Byte(71));
	//LCD_sendChar(EEPROM_Read_Byte(72));
	//LCD_sendChar(EEPROM_Read_Byte(73));
	//LCD_sendChar(EEPROM_Read_Byte(74));
	//LCD_sendChar(EEPROM_Read_Byte(75));
	//LCD_sendChar(EEPROM_Read_Byte(76));
	//LCD_sendChar(EEPROM_Read_Byte(78));
	//LCD_sendChar(EEPROM_Read_Byte(79));
	//LCD_sendChar(EEPROM_Read_Byte(80));
	//LCD_sendChar(EEPROM_Read_Byte(81));
	//LCD_sendChar(EEPROM_Read_Byte(82));
	//LCD_sendChar(EEPROM_Read_Byte(83));
	//LCD_sendChar(EEPROM_Read_Byte(84));
	//LCD_sendChar(EEPROM_Read_Byte(85));
	
	
	
	ADC_init();
	u16 digitalValue1=0;
	u16 digitalValue2=0;
	u32 number=80;
	
	/* Replace with your application code */
	while (1)
	{
		
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
		
	}
}

void savingSentences()
{
	EEPROM_Write_Byte(0,'I');
	EEPROM_Write_Byte(1,' ');
	EEPROM_Write_Byte(2,'L');
	EEPROM_Write_Byte(3,'o');
	EEPROM_Write_Byte(4,'v');
	EEPROM_Write_Byte(5,'e');
	EEPROM_Write_Byte(6,' ');
	EEPROM_Write_Byte(7,'Y');
	EEPROM_Write_Byte(8,'o');
	EEPROM_Write_Byte(9,'u');
	
	EEPROM_Write_Byte(10,'G');
	EEPROM_Write_Byte(11,'o');
	EEPROM_Write_Byte(12,'o');
	EEPROM_Write_Byte(13,'d');
	EEPROM_Write_Byte(14,' ');
	EEPROM_Write_Byte(15,'J');
	EEPROM_Write_Byte(16,'o');
	EEPROM_Write_Byte(17,'b');
	
	EEPROM_Write_Byte(18,'I');
	EEPROM_Write_Byte(19,' ');
	EEPROM_Write_Byte(20,'w');
	EEPROM_Write_Byte(21,'a');
	EEPROM_Write_Byte(22,'t');
	EEPROM_Write_Byte(23,'c');
	EEPROM_Write_Byte(24,'h');
	EEPROM_Write_Byte(25,' ');
	EEPROM_Write_Byte(27,'y');
	EEPROM_Write_Byte(28,'o');
	EEPROM_Write_Byte(29,'u');
	
	EEPROM_Write_Byte(30,'T');
	EEPROM_Write_Byte(31,'h');
	EEPROM_Write_Byte(32,'a');
	EEPROM_Write_Byte(33,'t');
	EEPROM_Write_Byte(34,' ');
	EEPROM_Write_Byte(35,'i');
	EEPROM_Write_Byte(36,'s');
	EEPROM_Write_Byte(37,' ');
	EEPROM_Write_Byte(38,'f');
	EEPROM_Write_Byte(39,'a');
	EEPROM_Write_Byte(40,'n');
	EEPROM_Write_Byte(41,'t');
	EEPROM_Write_Byte(42,'a');
	EEPROM_Write_Byte(43,'s');
	EEPROM_Write_Byte(44,'t');
	EEPROM_Write_Byte(45,'i');
	EEPROM_Write_Byte(46,'c');
	
	EEPROM_Write_Byte(47,'I');
	EEPROM_Write_Byte(48,' ');
	EEPROM_Write_Byte(49,'w');
	EEPROM_Write_Byte(50,'i');
	EEPROM_Write_Byte(51,'s');
	EEPROM_Write_Byte(52,'h');
	EEPROM_Write_Byte(53,' ');
	EEPROM_Write_Byte(54,'y');
	EEPROM_Write_Byte(55,'o');
	EEPROM_Write_Byte(56,'u');
	EEPROM_Write_Byte(57,' ');
	EEPROM_Write_Byte(58,'g');
	EEPROM_Write_Byte(59,'o');
	EEPROM_Write_Byte(60,'o');
	EEPROM_Write_Byte(61,'d');
	EEPROM_Write_Byte(62,' ');
	EEPROM_Write_Byte(63,'l');
	EEPROM_Write_Byte(64,'i');
	EEPROM_Write_Byte(65,'f');
	EEPROM_Write_Byte(67,'e');
	
	EEPROM_Write_Byte(68,'I');
	EEPROM_Write_Byte(69,' ');
	EEPROM_Write_Byte(70,'r');
	EEPROM_Write_Byte(71,'e');
	EEPROM_Write_Byte(72,'a');
	EEPROM_Write_Byte(73,'l');
	EEPROM_Write_Byte(74,'l');
	EEPROM_Write_Byte(75,'y');
	EEPROM_Write_Byte(76,' ');
	EEPROM_Write_Byte(78,'l');
	EEPROM_Write_Byte(79,'o');
	EEPROM_Write_Byte(80,'v');
	EEPROM_Write_Byte(81,'e');
	EEPROM_Write_Byte(82,' ');
	EEPROM_Write_Byte(83,'y');
	EEPROM_Write_Byte(84,'o');
	EEPROM_Write_Byte(85,'u');
	
	EEPROM_Write_Byte(86,'Y');
	EEPROM_Write_Byte(87,'o');
	EEPROM_Write_Byte(88,'u');
	
}