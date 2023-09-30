################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Support/Desktop_Communication/Src/subdir.mk
-include Modules/Mode_Timer/Src/subdir.mk
-include Modules/LED_Debug/Src/subdir.mk
-include Modules/Desktop_Communication/Src/subdir.mk
-include Modules/Calendar/Src/subdir.mk
-include Drivers/STM32WLxx_HAL_Driver/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include Common/System/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := AIR_Tag_Or_DETHREAT_Example_Framework_CM0PLUS
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
AIR_Tag_Or_DETHREAT_Example_Framework_CM0PLUS.elf \

MAP_FILES += \
AIR_Tag_Or_DETHREAT_Example_Framework_CM0PLUS.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
AIR_Tag_Or_DETHREAT_Example_Framework_CM0PLUS.list \


# All Target
all: main-build

# Main-build Target
main-build: AIR_Tag_Or_DETHREAT_Example_Framework_CM0PLUS.elf secondary-outputs

# Tool invocations
AIR_Tag_Or_DETHREAT_Example_Framework_CM0PLUS.elf AIR_Tag_Or_DETHREAT_Example_Framework_CM0PLUS.map: $(OBJS) $(USER_OBJS) /Users/kevinimlay/STM32CubeIDE/workspace_1.12.1/AIR_Tag_Or_DETHREAT_Example_Framework/CM0PLUS/STM32WL55JCIX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "AIR_Tag_Or_DETHREAT_Example_Framework_CM0PLUS.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m0plus -T"/Users/kevinimlay/STM32CubeIDE/workspace_1.12.1/AIR_Tag_Or_DETHREAT_Example_Framework/CM0PLUS/STM32WL55JCIX_FLASH.ld" --specs=nosys.specs -Wl,-Map="AIR_Tag_Or_DETHREAT_Example_Framework_CM0PLUS.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

AIR_Tag_Or_DETHREAT_Example_Framework_CM0PLUS.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "AIR_Tag_Or_DETHREAT_Example_Framework_CM0PLUS.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) AIR_Tag_Or_DETHREAT_Example_Framework_CM0PLUS.elf AIR_Tag_Or_DETHREAT_Example_Framework_CM0PLUS.list AIR_Tag_Or_DETHREAT_Example_Framework_CM0PLUS.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
