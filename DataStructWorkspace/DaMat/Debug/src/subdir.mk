################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/DaMat.cpp \
../src/Matrix.cpp \
../src/Vector3.cpp 

OBJS += \
./src/DaMat.o \
./src/Matrix.o \
./src/Vector3.o 

CPP_DEPS += \
./src/DaMat.d \
./src/Matrix.d \
./src/Vector3.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


