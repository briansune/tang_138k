################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/bsp/lib/delay.c \
../src/bsp/lib/mm.c \
../src/bsp/lib/printf.c \
../src/bsp/lib/read.c \
../src/bsp/lib/uart.c 

OBJS += \
./src/bsp/lib/delay.o \
./src/bsp/lib/mm.o \
./src/bsp/lib/printf.o \
./src/bsp/lib/read.o \
./src/bsp/lib/uart.o 

C_DEPS += \
./src/bsp/lib/delay.d \
./src/bsp/lib/mm.d \
./src/bsp/lib/printf.d \
./src/bsp/lib/read.d \
./src/bsp/lib/uart.d 


# Each subdirectory must supply rules for building sources it contributes
src/bsp/lib/%.o: ../src/bsp/lib/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Andes C Compiler'
	$(CROSS_COMPILE)gcc -I"/cygdrive/E/RDS5/workspace/ae350_ext_ethernet/src/bsp/ae350" -I"/cygdrive/E/RDS5/workspace/ae350_ext_ethernet/src/bsp/config" -I"/cygdrive/E/RDS5/workspace/ae350_ext_ethernet/src/bsp/driver/ae350" -I"/cygdrive/E/RDS5/workspace/ae350_ext_ethernet/src/bsp/driver/include" -I"/cygdrive/E/RDS5/workspace/ae350_ext_ethernet/src/bsp/lib" -I"/cygdrive/E/RDS5/workspace/ae350_ext_ethernet/src/demo" -Og -mcmodel=medium -g3 -Wall -mcpu=a25 -ffunction-sections -fdata-sections -c -fmessage-length=0 -fno-builtin -fomit-frame-pointer -fno-strict-aliasing -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $(@:%.o=%.o)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


