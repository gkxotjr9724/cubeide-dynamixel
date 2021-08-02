/***********************************
 * StepMotor.c
 *
 *  Created on: Dec 13, 2020
 *      Author: yhyee
 *  Please keep this area
 **********************************/

#include <stdio.h>
#include "main.h"
#include "StepMotor.h"

#define DELAY_TIME  20
uint8_t phase[4]={1,2,4,8};//A B /A /B

void StepMotorClockwise()
{

					  //0x01 = 0001
	                  HAL_GPIO_WritePin(STEP_A_GPIO_Port, STEP_A_Pin, GPIO_PIN_SET);
					  HAL_GPIO_WritePin(STEP_B_GPIO_Port, STEP_B_Pin, GPIO_PIN_RESET);
					  HAL_GPIO_WritePin(STEP_Ab_GPIO_Port, STEP_Ab_Pin, GPIO_PIN_RESET);
					  HAL_GPIO_WritePin(STEP_Bb_GPIO_Port, STEP_Bb_Pin, GPIO_PIN_RESET);
					  HAL_Delay(DELAY_TIME);

					  //0x02 = 0010
					  HAL_GPIO_WritePin(STEP_A_GPIO_Port, STEP_A_Pin, GPIO_PIN_RESET);
					  HAL_GPIO_WritePin(STEP_B_GPIO_Port, STEP_B_Pin, GPIO_PIN_SET);
					  HAL_GPIO_WritePin(STEP_Ab_GPIO_Port, STEP_Ab_Pin, GPIO_PIN_RESET);
					  HAL_GPIO_WritePin(STEP_Bb_GPIO_Port, STEP_Bb_Pin, GPIO_PIN_RESET);
					  HAL_Delay(DELAY_TIME);

					  //0x04 = 0100
					  HAL_GPIO_WritePin(STEP_A_GPIO_Port, STEP_A_Pin, GPIO_PIN_RESET);
					  HAL_GPIO_WritePin(STEP_B_GPIO_Port, STEP_B_Pin, GPIO_PIN_RESET);
					  HAL_GPIO_WritePin(STEP_Ab_GPIO_Port, STEP_Ab_Pin, GPIO_PIN_SET);
					  HAL_GPIO_WritePin(STEP_Bb_GPIO_Port, STEP_Bb_Pin, GPIO_PIN_RESET);
					  HAL_Delay(DELAY_TIME);

					  //0x08 = 1000
					  HAL_GPIO_WritePin(STEP_A_GPIO_Port, STEP_A_Pin, GPIO_PIN_RESET);
					  HAL_GPIO_WritePin(STEP_B_GPIO_Port, STEP_B_Pin, GPIO_PIN_RESET);
					  HAL_GPIO_WritePin(STEP_Ab_GPIO_Port, STEP_Ab_Pin, GPIO_PIN_RESET);
					  HAL_GPIO_WritePin(STEP_Bb_GPIO_Port, STEP_Bb_Pin, GPIO_PIN_SET);
					  HAL_Delay(DELAY_TIME);


}
void StepMotorCounterClockwise()
{

					  //0x08 1000
					  HAL_GPIO_WritePin(STEP_A_GPIO_Port, STEP_A_Pin, GPIO_PIN_RESET);
					  HAL_GPIO_WritePin(STEP_B_GPIO_Port, STEP_B_Pin, GPIO_PIN_RESET);
					  HAL_GPIO_WritePin(STEP_Ab_GPIO_Port, STEP_Ab_Pin, GPIO_PIN_RESET);
					  HAL_GPIO_WritePin(STEP_Bb_GPIO_Port, STEP_Bb_Pin, GPIO_PIN_SET);
					  HAL_Delay(DELAY_TIME);

					  //0x04 = 0100
					  HAL_GPIO_WritePin(STEP_A_GPIO_Port, STEP_A_Pin, GPIO_PIN_RESET);
					  HAL_GPIO_WritePin(STEP_B_GPIO_Port, STEP_B_Pin, GPIO_PIN_RESET);
					  HAL_GPIO_WritePin(STEP_Ab_GPIO_Port, STEP_Ab_Pin, GPIO_PIN_SET);
					  HAL_GPIO_WritePin(STEP_Bb_GPIO_Port, STEP_Bb_Pin, GPIO_PIN_RESET);
					  HAL_Delay(DELAY_TIME);

					  //0x02 = 0010
					  HAL_GPIO_WritePin(STEP_A_GPIO_Port, STEP_A_Pin, GPIO_PIN_RESET);
					  HAL_GPIO_WritePin(STEP_B_GPIO_Port, STEP_B_Pin, GPIO_PIN_SET);
					  HAL_GPIO_WritePin(STEP_Ab_GPIO_Port, STEP_Ab_Pin, GPIO_PIN_RESET);
					  HAL_GPIO_WritePin(STEP_Bb_GPIO_Port, STEP_Bb_Pin, GPIO_PIN_RESET);
					  HAL_Delay(DELAY_TIME);

					  //0x01 = 0001
					  HAL_GPIO_WritePin(STEP_A_GPIO_Port, STEP_A_Pin, GPIO_PIN_SET);
					  HAL_GPIO_WritePin(STEP_B_GPIO_Port, STEP_B_Pin, GPIO_PIN_RESET);
					  HAL_GPIO_WritePin(STEP_Ab_GPIO_Port, STEP_Ab_Pin, GPIO_PIN_RESET);
					  HAL_GPIO_WritePin(STEP_Bb_GPIO_Port, STEP_Bb_Pin, GPIO_PIN_RESET);
					  HAL_Delay(DELAY_TIME);

}
void StepMotorOutput(byte_t byte)
{
	if( byte.bit.A) 	HAL_GPIO_WritePin(STEP_A_GPIO_Port, STEP_A_Pin, GPIO_PIN_SET);
	else 				HAL_GPIO_WritePin(STEP_A_GPIO_Port, STEP_A_Pin, GPIO_PIN_RESET);

	if( byte.bit.B) 	HAL_GPIO_WritePin(STEP_B_GPIO_Port, STEP_B_Pin, GPIO_PIN_SET);
	else 				HAL_GPIO_WritePin(STEP_B_GPIO_Port, STEP_B_Pin, GPIO_PIN_RESET);

	if( byte.bit.Ab) 	HAL_GPIO_WritePin(STEP_Ab_GPIO_Port, STEP_Ab_Pin, GPIO_PIN_SET);
	else 				HAL_GPIO_WritePin(STEP_Ab_GPIO_Port, STEP_Ab_Pin, GPIO_PIN_RESET);

	if( byte.bit.Bb) 	HAL_GPIO_WritePin(STEP_Bb_GPIO_Port, STEP_Bb_Pin, GPIO_PIN_SET);
	else 				HAL_GPIO_WritePin(STEP_Bb_GPIO_Port, STEP_Bb_Pin, GPIO_PIN_RESET);
}

