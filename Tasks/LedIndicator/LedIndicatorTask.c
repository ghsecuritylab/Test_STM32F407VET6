#include "LedIndicatorTask.h"

//------------------------------------------------------------------------------------
//!
void StartLedIndicatorTask(void const * argument)
{    
    (void) argument;
//    GPIO_InitTypeDef GPIO_InitStruct;

//    /*Configure GPIO pin : PA3 */
//    GPIO_InitStruct.Pin = GPIO_PIN_3;
//    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
//    GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
//    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    const char *testMessage="LedIndicator";

    for(;;)
    {
//        HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,GPIO_PIN_RESET);
//        osDelay(500);
//        HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,GPIO_PIN_SET);
//        osDelay(500);

        //fprintf(stdout, "Это тест %d %f  fprintf(stdout, ", 10, 20.01);

        sendToLog(testMessage);
        osDelay(200);

        //-----------------------------------------------------
//        HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_15);
//        osDelay(200);
    }
}
//------------------------------------------------------------------------------------
//!
