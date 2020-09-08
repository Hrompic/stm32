///Hrompic 2020
/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "usb_device.h"

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
I2C_HandleTypeDef hi2c1;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
static void myTest();
static void testCir();
static void testCirb();
static void testRect1();
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C1_Init();
  MX_USB_DEVICE_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
	  myTest();
	 // ssd1306_TestAll();
	  HAL_Delay(1000);
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 15;
  RCC_OscInitStruct.PLL.PLLN = 144;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 5;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000*4;
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
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

}

/* USER CODE BEGIN 4 */
void myTest()
{
	ssd1306_Init();
	ssd1306_Fill(Black);
	ssd1306_WriteString("$Vasiliu$", Font_16x26, White);
	char str[] ="My name is Vasiliu pupkin, I live in Ukraine!!! ";
	char str2[] ="Peter Martyr Vermigli (8 September 1499 - 12 November 1562) was an Italian theologian.  ";
	for(int i=0; i<sizeof(str); i++)
	{
		ssd1306_SetCursor(2, 30);
		ssd1306_WriteString(str+i, Font_11x18, White);
		ssd1306_UpdateScreen();
		HAL_Delay(40);

		ssd1306_SetCursor(2, 52);
		ssd1306_WriteString(str2+(uint8_t)(1.5*i), Font_7x10, White);
		ssd1306_UpdateScreen();

	}
	HAL_Delay(500);
	ssd1306_Fill(Black);
//	ssd1306_WriteString("Тестовая версия русского шрифта", Font_5x7, White);
//	ssd1306_UpdateScreen();
//	HAL_Delay(3000);
	for(int i=0; i<20; i++)
	{
		ssd1306_DrawRectangle(0+i, 0+i, 50+i, 50+i, White);
		ssd1306_UpdateScreen();
	}
	for(int i=0; i<20; i++)
	{
		ssd1306_DrawRectangle(0+i, 0+i, 50+i, 50+i, Black);
		ssd1306_UpdateScreen();
	}
	for(int i=0; i<40; i++)
	{
		ssd1306_DrawRectangle(40+i, 20+i, 90-i, 40-i, White);
		ssd1306_UpdateScreen();
	}
	for(int i=0; i<40; i++)
	{
		ssd1306_DrawRectangle(40+i, 20+i, 90-i, 40-i, Black);
		ssd1306_UpdateScreen();
	}
	ssd1306_TestRectangle();
	testRect1();

	testCir();
	testCirb();
}
/* USER CODE END 4 */
void testCir()
{
	for(int delta = 0; delta < 40; delta ++)
	{
		ssd1306_DrawCircle(SSD1306_WIDTH/2, SSD1306_HEIGHT/2, delta*2, White);
		ssd1306_UpdateScreen();
	}
	for(int delta = 0; delta < 40; delta ++)
	{
		ssd1306_DrawCircle(SSD1306_WIDTH/2, SSD1306_HEIGHT/2, delta*2, Black);
		ssd1306_UpdateScreen();
	}

}
void testCirb()
{
	for(int delta=40; delta>0; delta--)
	{
		ssd1306_DrawCircle(SSD1306_WIDTH/2, SSD1306_HEIGHT/2, delta*2, White);
		ssd1306_UpdateScreen();
	}
	for(int delta=40; delta>0; delta--)
	{
		ssd1306_DrawCircle(SSD1306_WIDTH/2, SSD1306_HEIGHT/2, delta*2, Black);
		ssd1306_UpdateScreen();
	}

}
void testRect1()
{
  int i;

  for(i=7; i>=0; i--)
  {
    ssd1306_DrawRectangle(1 + (5*i),1 + (5*i) ,SSD1306_WIDTH-1 - (5*i),SSD1306_HEIGHT-1 - (5*i),White);
    ssd1306_UpdateScreen();
    HAL_Delay(75);
  }
	{
		  HAL_Delay(50);
		  ssd1306_Line(1,1,SSD1306_WIDTH - 1,SSD1306_HEIGHT - 1,Black);
		  ssd1306_UpdateScreen();
		  ssd1306_Line(SSD1306_WIDTH - 1,1,1,SSD1306_HEIGHT - 1,Black);
		  ssd1306_UpdateScreen();
	}
  for(i=7; i>=0; i--)
  {
	  ssd1306_DrawRectangle(1 + (5*i),1 + (5*i) ,SSD1306_WIDTH-1 - (5*i),SSD1306_HEIGHT-1 - (5*i),Black);
	  ssd1306_UpdateScreen();
	  HAL_Delay(75);
  }
  ssd1306_UpdateScreen();
}
/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
