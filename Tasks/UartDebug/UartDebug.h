#ifndef BLINKLEDTASK_H
#define BLINKLEDTASK_H
//------------------------------------------------------------------------------------
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "stm32f4xx_hal.h"
#include "cmsis_os.h"

#include "usart.h"

//------------------------------------------------------------------------------------

#define LOG_BUFFER_SIZE 400

//char LogBuffer[LOG_BUFFER_SIZE];

uint8_t transmitBuffer[LOG_BUFFER_SIZE];

//------------------------------------------------------------------------------------
typedef struct {
        uint8_t usart;
        uint8_t byte;
} myMes;
//------------------------------------------------------------------------------------
//!
void StartUartDebugTask(void const * argument);


void sendToLog(const char *buffer);


//------------------------------------------------------------------------------------
#endif // BLINKLEDTASK_H
