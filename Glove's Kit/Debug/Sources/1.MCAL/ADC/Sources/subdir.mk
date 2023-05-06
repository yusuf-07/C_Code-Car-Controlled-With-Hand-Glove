################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/1.MCAL/ADC/Sources/ADC.c 

OBJS += \
./Sources/1.MCAL/ADC/Sources/ADC.o 

C_DEPS += \
./Sources/1.MCAL/ADC/Sources/ADC.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/1.MCAL/ADC/Sources/%.o: ../Sources/1.MCAL/ADC/Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\yabul\OneDrive\Desktop\Programming\eclipse\R.E.M\Sources\0.Library" -I"C:\Users\yabul\OneDrive\Desktop\Programming\eclipse\R.E.M\Sources\5. Project\FlexSensor\Includes" -I"C:\Users\yabul\OneDrive\Desktop\Programming\eclipse\R.E.M\Sources\5. Project\Car_Receiver\Includes" -I"C:\Users\yabul\OneDrive\Desktop\Programming\eclipse\R.E.M\Sources\5. Project\Glove_Sender\Includes" -I"C:\Users\yabul\OneDrive\Desktop\Programming\eclipse\R.E.M\Sources\1.MCAL\ADC\Includes" -I"C:\Users\yabul\OneDrive\Desktop\Programming\eclipse\R.E.M\Sources\1.MCAL\DIO\Includes" -I"C:\Users\yabul\OneDrive\Desktop\Programming\eclipse\R.E.M\Sources\1.MCAL\EXTINT\Includes" -I"C:\Users\yabul\OneDrive\Desktop\Programming\eclipse\R.E.M\Sources\1.MCAL\GINT\Includes" -I"C:\Users\yabul\OneDrive\Desktop\Programming\eclipse\R.E.M\Sources\1.MCAL\I2C\Includes" -I"C:\Users\yabul\OneDrive\Desktop\Programming\eclipse\R.E.M\Sources\1.MCAL\Timer0\Includes" -I"C:\Users\yabul\OneDrive\Desktop\Programming\eclipse\R.E.M\Sources\1.MCAL\UART\Includes" -I"C:\Users\yabul\OneDrive\Desktop\Programming\eclipse\R.E.M\Sources\2.ECUAL\Buttons\Include" -I"C:\Users\yabul\OneDrive\Desktop\Programming\eclipse\R.E.M\Sources\2.ECUAL\Buzzer\Include" -I"C:\Users\yabul\OneDrive\Desktop\Programming\eclipse\R.E.M\Sources\2.ECUAL\DC Motor\Includes" -I"C:\Users\yabul\OneDrive\Desktop\Programming\eclipse\R.E.M\Sources\2.ECUAL\Keypad\Include" -I"C:\Users\yabul\OneDrive\Desktop\Programming\eclipse\R.E.M\Sources\2.ECUAL\EEPROM [MCAL]\Includes" -I"C:\Users\yabul\OneDrive\Desktop\Programming\eclipse\R.E.M\Sources\2.ECUAL\EEPROM24C16C [External]\Includes" -I"C:\Users\yabul\OneDrive\Desktop\Programming\eclipse\R.E.M\Sources\2.ECUAL\LCD\Include" -I"C:\Users\yabul\OneDrive\Desktop\Programming\eclipse\R.E.M\Sources\2.ECUAL\LED\Includes" -I"C:\Users\yabul\OneDrive\Desktop\Programming\eclipse\R.E.M\Sources\2.ECUAL\LM35\Includes" -I"C:\Users\yabul\OneDrive\Desktop\Programming\eclipse\R.E.M\Sources\2.ECUAL\SSD\Includes" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


