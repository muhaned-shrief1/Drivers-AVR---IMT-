/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/

/****************************************************/
/* Library Directives							    */
/****************************************************/
#define F_CPU 8000000UL
#include <util/delay.h>
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

/****************************************************/
/* DIO Directives								    */
/****************************************************/
#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/DIO/DIO_Private.h"
#include "MCAL/DIO/DIO_Config.h"

#include "HAL/LCD/LCD_Interface.h"
#include "HAL/LCD/LCD_Private.h"
#include "HAL/LCD/LCD_Config.h"

#include "OS/FreeRTOS.h"
#include "OS/task.h"
#include "OS/semphr.h"

void AppTask1(void * copy_VP);
void AppTask2(void * copy_VP);
void AppTask3(void * copy_VP);

void AppTask1LCD(void * copy_VP);
void AppTask2LCD(void * copy_VP);

xSemaphoreHandle LCD_Semaphor;

void (main)(void)
{
	/*Configure the direction of the 3 pins as O/P*/
	DIO_voidSetPinDirection(DIO_u8_PORTA, DIO_u8_PIN0, DIO_u8_OUTPUT);

	/*Create 3 Tasks*/
	xTaskCreate(&AppTask1, NULL, 200, NULL, 4, NULL);
	xTaskCreate(&AppTask2, NULL, 200, NULL, 3, NULL);
	xTaskCreate(&AppTask3, NULL, 200, NULL, 2, NULL);

	/*Start Scheduler*/
	vTaskStartScheduler();
	while (1)
	{

	}

}

void AppTask1(void * copy_VP)
{
	static u8 flag=0;
	while (1)
		{
			//Toggle LED1
			if (flag==0)
			{
				MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_HIGH);
				flag=1;
			}
			else
			{
				MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_LOW);
				flag=0;
			}
			vTaskDelay(1000);
		}
}

void AppTask2(void * copy_VP)
{
	static u8 flag=0;
	while (1)
		{
			//Toggle LED2
			if (flag==0)
			{
				MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN1,DIO_u8_HIGH);
				flag=1;
			}
			else
			{
				MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN1,DIO_u8_LOW);
				flag=0;
			}
			vTaskDelay(2000);
		}
}

void AppTask3(void * copy_VP)
{
	static u8 flag=0;
	while (1)
		{
			//Toggle LED3
			if (flag==0)
			{
				MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN2,DIO_u8_HIGH);
				flag=1;
			}
			else
			{
				MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN2,DIO_u8_LOW);
				flag=0;
			}
			vTaskDelay(5000);
		}
}



