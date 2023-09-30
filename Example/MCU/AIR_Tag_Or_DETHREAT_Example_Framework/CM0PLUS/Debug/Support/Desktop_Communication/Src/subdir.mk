################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Support/Desktop_Communication/Src/desktop_app_commands.c 

OBJS += \
./Support/Desktop_Communication/Src/desktop_app_commands.o 

C_DEPS += \
./Support/Desktop_Communication/Src/desktop_app_commands.d 


# Each subdirectory must supply rules for building sources it contributes
Support/Desktop_Communication/Src/%.o Support/Desktop_Communication/Src/%.su Support/Desktop_Communication/Src/%.cyclo: ../Support/Desktop_Communication/Src/%.c Support/Desktop_Communication/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DCORE_CM0PLUS -DSTM32WL55xx -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Modules/Mode_Timer/Inc -I../Modules/LED_Debug/Inc -I../Modules/Calendar/Inc -I../Modules/Desktop_Communication/Inc -I../Support/Desktop_Communication/Inc -I../../Drivers/STM32WLxx_HAL_Driver/Inc -I../../Drivers/STM32WLxx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32WLxx/Include -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Support-2f-Desktop_Communication-2f-Src

clean-Support-2f-Desktop_Communication-2f-Src:
	-$(RM) ./Support/Desktop_Communication/Src/desktop_app_commands.cyclo ./Support/Desktop_Communication/Src/desktop_app_commands.d ./Support/Desktop_Communication/Src/desktop_app_commands.o ./Support/Desktop_Communication/Src/desktop_app_commands.su

.PHONY: clean-Support-2f-Desktop_Communication-2f-Src

