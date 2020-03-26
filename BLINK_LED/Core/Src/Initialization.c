/*
 * Initialization.c
 *
 *  Created on: Mar 13, 2020
 *      Author: Job Heijlighen
 */
#include "Main.h"
#include "Initialization.h"
#include "Error.h"


 void MX_TIM1_Init(void)
{

  /* USER CODE BEGIN TIM1_Init 0 */

  /* USER CODE END TIM1_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};
  TIM_BreakDeadTimeConfigTypeDef sBreakDeadTimeConfig = {0};

  /* USER CODE BEGIN TIM1_Init 1 */

  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 0;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 65535;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCNPolarity = TIM_OCNPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
  sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
  if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_4) != HAL_OK)
  {
    Error_Handler();
  }
  sBreakDeadTimeConfig.OffStateRunMode = TIM_OSSR_DISABLE;
  sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_DISABLE;
  sBreakDeadTimeConfig.LockLevel = TIM_LOCKLEVEL_OFF;
  sBreakDeadTimeConfig.DeadTime = 0;
  sBreakDeadTimeConfig.BreakState = TIM_BREAK_DISABLE;
  sBreakDeadTimeConfig.BreakPolarity = TIM_BREAKPOLARITY_HIGH;
  sBreakDeadTimeConfig.AutomaticOutput = TIM_AUTOMATICOUTPUT_DISABLE;
  if (HAL_TIMEx_ConfigBreakDeadTime(&htim1, &sBreakDeadTimeConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */

  /* USER CODE END TIM1_Init 2 */
  HAL_TIM_MspPostInit(&htim1);

}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
 void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 0;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 0;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_PWM_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */
  HAL_TIM_MspPostInit(&htim2);

}
 void MX_ADC1_Init(void)
 {

   /* USER CODE BEGIN ADC1_Init 0 */

   /* USER CODE END ADC1_Init 0 */

   ADC_ChannelConfTypeDef sConfig = {0};

   /* USER CODE BEGIN ADC1_Init 1 */

   /* USER CODE END ADC1_Init 1 */
   /** Common config
   */
   hadc1.Instance = ADC1;
   hadc1.Init.ScanConvMode = ADC_SCAN_ENABLE;
   hadc1.Init.ContinuousConvMode = ENABLE;
   hadc1.Init.DiscontinuousConvMode = DISABLE;
   hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
   hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
   hadc1.Init.NbrOfConversion = 7;
   if (HAL_ADC_Init(&hadc1) != HAL_OK)
   {
     Error_Handler();
   }
   /** Configure Regular Channel
   */
   sConfig.Channel = ADC_CHANNEL_0;
   sConfig.Rank = ADC_REGULAR_RANK_1;
   sConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
   if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
   {
     Error_Handler();
   }
   /** Configure Regular Channel
   */
   sConfig.Channel = ADC_CHANNEL_1;
   sConfig.Rank = ADC_REGULAR_RANK_2;
   if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
   {
     Error_Handler();
   }
   /** Configure Regular Channel
   */
   sConfig.Channel = ADC_CHANNEL_4;
   sConfig.Rank = ADC_REGULAR_RANK_3;
   sConfig.SamplingTime = ADC_SAMPLETIME_239CYCLES_5;
   if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
   {
     Error_Handler();
   }
   /** Configure Regular Channel
   */
   sConfig.Channel = ADC_CHANNEL_5;
   sConfig.Rank = ADC_REGULAR_RANK_4;
   sConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
   if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
   {
     Error_Handler();
   }
   /** Configure Regular Channel
   */
   sConfig.Channel = ADC_CHANNEL_6;
   sConfig.Rank = ADC_REGULAR_RANK_5;
   if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
   {
     Error_Handler();
   }
   /** Configure Regular Channel
   */
   sConfig.Channel = ADC_CHANNEL_7;
   sConfig.Rank = ADC_REGULAR_RANK_6;
   if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
   {
     Error_Handler();
   }
   /** Configure Regular Channel
   */
   sConfig.Channel = ADC_CHANNEL_8;
   sConfig.Rank = ADC_REGULAR_RANK_7;
   if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
   {
     Error_Handler();
   }
   /* USER CODE BEGIN ADC1_Init 2 */

   /* USER CODE END ADC1_Init 2 */

 }

 /**
   * @brief I2C1 Initialization Function
   * @param None
   * @retval None
   * */
  void MX_I2C1_Init(void)
 {

   /* USER CODE BEGIN I2C1_Init 0 */

   /* USER CODE END I2C1_Init 0 */

   /* USER CODE BEGIN I2C1_Init 1 */

   /* USER CODE END I2C1_Init 1 */
   hi2c1.Instance = I2C1;
   hi2c1.Init.ClockSpeed = 100000;
   hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
   hi2c1.Init.OwnAddress1 = 0;
   hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
   hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
   hi2c1.Init.OwnAddress2 = 0;
   hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
   hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
   if (HAL_I2C_Init(&hi2c1) != HAL_OK)
   {
     Error_Handler();
   }
   /* USER CODE BEGIN I2C1_Init 2 */

   /* USER CODE END I2C1_Init 2 */

 }

 /**
   * @brief I2C2 Initialization Function
   * @param None
   * @retval None
   */
  void MX_I2C2_Init(void)
 {

   /* USER CODE BEGIN I2C2_Init 0 */

   /* USER CODE END I2C2_Init 0 */

   /* USER CODE BEGIN I2C2_Init 1 */

   /* USER CODE END I2C2_Init 1 */
   hi2c2.Instance = I2C2;
   hi2c2.Init.ClockSpeed = 100000;
   hi2c2.Init.DutyCycle = I2C_DUTYCYCLE_2;
   hi2c2.Init.OwnAddress1 = 0;
   hi2c2.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
   hi2c2.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
   hi2c2.Init.OwnAddress2 = 0;
   hi2c2.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
   hi2c2.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
   if (HAL_I2C_Init(&hi2c2) != HAL_OK)
   {
     Error_Handler();
   }
   /* USER CODE BEGIN I2C2_Init 2 */

   /* USER CODE END I2C2_Init 2 */

 }

 /**
   * @brief RTC Initialization Function
   * @param None
   * @retval None
   */

   void MX_USART2_UART_Init(void)
  {

    /* USER CODE BEGIN USART2_Init 0 */

    /* USER CODE END USART2_Init 0 */

    /* USER CODE BEGIN USART2_Init 1 */

    /* USER CODE END USART2_Init 1 */
    huart2.Instance = USART2;
    huart2.Init.BaudRate = 115200;
    huart2.Init.WordLength = UART_WORDLENGTH_8B;
    huart2.Init.StopBits = UART_STOPBITS_1;
    huart2.Init.Parity = UART_PARITY_NONE;
    huart2.Init.Mode = UART_MODE_TX_RX;
    huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart2.Init.OverSampling = UART_OVERSAMPLING_16;

    if (HAL_UART_Init(&huart2) != HAL_OK)
    {
      Error_Handler();
    }
    /* USER CODE BEGIN USART2_Init 2 */

    /* USER CODE END USART2_Init 2 */

  }

  /**
    * @brief GPIO Initialization Function
    * @param None
    * @retval None
    */

  void MX_RTC_Init(void)
 {

   /* USER CODE BEGIN RTC_Init 0 */

   /* USER CODE END RTC_Init 0 */

   /* USER CODE BEGIN RTC_Init 1 */

   /* USER CODE END RTC_Init 1 */
   /** Initialize RTC Only
   */
   hrtc.Instance = RTC;
   hrtc.Init.AsynchPrediv = RTC_AUTO_1_SECOND;
   hrtc.Init.OutPut = RTC_OUTPUTSOURCE_ALARM;
   if (HAL_RTC_Init(&hrtc) != HAL_OK)
   {
     Error_Handler();
   }
   /* USER CODE BEGIN RTC_Init 2 */

   /* USER CODE END RTC_Init 2 */

 }

 /**
   * @brief TIM1 Initialization Function
   * @param None
   * @retval None
   */


 /**
   * @brief GPIO Initialization Function
   * @param None
   * @retval None
   */
  void MX_GPIO_Init(void)
 {
   GPIO_InitTypeDef GPIO_InitStruct = {0};

   /* GPIO Ports Clock Enable */
   __HAL_RCC_GPIOC_CLK_ENABLE();
   __HAL_RCC_GPIOD_CLK_ENABLE();
   __HAL_RCC_GPIOA_CLK_ENABLE();
   __HAL_RCC_GPIOB_CLK_ENABLE();

   /*Configure GPIO pin Output Level */
   HAL_GPIO_WritePin(GPIOB, Output_9_Pin|Output_8_Pin|Output_7_Pin|Output_6_Pin
                           |Output_4_Pin|Output_3_Pin|Output_2_Pin|Output_1_Pin, GPIO_PIN_RESET);

   /*Configure GPIO pin Output Level */
   HAL_GPIO_WritePin(Output_5_GPIO_Port, Output_5_Pin, GPIO_PIN_RESET);

   /*Configure GPIO pin : Input_0_Pin */
   GPIO_InitStruct.Pin = Input_0_Pin;
   GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
   GPIO_InitStruct.Pull = GPIO_NOPULL;
   HAL_GPIO_Init(Input_0_GPIO_Port, &GPIO_InitStruct);

   /*Configure GPIO pins : Input_3_Pin Input_4_Pin */
   GPIO_InitStruct.Pin = Input_3_Pin|Input_4_Pin;
   GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
   GPIO_InitStruct.Pull = GPIO_NOPULL;
   HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

   /*Configure GPIO pins : Output_9_Pin Output_8_Pin Output_7_Pin Output_6_Pin
                            Output_4_Pin Output_3_Pin Output_2_Pin Output_1_Pin */
   GPIO_InitStruct.Pin = Output_9_Pin|Output_8_Pin|Output_7_Pin|Output_6_Pin
                           |Output_4_Pin|Output_3_Pin|Output_2_Pin|Output_1_Pin;
   GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
   GPIO_InitStruct.Pull = GPIO_NOPULL;
   GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
   HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

   /*Configure GPIO pin : Output_5_Pin */
   GPIO_InitStruct.Pin = Output_5_Pin;
   GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
   GPIO_InitStruct.Pull = GPIO_NOPULL;
   GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
   HAL_GPIO_Init(Output_5_GPIO_Port, &GPIO_InitStruct);

 }

  void MX_DMA_Init(void)
  {

    /* DMA controller clock enable */
    __HAL_RCC_DMA1_CLK_ENABLE();

    /* DMA interrupt init */
    /* DMA1_Channel1_IRQn interrupt configuration */
    HAL_NVIC_SetPriority(DMA1_Channel1_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(DMA1_Channel1_IRQn);

  }

 /* USER CODE BEGIN 4 */

 /* USER CODE END 4 */


 /**
   * @brief  This function is executed in case of error occurrence.
   * @retval None
   */
