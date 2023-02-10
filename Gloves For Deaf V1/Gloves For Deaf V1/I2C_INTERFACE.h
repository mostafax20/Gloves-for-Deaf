/*
 * I2C_INTERFACE.h
 *
 * Created: 10/21/2022 11:12:29 AM
 *  Author: Ziad Elbouriny
 */ 


#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_


void TWI_initMaster           (void);
void TWI_initSlave            (u8 slaveAdd);
void TWI_sendStartCondition   (void);
void TWI_sendRepStartCondition(void);
void TWI_sendStopCondition    (void);
void TWI_sendSlaveAddwithWrite(u8 slaveAdd);
void TWI_sendSlaveAddwithRead (u8 slaveAdd);
void TWI_sendMasterDataByte   (u8 TxData);
void TWI_readMasterDataByte   (u8* RxData);


#endif /* TWI_INTERFACE_H_ */

