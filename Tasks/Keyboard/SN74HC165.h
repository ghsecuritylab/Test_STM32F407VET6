#ifndef SN74HC165_H
#define SN74HC165_H
//------------------------------------------------------------------------------------
#include <stdbool.h>
//------------------------------------------------------------------------------------
// #include "SN74HC165.h"
//------------------------------------------------------------------------------------
/*
enum KeybName {
    Keyb1 = 0b00000001,
    Keyb2 = 0b00000010,
    Keyb3 = 0b00000100,
    Keyb4 = 0b00001000,
    Keyb5 = 0b00010000,
    Keyb6 = 0b00100000,
    Keyb7 = 0b01000000,
    Keyb8 = 0b10000000,
};
*/
//------------------------------------------------------------------------------------
union SN74HC165_device {
    unsigned char value;

    struct byte {
        unsigned Q0: 1;
        unsigned Q1: 1;
        unsigned Q2: 1;
        unsigned Q3: 1;
        unsigned Q4: 1;
        unsigned Q5: 1;
        unsigned Q6: 1;
        unsigned Q7: 1;
    } pin;
};
//------------------------------------------------------------------------------------
union SN74HC165_device SN74HC165_createDevice()
{
    union SN74HC165_device device;
    device.value = 0;
    return device;
}
//------------------------------------------------------------------------------------
//void KEYB_SCLR(bool bit) { HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, (bit) ? GPIO_PIN_SET : GPIO_PIN_RESET); }
//void KEYB_CLK(bool bit)  { HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, (bit) ? GPIO_PIN_SET : GPIO_PIN_RESET); }
//bool KEYB_QH(void)       { return (HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_10) == GPIO_PIN_SET) ? true : false; }
//------------------------------------------------------------------------------------
// http://robocraft.ru/blog/arduino/520.html
struct SN74HC165_line
{
    // [1] - SHLD - защёлка, SS (SPI)
    // Вход SH/L͞D (сдвиг/загрузка) управляет занесением состояний входов в триггеры — так называемой параллельной загрузкой:
    // стоит прижать его к «земле», как состояние входов регистра будет подано на S-входы триггеров.
    // Чтобы отключить триггеры от входов регистра и иметь возможность читать из регистра, нужно установить SH/L͞D в 1
    void (*SHLD)(bool);

    // [2] - CLK — тактовый вход, SCLK (SPI)
    // Тактирование происходит при переходе CLK из 0 в 1 при условии, что SH/L͞D = 1 (параллельная загрузка отключена),
    // а CLK INH = 0 (тактирование включено). При каждом «тике» CLK каждый триггер проталкивает бит в следующий триггер,
    // захватывая бит со своего 1D-входа. Так как к 1D-входу первого триггера подключен вход SER,
    // то подаваемые на него биты проталкиваются в регистр, позволяя соединять регистры в цепочки.
    // В конечном итоге проталкиваемые биты достигают выхода последнего регистра,
    // где подаются сразу на два вывода — на QH и, через инвертор, на Q͞H.
    void (*CLK)(bool);

    // [9] - QH — последовательный вывод, MISO (SPI)
    // [7] - ~Q͞H — инверсный вывод, на нём идут биты с QH, но инвертированные
    bool (*QH)(void);

    union SN74HC165_device *lineStorage;

    int storageLenght;
};
//------------------------------------------------------------------------------------
inline void SN74HC165_readLine(struct SN74HC165_line *line)
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
inline bool SN74HC165_state(struct SN74HC165_line *line, int id)
{
    return ((line->lineStorage + (id/8))->value) & (1<<(id%8));
}
//------------------------------------------------------------------------------------
#endif // SN74HC165_H
