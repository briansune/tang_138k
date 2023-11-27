################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/demo/ethernet.c \
../src/demo/main.c 

OBJS += \
./src/demo/ethernet.o \
./src/demo/main.o 

C_DEPS += \
./src/demo/ethernet.d \
./src/demo/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/demo/%.o: ../src/demo/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Andes C Compiler'
	$(CROSS_COMPILE)gcc -I"/cygdrive/E/RDS5/workspace/ae350_ext_ethernet/src/bsp/ae350" -I"/cygdrive/E/RDS5/workspace/ae350_ext_ethernet/src/bsp/config" -I"/cygdrive/E/RDS5/workspace/ae350_ext_ethernet/src/bsp/driver/ae350" -I"/cygdrive/E/RDS5/workspace/ae350_ext_ethernet/src/bsp/driver/include" -I"/cygdrive/E/RDS5/workspace/ae350_ext_ethernet/src/bsp/lib" -I"/cygdrive/E/RDS5/workspace/ae350_ext_ethernet/src/demo" -Og -mcmodel=medium -g3 -Wall -mcpu=a25 -ffunction-sections -fdata-sections -c -fmessage-length=0 -fno-builtin -fomit-frame-pointer -fno-strict-aliasing -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $(@:%.o=%.o)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


