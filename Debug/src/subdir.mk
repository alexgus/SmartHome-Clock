################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Clock.cpp \
../src/Conf.cpp \
../src/MQTTConnection.cpp \
../src/Ring.cpp \
../src/main.cpp 

OBJS += \
./src/Clock.o \
./src/Conf.o \
./src/MQTTConnection.o \
./src/Ring.o \
./src/main.o 

CPP_DEPS += \
./src/Clock.d \
./src/Conf.d \
./src/MQTTConnection.d \
./src/Ring.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1y -I/home/alexandre/Documents/Dev/TO52/org.eclipse.paho.mqtt.c/src -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



