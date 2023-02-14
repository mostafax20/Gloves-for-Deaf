/*
 * GFD_program.c
 *
 * Created: 2/13/2023 2:38:31 PM
 *  Author: Mostafa
 */ 
          /* Delay */ 
#define F_CPU 16000000UL
#include <util/delay.h>

          /* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

            /* MCAL */
#include "DIO_interface.h"
#include "ADC_interface.h"

           /* HAL */
#include "LCD_interface.h"
#include "EEPROM_Interface.h"
        /* APPLICATION */
#include "GDF_interface.h"


void GDF_PinDirectionInit(void)
{
	                 /*  ADC CHANNELS PINS */
	DIO_setPinDirection( DIO_PORTA , DIO_PIN0 , DIO_PIN_INPUT );//Channel 0
	DIO_setPinDirection( DIO_PORTA , DIO_PIN1 , DIO_PIN_INPUT );//Channel 1
	DIO_setPinDirection( DIO_PORTA , DIO_PIN2 , DIO_PIN_INPUT );//Channel 2
	DIO_setPinDirection( DIO_PORTA , DIO_PIN3 , DIO_PIN_INPUT );//Channel 3
    DIO_setPinDirection( DIO_PORTA , DIO_PIN4 , DIO_PIN_INPUT );//Channel 4

                       /*     LCD PINS      */
     DIO_setPinDirection(DIO_PORTC,DIO_PIN4,DIO_PIN_OUTPUT);
     DIO_setPinDirection(DIO_PORTC,DIO_PIN5,DIO_PIN_OUTPUT);
     DIO_setPinDirection(DIO_PORTC,DIO_PIN6,DIO_PIN_OUTPUT);
     DIO_setPinDirection(DIO_PORTC,DIO_PIN7,DIO_PIN_OUTPUT);
     DIO_setPinDirection(DIO_PORTB,DIO_PIN1,DIO_PIN_OUTPUT);
     DIO_setPinDirection(DIO_PORTB,DIO_PIN2,DIO_PIN_OUTPUT);
     DIO_setPinDirection(DIO_PORTB,DIO_PIN3,DIO_PIN_OUTPUT);
	 
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
	EEPROM_Write_Byte(26,'y');
	EEPROM_Write_Byte(27,'o');
	EEPROM_Write_Byte(28,'u');
	
	EEPROM_Write_Byte(39,'T');
	EEPROM_Write_Byte(30,'h');
	EEPROM_Write_Byte(31,'a');
	EEPROM_Write_Byte(32,'t');
	EEPROM_Write_Byte(33,' ');
	EEPROM_Write_Byte(34,'i');
	EEPROM_Write_Byte(35,'s');
	EEPROM_Write_Byte(36,' ');
	EEPROM_Write_Byte(37,'f');
	EEPROM_Write_Byte(38,'a');
	EEPROM_Write_Byte(39,'n');
	EEPROM_Write_Byte(40,'t');
	EEPROM_Write_Byte(41,'a');
	EEPROM_Write_Byte(42,'s');
	EEPROM_Write_Byte(43,'t');
	EEPROM_Write_Byte(44,'i');
	EEPROM_Write_Byte(45,'c');
	
	EEPROM_Write_Byte(46,'I');
	EEPROM_Write_Byte(47,' ');
	EEPROM_Write_Byte(48,'w');
	EEPROM_Write_Byte(49,'i');
	EEPROM_Write_Byte(50,'s');
	EEPROM_Write_Byte(51,'h');
	EEPROM_Write_Byte(52,' ');
	EEPROM_Write_Byte(53,'y');
	EEPROM_Write_Byte(54,'o');
	EEPROM_Write_Byte(55,'u');
	EEPROM_Write_Byte(56,' ');
	EEPROM_Write_Byte(57,'g');
	EEPROM_Write_Byte(58,'o');
	EEPROM_Write_Byte(59,'o');
	EEPROM_Write_Byte(60,'d');
	EEPROM_Write_Byte(61,' ');
	EEPROM_Write_Byte(62,'l');
	EEPROM_Write_Byte(63,'i');
	EEPROM_Write_Byte(64,'f');
	EEPROM_Write_Byte(65,'e');
	
	EEPROM_Write_Byte(66,'I');
	EEPROM_Write_Byte(67,' ');
	EEPROM_Write_Byte(68,'r');
	EEPROM_Write_Byte(69,'e');
	EEPROM_Write_Byte(70,'a');
	EEPROM_Write_Byte(71,'l');
	EEPROM_Write_Byte(72,'l');
	EEPROM_Write_Byte(73,'y');
	EEPROM_Write_Byte(74,' ');
	EEPROM_Write_Byte(75,'l');
	EEPROM_Write_Byte(76,'o');
	EEPROM_Write_Byte(77,'v');
	EEPROM_Write_Byte(78,'e');
	EEPROM_Write_Byte(79,' ');
	EEPROM_Write_Byte(80,'y');
	EEPROM_Write_Byte(81,'o');
	EEPROM_Write_Byte(82,'u');
	
	EEPROM_Write_Byte(83,'Y');
	EEPROM_Write_Byte(84,'o');
	EEPROM_Write_Byte(85,'u');
	
}

