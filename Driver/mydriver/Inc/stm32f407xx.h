
#ifndef INC_STM32F407XX_H_
#include <stdint.h>
#include <string.h>
#include <stddef.h>
#define INC_STM32F407XX_H_

/*
 *  Microprocessor  Defines
 *
 *
 * */
#define NVIC_ISER0                       ( (uint32_t*) (0xE000E100) )

#define __IO      volatile
#define SET_BIT(REG,BIT)                 ( (REG)  |=  (BIT) )
#define READ_BIT(REG,BIT)                ( (REG)  &   (BIT) )
#define CLEAR_BIT(REG,BIT)               ( (REG)  &= ~(BIT) )
#define UNUSED(x)                           (void)x

typedef enum{
	DISABLE=0x0U,
	ENABLE = !DISABLE

}FunctionalState_t;

/*
 * IRQ Numbers of MCU == Vector Table
 *
 *
 * */

typedef enum{

	EXTI0_IRQNumber = 6,
	EXTI1_IRQNumber = 7,
	EXTI2_IRQNumber = 8,
	EXTI3_IRQNumber = 9,
	SPI1_IRQNumber = 35,
	USART2_IRQNumber = 38

}IRQNumber_TypeDef;


/*
 *              Memory Base Address
 **/

#define FLASH_BASE_ADRR                  (0x08000000U)              /* Flash Base Address Up to 1MB   */
#define SRAM1_BASE_ADRR                  (0x20000000U)              /* SRAM1 Base Address Up to 112KB */
#define SRAM2_BASE_ADRR                  (0x2001C000U)              /* SRAM2 Base Address Up to 16KB  */

/*
 *  Peripheral  Base Address
 *
 * */

#define PERIPH_BASE_ADDR                 (0x40000000U)
#define APB1_BASE_ADDR                   (PERIPH_BASE_ADDR)                     /* APB1 Bus Domain Base Address   */
#define APB2_BASE_ADDR                   (PERIPH_BASE_ADDR + 0x00010000UL)      /* APB2 Bus Domain Base Address   */
#define AHB1_BASE_ADDR                   (PERIPH_BASE_ADDR + 0x00020000UL)      /* AHB1 Bus Domain Base Address   */
#define AHB2_BASE_ADDR                   (PERIPH_BASE_ADDR + 0x10000000UL)      /* AHB2 Bus Domain Base Address   */

/*
 *   APB1 Base Address
 *
 * */

#define TIM2_BASE_ADDR                   (APB1_BASE_ADDR + 0x0000UL)            /* Timer 2 base address  */
#define TIM3_BASE_ADDR                   (APB1_BASE_ADDR + 0x0400UL)            /* Timer 3 base address  */
#define SPI2_BASE_ADDR                   (APB1_BASE_ADDR + 0x3800UL)            /* SPI 2 base address    */
#define SPI3_BASE_ADDR                   (APB1_BASE_ADDR + 0x3C00UL)            /* SPI 3 base address    */
#define USART2_BASE_ADDR                 (APB1_BASE_ADDR + 0x4400UL)            /* USART 2 base address  */
#define USART3_BASE_ADDR                 (APB1_BASE_ADDR + 0x4800UL)            /* USART 3 base address  */
#define UART4_BASE_ADDR                  (APB1_BASE_ADDR + 0x4C00UL)            /* UART 4 base address   */
#define UART5_BASE_ADDR                  (APB1_BASE_ADDR + 0x5000UL)            /* UART 5 base address   */
#define I2C1_BASE_ADDR                   (APB1_BASE_ADDR + 0x5400UL)            /* I2C 1 base address    */
#define I2C2_BASE_ADDR                   (APB1_BASE_ADDR + 0x5800UL)            /* I2C 2 base address    */
#define I2C3_BASE_ADDR                   (APB1_BASE_ADDR + 0X5C00UL)            /* I2C 3 base address    */

/*
 *   APB2 Base Address
 *
 * */