#define STEP_PHASE_DRIVING 1

#if STEP_PHASE_DRIVING == 1
//WaveDrive
Step1PhaseDrive_t Step1PhaseDrive =
	{ 0, 4, {{1},  {2},  {4},  {8}} };
void StepPhaseDriving(direction_t direction)
{
//    PortData.bit16 = GPIOC->IDR;
    if( direction == STEP_CW){
    	Step1PhaseDrive.index++;
    	if( Step1PhaseDrive.index >= Step1PhaseDrive.MaxIndex ) Step1PhaseDrive.index =0;
    }

    if( direction == STEP_CCW){
    	Step1PhaseDrive.index--;
    	if( Step1PhaseDrive.index < 0 ) Step1PhaseDrive.index = Step1PhaseDrive.MaxIndex-1;
    }
    StepMotorOutput(Step1PhaseDrive.byte[Step1PhaseDrive.index]);
}

#elif STEP_PHASE_DRIVING == 2
//Full Step
Step1PhaseDrive_t Step2PhaseDrive =
	{ 0, 4, {{3},  {6},  {0xC},  {9}} };
void StepPhaseDriving(direction_t direction)
{
//    PortData.bit16 = GPIOC->IDR;
    if( direction == STEP_CW){
    	Step2PhaseDrive.index++;
    	if( Step2PhaseDrive.index >= Step2PhaseDrive.MaxIndex ) Step2PhaseDrive.index =0;
    }

    if( direction == STEP_CCW){
    	Step2PhaseDrive.index--;
    	if( Step2PhaseDrive.index < 0 ) Step2PhaseDrive.index = Step2PhaseDrive.MaxIndex-1;
    }
    StepMotorOutput(Step2PhaseDrive.byte[Step2PhaseDrive.index]);
}

#elif STEP_PHASE_DRIVING == 3
//HalfStep
Step12PhaseDrive_t Step12PhaseDrive =
	{ 0, 8, {{3},  {2},  {6},  {4}, {0xC},  {8},  {9},  {1} } };

void StepPhaseDriving(direction_t direction)
{
//    PortData.bit16 = GPIOC->IDR;
    if( direction == STEP_CW){
    	Step12PhaseDrive.index++;
    	if( Step12PhaseDrive.index >= Step12PhaseDrive.MaxIndex ) Step12PhaseDrive.index =0;
    }

    if( direction == STEP_CCW){
    	Step12PhaseDrive.index--;
    	if( Step12PhaseDrive.index < 0 ) Step12PhaseDrive.index = Step12PhaseDrive.MaxIndex-1;
    }
    StepMotorOutput(Step12PhaseDrive.byte[Step12PhaseDrive.index]);
}
#endif



