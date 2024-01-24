/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "MCAL/TIMER/TIMER_Interface.h"
#include "MCAL/TIMER/Timer_Private.h"
#include "MCAL/TIMER/Timer_Config.h"


void (* TIMER_pvTimer0NotificationFunction)(void) = NULL; 
void (* TIMER_pvICUNotificationFunction)(void) = NULL;

/*********************************************************************************/
/* Function: TIMER_voidTimer0Init	                        				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function initializes Timer0							       	    **/
/*********************************************************************************/
void TIMER_voidTimer0Init(void)
{
	#if WAVEFORM_GEN_MODE == NORMAL_MODE
	/*Set Timer 0 in NORMAL_MODE*/
	CLR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_WGM00);
	CLR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_WGM01);

	#elif WAVEFORM_GEN_MODE == PWM_OR_PHASE_COTROL
	/*Set Timer 0 in PWM_OR_PHASE_COTROL Mode*/
	SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_WGM00);
	CLR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_WGM01);

	#elif WAVEFORM_GEN_MODE == CTC_MODE
	/*Set Timer 0 in CTC_MODE*/
	CLR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_WGM00);
	SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_WGM01);
	switch(OC0_ACTION)
	{
		case NON_PWM_NORMAL_PORT_OPRETATION:				/*Normal Port Operation*/
															CLR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM00);
															CLR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM01);
															break;
		case NON_PWM_TOGGLE_OC0_ON_COMPARE_MATCH:	        /*Toggle OC0 on Compare Match*/
															SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM00);
															CLR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM01);
															break;
		case NON_PWM_CLEAR_OC0_ON_COMPARE_MATCH:	        /*Clear OC0 on Compare Match*/
															CLR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM00);
															SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM01);
															break;
		case NON_PWM_SET_OC0_ON_COMPARE_MATCH:	            /*Set OC0 on Compare Match*/
															SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM00);
															SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM01);
															break;
		default: break;
	}

	#elif WAVEFORM_GEN_MODE == FAST_PWM_MODE
	/*Set Timer 0 in FAST_PWM_MODE*/
	SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_WGM00);
	SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_WGM01);
	switch(OC0_ACTION)
	{
	case FAST_PWM_NORMAL_PORT_OPRETATION:						/*Normal Port Operation*/
																CLR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM00);
																CLR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM01);
																break;
	case FAST_PWM_CLEAR_OC0_ON_COMPARE_MATCH__SET_OC0_ON_TOP:	/*Set The "Clear On Compare, Sets On TOP" Mode (Non-Inverted)*/
																CLR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM00);
																SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM01);
																break;
	case FAST_PWM_SET_OC0_ON_COMPARE_MATCH__CLEAR_OC0_ON_TOP:	/*Set The "Set On Compare, Clear On TOP" Mode (Inverted)*/
																SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM00);
																SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM01);
																break;
	default: break;
	}
	#endif

	/*Set The Prescaler to be 8*/
	TIM0_u8_TCCR0_REG &= PRESCALER_MASK;
	TIM0_u8_TCCR0_REG |= PRESCALER_TYPE;
}

/*********************************************************************************/
/* Function: TIMER_voidTimer1Init	                        				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function initializes Timer1							       	    **/
/*********************************************************************************/
void TIMER_voidTimer1Init(void)
{
	/*Select The Normal Mode*/
	CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_WGM10);
	CLR_BIT(TIM1_u8_TCCR1A_REG, TIM1_u8_TCCR1A_WGM11);
	CLR_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_WGM12);
	CLR_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_WGM13);

	/*Set Prescaler to be 8*/
	CLR_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_CS10);
	SET_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_CS11);
	CLR_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_CS12);
}

/*********************************************************************************/
/* Function: TIMER_voidTimer0SetCompareValue	               				    **/
/* I/P Parameters: Copy_u8CompareValue						          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Sets the compare value of timer 0					       	**/
/*********************************************************************************/
/* Copy_u16CompareValue Options: Compare value assigned directly				**/
/*********************************************************************************/
void TIMER_voidTimer0SetCompareValue(u8 Copy_u8CompareValue)
{
	/*Set The Compare Value to the OCR0 Register*/
	TIM0_u8_OCR0_REG = Copy_u8CompareValue;
}

/*********************************************************************************/
/* Function: TIMER_voidTimer0SetCallBack		               				    **/
/* I/P Parameters: void (*Copy_pvNotificationFunction)(void)		   		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Sets the call back of Timer0							  	**/
/*********************************************************************************/
/* Copy_pvNotificationFunction Options: Address of the function to be executed	**/
/*********************************************************************************/
void TIMER_voidTimer0SetCallBack(void (*Copy_pvNotificationFunction)(void))
{
	/*Assign the function address to the global pointer to function*/
	TIMER_pvTimer0NotificationFunction = Copy_pvNotificationFunction;
}

