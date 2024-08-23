
#include "StdTypes.h"
#include "MemMap.h"
#include "Utlis.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "Motor_Interface.h"
#include "Timers_Services.h"
#include "Car.h"



void CAR_Init()
{
	Motor_Stop(M1);
	Motor_Stop(M2);
	PWM_Duty_Timer0(1);
	PWM_Duty_Timer2(1);
// 	Motor_Stop(M3);
// 	Motor_Stop(M4);
}

/*
void CAR_Runnable(void)
{
	if(Dio_ReadPin(B_F) == 0)
	{
		MoveForward();
		while(Dio_ReadPin(B_F) == 0);
	}
	if(Dio_ReadPin(B_B) == 0)
	{
		MoveBackward();
		while(Dio_ReadPin(B_B) == 0);
	}
	if(Dio_ReadPin(B_R) == 0)
	{
		MoveRight();
		while(Dio_ReadPin(B_R) == 0);
	}
	if(Dio_ReadPin(B_L) == 0)
	{
		MoveLeft();
		while(Dio_ReadPin(B_L) == 0);
	}
	if(Dio_ReadPin(B_S) == 0)
	{
		Stop();
		while(Dio_ReadPin(B_S) == 0);
	}
}
*/
 void MoveForward(u8 speed)
{
 	PWM_Duty_Timer0(speed);
 	PWM_Duty_Timer2(speed);
	Motor_CW(M1);
	Motor_CW(M2);
}

 void MoveBackward(u8 speed)
{
 	PWM_Duty_Timer0(speed);
 	PWM_Duty_Timer2(speed);
	Motor_CCW(M1);
	Motor_CCW(M2);
}


 void MoveRight(u8 speed)
{
	PWM_Duty_Timer0(speed/2);
	PWM_Duty_Timer2(speed);
	Motor_CW(M1);
	Motor_CW(M2);
}


 void MoveLeft(u8 speed)
{
	PWM_Duty_Timer0(speed);
	PWM_Duty_Timer2(speed/2);
	Motor_CW(M1);
	Motor_CW(M2);
}

void Stop(void)
{
	Motor_Stop(M1);
	Motor_Stop(M2);
}

void Turn_Right(u8 speed)
{
	PWM_Duty_Timer0(0);
	PWM_Duty_Timer2(speed);
	Motor_Stop(M1);
	Motor_CW(M2);
	//Stop();
}

void Turn_Right90(u8 speed)
{
	PWM_Duty_Timer0(speed);
	PWM_Duty_Timer2(speed);
	Motor_Stop(M1);
	Motor_CW(M2);
	_delay_ms(1500);
	//Stop();
}

void Turn_Left90(u8 speed)
{
	 PWM_Duty_Timer0(speed);
	 PWM_Duty_Timer2(speed);
	 Motor_Stop(M2);
	 Motor_CW(M1);
	 _delay_ms(1500);
	 //Stop();
	
}

void Turn_Left(u8 speed)
{
	PWM_Duty_Timer0(speed);
	PWM_Duty_Timer2(0);
	Motor_Stop(M2);
	Motor_CW(M1);
	//Stop();
	
}

void Turn_Right45(u8 speed)
{
	 PWM_Duty_Timer0(speed);
	 PWM_Duty_Timer2(speed);
	 Motor_Stop(M1);
	 Motor_CW(M2);
	_delay_ms(750);
	//Stop();
	
}

void Turn_Left45(u8 speed)
{
	PWM_Duty_Timer0(speed);
	PWM_Duty_Timer2(speed);
	Motor_Stop(M2);
	Motor_CW(M1);
	_delay_ms(750);
	//Stop();
	
}
void Turn_180(u8 speed)
{
	PWM_Duty_Timer0(speed);
	PWM_Duty_Timer2(speed);
	Motor_Stop(M1);
	Motor_CW(M2);
	_delay_ms(3000);
	//Stop();
}

void start_routine(u16 timeout) // in ms
{
	u16 c = 0;
	_delay_ms(1000);
	Turn_Right45(50);
	MoveForward(100);
	_delay_ms(6000);
	Turn_Left45(50);
	while(c<timeout)
	{
		c++;
		_delay_ms(1);
	}
	Stop();
}

void search(u8 speed)
{
	MoveLeft(speed); // moving in circular motion
}
