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


#endif /* ATMEGA32_REG_H_ */