/*********************************************************************************/
/* Function: TIMER_voidTimer1ASetCompareValue               				    **/
/* I/P Parameters: Copy_u16CompareValue						          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Sets the compare value of timer 1 - A				       	**/
/*********************************************************************************/
/* Copy_u16CompareValue Options: Compare value assigned directly				**/
/*********************************************************************************/
void TIMER_voidTimer1ASetCompareValue(u16 Copy_u16CompareValue)
{
	/* Set The Compare Value To OCR1 Channel A Register*/
	TIM1_u16_OCR1A_REG = Copy_u16CompareValue;
}

/*********************************************************************************/
/* Function: TIMER_voidTimer1BSetCompareValue               				    **/
/* I/P Parameters: Copy_u16CompareValue						          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Sets the compare value of timer 1 - B				       	**/
/*********************************************************************************/
/* Copy_u16CompareValue Options: Compare value assigned directly				**/
/*********************************************************************************/
void TIMER_voidTimer1BSetCompareValue(u16 Copy_u16CompareValue)
{
	/* Set The Compare Value To OCR1 Channel B Register*/
	TIM1_u16_OCR1B_REG = Copy_u16CompareValue;
}

/*********************************************************************************/
/* Function: TIMER_voidTimer1SetInputCaptureValue            				    **/
/* I/P Parameters: Copy_u16CaptureValue						          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Sets the input capture value of timer 1			       	**/
/*********************************************************************************/
/* Copy_u16CaptureValue Options: Capture value assigned directly				**/
/*********************************************************************************/
void TIMER_voidTimer1SetInputCaptureValue(u16 Copy_u16CaptureValue)
{
	/*Set The Input Capture Value to ICR1 Register*/
	TIM1_u16_ICR1_REG = Copy_u16CaptureValue;
}

/*********************************************************************************/
/* Function: ICU_voidInit			                        				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function initializes Input Capture unit				       	    **/
/*********************************************************************************/
void ICU_voidInit(void)
{
	/*Set Trigger to rising edge initially*/
	SET_BIT(TIM1_u8_TCCR1B_REG,TIM1_u8_TCCR1B_ICES1);

	/*Enable The ICU Interrupt*/
	SET_BIT(TIM0_u8_TIMSK_REG, TIM0_u8_TIMSK_TICIE1);
}

/*********************************************************************************/
/* Function: ICU_voidSetTrigger		                        				    **/
/* I/P Parameters: Copy_u8TriggerSource						          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function sets the trigger source of Input Capture unit	    	    **/
/*********************************************************************************/
/* Copy_u8TriggerSource Options: RISING_EDGE, FALLING_EDGE						**/
/*********************************************************************************/
void ICU_voidSetTrigger(u8 Copy_u8TriggerSource)
{
	switch(Copy_u8TriggerSource)
	{
		case RISING_EDGE:
			/*Set The Rising Edge to be the trigger source*/
			SET_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_ICES1);
			break;
		case FALLING_EDGE:
			/*Set The Falling Edge to be the trigger source*/
			CLR_BIT(TIM1_u8_TCCR1B_REG, TIM1_u8_TCCR1B_ICES1);
			break;
		default:
			break;
	}
}

/*********************************************************************************/
/* Function: ICU_u16ReadInputCapture	                       				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns u16	                                				    **/
/* Desc:This Function reads the value captured by Input Capture unit    	    **/
/*********************************************************************************/
u16 ICU_u16ReadInputCapture(void)
{
	/*Get The Captured Value From ICR1 Register*/
	return TIM1_u16_ICR1_REG;
}

/*********************************************************************************/
/* Function: ICU_u16ReadInputCapture	                       				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns Nothing                               				    **/
/* Desc:This Function disable the interrupt of Input Capture unit	    	    **/
/*********************************************************************************/
void ICU_voidInterruptDisbale(void)
{
	/*Disable The ICU Interrupt*/
	CLR_BIT(TIM0_u8_TIMSK_REG, TIM0_u8_TIMSK_TICIE1);
}

/*********************************************************************************/
/* Function: ICU_voidSetCallBack				               				    **/
/* I/P Parameters: void (*Copy_pvNotificationFunction)(void)		   		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Sets the call back of ICU								  	**/
/*********************************************************************************/
/* Copy_pvNotificationFunction Options: Address of the function to be executed	**/
/*********************************************************************************/
void ICU_voidSetCallBack(void (*Copy_pvNotificationFunction)(void))
{
	TIMER_pvICUNotificationFunction = Copy_pvNotificationFunction;
}

/***********************************Timer0 ISR forCompare Match Event***********************************/
void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
	/*Check if the global pointer to function is changed or not*/
	if(TIMER_pvTimer0NotificationFunction != NULL)
	{
		/*Execute the global pointer to function*/
		TIMER_pvTimer0NotificationFunction();
	}
}

/***********************************ISR for ICU Capture Event***********************************/
void __vector_6 (void) __attribute__((signal));
void __vector_6 (void)
{
	if(TIMER_pvICUNotificationFunction != NULL)
	{
		/*Execute the global pointer to function*/
		TIMER_pvICUNotificationFunction();
	}
	else
	{
		/*Do Nothing*/
	}
}

