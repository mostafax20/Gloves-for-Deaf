/*
 * EEPROM_Interface.h
 *
 * Created: 2/14/2023 6:50:30 PM
 *  Author: Ziad Elbouriny
 */ 


#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_


void EEPROM_Write_Byte(u8 address,u8 value);

u8 EEPROM_Read_Byte(u8 address);



#endif /* EEPROM_INTERFACE_H_ */