/*
 * DIO_Program.c
 *
 * Created: 9/3/2022 11:37:10 AM
 *  Author: LEGION
 */ 

/*MCAL*/

#include "DIO_Interface.h"

/* UTILIES */

#include "BIT_MATH.h"
#include "DATA_TYPES.h"
#include "ATMEGA32_REG.h"

/*Pin APIS*/
void DIO_SetPinDirection(u8 PortId,u8 PinId,u8 PinDirection)
{
	if(PortId<4 && PinId<8 && (PinDirection==DIO_PIN_OUTPUT || PinDirection==DIO_PIN_INPUT))
	{
	switch(PortId)
	{
		case DIO_PORTA:
		if(PinDirection==DIO_PIN_OUTPUT)
				SET_BIT(DDRA,PinId);
		else
				CLR_BIT(DDRA,PinId);
		break;
		
		case DIO_PORTB:
		if(PinDirection==DIO_PIN_OUTPUT)
			SET_BIT(DDRB,PinId);
		else
			CLR_BIT(DDRB,PinId);	
		break;
		
		case DIO_PORTC:
		if(PinDirection==DIO_PIN_OUTPUT)
			SET_BIT(DDRC,PinId);
		else
			CLR_BIT(DDRC,PinId);
		break;
		
		case DIO_PORTD:
		if(PinDirection==DIO_PIN_OUTPUT)
			SET_BIT(DDRD,PinId);
		else
			CLR_BIT(DDRD,PinId);
		break;
		
	}
	}
}
void DIO_SetPinValue(u8 PortId,u8 PinId,u8 PinValue)
{
	if(PortId<4 && PinId<8 && (PinValue==DIO_PIN_HIGH || PinValue==DIO_PIN_LOW))
	{
	switch(PortId)
	{
		case DIO_PORTA:
		if(PinValue==DIO_PIN_HIGH)
			SET_BIT(PORTA,PinId);
		else
			CLR_BIT(PORTA,PinId);
		break;
		
		case DIO_PORTB:
		if(PinValue==DIO_PIN_HIGH)
			SET_BIT(PORTB,PinId);
		else
			CLR_BIT(PORTB,PinId);
		break;
		
		case DIO_PORTC:
		if(PinValue==DIO_PIN_HIGH)
			SET_BIT(PORTC,PinId);
		else
			CLR_BIT(PORTC,PinId);
		break;
		
		case DIO_PORTD:
		if(PinValue==DIO_PIN_HIGH)
			SET_BIT(PORTD,PinId);
		else
			CLR_BIT(PORTD,PinId);
		break;
	}
	}
}
void DIO_GetPinValue(u8 PortId,u8 PinId,u8* PinValue)
{
	if(PortId<4 && PinId<8 && PinValue!=NULL)
	{
		switch(PortId)
		{
			case DIO_PORTA:
			if(DIO_PIN_HIGH==GET_BIT(PINA,PinId))
			*PinValue=DIO_PIN_HIGH;
			else
			*PinValue=DIO_PIN_LOW;
			
			break;
			
			case DIO_PORTB:
			if(DIO_PIN_HIGH==GET_BIT(PINB,PinId))
			*PinValue=DIO_PIN_HIGH;
			else
			*PinValue=DIO_PIN_LOW;
			
			break;
			
			case DIO_PORTC:
			if(DIO_PIN_HIGH==GET_BIT(PINC,PinId))
			*PinValue=DIO_PIN_HIGH;
			else
			*PinValue=DIO_PIN_LOW;
			
			break;
			
			case DIO_PORTD:
			if(DIO_PIN_HIGH==GET_BIT(PIND,PinId))
			*PinValue=DIO_PIN_HIGH;
			else
			*PinValue=DIO_PIN_LOW;
			
			break;
			
		}
	}
}
void DIO_TogglePinValue(u8 PortId,u8 PinId)
{
	if(PortId<4 && PinId<8)
	{
		switch(PortId)
		{
			case DIO_PORTA:
			TOG_BIT(PORTA,PinId);
			break;
			
			case DIO_PORTB:
			TOG_BIT(PORTB,PinId);
			break;
			
			case DIO_PORTC:
			TOG_BIT(PORTC,PinId);
			break;
			
			case DIO_PORTD:
			TOG_BIT(PORTD,PinId);
			break;
		}
	}
}
void DIO_SetPortDirection(u8 PortId,u8 PortDirection)
{
	switch(PortId)
	{
		case DIO_PORTA:
		if(PortDirection==DIO_PORT_OUTPUT)
		DDRA=0xff;
		else
		DDRA=0x00;
		break;
		
		case DIO_PORTB:
		if(PortDirection==DIO_PORT_OUTPUT)
		DDRB=0xff;
		else
		DDRB=0x00;
		break;
		
		case DIO_PORTC:
		if(PortDirection==DIO_PORT_OUTPUT)
		DDRC=0xff;
		else
		DDRC=0x00;
		break;
		
		case DIO_PORTD:
		if(PortDirection==DIO_PORT_OUTPUT)
		DDRD=0xff;
		else
		DDRD=0x00;
		break;
	}
}
void DIO_SetPortValue(u8 PortId,u8 PortValue)
{
	if(PortId<=DIO_PORTD && PortValue<=DIO_PORT_HIGH )
	{
	switch(PortId)
	{
		case DIO_PORTA:
		PORTA=PortValue;
		break;
		
		case DIO_PORTB:
		PORTB=PortValue;
		break;
		
		case DIO_PORTC:
		PORTC=PortValue;
		break;
		
		case DIO_PORTD:
		PORTD=PortValue;
		break;
	}
	}
}
void DIO_GetPortValue(u8 PortId,u8* PortValue)
{
	if(PortId<4 && PortValue!=NULL)
	{
		switch(PortId)
		{
			case DIO_PORTA:
			*PortValue=PINA;
			break;
			
			case DIO_PORTB:
			*PortValue=PINB;
			break;
			
			case DIO_PORTC:
			*PortValue=PINC;
			break;
			
			case DIO_PORTD:
			*PortValue=PIND;
			break;
		}
	}
}
void DIO_TogglePortValue(u8 PortId)
{
	
	if(PortId<4)
	{
		switch(PortId)
		{
			case DIO_PORTA:
		    PORTA^=0xff;
			break;
			
			case DIO_PORTB:
			PORTB^=0xff;
			break;
			
			case DIO_PORTC:
			PORTC^=0xff;
			break;
			
			case DIO_PORTD:
			PORTD^=0xff;
			break;
			
		}
	}
}
void DIO_SetInputPinResistance(u8 PortId,u8 PinId)
{
	if(PortId<4 && PinId<8)
	{
		switch(PortId)
		{
			case DIO_PORTA:
			SET_BIT(PORTA,PinId);
			break;
			
			case DIO_PORTB:
			SET_BIT(PORTB,PinId);
			break;
			
			case DIO_PORTC:
			SET_BIT(PORTC,PinId);
			break;
			
			case DIO_PORTD:
			SET_BIT(PORTD,PinId);
			break;
		}
	}
}