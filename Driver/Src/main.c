#include "stm32f407xx.h"


static void LedConfig();
static void GPIO_ButtonInterruptConfig();
static void SPI_Config();
static void SPI_GPIO_Config();

SPI_HandleTypeDef_t SPI_Handle;





void EXTI0_IRQHandler(){

	char msgToSend[] = "Hello Are You There ! \n";

	if(EXTI->PR & 0x1){

		EXTI->PR |= (0x1 << 0U);

		SPI_TransmitData_IT(&SPI_Handle, (uint8_t*)msgToSend, strlen(msgToSend));


	}

}

void SPI1_IRQHandler(){

SPI_InterruptHandler(&SPI_Handle);




}
int main(void)
{

	LedConfig();

	GPIO_ButtonInterruptConfig();

	SPI_GPIO_Config();

	SPI_Config();



	for(;;)
	{


	}
}


static void LedConfig(){

	GPIO_InitTypedef_t GPIO_LedStruct= { 0 };

	RCC_GPIOD_CLK_ENABLE();
	RCC_GPIOA_CLK_ENABLE();



	    GPIO_LedStruct.pinNumber = GPIO_Pin_12 |GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
		GPIO_LedStruct.Mode =GPIO_MODE_OUTPUT;
		GPIO_LedStruct.Otype=GPIO_OTYPE_PP;
		GPIO_LedStruct.PuPd=GPIO_PUPD_NOPULL;
		GPIO_LedStruct.Speed=GPIO_SPEED_LOW;

		GPIO_Init(GPIOD, &GPIO_LedStruct);
		memset(&GPIO_LedStruct,0,sizeof (GPIO_LedStruct));

	GPIO_LedStruct.pinNumber=GPIO_Pin_0;
	GPIO_LedStruct.Mode=GPIO_MODE_INPUT;
	GPIO_LedStruct.PuPd=GPIO_PUPD_PULLDOWN;

	GPIO_Init(GPIOA, &GPIO_LedStruct);






}
static void GPIO_ButtonInterruptConfig(){


	EXTI_InitTypedef_t EXTI_InitStruct = { 0 };
	RCC_SYSCFG_CLK_ENABLE();



	EXTI_LineConfig(EXTI_PortSource_GPIOA, EXTI_LineSource_0);

	EXTI_InitStruct.EXTI_LineCmd =ENABLE;
	EXTI_InitStruct.EXTI_LineNumber=EXTI_LineSource_0;
	EXTI_InitStruct.EXTI_Mode=EXTI_MODE_Interrupt;
	EXTI_InitStruct.TriggerSelection=EXTI_Trigger_Rising;

	EXTI_Init(&EXTI_InitStruct);

	NVIC_EnableInterrupt(EXTI0_IRQNumber);




}
static void SPI_Config()
{




	RCC_SPI1_CLK_ENABLE();

	SPI_Handle.Instance = SPI1;
	SPI_Handle.Init.BaudRate = SPI_BAUDRATE_DIV8; // 2MHz
	SPI_Handle.Init.BusConfig = SPI_BUS_FullDuplex;
	SPI_Handle.Init.CPHA = SPI_CPHA_FIRST;
	SPI_Handle.Init.CPOL = SPI_CPOL_LOW;
	SPI_Handle.Init.DFF_Format = SPI_DFF_8BITS;
	SPI_Handle.Init.FrameFormat = SPI_FRAMEFORMAT_MSB;
	SPI_Handle.Init.Mode = SPI_MODE_MASTER;
	SPI_Handle.Init.SSM_Cmd = SPI_SSM_ENABLE;

	SPI_Init(&SPI_Handle);

	NVIC_EnableInterrupt(SPI1_IRQNumber);

	SPI_PeriphCmd(&SPI_Handle, ENABLE);





}

static void SPI_GPIO_Config(){

	GPIO_InitTypedef_t GPIO_InitStruct = { 0 };

	GPIO_InitStruct.pinNumber = GPIO_Pin_5 | GPIO_Pin_7 ; //PA5 = SCK PA7 = MOSI
	GPIO_InitStruct.Mode = GPIO_MODE_AF;
	GPIO_InitStruct.Otype = GPIO_OTYPE_PP;
	GPIO_InitStruct.PuPd = GPIO_PUPD_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_VERY_HIGH;
	GPIO_InitStruct.Alternate = GPIO_AF5;

	GPIO_Init(GPIOA, &GPIO_InitStruct);
}











