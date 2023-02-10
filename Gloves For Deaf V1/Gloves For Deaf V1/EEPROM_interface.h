/*
 * EEPROM_interface.h
 *
 * Created: 2/5/2023 5:08:47 PM
 *  Author: Ziad Elbouriny
 */ 


#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

#define EEPROM_FIXED_ADDRESS          0x50

void EEPROM_writeByte(u16 byteAddress, u8 data);
u8 EEPROM_readByte (u16 byteAddress);


#endif /* EEPROM_INTERFACE_H_ */