#include "GPIO.h"


/**
  * @brief  GPIO_Init configures the port and pin
  * @param  GPIOx =GPIO port base address
  * @param  GPIO_InitTypedef_T user config structures
  * @retval Void
  */

void GPIO_Init(GPIO_TypeDef_t *GPIOx,GPIO_InitTypedef_t *GPIO_ConfigStruct)
{


	uint32_t position;
	uint32_t fakePosition=0;
	uint32_t lastPosition=0;

for(position=0; position < 16; position++)
{
	fakePosition= (0x1U << position);
	lastPosition= (uint32_t)(GPIO_ConfigStruct->pinNumber) & fakePosition;

	if(fakePosition == lastPosition)
	{
		   // MODE CONFİG
		uint32_t tempValue=GPIOx->MODER;
		tempValue &= ~(0x3U << (position *2) );
		tempValue |= (GPIO_ConfigStruct->Mode << (position *2) );

		GPIOx->MODER=tempValue;

		if(GPIO_ConfigStruct->Mode == GPIO_MODE_OUTPUT || GPIO_ConfigStruct->Mode == GPIO_MODE_AF)
		{
			//OTYPE CONFİG
			tempValue =GPIOx->OTYPER;
			tempValue &= ~(0x1U << position);
			tempValue |=(GPIO_ConfigStruct ->Otype <<(position) );

			GPIOx->OTYPER=tempValue;

			//OSPEED CONFİG
			tempValue =GPIOx->OSPPEDR;
			tempValue &= ~(0x3U << (position *2) );
			tempValue |= (GPIO_ConfigStruct ->Speed << (position *2) );
			GPIOx->OSPPEDR=tempValue;

		}

		    //PUPDR CONFİG
		tempValue =GPIOx->PUPDR;
		tempValue &= ~(0x3U << (position *2 ) );
		tempValue |= (GPIO_ConfigStruct->PuPd << (position *2 ) );
		GPIOx->PUPDR=tempValue;

		if(GPIO_ConfigStruct->Mode == GPIO_MODE_AF)
		{
			tempValue = GPIOx->AFR[position >> 3U];
			tempValue &= ~(0xFU << ( (position & 0x7U)* 4) );
			tempValue |= (GPIO_ConfigStruct->Alternate << ( (position & 0x7U)* 4) );

			GPIOx->AFR[position >> 3U] = tempValue;



		}

	}



}




}


/**
  * @brief  GPIO_WritePin makes pin high or low
  * @param  GPIOx =GPIO port base address
  * @param  pinNumber GPIO Pin Number 0-15
  * @param  pinState make pin set or reset
  * @retval Void
  */

void GPIO_Write_Pin(GPIO_TypeDef_t*GPIOx,uint16_t pinNumber, GPIO_PinState_t pinState){

	if(pinState == GPIO_PIN_SET){

		GPIOx->BSRR=pinNumber;


	}
	else{

		GPIOx->BSRR=(pinNumber<<16);
	}


}
/**
  * @brief  GPIO_Read_Pin read pin set or reset
  * @param  GPIOx =GPIO port base address
  * @param  pinNumber GPIO Pin Number 0-15
  * @retval Void
  */
GPIO_PinState_t GPIO_Read_Pin(GPIO_TypeDef_t*GPIOx,uint16_t pinNumber){

	GPIO_PinState_t bitStatus=GPIO_PIN_RESET;
	if((GPIOx->IDR & pinNumber) != GPIO_PIN_RESET ){

		bitStatus=GPIO_PIN_SET;

	}

	return bitStatus;


}
/**
 * @brief  GPIO_LockPin lock port pin
 * @param  GPIOx =GPIO port base address
 * @param  pinNumber GPIO Pin Number 0-15
 * @retval Void
 */
void GPIO_LockPin(GPIO_TypeDef_t*GPIOx,uint16_t pinNumber){

	uint32_t tempValue=(0x1 <<16) | pinNumber;
	GPIOx->LCKR=tempValue; // '1'  + LCKR[15:0]
	GPIOx->LCKR=pinNumber; // '0'  + LCKR[15:0]
	GPIOx->LCKR=tempValue; // '1'  + LCKR[15:0]

	tempValue=GPIOx->LCKR; // Read lock register


}
/**
 * @brief  GPIO_TogglePin toggles the pin of GPIOx
 * @param  GPIOx =GPIO port base address
 * @param  pinNumber GPIO Pin Number 0-15
 * @retval Void
 */
void GPIO_TogglePin(GPIO_TypeDef_t*GPIOx,uint16_t pinNumber){

	uint32_t tempODRRegister=GPIOx->ODR;


	GPIOx->BSRR= ( (tempODRRegister & pinNumber) << 16U)  | (~(tempODRRegister) & pinNumber);











}
