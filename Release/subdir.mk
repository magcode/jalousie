################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
INO_SRCS += \
..\jalousie.ino 

CPP_SRCS += \
..\.ino.cpp \
..\J_down.cpp 

LINK_OBJ += \
.\.ino.cpp.o \
.\J_down.cpp.o 

INO_DEPS += \
.\jalousie.ino.d 

CPP_DEPS += \
.\.ino.cpp.d \
.\J_down.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
.ino.cpp.o: ../.ino.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.16\cores\arduino" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.16\variants\eightanaloginputs" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

J_down.cpp.o: ../J_down.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.16\cores\arduino" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.16\variants\eightanaloginputs" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

jalousie.o: ../jalousie.ino
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.16\cores\arduino" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.16\variants\eightanaloginputs" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '


