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
//#include "LCD_interface.h"
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
		else if (  (Analog_Thumb < ) && (Analog_Index_Finger < ) && (Analog_Middle_Finger < )  &&  ( Analog_Ring_Finger  < )  &&  ( Analog_Little_Finger < )   )
		{   
			
			 _delay_ms(1000);
			//Clear LCD
			//SENTENCE FROM EEPROM CORRESPONDING TO THE RELATIVE VALUES TO BE PRINTED ON THE LCD
			// LCD SEND CHAR
		}
		
	}
		
		
		
}
	
