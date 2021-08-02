/***********************************
 * StepMotor.c
 *
 *  Created on: Dec 13, 2020
 *      Author: yhyee
 *  Please keep this area
 **********************************/

typedef enum{
  STEP_CW = 0,
  STEP_CCW =1
} direction_t;

typedef union {
    uint8_t nibble;
    struct {
      uint8_t A  :1;//lsb
      uint8_t B  :1;
      uint8_t Ab :1;
      uint8_t Bb :1; //msb
    } bit;
} byte_t;

typedef  struct{
   int16_t index;
   int16_t MaxIndex;
   byte_t byte[4];
} Step1PhaseDrive_t;//1��, 2�� 援щ��

typedef  struct{
   int16_t index;
   int16_t MaxIndex;
   byte_t byte[8];
} Step12PhaseDrive_t;
void StepMotorClockwise();
void StepMotorCounterClockwise();
void StepMotorOutput(byte_t byte);
void StepPhaseDriving(direction_t direction);
void StepMotorUnipolarPhase(direction_t direction);
void StepMotorBipolarPhase(direction_t direction);

