################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Source\ Files/main.cpp 

OBJS += \
./Source\ Files/main.o 

CPP_DEPS += \
./Source\ Files/main.d 


# Each subdirectory must supply rules for building sources it contributes
Source\ Files/main.o: ../Source\ Files/main.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Source Files/main.d" -MT"Source\ Files/main.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


