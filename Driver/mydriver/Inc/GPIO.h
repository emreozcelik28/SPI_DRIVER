

#ifndef INC_GPIO_H_
#define INC_GPIO_H_

#include"stm32f407xx.h"

/*
 * @def_group GPIO_Pin
 *
 * */
#define GPIO_Pin_0         (uint16_t)(0x0001)     /*    GPIO Pin 0   Selected     */
#define GPIO_Pin_1         (uint16_t)(0x0002)     /*    GPIO Pin 1   Selected     */
#define GPIO_Pin_2         (uint16_t)(0x0004)     /*    GPIO Pin 2   Selected     */
#define GPIO_Pin_3         (uint16_t)(0x0008)     /*    GPIO Pin 3   Selected     */
#define GPIO_Pin_4         (uint16_t)(0x0010)     /*    GPIO Pin 4   Selected     */
#define GPIO_Pin_5         (uint16_t)(0x0020)     /*    GPIO Pin 5   Selected     */
#define GPIO_Pin_6         (uint16_t)(0x0040)     /*    GPIO Pin 6   Selected     */
#define GPIO_Pin_7         (uint16_t)(0x0080)     /*    GPIO Pin 7   Selected     */
#define GPIO_Pin_8         (uint16_t)(0x0100)     /*    GPIO Pin 8   Selected     */
#define GPIO_Pin_9         (uint16_t)(0x0200)     /*    GPIO Pin 9   Selected     */
#define GPIO_Pin_10        (uint16_t)(0x0400)     /*    GPIO Pin 10  Selected     */
#define GPIO_Pin_11        (uint16_t)(0x0800)     /*    GPIO Pin 11  Selected     */
#define GPIO_Pin_12        (uint16_t)(0x1000)     /*    GPIO Pin 12  Selected     */
#define GPIO_Pin_13        (uint16_t)(0x2000)     /*    GPIO Pin 13  Selected     */
#define GPIO_Pin_14        (uint16_t)(0x4000)     /*    GPIO Pin 14  Selected     */
#define GPIO_Pin_15        (uint16_t)(0x8000)     /*    GPIO Pin 15  Selected     */
#define GPIO_Pin_All       (uint16_t)(0xFFFF)     /*    GPIO Pin All Selected     */

/*
 * @def_group GPIO_Modes
 *
 * */

#define GPIO_MODE_INPUT              (0x0U)
#define GPIO_MODE_OUTPUT             (0x1U)
#define GPIO_MODE_AF                 (0x2U)
#define GPIO_MODE_ANALOG             (0x3U)
/*
 * @def_group GPIO_OTYPE_Modes
 *
 * */
#define GPIO_OTYPE_PP                (0x0U)
#define GPIO_OTYPE_OD                (0x1U)

/*
 * @def_group GPIO_PUPD_Modes
 *
 * */

#define GPIO_PUPD_NOPULL             (0x0U)
#define GPIO_PUPD_PULLUP             (0x1U)
#define GPIO_PUPD_PULLDOWN           (0x2U)
/*
 * @def_group GPIO_Speed
 *
 * */

#define GPIO_SPEED_LOW               (0x0U)
#define GPIO_SPEED_MEDIUM            (0x1U)
#define GPIO_SPEED_HIGH              (0x2U)
#define GPIO_SPEED_VERY_HIGH         (0x3U)

/*
 * @def_group GPIO_Alternate
 *
 * */
#define GPIO_AF0					 (0x0U)
#define GPIO_AF1					 (0x1U)
#define GPIO_AF2					 (0x2U)
#define GPIO_AF3					 (0x3U)
#define GPIO_AF4					 (0x4U)
#define GPIO_AF5					 (0x5U)
#define GPIO_AF6					 (0x6U)
#define GPIO_AF7					 (0x7U)
#define GPIO_AF8      				 (0x8U)
#define GPIO_AF9					 (0x9U)
#define GPIO_AF10					 (0xAU)
#define GPIO_AF11					 (0xBU)
#define GPIO_AF12					 (0xCU)
#define GPIO_AF13					 (0xDU)
#define GPIO_AF14					 (0xEU)
#define GPIO_AF15					 (0xFU)



typedef enum{
	GPIO_PIN_RESET=0x00U,
	GPIO_PIN_SET= !GPIO_PIN_RESET


}GPIO_PinState_t;

typedef struct{

	uint32_t pinNumber;         /*!> GPIO Pin Numbers @def_groups GPIO_Pins       */
	uint32_t Mode;              /*!> GPIO Pin Numbers @def_groups GPIO_MODE       */
	uint32_t Otype;             /*!> GPIO Pin Numbers @def_groups GPIO_OTYPE_MODE */
	uint32_t PuPd;              /*!> GPIO Pin Numbers @def_groups GPIO_PUPD       */
	uint32_t Speed;             /*!> GPIO Pin Numbers @def_groups GPIO_Speed      */
	uint32_t Alternate;         /*!> GPIO Pin Numbers @def_groups GPIO_Alternate  */

}GPIO_InitTypedef_t;


void GPIO_Init(GPIO_TypeDef_t *GPIOx,GPIO_InitTypedef_t *GPIO_ConfigStruct);
void GPIO_Write_Pin(GPIO_TypeDef_t*GPIOx,uint16_t pinNumber,GPIO_PinState_t pinState);
GPIO_PinState_t GPIO_Read_Pin(GPIO_TypeDef_t*GPIOx,uint16_t pinNumber);
void GPIO_LockPin(GPIO_TypeDef_t*GPIOx,uint16_t pinNumber);
void GPIO_TogglePin(GPIO_TypeDef_t*GPIOx,uint16_t pinNumber);

















#endif
