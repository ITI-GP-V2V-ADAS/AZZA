/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "nrf24l01p.h"
#include <string.h>
#include <stdio.h>

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart6;
extern SPI_HandleTypeDef hspi2;
extern TIM_HandleTypeDef htim2;

#define NRF24L01P_PAYLOAD_LENGTH		2     // 1 - 32bytes nfsha in nrf.h
#define DUTY_CYCLE						0
#define NEXT_MOVE						1
extern uint8_t rxNRF[NRF24L01P_PAYLOAD_LENGTH];

extern uint8_t rxBlue;

#define DISPLAY_ELEMENTS	7
#define DISPLAY_STRING		20

#define ZOZZA_SPEED			0
#define ZOZZA_NEXT_MOVE		1
#define AZZA_SPEED			2
#define AZZA_NEXT_MOVE		3

#define BLIND				4
#define FRONT				5
#define BACK				6
#define TERMINATOR			7

#define NOTHING				0
#define LEFT				1
#define RIGHT				2
#define YELLOW				1
#define RED					2
extern uint8_t txDisplay[DISPLAY_ELEMENTS];
extern uint8_t txDisplayStr[DISPLAY_STRING];
/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED_Pin GPIO_PIN_13
#define LED_GPIO_Port GPIOC
#define MOTOR_4_Pin GPIO_PIN_6
#define MOTOR_4_GPIO_Port GPIOA
#define MOTOR_3_Pin GPIO_PIN_7
#define MOTOR_3_GPIO_Port GPIOA
#define MOTOR_2_Pin GPIO_PIN_0
#define MOTOR_2_GPIO_Port GPIOB
#define MOTOR_1_Pin GPIO_PIN_1
#define MOTOR_1_GPIO_Port GPIOB
#define CE_Pin GPIO_PIN_12
#define CE_GPIO_Port GPIOB
#define SPI2_CSN_Pin GPIO_PIN_13
#define SPI2_CSN_GPIO_Port GPIOB
#define IRQ_Pin GPIO_PIN_9
#define IRQ_GPIO_Port GPIOB
#define IRQ_EXTI_IRQn EXTI9_5_IRQn

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