#define TIM1_BASE_ADDR                   (APB2_BASE_ADDR + 0x0000UL)            /* Timer 1 base address  */
#define USART1_BASE_ADDR                 (APB2_BASE_ADDR + 0x1000UL)            /* USART 1 base address  */
#define USART6_BASE_ADDR                 (APB2_BASE_ADDR + 0x1400UL)            /* USART 6 base address  */
#define SPI1_BASE_ADDR                   (APB2_BASE_ADDR + 0x3000UL)            /* SPI 1 base address    */
#define SPI4_BASE_ADDR                   (APB2_BASE_ADDR + 0x3400UL)            /* SPI 4 base address    */
#define SYSCFG_BASE_ADDR                 (APB2_BASE_ADDR + 0x3800UL)            /* SYSCFG base address   */
#define EXTI_BASE_ADDR                   (APB2_BASE_ADDR + 0x3C00UL)            /* EXTI base address     */

/*
 *
 * AHB1 Base Address
 *
 * */
#define GPIOA_BASE_ADDR                  (AHB1_BASE_ADDR + 0x0000UL)            /*GPIOA port base address */
#define GPIOB_BASE_ADDR                  (AHB1_BASE_ADDR + 0x0400UL)            /*GPIOB port base address */
#define GPIOC_BASE_ADDR                  (AHB1_BASE_ADDR + 0x0800UL)            /*GPIOC port base address */
#define GPIOD_BASE_ADDR                  (AHB1_BASE_ADDR + 0x0C00UL)            /*GPIOD port base address */
#define GPIOE_BASE_ADDR                  (AHB1_BASE_ADDR + 0x1000UL)            /*GPIOE port base address */

#define RCC_BASE_ADDR                    (AHB1_BASE_ADDR + 0x3800UL)            /*RCC  base address       */

typedef struct{

	__IO uint32_t MODER;   /*GPIO port mode register base address 0x00               */
	__IO uint32_t OTYPER;  /*GPIO port output type register base address 0x04        */
	__IO uint32_t OSPPEDR; /*GPIO port output speed register base address 0x08       */
	__IO uint32_t PUPDR;   /*GPIO port pull-up/pull-down register base address 0x0C  */
	__IO uint32_t IDR;     /*GPIO port input data register base address 0x10         */
	__IO uint32_t ODR;     /*GPIO port output data register base address 0x14        */
	__IO uint32_t BSRR;    /*GPIO port bit set/reset register base address 0x18      */
	__IO uint32_t LCKR;    /*GPIO port configuration lock register base address 0x1C */
	__IO uint32_t AFR[2];  /*GPIO alternate function low register base address 0x20  */



}GPIO_TypeDef_t;

