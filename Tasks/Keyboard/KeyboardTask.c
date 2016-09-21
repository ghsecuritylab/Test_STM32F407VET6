#include "KeyboardTask.h"
////------------------------------------------------------------------------------------
////!
//void CreateLedBoardTask(void)
//{
//    osThreadDef(LedBoardTask, StartLedBoardTask, osPriorityNormal, 0, 128);
//    ledBoardHandle = osThreadCreate(osThread(LedBoardTask), NULL);
//}
//------------------------------------------------------------------------------------
//!
void StartKeyboardTask(void const * argument)
{    
    (void) argument;
    //const char *testMessage="KeyboardTask";

    for(;;)
    {
        SN74HC165_readLine( &KeyboardLine );

        memset(msg, 0, sizeof(msg));

        strcat(msg, "KeyboardTask : ");

        for(int i = 0; i < 24; ++i)
        {
            if(i%8 == 0)
                strcat(msg, " ");

            strcat(msg, ((SN74HC165_state(&KeyboardLine, i)) ? "1" : "0"));
        }

        sendToLog( msg );

        osDelay(200);
        //taskYIELD();
    }
}
//------------------------------------------------------------------------------------
/*
void SN74HC165_readLine(struct SN74HC165_line *line)
{
    // Выставим на защёлке сначала низкий, потом - высокий уровни.
    // Сдвиговый регистр запомнит уровни сигналов на входах и сможет
    // их нам потом отдать бит за битом.
    line->SHLD(LOW);
    line->SHLD(HIGH);

    union SN74HC165_device *device;

    // перебрать устройства на линии
    //for(int deviceId = 0; deviceId < line->storageLenght; ++deviceId)
    for(int deviceId = (line->storageLenght-1); deviceId >= 0; --deviceId)
    {
        // выбрать устройство
        device = line->lineStorage + deviceId;

        // перебор битов устройства
        //for(int bitId = 0; bitId < 8; ++bitId)
        for(int bitId = (8-1); bitId >= 0; --bitId)
        {
            if( line->QH() )
            {
                device->value |= (1<<bitId);
            } else {
                device->value &= (~(1<<bitId));
            }

            line->CLK(LOW);
            line->CLK(HIGH);
        }

        volatile union SN74HC165_device dc;
        dc.value = device->value;
    }
}
//------------------------------------------------------------------------------------
bool SN74HC165_state(struct SN74HC165_line *line, int id)
{
    //union SN74HC165_device *device = (line->lineStorage + (id%8));
    return ((line->lineStorage + (id/8))->value) & (1<<(id%8));
}
//------------------------------------------------------------------------------------
*/
