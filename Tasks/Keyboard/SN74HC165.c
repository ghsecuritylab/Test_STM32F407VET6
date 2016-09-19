#include "SN74HC165.h"

//------------------------------------------------------------------------------------
void SN74HC165_readLine(struct SN74HC165_line *line)
{
    // Выставим на защёлке сначала низкий, потом - высокий уровни.
    // Сдвиговый регистр запомнит уровни сигналов на входах и сможет
    // их нам потом отдать бит за битом.
    line->SHLD(0);
    line->SHLD(1);

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

            line->CLK(0);
            line->CLK(1);
        }
    }
}
//------------------------------------------------------------------------------------
bool SN74HC165_state(struct SN74HC165_line *line, int id)
{
    return ((line->lineStorage + (id/8))->value) & (1<<(id%8));
}
//------------------------------------------------------------------------------------