typedef struct {

	uint32_t CR;             /* RCC clock control register                                       address offset 0x00*/
	uint32_t PLLCFGR;        /* RCC PLL configuration register                                   address offset 0x04*/
	uint32_t CFGR;           /* RCC clock configuration register                                 address offset 0x08*/
	uint32_t CIR; 	 		 /* RCC clock interrupt register                                     address offset 0x0C*/
	uint32_t AHB1RSTR; 	 	 /* RCC AHB1 peripheral reset register                               address offset 0x10*/
	uint32_t AHB2RSTR; 		 /* RCC AHB2 peripheral reset register                               address offset 0x14*/
	uint32_t AHB3RSTR; 		 /* RCC AHB3 peripheral reset register                               address offset 0x18*/
	uint32_t RESERVED;	 	 /* RESERVED                                                         address offset 0x1C*/
	uint32_t APB1RSTR; 		 /* RCC APB1 peripheral reset register                               address offset 0x20*/
	uint32_t APB2RSTR; 		 /* RCC APB2 peripheral reset register                               address offset 0x24*/
	uint32_t RESERVED2;	 	 /* RESERVED                                                         address offset 0x28*/
	uint32_t RESERVED3; 	 /* RESERVED                                                         address offset 0x2C*/
	uint32_t AHB1ENR;	 	 /* RCC AHB1 peripheral clock enable register                        address offset 0x30*/
	uint32_t AHB2ENR;	 	 /* RCC AHB2 peripheral clock enable register                        address offset 0x34*/
	uint32_t AHB3ENR;        /* RCC AHB3 peripheral clock enable register                        address offset 0x38*/
	uint32_t RESERVED4;      /* RESERVED                                                         address offset 0x3C*/
	uint32_t APB1ENR;        /* RCC APB1 peripheral clock enable register                        address offset 0x40*/
	uint32_t APB2ENR;        /* RCC APB2 peripheral clock enable register                        address offset 0x44*/
	uint32_t RESERVED5;      /* RESERVED                                                         address offset 0x48*/
	uint32_t RESERVED6;      /* RESERVED                                                         address offset 0x4C*/
	uint32_t AHB1LPENR;      /* RCC AHB1 peripheral clock enable in low power mode register      address offset 0x50*/
	uint32_t AHB2LPENR;      /* RCC AHB2 peripheral clock enable in low power mode register      address offset 0x54*/
	uint32_t AHB3LPENR;      /* RCC AHB3 peripheral clock enable in low power mode register      address offset 0x58*/
	uint32_t RESERVED7; 	 /* RESERVED                                                         address offset 0x5C*/
	uint32_t APB1LPENR; 	 /* RCC APB1 peripheral clock enable in low power mode register      address offset 0x60*/
	uint32_t APB2LPENR; 	 /* RCC APB2 peripheral clock enable in low power mode register      address offset 0x64*/
	uint32_t RESERVED8;	   	 /* RESERVED                                                         address offset 0x68*/
	uint32_t RESERVED9;      /* RESERVED                                                         address offset 0x6C*/
	uint32_t BDCR;           /* RCC Backup domain control register                               address offset 0x70*/
	uint32_t CSR;            /* RCC clock control & status register                              address offset 0x74*/
	uint32_t RESERVED10;     /* RESERVED                                                         address offset 0x78*/
 	uint32_t RESERVED11;     /* RESERVED                                                         address offset 0x7C*/
	uint32_t SSCGR;          /* RCC spread spectrum clock generation register                    address offset 0x80*/
	uint32_t PLLI2SCFGR;     /* RCC PLLI2S configuration register                                address offset 0x84*/



}RCC_TypeDef_t;

typedef struct {

	__IO uint32_t MEMRMP;    /*SYSCFG memory remap register                                      address offset 0x00*/
	__IO uint32_t PMC;       /*SYSCFG peripheral mode configuration register                     address offset 0x04*/
	__IO uint32_t EXTICR[4]; /*SYSCFG external interrupt configuration register                  address offset 0x08*/
	__IO uint32_t CMPCR;     /*Compensation cell control register                                address offset 0x20*/





}SYSCFG_TypeDef_t;

typedef struct {

	__IO uint32_t IMR;      /*  Interrupt mask register                                          address offset 0x00 */
	__IO uint32_t EMR; 		/*  Event mask register                                              address offset 0x04 */
	__IO uint32_t RTSR;     /*  Rising trigger selection register                                address offset 0x08 */
	__IO uint32_t FTSR;     /*  Falling trigger selection register                               address offset 0x0C */
	__IO uint32_t SWIER;    /*  Software interrupt event register                                address offset 0x10 */
	__IO uint32_t PR;       /*  Pending register                                                 address offset 0x14 */




}EXTI_TypeDef_t;


typedef struct {

	__IO uint32_t CR1;      /*  SPI control register 1                                           address offset 0x00 */
	__IO uint32_t CR2;      /*  SPI control register 2                                           address offset 0x04 */
	__IO uint32_t SR;       /*  SPI status register                                              address offset 0x08 */
	__IO uint32_t DR;       /*  SPI data register                                                address offset 0x0C */
	__IO uint32_t CRCPR;    /*  SPI CRC polynomial register                                      address offset 0x10 */
	__IO uint32_t RXCRCR;   /*  SPI RX CRC register                                              address offset 0x14 */
	__IO uint32_t TXCRCR;   /*  SPI TX CRC register                                              address offset 0x18 */
	__IO uint32_t I2SCFGR;  /*  SPI_I2S configuration register                                   address offset 0x1C */
	__IO uint32_t I2SPR;    /*  SPI_I2S prescaler register                                       address offset 0x20 */



}SPI_TypeDef_t;

