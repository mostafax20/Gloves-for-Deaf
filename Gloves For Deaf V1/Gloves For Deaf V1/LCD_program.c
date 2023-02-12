/*
 * LCD_program.c
 *
 * Created: 9/10/2022 10:22:08 AM
 *  Author: LEGION
 */ 



#define F_CPU 16000000UL
#include <util/delay.h>
/* UTILIES */

#include "BIT_MATH.h"
#include "DATA_TYPES.h"
#include "ATMEGA32_REG.h"

/*MCAL*/

#include "DIO_Interface.h"

/* HAL */
#include "LCD_cofig.h"
#include "LCD_interface.h"


void LCD_sendCmnd(u8 cmnd)
{
	/* SET RS TO 0 (write commend) */
	DIO_SetPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_LOW);
	
	/* SET RW TO 0 (write) */
	DIO_SetPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_LOW);
	
	/* write the most 4 bits of command on data pins */
	PRIVATE_WriteHalfPort(cmnd>>4);
	
	/* Enable pulse */
	DIO_SetPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_LOW);
	
	/* write the least 4 bits of command on data pins */
	PRIVATE_WriteHalfPort(cmnd);
	
	/* Enable pulse */
	DIO_SetPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_LOW);
	
	
}
void LCD_init(void)
{
	_delay_ms(35);
	
	#if LCD_MODE == LCD_8_BIT_MODE
	LCD_sendCmnd(0b00111000); // Function Set command 2*16 LCD
	#elif LCD_MODE == LCD_4_BIT_MODE
	// set Rs pin = 0 (write command)
	DIO_SetPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_LOW);
	
	// set Rw pin = 0 (write)
	DIO_SetPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_LOW);
	PRIVATE_WriteHalfPort(0b0010);
	/* Enable Pulse *//* H => L */
	DIO_SetPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_LOW);
	
	LCD_sendCmnd(0b00101000);
	#endif
	
	
	
	_delay_us(42);
	
	/* Display on/off Control (Display on(D) ,Cursor on(C),Blink off(B)) */
	LCD_sendCmnd(0b00001111);
	
	_delay_us(42);
	
	/* Clear Display */
	LCD_sendCmnd(0b00000001);
	_delay_us(1600);
	
	/* Entry Mode Set (Increment on (I/D) ,Shift Display off(S) */
	LCD_sendCmnd(0b00000110);
	
	
}
void LCD_sendChar(u8 data)
{
	/* SET RS TO 1 (write commend) */
	DIO_SetPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_HIGH);
	
	/* SET RW TO 0 (write) */
	DIO_SetPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_LOW);
	
	/* write the most 4 bits of command on data pins */
	PRIVATE_WriteHalfPort(data>>4);
	
	/* Enable pulse */
	DIO_SetPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_LOW);
	
	/* write the least 4 bits of command on data pins */
	PRIVATE_WriteHalfPort(data);
	
	/* Enable pulse */
	DIO_SetPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_LOW);
}

void LCD_writeNumber(u32 number)
{
	u32 Local_reversed = 1;
	if (number == 0)
	{
		LCD_sendChar('0');
	}
	else
	{
		// Reverse Number
		while (number != 0)
		{
			Local_reversed = Local_reversed*10 + (number%10);
			number /= 10;
		}
		
		do
		{
			LCD_sendChar((Local_reversed%10)+'0');
			Local_reversed /= 10;
		}while (Local_reversed != 1);
	}
}
void LCD_goToSpecificPosition(u8 LineNumber, u8 Position)
{
	if(LineNumber == LCD_LINE_ONE)
	{
		if(Position <= 15)
		{
			LCD_sendCmnd(0x80 + Position);
		}
	}

	else if (LineNumber == LCD_LINE_TWO)
	{
		if(Position <= 15)
		{
			LCD_sendCmnd(0xc0 + Position);
		}
	}
}

void LCD_display(u8*string)
{
	u8 check = -1;
	if((string[16] != ' ') || (string[16] != '\0'))
	{
		for(u8 j = 16; j > 0; j--)
		{
			if(string[j] = ' ')
			{
				check = j;
			}
		u8 counter=0;
		while (string[counter]!='\0')
		{	
			if(counter == check)
			{
				LCD_goToSpecificPosition(2, 0);
				LCD_sendChar(string[counter]);
				++counter;
			}
			else
			{
				LCD_sendChar(string[counter]);
				++counter;
			}
		}
		}
	}
}

static void PRIVATE_WriteHalfPort(u8 value)
{
	DIO_SetPinValue(DIO_PORTC,DIO_PIN4,GET_BIT(value,0));
	DIO_SetPinValue(DIO_PORTC,DIO_PIN5,GET_BIT(value,1));
	DIO_SetPinValue(DIO_PORTC,DIO_PIN6,GET_BIT(value,2));
	DIO_SetPinValue(DIO_PORTC,DIO_PIN7,GET_BIT(value,3));
}