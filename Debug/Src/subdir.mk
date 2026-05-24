################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/ADC_driver.c \
../Src/GPIO_driver.c \
../Src/SYSTICK_driver.c \
../Src/TIMER_driver.c \
../Src/app.c \
../Src/led_logic.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/ADC_driver.o \
./Src/GPIO_driver.o \
./Src/SYSTICK_driver.o \
./Src/TIMER_driver.o \
./Src/app.o \
./Src/led_logic.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/ADC_driver.d \
./Src/GPIO_driver.d \
./Src/SYSTICK_driver.d \
./Src/TIMER_driver.d \
./Src/app.d \
./Src/led_logic.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F303xE -DSTM32 -DSTM32F3 -DSTM32F303RETx -c -I../Inc -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/ADC_driver.cyclo ./Src/ADC_driver.d ./Src/ADC_driver.o ./Src/ADC_driver.su ./Src/GPIO_driver.cyclo ./Src/GPIO_driver.d ./Src/GPIO_driver.o ./Src/GPIO_driver.su ./Src/SYSTICK_driver.cyclo ./Src/SYSTICK_driver.d ./Src/SYSTICK_driver.o ./Src/SYSTICK_driver.su ./Src/TIMER_driver.cyclo ./Src/TIMER_driver.d ./Src/TIMER_driver.o ./Src/TIMER_driver.su ./Src/app.cyclo ./Src/app.d ./Src/app.o ./Src/app.su ./Src/led_logic.cyclo ./Src/led_logic.d ./Src/led_logic.o ./Src/led_logic.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

