/*
 * ATMEGA32_REG.h
 *
 * Created: 9/3/2022 11:56:09 AM
 *  Author: LEGION
 */ 


#ifndef ATMEGA32_REG_H_
#define ATMEGA32_REG_H_
		/*DIO REGUSTERS*/
/*DATA DIRECTION REGISTERS*/
#define DDRA  (*(volatile u8*)0x3A)
#define DDRB  (*(volatile u8*)0x37)
#define DDRC  (*(volatile u8*)0x34)
#define DDRD  (*(volatile u8*)0x31)

/*OUTPUT REGISTERS*/
#define PORTA  (*(volatile u8*)0x3B)
#define PORTB  (*(volatile u8*)0x38)
#define PORTC  (*(volatile u8*)0x35)
#define PORTD  (*(volatile u8*)0x32)

/*INPUT REGISTERS*/

#define PINA  (*(volatile u8*)0x39)
#define PINB  (*(volatile u8*)0x36)
#define PINC  (*(volatile u8*)0x33)
#define PIND  (*(volatile u8*)0x30)



		/* EXTERNAL INTERRUPTS REGISTERS */
#define MCUCR (*(volatile u8*)0x55)
#define MCUCSR (*(volatile u8*)0x54)
#define GICR (*(volatile u8*)0x5B)
#define GIFR (*(volatile u8*)0x5A)

#define SREG (*(volatile u8*)0x5F)


		/* ADC registers */
		
//ADC Multiplexer Selection Register		
#define ADMUX (*(volatile u8*)0x27)	
//ADC Control and Status Register
#define ADCSRA (*(volatile u8*)0x26)	
/*The ADC Data Register*/
#define ADCH (*(volatile u8*)0x25)
#define ADCL (*(volatile u8*)0x24)
#define ADC_u16 (*(volatile u16*)0x24)
//Special FunctionIO Register
#define SFIOR (*(volatile u8*)0x50)	 

/*TIMERS REGISTERS*/
/*TIMER0 */
#define TCCR0 (*(volatile u8*)0x53)
#define TCNT0 (*(volatile u8*)0x52)
#define OCR0 (*(volatile u8*)0x5C)
#define TIMSK (*(volatile u8*)0x59)
#define TIFR (*(volatile u8*)0x58)

/* UART REGISTERS*/

// USART I/O Data Register
#define UDR            (*(volatile u8*)0x2C)

// USART Control and Status Register A
#define UCSRA          (*(volatile u8*)0x2B)

// USART Control and Status Register B
#define UCSRB          (*(volatile u8*)0x2A)

// USART Control and Status Register C
#define UCSRC          (*(volatile u8*)0x40)

// USART Baud Rate Registers
#define UBRRL          (*(volatile u8*)0x29)
#define UBRRH          (*(volatile u8*)0x40)

/*I2C(TWI) Registers*/
//TWI Bit Rate Register
#define  TWBR			(*(volatile u8*)0x20)
//TWI Control Register
#define TWCR			(*(volatile u8*)0x56)
//TWI Status Register
#define TWSR			(*(volatile u8*)0x21)
//TWI Data Register
#define TWDR			(*(volatile u8*)0x23)
//TWI (Slave) Address Register
#define TWAR			(*(volatile u8*)0x22)

/* EEPROM */ 

#define EEARL              *((volatile u8*)0x3E)
#define EEARH              *((volatile u8*)0x3F)
#define EEDR               *((volatile u8*)0x3D)
#define EECR               *((volatile u8*)0x3C)
#define EEAR_u16           *((volatile u16*)0x3E)

#endif /* ATMEGA32_REG_H_ */