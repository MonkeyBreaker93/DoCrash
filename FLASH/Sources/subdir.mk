################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/gEvent.c" \
"../Sources/gGame.c" \
"../Sources/gIntro.c" \
"../Sources/gMenu.c" \
"../Sources/gObject.c" \
"../Sources/iCpu.c" \
"../Sources/iDio.c" \
"../Sources/iPit.c" \
"../Sources/mBlinkLed.c" \
"../Sources/mCpu.c" \
"../Sources/mDelays.c" \
"../Sources/mLcd.c" \
"../Sources/mLeds.c" \
"../Sources/mSwitch.c" \
"../Sources/main.c" \
"../Sources/sa_mtb.c" \

C_SRCS += \
../Sources/gEvent.c \
../Sources/gGame.c \
../Sources/gIntro.c \
../Sources/gMenu.c \
../Sources/gObject.c \
../Sources/iCpu.c \
../Sources/iDio.c \
../Sources/iPit.c \
../Sources/mBlinkLed.c \
../Sources/mCpu.c \
../Sources/mDelays.c \
../Sources/mLcd.c \
../Sources/mLeds.c \
../Sources/mSwitch.c \
../Sources/main.c \
../Sources/sa_mtb.c \

OBJS += \
./Sources/gEvent.o \
./Sources/gGame.o \
./Sources/gIntro.o \
./Sources/gMenu.o \
./Sources/gObject.o \
./Sources/iCpu.o \
./Sources/iDio.o \
./Sources/iPit.o \
./Sources/mBlinkLed.o \
./Sources/mCpu.o \
./Sources/mDelays.o \
./Sources/mLcd.o \
./Sources/mLeds.o \
./Sources/mSwitch.o \
./Sources/main.o \
./Sources/sa_mtb.o \

C_DEPS += \
./Sources/gEvent.d \
./Sources/gGame.d \
./Sources/gIntro.d \
./Sources/gMenu.d \
./Sources/gObject.d \
./Sources/iCpu.d \
./Sources/iDio.d \
./Sources/iPit.d \
./Sources/mBlinkLed.d \
./Sources/mCpu.d \
./Sources/mDelays.d \
./Sources/mLcd.d \
./Sources/mLeds.d \
./Sources/mSwitch.d \
./Sources/main.d \
./Sources/sa_mtb.d \

OBJS_QUOTED += \
"./Sources/gEvent.o" \
"./Sources/gGame.o" \
"./Sources/gIntro.o" \
"./Sources/gMenu.o" \
"./Sources/gObject.o" \
"./Sources/iCpu.o" \
"./Sources/iDio.o" \
"./Sources/iPit.o" \
"./Sources/mBlinkLed.o" \
"./Sources/mCpu.o" \
"./Sources/mDelays.o" \
"./Sources/mLcd.o" \
"./Sources/mLeds.o" \
"./Sources/mSwitch.o" \
"./Sources/main.o" \
"./Sources/sa_mtb.o" \

C_DEPS_QUOTED += \
"./Sources/gEvent.d" \
"./Sources/gGame.d" \
"./Sources/gIntro.d" \
"./Sources/gMenu.d" \
"./Sources/gObject.d" \
"./Sources/iCpu.d" \
"./Sources/iDio.d" \
"./Sources/iPit.d" \
"./Sources/mBlinkLed.d" \
"./Sources/mCpu.d" \
"./Sources/mDelays.d" \
"./Sources/mLcd.d" \
"./Sources/mLeds.d" \
"./Sources/mSwitch.d" \
"./Sources/main.d" \
"./Sources/sa_mtb.d" \

OBJS_OS_FORMAT += \
./Sources/gEvent.o \
./Sources/gGame.o \
./Sources/gIntro.o \
./Sources/gMenu.o \
./Sources/gObject.o \
./Sources/iCpu.o \
./Sources/iDio.o \
./Sources/iPit.o \
./Sources/mBlinkLed.o \
./Sources/mCpu.o \
./Sources/mDelays.o \
./Sources/mLcd.o \
./Sources/mLeds.o \
./Sources/mSwitch.o \
./Sources/main.o \
./Sources/sa_mtb.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/gEvent.o: ../Sources/gEvent.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/gEvent.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/gEvent.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/gGame.o: ../Sources/gGame.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/gGame.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/gGame.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/gIntro.o: ../Sources/gIntro.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/gIntro.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/gIntro.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/gMenu.o: ../Sources/gMenu.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/gMenu.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/gMenu.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/gObject.o: ../Sources/gObject.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/gObject.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/gObject.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/iCpu.o: ../Sources/iCpu.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/iCpu.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/iCpu.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/iDio.o: ../Sources/iDio.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/iDio.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/iDio.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/iPit.o: ../Sources/iPit.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/iPit.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/iPit.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/mBlinkLed.o: ../Sources/mBlinkLed.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/mBlinkLed.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/mBlinkLed.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/mCpu.o: ../Sources/mCpu.c
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/mCpu.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/mCpu.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/mDelays.o: ../Sources/mDelays.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/mDelays.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/mDelays.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/mLcd.o: ../Sources/mLcd.c
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/mLcd.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/mLcd.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/mLeds.o: ../Sources/mLeds.c
	@echo 'Building file: $<'
	@echo 'Executing target #13 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/mLeds.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/mLeds.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/mSwitch.o: ../Sources/mSwitch.c
	@echo 'Building file: $<'
	@echo 'Executing target #14 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/mSwitch.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/mSwitch.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/main.o: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #15 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/main.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/main.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/sa_mtb.o: ../Sources/sa_mtb.c
	@echo 'Building file: $<'
	@echo 'Executing target #16 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/sa_mtb.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/sa_mtb.o"
	@echo 'Finished building: $<'
	@echo ' '


