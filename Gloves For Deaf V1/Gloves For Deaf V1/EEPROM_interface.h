/*
 * EEPROM_interface.h
 *
 * Created: 2/11/2023 10:32:58 PM
 *  Author: Kimo Store
 */ 


#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_


void EEPROM_Write_Byte(u8 address,u8 value);

u8 EEPROM_Read_Byte(u8 address);







#endif /* EEPROM_INTERFACE_H_ */