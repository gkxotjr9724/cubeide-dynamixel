/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define MOTOR_EN1_Pin GPIO_PIN_2
#define MOTOR_EN1_GPIO_Port GPIOE
#define MOTOR_EN2_Pin GPIO_PIN_3
#define MOTOR_EN2_GPIO_Port GPIOE
#define USER_Pin GPIO_PIN_0
#define USER_GPIO_Port GPIOA
#define STEP_Bb_Pin GPIO_PIN_5
#define STEP_Bb_GPIO_Port GPIOA
#define STEP_B_Pin GPIO_PIN_6
#define STEP_B_GPIO_Port GPIOA
#define STEP_A_Pin GPIO_PIN_11
#define STEP_A_GPIO_Port GPIOE
#define STEP_Ab_Pin GPIO_PIN_13
#define STEP_Ab_GPIO_Port GPIOE
#define CONV_DIR_Pin GPIO_PIN_13
#define CONV_DIR_GPIO_Port GPIOB
#define CONV_EN_Pin GPIO_PIN_15
#define CONV_EN_GPIO_Port GPIOB
#define LD3_Pin GPIO_PIN_13
#define LD3_GPIO_Port GPIOG
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
