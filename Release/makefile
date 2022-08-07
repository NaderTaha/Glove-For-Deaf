################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/UART/subdir.mk
-include MCAL/GIE/subdir.mk
-include MCAL/EXTI/subdir.mk
-include MCAL/DIO/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/Key_pad/subdir.mk
-include Application/subdir.mk
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
My_Drive.lss \

FLASH_IMAGE += \
My_Drive.hex \

EEPROM_IMAGE += \
My_Drive.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: My_Drive.elf secondary-outputs

# Tool invocations
My_Drive.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,My_Drive.map -mmcu=atmega32 -o "My_Drive.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

My_Drive.lss: My_Drive.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S My_Drive.elf  >"My_Drive.lss"
	@echo 'Finished building: $@'
	@echo ' '

My_Drive.hex: My_Drive.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex My_Drive.elf  "My_Drive.hex"
	@echo 'Finished building: $@'
	@echo ' '

My_Drive.eep: My_Drive.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex My_Drive.elf  "My_Drive.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: My_Drive.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 My_Drive.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) My_Drive.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
