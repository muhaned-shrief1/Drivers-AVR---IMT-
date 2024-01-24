/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/
#ifndef		ADC_PRIVATE_H
#define		ADC_PRIVATE_H

/*Registers & their Pins Macros*/
#define     ADC_u8_ADMUX_REG        *((volatile u8 *)(0x27))
#define     ADC_u8_ADMUX_MUX0       0
#define     ADC_u8_ADMUX_MUX1       1
#define     ADC_u8_ADMUX_MUX2       2
#define     ADC_u8_ADMUX_MUX3       3
#define     ADC_u8_ADMUX_MUX4       4
#define     ADC_u8_ADMUX_ADLAR      5
#define     ADC_u8_ADMUX_REFS0      6
#define     ADC_u8_ADMUX_REFS1      7

#define     ADC_u8_ADCSRA_REG       *((volatile u8 *)(0x26))
#define     ADC_u8_ADCSRA_ADPS0     0
#define     ADC_u8_ADCSRA_ADPS1     1
#define     ADC_u8_ADCSRA_ADPS2     2
#define     ADC_u8_ADCSRA_ADIE      3
#define     ADC_u8_ADCSRA_ADIF      4
#define     ADC_u8_ADCSRA_ADATE     5
#define     ADC_u8_ADCSRA_ADSC      6
#define     ADC_u8_ADCSRA_ADEN      7

#define     ADC_u8_ADCH_REG         *((volatile u8 *)0x25)
#define     ADC_u8_ADCL_REG         *((volatile u8 *)0x24)

#define     ADC_u16_ADC_REG         *((volatile u16 *)0x24)

/*Private Macros*/
/*********************************************************************************/
/* ADC_REFVOLT Options: 	ADC_AREF	ADC_AVCC    ADC_INTERNAL			    **/
/*********************************************************************************/
#define		ADC_AREF	  0
#define     ADC_AVCC      1
#define     ADC_INTERNAL  2	
/*********************************************************************************/
/* ADC_ADJUST_CTRL Options: 	LEFT, RIGHT                     			    **/
/*********************************************************************************/
#define     LEFT		  1
#define     RIGHT         0

/*********************************************************************************/
/* Necessary masks                                              			    **/
/*********************************************************************************/
#define		ADC_PRES_MASK		0b11111000
#define		ADC_CHANNEL_MASK	0b11100000

#define		NOTBUSY			0
#define		BUSY			1

#endif
