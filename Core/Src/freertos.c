/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
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

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for CTRLt */
osThreadId_t CTRLtHandle;
const osThreadAttr_t CTRLt_attributes = {
  .name = "CTRLt",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityHigh,
};
/* Definitions for SPEEDt */
osThreadId_t SPEEDtHandle;
const osThreadAttr_t SPEEDt_attributes = {
  .name = "SPEEDt",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime,
};
/* Definitions for Dashboardt */
osThreadId_t DashboardtHandle;
const osThreadAttr_t Dashboardt_attributes = {
  .name = "Dashboardt",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityHigh1,
};
/* Definitions for CANt */
osThreadId_t CANtHandle;
const osThreadAttr_t CANt_attributes = {
  .name = "CANt",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime,
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);
void CTRL(void *argument);
void SPEED(void *argument);
void Dashboard(void *argument);
void CAN(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* creation of CTRLt */
  CTRLtHandle = osThreadNew(CTRL, NULL, &CTRLt_attributes);

  /* creation of SPEEDt */
  SPEEDtHandle = osThreadNew(SPEED, NULL, &SPEEDt_attributes);

  /* creation of Dashboardt */
  DashboardtHandle = osThreadNew(Dashboard, NULL, &Dashboardt_attributes);

  /* creation of CANt */
  CANtHandle = osThreadNew(CAN, NULL, &CANt_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_CTRL */
/**
* @brief Function implementing the CTRLt thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_CTRL */
void CTRL(void *argument)
{
  /* USER CODE BEGIN CTRL */
  /* Infinite loop */
  for(;;){
  switch (rxBlue) {

  case 70:	//forward 'F'
  case 102:	//forward 'f'
    HAL_GPIO_WritePin(MOTOR_1_GPIO_Port, MOTOR_1_Pin, 1);
    HAL_GPIO_WritePin(MOTOR_2_GPIO_Port, MOTOR_2_Pin, 0);
    HAL_GPIO_WritePin(MOTOR_3_GPIO_Port, MOTOR_3_Pin, 1);
    HAL_GPIO_WritePin(MOTOR_4_GPIO_Port, MOTOR_4_Pin, 0);
    break;

  case 82:	//right 'R'
  //case 114:	//right 'r'
    HAL_GPIO_WritePin(MOTOR_1_GPIO_Port, MOTOR_1_Pin, 0);
    HAL_GPIO_WritePin(MOTOR_2_GPIO_Port, MOTOR_2_Pin, 1);
    HAL_GPIO_WritePin(MOTOR_3_GPIO_Port, MOTOR_3_Pin, 1);
    HAL_GPIO_WritePin(MOTOR_4_GPIO_Port, MOTOR_4_Pin, 0);
    break;

  case 76:	//left 'L'
  //case 108:	//left 'l'
    HAL_GPIO_WritePin(MOTOR_1_GPIO_Port, MOTOR_1_Pin, 1);
    HAL_GPIO_WritePin(MOTOR_2_GPIO_Port, MOTOR_2_Pin, 0);
        HAL_GPIO_WritePin(MOTOR_3_GPIO_Port, MOTOR_3_Pin, 0);
        HAL_GPIO_WritePin(MOTOR_4_GPIO_Port, MOTOR_4_Pin, 1);
    break;

  case 71:	//back 'G'
  case 103:	//back 'g'
    HAL_GPIO_WritePin(MOTOR_1_GPIO_Port, MOTOR_1_Pin, 0);
        HAL_GPIO_WritePin(MOTOR_2_GPIO_Port, MOTOR_2_Pin, 1);
        HAL_GPIO_WritePin(MOTOR_3_GPIO_Port, MOTOR_3_Pin, 0);
        HAL_GPIO_WritePin(MOTOR_4_GPIO_Port, MOTOR_4_Pin, 1);
    break;

  case 88:	//stop 'X'
        HAL_GPIO_WritePin(MOTOR_1_GPIO_Port, MOTOR_1_Pin, 0);
        HAL_GPIO_WritePin(MOTOR_2_GPIO_Port, MOTOR_2_Pin, 0);
        HAL_GPIO_WritePin(MOTOR_3_GPIO_Port, MOTOR_3_Pin, 0);
        HAL_GPIO_WritePin(MOTOR_4_GPIO_Port, MOTOR_4_Pin, 0);
    break;

  default:
    break;

  }
	osDelay(1);
	}
  /* USER CODE END CTRL */
}

/* USER CODE BEGIN Header_SPEED */
/**
* @brief Function implementing the SPEEDt thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_SPEED */
void SPEED(void *argument)
{
  /* USER CODE BEGIN SPEED */
  /* Infinite loop */
  for(;;)
  {
    if (rxBlue=='X') {
      __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 0);
      __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, 0);
      txDisplay[AZZA_SPEED] = 0;
  }else if (rxBlue=='F'||rxBlue=='G'||rxBlue=='L'||rxBlue=='R'){
      __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 900);
      __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, 900);
      txDisplay[AZZA_SPEED] = 9;
  }else if (rxBlue=='f'||rxBlue=='g'||rxBlue=='l'||rxBlue=='r'){
      __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 400);
      __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, 400);
      txDisplay[AZZA_SPEED] = 4;
  }
    osDelay(1);
  }

  /* USER CODE END SPEED */
}

/* USER CODE BEGIN Header_Dashboard */
/**
* @brief Function implementing the Dashboardt thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Dashboard */
void Dashboard(void *argument)
{
  /* USER CODE BEGIN Dashboard */
  /* Infinite loop */
  for(;;)
  {
	  sprintf((char *)txDisplayStr, "%d,%d,%d,%d,%d,%d,%d,\\n",
			  txDisplay[ZOZZA_SPEED], txDisplay[ZOZZA_NEXT_MOVE], txDisplay[AZZA_SPEED], txDisplay[AZZA_NEXT_MOVE],
			  txDisplay[BLIND], txDisplay[FRONT], txDisplay[BACK]);
	  HAL_UART_Transmit(&huart6, (uint8_t *)txDisplayStr, sizeof(txDisplayStr), HAL_MAX_DELAY);
	  osDelay(1000);
  }
  /* USER CODE END Dashboard */
}

/* USER CODE BEGIN Header_CAN */
/**
* @brief Function implementing the CANt thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_CAN */
void CAN(void *argument)
{
  /* USER CODE BEGIN CAN */
  /* Infinite loop */
  for(;;)
  {
	  if(CANSPI_Receive(&rxCAN)){
		  if(rxCAN.frame.id == 0x0A){
			  if(rxCAN.frame.data0 == 1){
				  HAL_GPIO_WritePin(CAN_LED_GPIO_Port, CAN_LED_Pin, GPIO_PIN_SET);
			  }else{
				  HAL_GPIO_WritePin(CAN_LED_GPIO_Port, CAN_LED_Pin, GPIO_PIN_RESET);
			  }
		  }
	}
    osDelay(300);
  }
  /* USER CODE END CAN */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

