################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/2.ECUAL/Keypad/Sources/KEYPAD.c 

OBJS += \
./Sources/2.ECUAL/Keypad/Sources/KEYPAD.o 

C_DEPS += \
./Sources/2.ECUAL/Keypad/Sources/KEYPAD.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/2.ECUAL/Keypad/Sources/%.o: ../Sources/2.ECUAL/Keypad/Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"E:\mohadrat w araf\AMIT\Workspace\R.E.M1\Sources\0.Library" -I"E:\mohadrat w araf\AMIT\Workspace\R.E.M1\Sources\1.MCAL\ADC" -I"E:\mohadrat w araf\AMIT\Workspace\R.E.M1\Sources\5. Project\FlexSensor\Includes" -I"E:\mohadrat w araf\AMIT\Workspace\R.E.M1\Sources\5. Project\Glove_Sender\Includes" -I"E:\mohadrat w araf\AMIT\Workspace\R.E.M1\Sources\1.MCAL\DIO\Includes" -I"E:\mohadrat w araf\AMIT\Workspace\R.E.M1\Sources\1.MCAL\EXTINT\Includes" -I"E:\mohadrat w araf\AMIT\Workspace\R.E.M1\Sources\1.MCAL\GINT\Includes" -I"E:\mohadrat w araf\AMIT\Workspace\R.E.M1\Sources\1.MCAL\I2C\Includes" -I"E:\mohadrat w araf\AMIT\Workspace\R.E.M1\Sources\1.MCAL\Timer0\Includes" -I"E:\mohadrat w araf\AMIT\Workspace\R.E.M1\Sources\1.MCAL\UART\Includes" -I"E:\mohadrat w araf\AMIT\Workspace\R.E.M1\Sources\2.ECUAL\Buttons\Include" -I"E:\mohadrat w araf\AMIT\Workspace\R.E.M1\Sources\2.ECUAL\Buzzer\Include" -I"E:\mohadrat w araf\AMIT\Workspace\R.E.M1\Sources\2.ECUAL\DC Motor\Includes" -I"E:\mohadrat w araf\AMIT\Workspace\R.E.M1\Sources\2.ECUAL\Keypad\Include" -I"E:\mohadrat w araf\AMIT\Workspace\R.E.M1\Sources\2.ECUAL\EEPROM [MCAL]\Includes" -I"E:\mohadrat w araf\AMIT\Workspace\R.E.M1\Sources\2.ECUAL\EEPROM24C16C [External]\Includes" -I"E:\mohadrat w araf\AMIT\Workspace\R.E.M1\Sources\2.ECUAL\LCD\Include" -I"E:\mohadrat w araf\AMIT\Workspace\R.E.M1\Sources\2.ECUAL\LED\Includes" -I"E:\mohadrat w araf\AMIT\Workspace\R.E.M1\Sources\2.ECUAL\LM35\Includes" -I"E:\mohadrat w araf\AMIT\Workspace\R.E.M1\Sources\2.ECUAL\SSD\Includes" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


