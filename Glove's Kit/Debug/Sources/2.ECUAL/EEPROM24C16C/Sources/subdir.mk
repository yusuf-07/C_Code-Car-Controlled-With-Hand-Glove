################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/2.ECUAL/EEPROM24C16C/Sources/EEPROM24C16C.c 

OBJS += \
./Sources/2.ECUAL/EEPROM24C16C/Sources/EEPROM24C16C.o 

C_DEPS += \
./Sources/2.ECUAL/EEPROM24C16C/Sources/EEPROM24C16C.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/2.ECUAL/EEPROM24C16C/Sources/%.o: ../Sources/2.ECUAL/EEPROM24C16C/Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\yabul\OneDrive\Desktop\Programming\eclipse\Blinking_LED_1\Sources\0.Library" -I"C:\Users\yabul\OneDrive\Desktop\Programming\eclipse\Blinking_LED_1\Sources\1.MCAL\I2C\Includes" -I"C:\Users\yabul\OneDrive\Desktop\Programming\eclipse\Blinking_LED_1\Sources\2.ECUAL\EEPROM\Includes" -I"C:\Users\yabul\OneDrive\Desktop\Programming\eclipse\Blinking_LED_1\Sources\1.MCAL\UART\Includes" -I"C:\Users\yabul\OneDrive\Desktop\Programming\eclipse\Blinking_LED_1\Sources\2.ECUAL\DC Motor\Includes" -I"C:\Users\yabul\OneDrive\Desktop\Programming\eclipse\Blinking_LED_1\Sources\1.MCAL\Timer0\Includes" -I"C:\Users\yabul\OneDrive\Desktop\Programming\eclipse\Blinking_LED_1\Sources\2.ECUAL\LM35\Includes" -I"C:\Users\yabul\OneDrive\Desktop\Programming\eclipse\Blinking_LED_1\Sources\1.MCAL\ADC\Includes" -I"C:\Users\yabul\OneDrive\Desktop\Programming\eclipse\Blinking_LED_1\Sources\1.MCAL\ADC\Includes" -I"C:\Users\yabul\OneDrive\Desktop\Programming\eclipse\Blinking_LED_1\Sources\1.MCAL\EXTINT\Includes" -I"C:\Users\yabul\OneDrive\Desktop\Programming\eclipse\Blinking_LED_1\Sources\1.MCAL\GINT\Includes" -I"C:\Users\yabul\OneDrive\Desktop\Programming\eclipse\Blinking_LED_1\Sources\2.ECUAL\Keypad\Include" -I"C:\Users\yabul\OneDrive\Desktop\Programming\eclipse\Blinking_LED_1\Sources\2.ECUAL\LCD\Include" -I"C:\Users\yabul\OneDrive\Desktop\Programming\eclipse\Blinking_LED_1\Sources\2.ECUAL\SSD\Includes" -I"C:\Users\yabul\OneDrive\Desktop\Programming\eclipse\Blinking_LED_1\Sources\1.MCAL\DIO\Includes" -I"C:\Users\yabul\OneDrive\Desktop\Programming\eclipse\Blinking_LED_1\Sources\2.ECUAL\Buttons\Include" -I"C:\Users\yabul\OneDrive\Desktop\Programming\eclipse\Blinking_LED_1\Sources\2.ECUAL\Buzzer\Include" -I"C:\Users\yabul\OneDrive\Desktop\Programming\eclipse\Blinking_LED_1\Sources\2.ECUAL\LED\Includes" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


