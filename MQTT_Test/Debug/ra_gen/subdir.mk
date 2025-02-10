################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ra_gen/common_data.c \
../ra_gen/hal_data.c \
../ra_gen/main.c \
../ra_gen/main_thread.c \
../ra_gen/pin_data.c \
../ra_gen/vector_data.c 

CREF += \
MQTT_Test.cref 

C_DEPS += \
./ra_gen/common_data.d \
./ra_gen/hal_data.d \
./ra_gen/main.d \
./ra_gen/main_thread.d \
./ra_gen/pin_data.d \
./ra_gen/vector_data.d 

OBJS += \
./ra_gen/common_data.o \
./ra_gen/hal_data.o \
./ra_gen/main.o \
./ra_gen/main_thread.o \
./ra_gen/pin_data.o \
./ra_gen/vector_data.o 

MAP += \
MQTT_Test.map 


# Each subdirectory must supply rules for building sources it contributes
ra_gen/%.o: ../ra_gen/%.c
	@echo 'Building file: $<'
	$(file > $@.in,-mcpu=cortex-m33 -mthumb -mlittle-endian -mfloat-abi=hard -mfpu=fpv5-sp-d16 -O2 -ffunction-sections -fdata-sections -fno-strict-aliasing -fmessage-length=0 -funsigned-char -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Waggregate-return -Wno-parentheses-equality -Wfloat-equal -g3 -std=c99 -fshort-enums -fno-unroll-loops -I"D:\\e2_studio\\workspace\\MQTT_Test\\src" -I"." -I"D:\\e2_studio\\workspace\\MQTT_Test\\ra\\fsp\\inc" -I"D:\\e2_studio\\workspace\\MQTT_Test\\ra\\fsp\\inc\\api" -I"D:\\e2_studio\\workspace\\MQTT_Test\\ra\\fsp\\inc\\instances" -I"D:\\e2_studio\\workspace\\MQTT_Test\\ra\\fsp\\src\\rm_freertos_port" -I"D:\\e2_studio\\workspace\\MQTT_Test\\ra\\aws\\FreeRTOS\\FreeRTOS\\Source\\include" -I"D:\\e2_studio\\workspace\\MQTT_Test\\ra\\arm\\CMSIS_6\\CMSIS\\Core\\Include" -I"D:\\e2_studio\\workspace\\MQTT_Test\\ra_gen" -I"D:\\e2_studio\\workspace\\MQTT_Test\\ra_cfg\\fsp_cfg\\bsp" -I"D:\\e2_studio\\workspace\\MQTT_Test\\ra_cfg\\fsp_cfg" -I"D:\\e2_studio\\workspace\\MQTT_Test\\ra_cfg\\aws" -I"D:\\e2_studio\\workspace\\MQTT_Test\\ra\\fsp\\src\\rm_wifi_da16xxx" -I"D:\\e2_studio\\workspace\\MQTT_Test\\ra\\fsp\\src\\rm_at_transport_da16xxx_uart" -I"D:\\e2_studio\\workspace\\MQTT_Test\\ra\\fsp\\src\\rm_mqtt_onchip_da16xxx" -D_RENESAS_RA_ -D_RA_CORE=CM33 -D_RA_ORDINAL=1 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -x c "$<" -c -o "$@")
	@clang --target=arm-none-eabi @"$@.in"