typedef struct {

	__IO uint32_t SR;       /*  USART Status register                                               address offset 0x00 */
	__IO uint32_t DR;		/*  USART Data register                                                 address offset 0x04 */
	__IO uint32_t BRR;		/*  USART Baud rate register                                            address offset 0x08 */
	__IO uint32_t CR1;		/*  USART Control register 1                                            address offset 0x0C */
	__IO uint32_t CR2;		/*  USART Control register 2                                            address offset 0x10 */
	__IO uint32_t CR3;		/*  USART Control register 3                                            address offset 0x14 */
	__IO uint32_t GTPR;		/*  USART Guard time and prescaler register                             address offset 0x18 */



}USART_TypeDef_t;

#define GPIOA                    ( (GPIO_TypeDef_t*) (GPIOA_BASE_ADDR)    )
#define GPIOB                    ( (GPIO_TypeDef_t*) (GPIOB_BASE_ADDR)    )
#define GPIOC                    ( (GPIO_TypeDef_t*) (GPIOC_BASE_ADDR)    )
#define GPIOD                    ( (GPIO_TypeDef_t*) (GPIOD_BASE_ADDR)    )
#define GPIOE                    ( (GPIO_TypeDef_t*) (GPIOE_BASE_ADDR)    )

#define RCC                      ( (RCC_TypeDef_t*)   (RCC_BASE_ADDR)     )

#define SYSCFG                   ( (SYSCFG_TypeDef_t*) (SYSCFG_BASE_ADDR) )

#define EXTI                     ( (EXTI_TypeDef_t*)  (EXTI_BASE_ADDR)    )

#define SPI1                     ( (SPI_TypeDef_t*)   (SPI1_BASE_ADDR )   )
#define SPI2                     ( (SPI_TypeDef_t*)   (SPI2_BASE_ADDR )   )
#define SPI3                     ( (SPI_TypeDef_t*)   (SPI3_BASE_ADDR )   )
#define SPI4                     ( (SPI_TypeDef_t*)   (SPI4_BASE_ADDR )   )

#define USART1                   ( (USART_TypeDef_t*) (USART1_BASE_ADDR)  )
#define USART2                   ( (USART_TypeDef_t*) (USART2_BASE_ADDR)  )
#define USART3                   ( (USART_TypeDef_t*) (USART3_BASE_ADDR)  )
#define USART6                   ( (USART_TypeDef_t*) (USART6_BASE_ADDR)  )



#define RCC_AHB1_GPIOAEN_Pos     (0U)                                //RCC APB2ENR register GPIOAEN position
#define RCC_AHB1_GPIOAEN_Msk     (0x1 << RCC_AHB1_GPIOAEN_Pos)       //RCC APB2ENR register GPIOAEN Bit Mask
#define RCC_AHB1_GPIOAEN         ( RCC_AHB1_GPIOAEN_Msk )            //RCC APB2ENR register GPIOAEN Macro

#define RCC_AHB1_GPIOBEN_Pos     (1U)                                //RCC APB2ENR register GPIOBEN position
#define RCC_AHB1_GPIOBEN_Msk     (0x1 << RCC_AHB1_GPIOBEN_Pos)       //RCC APB2ENR register GPIOBEN Bit Mask
#define RCC_AHB1_GPIOBEN         ( RCC_AHB1_GPIOBEN_Msk )            //RCC APB2ENR register GPIOBEN Macro

#define RCC_AHB1_GPIOCEN_Pos     (2U)                                //RCC APB2ENR register GPIOCEN position
#define RCC_AHB1_GPIOCEN_Msk     (0x1 << RCC_AHB1_GPIOCEN_Pos)       //RCC APB2ENR register GPIOCEN Bit Mask
#define RCC_AHB1_GPIOCEN         ( RCC_AHB1_GPIOCEN_Msk )            //RCC APB2ENR register GPIOCEN Macro

#define RCC_AHB1_GPIODEN_Pos     (3U)                                //RCC APB2ENR register GPIODEN position
#define RCC_AHB1_GPIODEN_Msk     (0x1 << RCC_AHB1_GPIODEN_Pos)       //RCC APB2ENR register GPIODEN Bit Mask
#define RCC_AHB1_GPIODEN         ( RCC_AHB1_GPIODEN_Msk )            //RCC APB2ENR register GPIODEN Macro

