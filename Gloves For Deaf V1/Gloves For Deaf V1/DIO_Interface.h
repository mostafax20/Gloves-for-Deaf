/*
 * IncFile1.h
 *
 * Created: 9/3/2022 11:35:54 AM
 *  Author: LEGION
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
#include "DATA_TYPES.h"

		/*PortId*/

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3
    
		/*PinDirection*/

#define DIO_PIN_OUTPUT 1
#define DIO_PIN_INPUT 0
 
			/*PinId*/
			
#define DIO_PIN0  0
#define DIO_PIN1  1
#define DIO_PIN2  2
#define DIO_PIN3  3
#define DIO_PIN4  4
#define DIO_PIN5  5
#define DIO_PIN6  6
#define DIO_PIN7  7

			/*pin value*/

#define DIO_PIN_HIGH 1
#define DIO_PIN_LOW 0

			/*PortValue*/
			
#define DIO_PORT_OUTPUT 0xff
#define DIO_PORT_INPUT 0x00 

#define DIO_PORT_HIGH 1
#define DIO_PORT_LOW 0

/*Pin APIS(application program interface)*/

void DIO_SetPinDirection(u8 PortId,u8 PinId,u8 PinDirection);
void DIO_SetPinValue(u8 PortId,u8 PinId,u8 PinValue);
void DIO_GetPinValue(u8 PortId,u8 PinId,u8* PinValue);
void DIO_TogglePinValue(u8 PortId,u8 PinId);
void DIO_SetInputPinResistance(u8 PortId,u8 PinId);
/*Port APIS(application program interface)*/

void DIO_SetPortDirection(u8 PortId,u8 PortDirection);
void DIO_SetPortValue(u8 PortId,u8 PortValue);
void DIO_GetPortValue(u8 PortId,u8* PortValue);
void DIO_TogglePortValue(u8 PortId);

void DIO_SetInputPortResistance(u8 PortId);


#endif /* DIO_Interface_H_ */