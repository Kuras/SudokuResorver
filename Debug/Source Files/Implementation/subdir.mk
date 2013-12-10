################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Source\ Files/Implementation/SudukuImplementation.cpp \
../Source\ Files/Implementation/TestSudukuGrid.cpp 

OBJS += \
./Source\ Files/Implementation/SudukuImplementation.o \
./Source\ Files/Implementation/TestSudukuGrid.o 

CPP_DEPS += \
./Source\ Files/Implementation/SudukuImplementation.d \
./Source\ Files/Implementation/TestSudukuGrid.d 


# Each subdirectory must supply rules for building sources it contributes
Source\ Files/Implementation/SudukuImplementation.o: ../Source\ Files/Implementation/SudukuImplementation.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Source Files/Implementation/SudukuImplementation.d" -MT"Source\ Files/Implementation/SudukuImplementation.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source\ Files/Implementation/TestSudukuGrid.o: ../Source\ Files/Implementation/TestSudukuGrid.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Source Files/Implementation/TestSudukuGrid.d" -MT"Source\ Files/Implementation/TestSudukuGrid.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