#define RCC_AHB1_GPIOEEN_Pos     (4U)                                //RCC APB2ENR register GPIOEEN position
#define RCC_AHB1_GPIOEEN_Msk     (0x1 << RCC_AHB1_GPIOEEN_Pos)       //RCC APB2ENR register GPIOEEN Bit Mask
#define RCC_AHB1_GPIOEEN         ( RCC_AHB1_GPIOEEN_Msk )            //RCC APB2ENR register GPIOEEN Macro

#define RCC_APB2_SYSCFGEN_Pos    (14U)
#define RCC_APB2_SYSCFGEN_Msk    (0x1 << RCC_APB2_SYSCFGEN_Pos)
#define RCC_APB2_SYSCFGEN        ( RCC_APB2_SYSCFGEN_Msk      )

#define RCC_APB2_SPI1EN_Pos      (12U)
#define RCC_APB2_SPI1EN_Msk      (0x1 << RCC_APB2_SPI1EN_Pos  )
#define RCC_APB2_SPI1EN          ( RCC_APB2_SPI1EN_Msk        )

#define RCC_APB1_SPI2EN_Pos      (14U)
#define RCC_APB1_SPI2EN_Msk      (0x1 << RCC_APB1_SPI2EN_Pos  )
#define RCC_APB1_SPI2EN          ( RCC_APB1_SPI2EN_Msk        )

#define RCC_APB1_SPI3EN_Pos      (15U)
#define RCC_APB1_SPI3EN_Msk      (0x1 << RCC_APB1_SPI3EN_Pos  )
#define RCC_APB1_SPI3EN          ( RCC_APB1_SPI3EN_Msk        )

#define RCC_APB2_SPI4EN_Pos      (13U)
#define RCC_APB2_SPI4EN_Msk      (0x1 << RCC_APB2_SPI4EN_Pos  )
#define RCC_APB2_SPI4EN          ( RCC_APB2_SPI4EN_Msk        )



#define RCC_APB2_USART1_Pos      (4U)
#define RCC_APB2_USART1_Msk      (0x1 << RCC_APB2_USART1_Pos  )
#define RCC_APB2_USART1EN        (RCC_APB2_USART1_Msk         )

#define RCC_APB1_USART2_Pos      (17U)
#define RCC_APB1_USART2_Msk      (0x1 << RCC_APB1_USART2_Pos  )
#define RCC_APB1_USART2EN        (RCC_APB1_USART2_Msk         )

#define RCC_APB1_USART3_Pos      (18U)
#define RCC_APB1_USART3_Msk      (0x1 << RCC_APB1_USART3_Pos  )
#define RCC_APB1_USART3EN        (RCC_APB1_USART3_Msk         )





#define SPI_SR_Busy 			 (7U)
#define SPI_SR_TxE               (1U)
#define SPI_SR_RxNE              (0U)

#define SPI_CR1_SPE              (6U)
#define SPI_CR1_DFF              (11U)

#define SPI_CR2_TXEIE            (7U)
#define SPI_CR2_RXNEIE           (6U)

#define USART_CR1_UE             (13U)
#define USART_CR1_TxEIE          (7U)
#define USART_CR1_RxNEIE         (5U)

#define UART_CR2_STOP            (12U)

#define USART_SR_TxE             (7U)
#define USART_SR_TC              (6U)
#define USART_SR_RxNE            (5U)
/*
 *  Flag Definitions
 *
 * */
#define SPI_TxE_FLAG             ( 0x1U << SPI_SR_TxE  )
#define SPI_Busy_FLAG			 ( 0x1U << SPI_SR_Busy )
#define SPI_RxNE_FLAG            ( 0x1U << SPI_SR_RxNE )

#define USART_TxE_FLAG           ( 0x1U << USART_SR_TxE)
#define USART_TC_FLAG            ( 0x1U << USART_SR_TC )
#define USART_RxNE_FLAG          ( 0x1U << USART_SR_RxNE )

#include"RCC.h"
#include "GPIO.h"
#include "EXTI.h"
#include "SPI.h"
#include "USART.h"
#endif
