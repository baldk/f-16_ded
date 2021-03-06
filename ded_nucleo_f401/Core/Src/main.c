/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "dma.h"
#include "spi.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdio.h"
#include "string.h"
#include "ssd1322.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define DMA_RX_BUFFER_SIZE      512       // DMA_RX_BUFFER_SIZE must be smaller than COM_RX_BUFFER_SIZE and power of 2 !!!
#define COM_RX_BUFFER_SIZE      1024     	// COM_RX_BUFFER_SIZE must be larger than DMA_RX_BUFFER_SIZE and power of 2 !!!
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
uint8_t  volatile   DmaRxBuffer[DMA_RX_BUFFER_SIZE];
uint8_t  volatile   ComRxBuffer[COM_RX_BUFFER_SIZE];
uint16_t volatile   ComRxIn;
uint16_t            ComRxOut;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void UpdateDisplay(void);
void StartReceive(void);
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
  MX_DMA_Init();
  MX_USART2_UART_Init();
  MX_SPI3_Init();
  /* USER CODE BEGIN 2 */

  // Initialize OLED display
  SSD1322_Initialize();

  // Start receiving data from UART
  StartReceive();

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    UpdateDisplay();
    /* USER CODE END WHILE */

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
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void UpdateDisplay(void)
{
  uint16_t Length;
  uint16_t Buffer[120];

  if (ComRxIn == ComRxOut)
  {
    return;
  }
  else
  {
    if (ComRxIn > ComRxOut)
    {
      Length = ComRxIn - ComRxOut;
    }
    else
    {
      Length = (COM_RX_BUFFER_SIZE - ComRxOut) + ComRxIn;
    }
  }

  if (Length >= 240)
  {
    for (uint16_t i = 0; i < 120; i++)
    {
      Buffer[i]  = ComRxBuffer[ComRxOut];
      ComRxOut   = (ComRxOut + 1) % COM_RX_BUFFER_SIZE;
      Buffer[i] |= (ComRxBuffer[ComRxOut]<<8);
      ComRxOut   = (ComRxOut + 1) % COM_RX_BUFFER_SIZE;
    }

    for (uint16_t i = 0; i < 120; i++)
    {
      SSD1322_DrawUnicode(Buffer[i], 20 + ((i % 24) * 9), 0 + ((9 + 4) * (i / 24)), i < 66 ? 0 : 1);
    }

    SSD1322_Display();
  }
}


void StartReceive(void)
{
  if (&huart2 != NULL)
  {
    __HAL_UART_ENABLE_IT(&huart2, UART_IT_IDLE);            // Enable idle line interrupt
    __HAL_DMA_ENABLE_IT(huart2.hdmarx, DMA_IT_TC);        // Enable DMA RX complete interrupt

    HAL_UART_Receive_DMA(&huart2, (uint8_t*)(DmaRxBuffer), DMA_RX_BUFFER_SIZE);

#if defined (STM32F4)
    huart2.hdmarx->Instance->CR  &= ~DMA_SxCR_HTIE;       // Disable UART half TX interrupt
#elif defined(STM32F1)
//    huart2->hdmarx->Instance->CCR &= ~DMA_CCR_HTIE;        // Disable UART half TX interrupt
#else
    #error "Specific STM32 has not been defined"
#endif

    // Reset buffer pointers
    ComRxIn  = 0;
    ComRxOut = ComRxIn;
  }
}


void USART_IrqHandler(UART_HandleTypeDef *huart, DMA_HandleTypeDef *hdma)
{
  uint16_t StatusRegister = huart->Instance->SR;

//  if (huart->Instance->SR & UART_FLAG_IDLE)           /* if Idle flag is set */
  if (StatusRegister & UART_FLAG_IDLE)                /* if Idle flag is set */
  {
    uint32_t volatile tmp;                            /* Must be volatile to prevent optimizations */
    tmp = huart->Instance->SR;                        /* Read status register */
    tmp = huart->Instance->DR;                        /* Read data register */

#if defined (STM32F4)
    hdma->Instance->CR  &= ~DMA_SxCR_EN;              /* Disabling DMA will force transfer complete interrupt if enabled */
#elif defined (STM32F1)
    hdma->Instance->CCR &= ~DMA_CCR_EN;               /* Disabling DMA will force transfer complete interrupt if enabled */

//    if (huart->Instance->SR & (UART_FLAG_ORE | UART_FLAG_NE | UART_FLAG_FE | UART_FLAG_PE))
    if (StatusRegister & (UART_FLAG_ORE | UART_FLAG_NE | UART_FLAG_FE | UART_FLAG_PE))
    {
      DMA_TypeDef* regs = hdma->DmaBaseAddress;

      /* Important! DMA stream won't start if all flags are not cleared first */
      regs->IFCR = 0x3FU << hdma->ChannelIndex;           /* Clear all interrupts */
      hdma->Instance->CMAR   = (uint32_t)(DmaRxBuffer);   /* Set memory address for DMA again */
      hdma->Instance->CNDTR  = DMA_RX_BUFFER_SIZE;        /* Set number of bytes to receive */
      hdma->Instance->CCR   |= DMA_CCR_EN;                /* Start DMA transfer */
    }
    else
    {
      DMA_IrqHandler(hdma);
    }
#else
    #error "Specific STM32 has not been defined"
#endif
  }
  else
  {
    HAL_UART_IRQHandler(huart);
  }
}


