################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../mydriver/Src/EXTI.c \
../mydriver/Src/GPIO.c \
../mydriver/Src/RCC.c \
../mydriver/Src/SPI.c \
../mydriver/Src/USART.c 

OBJS += \
./mydriver/Src/EXTI.o \
./mydriver/Src/GPIO.o \
./mydriver/Src/RCC.o \
./mydriver/Src/SPI.o \
./mydriver/Src/USART.o 

C_DEPS += \
./mydriver/Src/EXTI.d \
./mydriver/Src/GPIO.d \
./mydriver/Src/RCC.d \
./mydriver/Src/SPI.d \
./mydriver/Src/USART.d 


# Each subdirectory must supply rules for building sources it contributes
mydriver/Src/%.o mydriver/Src/%.su mydriver/Src/%.cyclo: ../mydriver/Src/%.c mydriver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"C:/Users/emre/STM32CubeIDE/workspace_1.13.0/Driver/mydriver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-mydriver-2f-Src

clean-mydriver-2f-Src:
	-$(RM) ./mydriver/Src/EXTI.cyclo ./mydriver/Src/EXTI.d ./mydriver/Src/EXTI.o ./mydriver/Src/EXTI.su ./mydriver/Src/GPIO.cyclo ./mydriver/Src/GPIO.d ./mydriver/Src/GPIO.o ./mydriver/Src/GPIO.su ./mydriver/Src/RCC.cyclo ./mydriver/Src/RCC.d ./mydriver/Src/RCC.o ./mydriver/Src/RCC.su ./mydriver/Src/SPI.cyclo ./mydriver/Src/SPI.d ./mydriver/Src/SPI.o ./mydriver/Src/SPI.su ./mydriver/Src/USART.cyclo ./mydriver/Src/USART.d ./mydriver/Src/USART.o ./mydriver/Src/USART.su

.PHONY: clean-mydriver-2f-Src

