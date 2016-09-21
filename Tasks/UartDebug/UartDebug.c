#include "UartDebug.h"

//------------------------------------------------------------------------------------
//!
void StartUartDebugTask(void const * argument)
{
    (void) argument;

    // turn off buffers, so IO occurs immediately
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    const char *testMessage = "------------------\r\n"
                              "   Start debug\r\n"
                              "------------------\r\n";

    HAL_UART_Transmit(&huart1, testMessage, sizeof (testMessage), 100);

    for(;;)
    {

        //if(strlen(transmitBuffer) > (LOG_BUFFER_SIZE-(LOG_BUFFER_SIZE/2)))
        //{
            HAL_UART_Transmit(&huart1,(uint8_t *)&transmitBuffer, sizeof(transmitBuffer), 100);

            //fprintf(stdout, &transmitBuffer);
            //fflush(stdout);
            memset(transmitBuffer, 0, sizeof(transmitBuffer));
        //}

        osDelay(100);
    }
}
//------------------------------------------------------------------------------------
//!
void sendToLog(const char *buffer)
{
    char tickCount[20];

    // отсутствуют в линукс версии компилятора
    itoa(xTaskGetTickCount(), tickCount, 10);
    //utoa_builtin_div(HAL_GetTick(), tickCount);

    strcat(transmitBuffer, tickCount);
    strcat(transmitBuffer, " : ");
    strcat(transmitBuffer, buffer);
    strcat(transmitBuffer, "\r\n");

}
//------------------------------------------------------------------------------------
//!
