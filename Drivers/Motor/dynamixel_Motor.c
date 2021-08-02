/***********************************
 * StepMotor.c
 *
 *  Created on: July 13, 2021
 *      Author: tsha
 *  Please keep this area
 **********************************/
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "dynamixel_Motor.h"

UART_HandleTypeDef huart1;
#if 1
typedef struct{
	uint8_t data[50];
	int16_t len;
} DynamixelPacket;

DynamixelPacket  Postion1={
		{0xFF, 0xFF,0xFE,0x0E,0x83,0x1E,0x04,0x01,0x08,0x02,0x3C,0x00,0x02,0x94,0x02,0x5A,0x00,0x15},
		18
        };
DynamixelPacket  Postion2={
		{0xFF, 0xFF,0xFE,0x0E,0x83,0x1E,0x04,0x01,0x44,0x02,0x3C,0x00,0x02,0xF4,0x01,0x5A,0x00,0x7A},
		18
        };

DynamixelPacket  Postion3={
		{0xFF, 0xFF,0xFE,0x0E,0x83,0x1E,0x04,0x01,0x26,0x02,0x14,0x00,0x02,0x62,0x02,0x50,0x00,0x5B},
		18
        };

DynamixelPacket  Postion4={
		{0xFF, 0xFF,0xFE,0x0E,0x83,0x1E,0x04,0x01,0xA8,0x02,0x3C,0x00,0x02,0x3A,0x02,0x3C,0x00,0xED},
		18
        };

DynamixelPacket  Postion5={
		{0xFF, 0xFF,0xFE,0x0E,0x83,0x1E,0x04,0x01,0x8A,0x02,0x46,0x00,0x02,0x35,0x02,0x28,0x00,0x1A},
		18
        };
DynamixelPacket  Postion6={
		{0xFF, 0xFF,0xFE,0x0E,0x83,0x1E,0x04,0x01,0x44,0x02,0x3C,0x00,0x02,0xF4,0x01,0x3C,0x00,0x98},
		18
        };





void arm_up()
{
	HAL_UART_Transmit(&huart1, Postion1.data, Postion1.len ,100);
	HAL_UART_Transmit(&huart1, Postion1.data, Postion1.len ,100);
	HAL_UART_Transmit(&huart1, Postion1.data, Postion1.len ,100);
}

void arm_grabposition()
{
	HAL_UART_Transmit(&huart1, Postion2.data, Postion2.len ,100);
	HAL_UART_Transmit(&huart1, Postion2.data, Postion2.len ,100);
	HAL_UART_Transmit(&huart1, Postion2.data, Postion2.len ,100);
}
void arm_grabup()
{
	HAL_UART_Transmit(&huart1, Postion3.data, Postion3.len ,100);
	HAL_UART_Transmit(&huart1, Postion3.data, Postion3.len ,100);
	HAL_UART_Transmit(&huart1, Postion3.data, Postion3.len ,100);
}
void arm_forward()
{
	HAL_UART_Transmit(&huart1, Postion4.data, Postion4.len ,100);
	HAL_UART_Transmit(&huart1, Postion4.data, Postion4.len ,100);
	HAL_UART_Transmit(&huart1, Postion4.data, Postion4.len ,100);
}
void arm_3forward()
{
	HAL_UART_Transmit(&huart1, Postion5.data, Postion5.len ,100);
	HAL_UART_Transmit(&huart1, Postion5.data, Postion5.len ,100);
	HAL_UART_Transmit(&huart1, Postion5.data, Postion5.len ,100);
}
void arm_comeback()
{
	HAL_UART_Transmit(&huart1, Postion6.data, Postion6.len ,100);
	HAL_UART_Transmit(&huart1, Postion6.data, Postion6.len ,100);
	HAL_UART_Transmit(&huart1, Postion6.data, Postion6.len ,100);
}

#elif 0
void arm_up()
{
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\xFF",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\xFF",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\xFE",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x0E",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x83",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x1E",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x04",1,100);//cksm 1B1
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x01",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x08",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x02",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x3C",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x00",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x02",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x94",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x02",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x5A",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x00",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x15",1,100); // 물체 이동할때 머리 들어주기
}

void arm_grabposition()
{
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\xFF",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\xFF",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\xFE",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x0E",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x83",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x1E",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x04",1,100);//cksm 1B1
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x01",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x44",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x02",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x3C",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x00",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x02",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\xF4",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x01",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x5A",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x00",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x7A",1,100); // 물체 잡는 포지션
}

void arm_grabup()
{
			  HAL_UART_Transmit(&huart1, (uint8_t*)"\xFF",1,100);
		 	  HAL_UART_Transmit(&huart1, (uint8_t*)"\xFF",1,100);
		 	  HAL_UART_Transmit(&huart1, (uint8_t*)"\xFE",1,100);
		 	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x0E",1,100);
		 	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x83",1,100);
		 	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x1E",1,100);
		 	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x04",1,100);//cksm 1B1
		 	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x01",1,100);
		 	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x26",1,100);
		 	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x02",1,100);
		 	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x14",1,100);
		 	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x00",1,100);
		 	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x02",1,100);
		 	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x62",1,100);
		 	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x02",1,100);
		 	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x50",1,100);
		 	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x00",1,100);
		 	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x5B",1,100); // 물체 회전하려 올리기

}

void arm_forward()
{
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\xFF",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\xFF",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\xFE",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x0E",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x83",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x1E",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x04",1,100);//cksm 1B1
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x01",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\xA8",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x02",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x3C",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x00",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x02",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x3A",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x02",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x3C",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x00",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\xED",1,100);// 물체 전방 뻗기
}

void arm_3forward()
{
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\xFF",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\xFF",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\xFE",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x0E",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x83",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x1E",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x04",1,100);//cksm 1B1
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x01",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x8A",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x02",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x46",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x00",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x02",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x35",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x02",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x28",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x00",1,100);
	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x1A",1,100);// 물체 전방 뻗기
}
void arm_comeback()
{
			  HAL_UART_Transmit(&huart1, (uint8_t*)"\xFF",1,100);
		 	  HAL_UART_Transmit(&huart1, (uint8_t*)"\xFF",1,100);
		 	  HAL_UART_Transmit(&huart1, (uint8_t*)"\xFE",1,100);
		 	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x0E",1,100);
		 	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x83",1,100);
		 	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x1E",1,100);
		 	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x04",1,100);//cksm 1B1
		 	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x01",1,100);
		 	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x44",1,100);
		 	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x02",1,100);
		 	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x3C",1,100);
		 	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x00",1,100);
		 	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x02",1,100);
		 	  HAL_UART_Transmit(&huart1, (uint8_t*)"\xF4",1,100);
		 	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x01",1,100);
		 	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x3C",1,100);
		 	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x00",1,100);
		 	  HAL_UART_Transmit(&huart1, (uint8_t*)"\x98",1,100); // 뻗고 다시 돌아오기
}
#endif
