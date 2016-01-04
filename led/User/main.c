/**
  ******************************************************************************
  * @file    Project/STM32F10x_StdPeriph_Template/main.c 
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */  

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"

#include <stdio.h>

#define CLOCK 72/8 //时钟=72M

/** @addtogroup STM32F10x_StdPeriph_Template
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/



/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
GPIO_InitTypeDef GPIO_InitStructure;


/* Private function prototypes -----------------------------------------------*/

/* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
   set to 'Yes') calls __io_putchar() */


/* Private functions ---------------------------------------------------------*/

/*------------------------------------------------------------
                         us延时函数 
------------------------------------------------------------*/
void delay_us(unsigned int us)
{
	u8 n;		    
	while(us--)for(n=0;n<CLOCK;n++); 	 
}

/*------------------------------------------------------------
                         ms延时函数
------------------------------------------------------------*/
void delay_ms(unsigned int ms)
{
	while(ms--)delay_us(1000);	 
}


/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
  /*!< At this stage the microcontroller clock setting is already configured, 
       this is done through SystemInit() function which is called from startup
       file (startup_stm32f10x_xx.s) before to branch to application main.
       To reconfigure the default setting of SystemInit() function, refer to
       system_stm32f10x.c file
     */     

  /* Initialize LEDs, Key Button, LCD and COM port(USART) available on
     STM3210X-EVAL board ******************************************************/
 
  /* GPIOB Periph clock enable */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

  /* Configure PD8 in output pushpull mode */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(GPIOB, &GPIO_InitStructure);



  /* USARTx configured as follow:
        - BaudRate = 115200 baud  
        - Word Length = 8 Bits
        - One Stop Bit
        - No parity
        - Hardware flow control disabled (RTS and CTS signals)
        - Receive and transmit enabled
  */

 

  /* Initialize the LCD */



  /* Display message on STM3210X-EVAL LCD *************************************/
  /* Clear the LCD */ 


  /* Set the LCD Back Color */

  /* Set the LCD Text Color */
 

  /* Retarget the C library printf function to the USARTx, can be USART1 or USART2
     depending on the EVAL board you are using ********************************/



  /* Turn on leds available on STM3210X-EVAL **********************************/


  /* Add your application code here
     */

  /* Infinite loop */
  while (1)
  {
  	delay_ms(50);
	     	 
//	GPIOB->ODR=0;	  		 //全部输出0
//	GPIOA->ODR=0;		
//	GPIOC->ODR=0;
//	GPIOB->BSRR=0X01000000;	 //PB8置0

//	GPIOB->BRR=0X0100;	 //PB8置0	

//	GPIO_ResetBits(GPIOB, GPIO_Pin_8); //PB8置0	

//	GPIO_WriteBit(GPIOB, GPIO_Pin_8, Bit_RESET);   //PB8置0
	GPIO_Write(GPIOB,0x0000) ;	   //PB8置0
		
	delay_ms(50);
	
//	GPIOB->ODR=0xffffffff;	 //全部输出1 
//	GPIOA->ODR=0xffffffff;	  
//	GPIOC->ODR=0xffffffff;
//	GPIOB->BSRR=0X0100;	 ////PB8置1

//	GPIO_SetBits(GPIOB, GPIO_Pin_8); //PB8置1

//	GPIO_WriteBit(GPIOB, GPIO_Pin_8, Bit_SET);	 //PB8置1
	GPIO_Write(GPIOB,0x0100) ;	 //PB8置1
  }
}

/**
  * @brief  Retargets the C library printf function to the USART.
  * @param  None
  * @retval None
  */



/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */

/**
  * @}
  */


/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
