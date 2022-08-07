################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/GIE/subdir.mk
-include MCAL/EXTI/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/LCD/subdir.mk
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
Glove_For_Deaf.lss \

FLASH_IMAGE += \
Glove_For_Deaf.hex \

EEPROM_IMAGE += \
Glove_For_Deaf.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: Glove_For_Deaf.elf secondary-outputs

# Tool invocations
Glove_For_Deaf.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Glove_For_Deaf.map -mmcu=atmega32 -o "Glove_For_Deaf.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Glove_For_Deaf.lss: Glove_For_Deaf.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Glove_For_Deaf.elf  >"Glove_For_Deaf.lss"
	@echo 'Finished building: $@'
	@echo ' '

Glove_For_Deaf.hex: Glove_For_Deaf.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Glove_For_Deaf.elf  "Glove_For_Deaf.hex"
	@echo 'Finished building: $@'
	@echo ' '

Glove_For_Deaf.eep: Glove_For_Deaf.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Glove_For_Deaf.elf  "Glove_For_Deaf.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Glove_For_Deaf.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Glove_For_Deaf.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Glove_For_Deaf.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
