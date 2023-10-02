#include "EXTI.h"

/**
  * @brief  EXTI_Init for valid GPİO port and line number
  * @param  EXTI_InitStruct = User config structure
  *
  * @retval Void
  */


void EXTI_Init(EXTI_InitTypedef_t* EXTI_InitStruct){

	uint32_t tempValue=0;

	tempValue= (uint32_t)EXTI_BASE_ADDR;

	EXTI->IMR &= ~(0x1U << EXTI_InitStruct->EXTI_LineNumber);
	EXTI->EMR &= ~(0x1U << EXTI_InitStruct->EXTI_LineNumber);


	if(EXTI_InitStruct->EXTI_LineCmd != DISABLE){

		tempValue += EXTI_InitStruct->EXTI_Mode;


		*( (__IO uint32_t*)tempValue )  |= (0x1U << EXTI_InitStruct->EXTI_LineNumber);

		tempValue= (uint32_t)EXTI_BASE_ADDR;

		EXTI->RTSR &= ~(0x1U << EXTI_InitStruct->EXTI_LineNumber);
		EXTI->FTSR &= ~(0x1U << EXTI_InitStruct->EXTI_LineNumber);

		if(EXTI_InitStruct->TriggerSelection == EXTI_Trigger_RF){

			EXTI->RTSR |= (0x1U << EXTI_InitStruct->EXTI_LineNumber);
			EXTI->FTSR |= (0x1U << EXTI_InitStruct->EXTI_LineNumber);


		}
		else{
			tempValue += EXTI_InitStruct->TriggerSelection;
			*( (__IO uint32_t*) tempValue ) |= (0x1U << EXTI_InitStruct->EXTI_LineNumber);


		}




	}
	else{

		tempValue =(uint32_t) EXTI_BASE_ADDR;

		tempValue += EXTI_InitStruct->EXTI_Mode;

		*( (__IO uint32_t*) tempValue) &= ~(0x1U << EXTI_InitStruct->EXTI_LineNumber);





	}


}



/**
  * @brief  GPIO_Line_Config configures the port and pin for SYSCFG
  * @param  portSource = Port values A-I @def_groups PORT_Values
  * @param  EXTI_LineSource = Pin numbers & Line numbers @def_groups EXTI_Line_Values
  *
  * @retval Void
  */
void EXTI_LineConfig(uint8_t portSource, uint8_t EXTI_LineSource){

	uint32_t tempValue;
	tempValue=SYSCFG->EXTICR[EXTI_LineSource >> 2U];
	tempValue=~(0xF << (EXTI_LineSource & 0x3U) *4);
	tempValue=(portSource << (EXTI_LineSource & 0x3U) *4);
	SYSCFG->EXTICR[EXTI_LineSource >> 2U]=tempValue;



}
/**
  * @brief  NVIC_EnableInterrupt
  *
  * @param  IRQNumber = IRQ Number of line
  *
  * @retval Void
  */
void NVIC_EnableInterrupt(IRQNumber_TypeDef IRQNumber){


	uint32_t tempValue=0;

	tempValue = *( (IRQNumber >> 5U) + NVIC_ISER0 );
    tempValue &= ~(0x1U << (IRQNumber & 0x1FU) );
    tempValue |=  (0x1U << (IRQNumber & 0x1FU) );

    *( (IRQNumber >> 5U) + NVIC_ISER0 )=tempValue;


}



















