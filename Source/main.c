 
#include "StdTypes.h"
#include "Utlis.h"
#include "MemMap.h"

#define F_CPU  8000000UL
#include <util/delay.h>

#include "DIO_Interface.h"
#include "Timers.h"



#include "LCD_Interface.h"
#include "Motor_Interface.h"
#include "UART.h"
#include "Car.h"

#define FULL_SPEED 100
#define HALF_SPEED 50


int main(void)
{
	u16 command = 0;
/***********************Initialisation******************************/	
DIO_Init();
LCD_Init();
CAR_Init();
UART_Init();
TIMER0_Init(TIMER0_FASTPWM_MODE,TIMER0_SCALER_256);
TIMER0_OC0Mode(OC0_NON_INVERTING);
TIMER2_Init(TIMER2_FASTPWM_MODE,TIMER0_SCALER_256);
TIMER2_OC2Mode(OC2_NON_INVERTING);
/*********************************************************************/
    while (1) 
    {
		
	if(UART_ReceivePeriodic(&command))
	{

		if(command == 'F')
		{
			MoveForward(FULL_SPEED);
		}
		if(command == 'B')
		{
			MoveBackward(FULL_SPEED);
		}
		if(command == 'R')
		{
			Turn_Right(FULL_SPEED);
		}
		if(command == 'L')
		{
			Turn_Left(FULL_SPEED);
		}
		if(command == 'E')
		{
			MoveRight(FULL_SPEED);
		}
		if(command == 'Q')
		{
			MoveLeft(FULL_SPEED);
		}
		if(command == 'S')
		{
			Stop();
		}
	}
	
	}
}

