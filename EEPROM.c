/*
 * EEPROM.c
 *
 * Created: 2/5/2023 5:07:44 PM
 *  Author: Ziad Elbouriny
 */ 
#define F_CPU 16000000UL
#include <util/delay.h>

/* UTILES_LIB */
#include "DATA_TYPES.H"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

/* MCAL */
#include "I2C_INTERFACE.h"

/* HAL */
#include "EEPROM_interface.h"


void EEPROM_writeByte(u16 byteAddress, u8 data)
{
	u8 address = EEPROM_FIXED_ADDRESS | (u8)(byteAddress>>8);
	
	// Send start condition
	TWI_sendStartCondition();
	
	// Send slave address with write operation
	TWI_sendSlaveAddwithWrite(address);
	
	// Send byte address
	TWI_sendMasterDataByte((u8)byteAddress);
	
	// Send byte data
	TWI_sendMasterDataByte(data);
	
	// Send stop condition
	TWI_sendStopCondition();
	
	_delay_ms(5);
}


u8 EEPROM_readByte(u16 byteAddress)
{
	u8 address = EEPROM_FIXED_ADDRESS | (u8)(byteAddress>>8);
	
	u8 Local_data;
	
	// Send start condition
	TWI_sendStartCondition();
	
	// Send slave address with write operation
	TWI_sendSlaveAddwithWrite(address);
	
	// Send byte address
	TWI_sendMasterDataByte((u8)byteAddress);
	
	// Send repeated start
	TWI_sendRepStartCondition();
	
	// Send slave address with read operation
	TWI_sendSlaveAddwithRead(address);
	
	// Read byte data
	TWI_readMasterDataByte(&Local_data);
	
	// Send stop condition
	TWI_sendStopCondition();
	
	return Local_data;
	
	_delay_ms(5);
}