void DMA_IrqHandler(DMA_HandleTypeDef *hdma)
{
  uint16_t len;
  uint16_t tocopy;
  uint8_t* ptr;

#if defined (STM32F4)
  typedef struct
  {
    __IO uint32_t ISR;   /*!< DMA interrupt status register */
    __IO uint32_t Reserved0;
    __IO uint32_t IFCR;  /*!< DMA interrupt flag clear register */
  } DMA_Base_Registers;

  DMA_Base_Registers *regs = (DMA_Base_Registers *)(hdma->StreamBaseAddress);
#elif defined (STM32F1)
  DMA_TypeDef* regs = hdma->DmaBaseAddress;
#else
  #error "Specific STM32 has not been defined"
#endif

  if (__HAL_DMA_GET_IT_SOURCE(hdma, DMA_IT_TC) != RESET)   // if the source is TC
  {
#if defined (STM32F4)
    /* Clear the transfer complete flag */
    regs->IFCR = DMA_FLAG_TCIF1_5 << hdma->StreamIndex;

    /* Get the length of the data */
    len = DMA_RX_BUFFER_SIZE - hdma->Instance->NDTR;
#elif defined(STM32F1)
    /* Clear the transfer complete flag */
    regs->IFCR = DMA_FLAG_TC1 << hdma->ChannelIndex;
    //regs->IFCR = DMA_FLAG_GL1 << hdma->ChannelIndex;
    //((DMA_TypeDef*)(hdma->DmaBaseAddress))->IFCR = DMA_FLAG_TC1 << hdma->ChannelIndex;// regs->IFCR = DMA_FLAG_TC1 << hdma->ChannelIndex;

    /* Get the length of the data */
    len = DMA_RX_BUFFER_SIZE - hdma->Instance->CNDTR;
#else
    #error "Specific STM32 has not been defined"
#endif

#if 1
    if (len > 0)
    {
      tocopy = 0;
    }

    /* Get number of bytes we can copy to the end of buffer */
    tocopy = COM_RX_BUFFER_SIZE - ComRxIn;

    /* Check how many bytes to copy */
    if (tocopy > len)
    {
      tocopy = len;
    }

    /* Write received data for UART main buffer for manipulation later */
    ptr = (uint8_t*)(DmaRxBuffer);

    memcpy((void*)(&ComRxBuffer[ComRxIn]), ptr, tocopy);   /* Copy first part */

    /* Correct values for remaining data */
    ComRxIn += tocopy;
    len -= tocopy;
    ptr += tocopy;

    /* UNCOMMENT BELOW TO transmit the data via uart */
//    HAL_UART_Transmit(&huart2, &UART_Buffer[Write-tocopy], tocopy, 10);

    /* If still data to write for beginning of buffer */
    if (len)
    {
      memcpy((void*)&ComRxBuffer[0], ptr, len);          /* Don't care if we override Read pointer now */
      ComRxIn = len;

      /* UNCOMMENT BELOW TO transmit the data via uart */
//      HAL_UART_Transmit(&huart2, UART_Buffer, len, 10);  // transmit the remaining data
    }
#else
    cUsb_Write((uint8_t*)(DmaRxBuffer), DMA_RX_BUFFER_SIZE - hdma->Instance->CNDTR, 0);
#endif

    ComRxIn %= COM_RX_BUFFER_SIZE;

    /* Prepare DMA for next transfer */
#if defined (STM32F4)
    /* Important! DMA stream won't start if all flags are not cleared first */
    regs->IFCR = 0x3FU << hdma->StreamIndex;            /* Clear all interrupts */
    hdma->Instance->M0AR   = (uint32_t)DmaRxBuffer;     /* Set memory address for DMA again */
    hdma->Instance->NDTR   = DMA_RX_BUFFER_SIZE;        /* Set number of bytes to receive */
    hdma->Instance->CR    |= DMA_SxCR_EN;               /* Start DMA transfer */
#elif defined (STM32F1)
    /* Important! DMA stream won't start if all flags are not cleared first */
    regs->IFCR = 0x3FU << hdma->ChannelIndex;           /* Clear all interrupts */
    hdma->Instance->CMAR   = (uint32_t)(DmaRxBuffer);   /* Set memory address for DMA again */
    hdma->Instance->CNDTR  = DMA_RX_BUFFER_SIZE;        /* Set number of bytes to receive */
    hdma->Instance->CCR   |= DMA_CCR_EN;                /* Start DMA transfer */
#else
    #error "Specific STM32 has not been defined"
#endif
  }
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
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
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