void GDF_MainCode(void)
{
	   /* Variables to store digital values of fingers */
	u16 Digital_Thumb
	 ,  Digital_Index_Finger 
	 ,  Digital_Middle_Finger 
	 ,  Digital_Ring_Finger 
	 ,  Digital_Little_Finger ; 
	  /* Variables to store analog values of fingers */
	u16 Analog_Thumb
	 ,  Analog_Index_Finger
	 ,  Analog_Middle_Finger
	 ,  Analog_Ring_Finger
	 ,  Analog_Little_Finger ;
	  
	ADC_init(); // Initializing ADC 
	while (1)
	{ 
		                    /* Value of THIMB */
		ADC_getDigitalValue( ADC_SINGLE_ENDED_CHANNEL_0 , &Digital_Thumb         );
		Analog_Thumb = (( (u32)Digital_Thumb * 5000UL )/1024 );//digital * stepsize ( 5v->5000mv  )
		                   /* Value of INDEX Finger */
		ADC_getDigitalValue( ADC_SINGLE_ENDED_CHANNEL_1 , &Digital_Index_Finger  );
		Analog_Index_Finger = (( (u32) Digital_Index_Finger * 5000UL )/1024 );
		                    /* Value of MIDDLE Finger */
		ADC_getDigitalValue( ADC_SINGLE_ENDED_CHANNEL_2 , &Digital_Middle_Finger );
		Analog_Middle_Finger = (( (u32)Digital_Middle_Finger * 5000UL )/1024 );
		                    /* Value of RING Finger */
		ADC_getDigitalValue( ADC_SINGLE_ENDED_CHANNEL_3 , &Digital_Ring_Finger   );
		Analog_Ring_Finger = (( (u32)Digital_Ring_Finger * 5000UL )/1024 );
		                    /* Value of LITTLE Finger */
		ADC_getDigitalValue( ADC_SINGLE_ENDED_CHANNEL_4 , &Digital_Little_Finger );
		Analog_Little_Finger = (( (u32)Digital_Little_Finger * 5000UL )/1024 );
		
		if (  (Analog_Thumb < ) && (Analog_Index_Finger < ) && (Analog_Middle_Finger < )  &&  ( Analog_Ring_Finger  < )  &&  ( Analog_Little_Finger < )   )
		{  
			 _delay_ms(1000);
			//Clear LCD 
			u8 st[10];
			st[9] = '\0';
			for(u8 i = 0; i <= 9; i++)
			{
				st[i] = EEPROM_Read_Byte(i);
			};
			
			LCD_display(st);
			
		}
		else if (  (Analog_Thumb < ) && (Analog_Index_Finger < ) && (Analog_Middle_Finger < )  &&  ( Analog_Ring_Finger  < )  &&  ( Analog_Little_Finger < )   )
		{
			_delay_ms(1000);
			//Clear LCD
			//SENTENCE FROM EEPROM CORRESPONDING TO THE RELATIVE VALUES TO BE PRINTED ON THE LCD
			// LCD SEND CHAR
			

		}
		else if (  (Analog_Thumb < ) && (Analog_Index_Finger < ) && (Analog_Middle_Finger < )  &&  ( Analog_Ring_Finger  < )  &&  ( Analog_Little_Finger < )   )
		{   
			
			 _delay_ms(1000);
			//Clear LCD
			//SENTENCE FROM EEPROM CORRESPONDING TO THE RELATIVE VALUES TO BE PRINTED ON THE LCD
			// LCD SEND CHAR
		}
		
		else if (  (Analog_Thumb < ) && (Analog_Index_Finger < ) && (Analog_Middle_Finger < )  &&  ( Analog_Ring_Finger  < )  &&  ( Analog_Little_Finger < )   )
		{   
			
			 _delay_ms(1000);
			 //Clear LCD
			 //SENTENCE FROM EEPROM CORRESPONDING TO THE RELATIVE VALUES TO BE PRINTED ON THE LCD
			 // LCD SEND CHAR
		}
		else if (  (Analog_Thumb < ) && (Analog_Index_Finger < ) && (Analog_Middle_Finger < )  &&  ( Analog_Ring_Finger  < )  &&  ( Analog_Little_Finger < )   )
		{   
			
			 _delay_ms(1000);
			 //Clear LCD
			 //SENTENCE FROM EEPROM CORRESPONDING TO THE RELATIVE VALUES TO BE PRINTED ON THE LCD
			 // LCD SEND CHAR
		}
		else if (  (Analog_Thumb < ) && (Analog_Index_Finger < ) && (Analog_Middle_Finger < )  &&  ( Analog_Ring_Finger  < )  &&  ( Analog_Little_Finger < )   )
		{   
			
			 _delay_ms(1000);
			 //Clear LCD
			 //SENTENCE FROM EEPROM CORRESPONDING TO THE RELATIVE VALUES TO BE PRINTED ON THE LCD
			 // LCD SEND CHAR
		}
		else if (  (Analog_Thumb < ) && (Analog_Index_Finger < ) && (Analog_Middle_Finger < )  &&  ( Analog_Ring_Finger  < )  &&  ( Analog_Little_Finger < )   )
		{   
			
			 _delay_ms(1000);
			//Clear LCD
			//SENTENCE FROM EEPROM CORRESPONDING TO THE RELATIVE VALUES TO BE PRINTED ON THE LCD
			// LCD SEND CHAR
		}
		
	}
		
		
		
}
	
