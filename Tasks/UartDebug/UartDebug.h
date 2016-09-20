#ifndef UARTDEBUGTASK_H
#define UARTDEBUGTASK_H
//------------------------------------------------------------------------------------
// Возможно прийдется закоментировать
#include <stdlib.h>

#include <stdio.h>
#include <string.h>

#include "stm32f4xx_hal.h"
#include "cmsis_os.h"

#include "usart.h"

#include "int2str.h"
//------------------------------------------------------------------------------------

#define LOG_BUFFER_SIZE 400

//char LogBuffer[LOG_BUFFER_SIZE];

char transmitBuffer[LOG_BUFFER_SIZE];

//------------------------------------------------------------------------------------
//typedef struct {
//        uint8_t usart;
//        uint8_t byte;
//} myMes;
//------------------------------------------------------------------------------------
//!
void StartUartDebugTask(void const * argument);


void sendToLog(const char *buffer);


//------------------------------------------------------------------------------------
#endif // UARTDEBUGTASK_H
