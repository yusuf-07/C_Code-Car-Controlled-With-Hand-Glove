################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Sources/5.\ Project/Glove_Sender/Sources/subdir.mk
-include Sources/4.Applicaton/subdir.mk
-include Sources/2.ECUAL/SSD/Sources/subdir.mk
-include Sources/2.ECUAL/LM35/Sources/subdir.mk
-include Sources/2.ECUAL/LED/Sources/subdir.mk
-include Sources/2.ECUAL/LCD/Sources/subdir.mk
-include Sources/2.ECUAL/Keypad/Sources/subdir.mk
-include Sources/2.ECUAL/EEPROM24C16C\ [External]/Sources/subdir.mk
-include Sources/2.ECUAL/EEPROM\ [MCAL]/Sources/subdir.mk
-include Sources/2.ECUAL/DC\ Motor/Sources/subdir.mk
-include Sources/2.ECUAL/Buzzer/Sources/subdir.mk
-include Sources/2.ECUAL/Buttons/Sources/subdir.mk
-include Sources/1.MCAL/UART/Sources/subdir.mk
-include Sources/1.MCAL/Timer0/Sources/subdir.mk
-include Sources/1.MCAL/I2C/Sources/subdir.mk
-include Sources/1.MCAL/GINT/Sources/subdir.mk
-include Sources/1.MCAL/EXTINT/Sources/subdir.mk
-include Sources/1.MCAL/DIO/Sources/subdir.mk
-include Sources/1.MCAL/ADC/subdir.mk
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
R.E.M1.lss \
R.E.M1.lss \

FLASH_IMAGE += \
R.E.M1.hex \

SIZEDUMMY += \
sizedummy \
sizedummy \


# All Target
all: R.E.M1.elf secondary-outputs

# Tool invocations
R.E.M1.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,R.E.M1.map -mmcu=atmega32 -o "R.E.M1.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

R.E.M1.lss: R.E.M1.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S R.E.M1.elf  >"R.E.M1.lss"
	@echo 'Finished building: $@'
	@echo ' '

R.E.M1.hex: R.E.M1.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex R.E.M1.elf  "R.E.M1.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: R.E.M1.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 R.E.M1.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) R.E.M1.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
