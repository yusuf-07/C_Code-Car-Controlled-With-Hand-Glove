################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Sources/4.Application/subdir.mk
-include Sources/2.HAL/MG995/subdir.mk
-include Sources/2.HAL/LCD/subdir.mk
-include Sources/2.HAL/DC_Motor/subdir.mk
-include Sources/1.MCAL/UART/subdir.mk
-include Sources/1.MCAL/TIMER/subdir.mk
-include Sources/1.MCAL/Interrupts/subdir.mk
-include Sources/1.MCAL/DIO/subdir.mk
-include Sources/1.MCAL/ADC/subdir.mk
-include Sources/0.Library/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Glove_Controlled_Car.lss \

FLASH_IMAGE += \
Glove_Controlled_Car.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Glove_Controlled_Car.elf secondary-outputs

# Tool invocations
Glove_Controlled_Car.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Glove_Controlled_Car.map -mmcu=atmega32 -o "Glove_Controlled_Car.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Glove_Controlled_Car.lss: Glove_Controlled_Car.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Glove_Controlled_Car.elf  >"Glove_Controlled_Car.lss"
	@echo 'Finished building: $@'
	@echo ' '

Glove_Controlled_Car.hex: Glove_Controlled_Car.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Glove_Controlled_Car.elf  "Glove_Controlled_Car.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Glove_Controlled_Car.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Glove_Controlled_Car.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Glove_Controlled_Car.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
