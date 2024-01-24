/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/
#ifndef TIMER_CONFIG_H
#define TIMER_CONFIG_H

/**************************************************************************************************/
/**********************************WAVEFORM_GEN_MODE options***************************************/
/* 			  	                    0  NORMAL_MODE                                                */
/*                                  1  PWM_OR_PHASE_COTROL                                        */
/*                                  2  CTC_MODE                                                   */
/*                                  3  FAST_PWM_MODE                                              */
/**************************************************************************************************/
/**************************************************************************************************/
#define 	  WAVEFORM_GEN_MODE          FAST_PWM_MODE

/*********************************Control action on OC0 pin****************************************/
/**********************************for Non-PWM Mode options****************************************/
/* 			  	                    0  NORMAL_MODE                                                */
/*                                  1  PWM_OR_PHASE_COTROL                                        */
/*                                  2  CTC_MODE                                                   */
/*                                  3  FAST_PWM_MODE                                              */
/**************************************************************************************************/
/***********************************FAST_PWM_MODE options******************************************/
/*  0  FAST_PWM_NORMAL_PORT_OPRETATION                                                            */
/*  1  FAST_PWM_CLEAR_OC0_ON_COMPARE_MATCH__SET_OC0_ON_TOP    (non inverted mode)                 */
/*  2  FAST_PWM_SET_OC0_ON_COMPARE_MATCH__CLEAR_OC0_ON_TOP	   (inverted mode)                    */
/**************************************************************************************************/
/**************************************************************************************************/
#define 	 OC0_ACTION                 FAST_PWM_CLEAR_OC0_ON_COMPARE_MATCH__SET_OC0_ON_TOP

/**************************************************************************************************/
/**********************************PRESCALER_TYPE options******************************************/
/* 	TIMER_COUNTER_DISABLED              No clock source (Timer/Counter stopped).                  */
/*  CLK_DIV_BY_0				        (No   prescaling)                                         */
/*  CLK_DIV_BY_8				        (From prescaler)                                          */
/*  CLK_DIV_BY_64                       (From prescaler)                                          */
/* 	CLK_DIV_BY_256                      (From prescaler)                                          */
/*  CLK_DIV_BY_1024                     (From prescaler)                                          */
/*  ECS_ON_T0_FALLING_EDGE              External clock source on T0 pin. Clock on falling edge.   */
/*  ECS_ON_T0_RISING_EDGE               External clock source on T0 pin. Clock on rising edge     */
/* 	ECS_ON_T1_FALLING_EDGE              External clock source on T1 pin. Clock on falling edge.   */
/*  ECS_ON_T1_RISING_EDGE               External clock source on T1 pin. Clock on rising edge     */
/**************************************************************************************************/
/**************************************************************************************************/
#define 	 PRESCALER_TYPE     CLK_DIV_BY_8

#define 	 PRESCALER_MASK     0b11111000


/*****************************Timer1**************************************/
//Try the same concept with Timer 1 :)

#endif
