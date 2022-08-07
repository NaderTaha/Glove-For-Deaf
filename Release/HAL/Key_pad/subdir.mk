################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Key_pad/keypad_prog.c 

OBJS += \
./HAL/Key_pad/keypad_prog.o 

C_DEPS += \
./HAL/Key_pad/keypad_prog.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/Key_pad/%.o: ../HAL/Key_pad/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


