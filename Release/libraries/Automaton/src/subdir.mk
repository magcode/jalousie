################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src\Atm_analog.cpp \
C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src\Atm_bit.cpp \
C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src\Atm_button.cpp \
C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src\Atm_command.cpp \
C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src\Atm_comparator.cpp \
C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src\Atm_controller.cpp \
C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src\Atm_digital.cpp \
C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src\Atm_encoder.cpp \
C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src\Atm_fade.cpp \
C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src\Atm_fan.cpp \
C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src\Atm_led.cpp \
C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src\Atm_player.cpp \
C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src\Atm_step.cpp \
C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src\Atm_timer.cpp \
C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src\Automaton.cpp \
C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src\Machine.cpp \
C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src\atm_connector.cpp \
C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src\atm_counter.cpp \
C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src\atm_timer_millis.cpp 

LINK_OBJ += \
.\libraries\Automaton\src\Atm_analog.cpp.o \
.\libraries\Automaton\src\Atm_bit.cpp.o \
.\libraries\Automaton\src\Atm_button.cpp.o \
.\libraries\Automaton\src\Atm_command.cpp.o \
.\libraries\Automaton\src\Atm_comparator.cpp.o \
.\libraries\Automaton\src\Atm_controller.cpp.o \
.\libraries\Automaton\src\Atm_digital.cpp.o \
.\libraries\Automaton\src\Atm_encoder.cpp.o \
.\libraries\Automaton\src\Atm_fade.cpp.o \
.\libraries\Automaton\src\Atm_fan.cpp.o \
.\libraries\Automaton\src\Atm_led.cpp.o \
.\libraries\Automaton\src\Atm_player.cpp.o \
.\libraries\Automaton\src\Atm_step.cpp.o \
.\libraries\Automaton\src\Atm_timer.cpp.o \
.\libraries\Automaton\src\Automaton.cpp.o \
.\libraries\Automaton\src\Machine.cpp.o \
.\libraries\Automaton\src\atm_connector.cpp.o \
.\libraries\Automaton\src\atm_counter.cpp.o \
.\libraries\Automaton\src\atm_timer_millis.cpp.o 

CPP_DEPS += \
.\libraries\Automaton\src\Atm_analog.cpp.d \
.\libraries\Automaton\src\Atm_bit.cpp.d \
.\libraries\Automaton\src\Atm_button.cpp.d \
.\libraries\Automaton\src\Atm_command.cpp.d \
.\libraries\Automaton\src\Atm_comparator.cpp.d \
.\libraries\Automaton\src\Atm_controller.cpp.d \
.\libraries\Automaton\src\Atm_digital.cpp.d \
.\libraries\Automaton\src\Atm_encoder.cpp.d \
.\libraries\Automaton\src\Atm_fade.cpp.d \
.\libraries\Automaton\src\Atm_fan.cpp.d \
.\libraries\Automaton\src\Atm_led.cpp.d \
.\libraries\Automaton\src\Atm_player.cpp.d \
.\libraries\Automaton\src\Atm_step.cpp.d \
.\libraries\Automaton\src\Atm_timer.cpp.d \
.\libraries\Automaton\src\Automaton.cpp.d \
.\libraries\Automaton\src\Machine.cpp.d \
.\libraries\Automaton\src\atm_connector.cpp.d \
.\libraries\Automaton\src\atm_counter.cpp.d \
.\libraries\Automaton\src\atm_timer_millis.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
libraries\Automaton\src\Atm_analog.cpp.o: C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src\Atm_analog.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.16\cores\arduino" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.16\variants\eightanaloginputs" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

libraries\Automaton\src\Atm_bit.cpp.o: C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src\Atm_bit.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.16\cores\arduino" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.16\variants\eightanaloginputs" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

libraries\Automaton\src\Atm_button.cpp.o: C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src\Atm_button.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.16\cores\arduino" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.16\variants\eightanaloginputs" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

libraries\Automaton\src\Atm_command.cpp.o: C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src\Atm_command.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.16\cores\arduino" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.16\variants\eightanaloginputs" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

libraries\Automaton\src\Atm_comparator.cpp.o: C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src\Atm_comparator.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.16\cores\arduino" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.16\variants\eightanaloginputs" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

libraries\Automaton\src\Atm_controller.cpp.o: C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src\Atm_controller.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.16\cores\arduino" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.16\variants\eightanaloginputs" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

libraries\Automaton\src\Atm_digital.cpp.o: C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src\Atm_digital.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.16\cores\arduino" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.16\variants\eightanaloginputs" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

libraries\Automaton\src\Atm_encoder.cpp.o: C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src\Atm_encoder.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.16\cores\arduino" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.16\variants\eightanaloginputs" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

libraries\Automaton\src\Atm_fade.cpp.o: C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src\Atm_fade.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.16\cores\arduino" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.16\variants\eightanaloginputs" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

libraries\Automaton\src\Atm_fan.cpp.o: C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src\Atm_fan.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.16\cores\arduino" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.16\variants\eightanaloginputs" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

libraries\Automaton\src\Atm_led.cpp.o: C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src\Atm_led.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.16\cores\arduino" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.16\variants\eightanaloginputs" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

libraries\Automaton\src\Atm_player.cpp.o: C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src\Atm_player.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.16\cores\arduino" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.16\variants\eightanaloginputs" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

libraries\Automaton\src\Atm_step.cpp.o: C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src\Atm_step.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.16\cores\arduino" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.16\variants\eightanaloginputs" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

libraries\Automaton\src\Atm_timer.cpp.o: C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src\Atm_timer.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.16\cores\arduino" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.16\variants\eightanaloginputs" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

libraries\Automaton\src\Automaton.cpp.o: C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src\Automaton.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.16\cores\arduino" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.16\variants\eightanaloginputs" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

libraries\Automaton\src\Machine.cpp.o: C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src\Machine.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.16\cores\arduino" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.16\variants\eightanaloginputs" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

libraries\Automaton\src\atm_connector.cpp.o: C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src\atm_connector.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.16\cores\arduino" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.16\variants\eightanaloginputs" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

libraries\Automaton\src\atm_counter.cpp.o: C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src\atm_counter.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.16\cores\arduino" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.16\variants\eightanaloginputs" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

libraries\Automaton\src\atm_timer_millis.cpp.o: C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src\atm_timer_millis.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\tools\arduino\avr-gcc\4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.16\cores\arduino" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.16\variants\eightanaloginputs" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1" -I"C:\Users\Marko\privat\ha\sloeber\arduinoPlugin\libraries\Automaton\1.0.1\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '


