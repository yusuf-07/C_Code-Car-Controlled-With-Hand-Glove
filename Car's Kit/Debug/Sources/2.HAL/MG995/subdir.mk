################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/2.HAL/MG995/MG995.c 

OBJS += \
./Sources/2.HAL/MG995/MG995.o 

C_DEPS += \
./Sources/2.HAL/MG995/MG995.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/2.HAL/MG995/%.o: ../Sources/2.HAL/MG995/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Git Repositories\Glove-Controlled-Car\Sources\0.Library" -I"C:\Git Repositories\Glove-Controlled-Car\Sources\1.MCAL\DIO" -I"C:\Git Repositories\Glove-Controlled-Car\Sources\1.MCAL\ADC" -I"C:\Git Repositories\Glove-Controlled-Car\Sources\1.MCAL\Interrupts" -I"C:\Git Repositories\Glove-Controlled-Car\Sources\1.MCAL\TIMER" -I"C:\Git Repositories\Glove-Controlled-Car\Sources\1.MCAL\UART" -I"C:\Git Repositories\Glove-Controlled-Car\Sources\2.HAL\DC_Motor" -I"C:\Git Repositories\Glove-Controlled-Car\Sources\2.HAL\LCD" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


