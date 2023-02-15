/*
 * EEPROM_Program.c
 *
 * Created: 2/14/2023 6:49:19 PM
 *  Author: Ziad Elbouriny
 */ 
/* UTILES_LIB */

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "ATMEGA32_REG.h"


void EEPROM_Write_Byte(u8 address,u8 value)
{
	
	while( GET_BIT(EECR,1)==1 );  /* POLLING WITH BLOCKING to wait until the EEWE is cleared */
	
	EEAR_u16 = address;
	//EECR |= (1<<EERE);
	
	
	EEDR = value;
	SET_BIT(EECR,2);						//EECR |= (1<<EEMWE);
	SET_BIT(EECR,1);						//EECR |= (1<<EEWE);
	
	
}

u8 EEPROM_Read_Byte(u8 address)
{
	
	while( GET_BIT(EECR,1)==1 );
	

	EEAR_u16 = address;

	SET_BIT(EECR,0);							//EECR |= (1<<EERE);
	

	return EEDR;
	
	
}