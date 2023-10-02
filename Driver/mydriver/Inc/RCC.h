
#ifndef INC_RCC_H_
#define INC_RCC_H_

#include "stm32f407xx.h"

/*
 * RCC AHB1 Peripherals Clock Control Macro Definitions
 * */
#define RCC_GPIOA_CLK_ENABLE()  do{   uint32_t tempValue=0;       \
	                            SET_BIT(RCC->AHB1ENR,RCC_AHB1_GPIOAEN);       \
							    tempValue=READ_BIT(RCC->AHB1ENR,RCC_AHB1_GPIOAEN) ; \
							    UNUSED(tempValue);       \
                               }while(0)

#define RCC_GPIOB_CLK_ENABLE()  do{   uint32_t tempValue=0;       \
	                            SET_BIT(RCC->AHB1ENR,RCC_AHB1_GPIOBEN);       \
							    tempValue=READ_BIT(RCC->AHB1ENR,RCC_AHB1_GPIOBEN) ; \
							    UNUSED(tempValue);       \
                               }while(0)

#define RCC_GPIOC_CLK_ENABLE()  do{   uint32_t tempValue=0;       \
	                            SET_BIT(RCC->AHB1ENR,RCC_AHB1_GPIOCEN);       \
							    tempValue=READ_BIT(RCC->AHB1ENR,RCC_AHB1_GPIOCEN) ; \
							    UNUSED(tempValue);       \
                               }while(0)

#define RCC_GPIOD_CLK_ENABLE()  do{   uint32_t tempValue=0;       \
	                            SET_BIT(RCC->AHB1ENR,RCC_AHB1_GPIODEN);       \
							    tempValue=READ_BIT(RCC->AHB1ENR,RCC_AHB1_GPIODEN) ; \
							    UNUSED(tempValue);       \
                               }while(0)

#define RCC_GPIOE_CLK_ENABLE()  do{   uint32_t tempValue=0;       \
	                            SET_BIT(RCC->AHB1ENR,RCC_AHB1_GPIOEEN);       \
							    tempValue=READ_BIT(RCC->AHB1ENR,RCC_AHB1_GPIOEEN) ; \
							    UNUSED(tempValue);       \
                               }while(0)

#define RCC_SYSCFG_CLK_ENABLE() do{   uint32_t tempValue=0;     \
                                      SET_BIT(RCC->APB2ENR,RCC_APB2_SYSCFGEN);   \
                                      tempValue=READ_BIT(RCC->APB2ENR,RCC_APB2_SYSCFGEN);   \
                                      UNUSED(tempValue);    \
                                   }while(0)

#define RCC_GPIOA_CLK_DISABLE()             CLEAR_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOAEN)
#define RCC_GPIOB_CLK_DISABLE()             CLEAR_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOBEN)
#define RCC_GPIOC_CLK_DISABLE()             CLEAR_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOCEN)
#define RCC_GPIOD_CLK_DISABLE()             CLEAR_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIODEN)
#define RCC_GPIOE_CLK_DISABLE()             CLEAR_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOEEN)

/*
 * RCC APB1 Peripherals Clock Control Macro Definitions
 * */


#define RCC_SPI2_CLK_ENABLE()              do{ uint32_t tempValue=0;         \
                                               SET_BIT(RCC->APB1ENR,RCC_APB1_SPI2EN);   \
											   tempValue= READ_BIT(RCC->APB1ENR,RCC_APB1_SPI2EN);  \
											   UNUSED(tempValue);     \
											  }while(0)


#define RCC_SPI3_CLK_ENABLE()              do{ uint32_t tempValue=0;         \
                                               SET_BIT(RCC->APB1ENR,RCC_APB1_SPI3EN);   \
											   tempValue= READ_BIT(RCC->APB1ENR,RCC_APB1_SPI3EN);  \
											   UNUSED(tempValue);     \
											  }while(0)


#define RCC_USART2_CLK_ENABLE()            do{ uint32_t tempValue = 0;      \
	                                           SET_BIT(RCC->APB1ENR,RCC_APB1_USART2EN);          \
	                                           tempValue = READ_BIT(RCC->APB1ENR,RCC_APB1_USART2EN);      \
	                                           UNUSED(tempValue);    \
	                                          }while(0)

#define RCC_USART3_CLK_ENABLE()            do{ uint32_t tempValue = 0;      \
	                                           SET_BIT(RCC->APB1ENR,RCC_APB1_USART3EN);          \
	                                           tempValue = READ_BIT(RCC->APB1ENR,RCC_APB1_USART3EN);      \
	                                           UNUSED(tempValue);    \
	                                          }while(0)


/*
 * RCC APB2 Peripherals Clock Control Macro Definitions
 * */
#define RCC_SPI1_CLK_ENABLE()              do{ uint32_t tempValue=0;         \
                                               SET_BIT(RCC->APB2ENR,RCC_APB2_SPI1EN);   \
											   tempValue= READ_BIT(RCC->APB2ENR,RCC_APB2_SPI1EN);  \
											   UNUSED(tempValue);     \
											  }while(0)

#define RCC_SPI4_CLK_ENABLE()              do{ uint32_t tempValue=0;         \
                                               SET_BIT(RCC->APB2ENR,RCC_APB2_SPI4EN);   \
											   tempValue= READ_BIT(RCC->APB2ENR,RCC_APB2_SPI4EN);  \
											   UNUSED(tempValue);     \
											  }while(0)

#define RCC_USART1_CLK_ENABLE()            do{ uint32_t tempValue = 0;      \
	                                           SET_BIT(RCC->APB2ENR,RCC_APB2_USART1EN);          \
	                                           tempValue = READ_BIT(RCC->APB2ENR,RCC_APB2_USART1EN);      \
	                                           UNUSED(tempValue);    \
	                                          }while(0)

uint32_t RCC_GetSystemClock(void);
uint32_t RCC_GetHClock(void);
uint32_t RCC_GetPClock1(void);
uint32_t RCC_GetPClock2(void);

#endif
