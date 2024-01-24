/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/

#ifndef    TIMER_INTERFACE_H
#define    TIMER_INTERFACE_H

/*Public Macros*/
#define    NORMAL_MODE      			                            0
#define    PWM_OR_PHASE_COTROL                                      1
#define    CTC_MODE                                                 2
#define    FAST_PWM_MODE                                            3

#define    NON_PWM_NORMAL_PORT_OPRETATION                           0
#define    NON_PWM_TOGGLE_OC0_ON_COMPARE_MATCH                      1
#define    NON_PWM_CLEAR_OC0_ON_COMPARE_MATCH                       2
#define    NON_PWM_SET_OC0_ON_COMPARE_MATCH						    3


#define    FAST_PWM_NORMAL_PORT_OPRETATION                          0
#define    FAST_PWM_CLEAR_OC0_ON_COMPARE_MATCH__SET_OC0_ON_TOP      1
#define    FAST_PWM_SET_OC0_ON_COMPARE_MATCH__CLEAR_OC0_ON_TOP	  	2


#define    CLK_DIV_BY_0										 	    1
#define    CLK_DIV_BY_8										 	    2
#define    CLK_DIV_BY_64                                            3
#define    CLK_DIV_BY_256                                           4
#define    CLK_DIV_BY_1024                                          5
#define    ECS_ON_T0_FALLING_EDGE      								6
#define    ECS_ON_T0_RISING_EDGE       								7

#define	   RISING_EDGE												0
#define	   FALLING_EDGE												1

/*********************************************************************************/
/*************************Public Functions Prototypes*****************************/
/*********************************************************************************/

/*********************************************************************************/
/* Function: TIMER_voidTimer0Init	                        				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function initializes Timer0							       	    **/
/*********************************************************************************/
void TIMER_voidTimer0Init(void);

/*********************************************************************************/
/* Function: TIMER_voidTimer1Init	                        				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function initializes Timer1							       	    **/
/*********************************************************************************/
void TIMER_voidTimer1Init(void);

/*********************************************************************************/
/* Function: TIMER_voidTimer0SetCompareValue	               				    **/
/* I/P Parameters: Copy_u8CompareValue						          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Sets the compare value of timer 0					       	**/
/*********************************************************************************/
/* Copy_u16CompareValue Options: Compare value assigned directly				**/
/*********************************************************************************/
void TIMER_voidTimer0SetCompareValue(u8 Copy_u8CompareValue);

/*********************************************************************************/
/* Function: TIMER_voidTimer0SetCallBack		               				    **/
/* I/P Parameters: void (*Copy_pvNotificationFunction)(void)		   		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Sets the call back of Timer0							  	**/
/*********************************************************************************/
/* Copy_pvNotificationFunction Options: Address of the function to be executed	**/
/*********************************************************************************/
void TIMER_voidTimer0SetCallBack(void (*Copy_pvNotificationFunction)(void));

/*********************************************************************************/
/* Function: TIMER_voidTimer1ASetCompareValue               				    **/
/* I/P Parameters: Copy_u16CompareValue						          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Sets the compare value of timer 1 - A				       	**/
/*********************************************************************************/
/* Copy_u16CompareValue Options: Compare value assigned directly				**/
/*********************************************************************************/
void TIMER_voidTimer1ASetCompareValue(u16 Copy_u16CompareValue);

/*********************************************************************************/
/* Function: TIMER_voidTimer1BSetCompareValue               				    **/
/* I/P Parameters: Copy_u16CompareValue						          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Sets the compare value of timer 1 - B				       	**/
/*********************************************************************************/
/* Copy_u16CompareValue Options: Compare value assigned directly				**/
/*********************************************************************************/
void TIMER_voidTimer1BSetCompareValue(u16 Copy_u16CompareValue);

/*********************************************************************************/
/* Function: TIMER_voidTimer1SetInputCaptureValue            				    **/
/* I/P Parameters: Copy_u16CaptureValue						          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Sets the input capture value of timer 1			       	**/
/*********************************************************************************/
/* Copy_u16CaptureValue Options: Capture value assigned directly				**/
/*********************************************************************************/
void TIMER_voidTimer1SetInputCaptureValue(u16 Copy_u16CaptureValue);

/*********************************************************************************/
/* Function: ICU_voidInit			                        				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function initializes Input Capture unit				       	    **/
/*********************************************************************************/
void ICU_voidInit(void);

/*********************************************************************************/
/* Function: ICU_voidSetTrigger		                        				    **/
/* I/P Parameters: Copy_u8TriggerSource						          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function sets the trigger source of Input Capture unit	    	    **/
/*********************************************************************************/
/* Copy_u8TriggerSource Options: RISING_EDGE, FALLING_EDGE						**/
/*********************************************************************************/
void ICU_voidSetTrigger(u8 Copy_u8TriggerSource);

/*********************************************************************************/
/* Function: ICU_u16ReadInputCapture	                       				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns u16	                                				    **/
/* Desc:This Function reads the value captured by Input Capture unit    	    **/
/*********************************************************************************/
u16 ICU_u16ReadInputCapture(void);

/*********************************************************************************/
/* Function: ICU_u16ReadInputCapture	                       				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns Nothing                               				    **/
/* Desc:This Function disable the interrupt of Input Capture unit	    	    **/
/*********************************************************************************/
void ICU_voidInterruptDisbale(void);

/*********************************************************************************/
/* Function: ICU_voidSetCallBack				               				    **/
/* I/P Parameters: void (*Copy_pvNotificationFunction)(void)		   		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function Sets the call back of ICU								  	**/
/*********************************************************************************/
/* Copy_pvNotificationFunction Options: Address of the function to be executed	**/
/*********************************************************************************/
void ICU_voidSetCallBack(void (*Copy_pvNotificationFunction)(void));

#endif
