#ifndef LEDBOARD_H
#define LEDBOARD_H
//------------------------------------------------------------------------------------
#include "stm32f4xx_hal.h"
#include "cmsis_os.h"

#include "gpio.h"

#include "UartDebug.h"
#include "SN74HC165.h"
//------------------------------------------------------------------------------------
//! Колличество микросхем на линии
#define KeyboardNumberOf74HC165  3

//------------------------------------------------------------------------------------
// Описание кнопок клавиатуры
enum KeybName {
    Keyb1   = 1,      // 1
    Keyb2   = 2,      // 2
    Keyb3   = 3,      // 3
    Keyb4   = 4,      // 4
    Keyb5   = 5,      // 5
    Keyb6   = 6,      // 6
    Keyb7   = 7,      // 7
    Keyb8   = 8,      // 8

    Keyb9   = 9,      // 9
    Keyb10  = 10,     // 10
    Keyb11  = 11,     // 11
    Keyb12  = 12,     // 12
    Keyb13  = 13,     // 13
    Keyb14  = 14,     // 14
    Keyb15  = 15,     // 15
    Keyb16  = 16,     // 16

    Keyb17  = 17,     // 17
    Keyb18  = 18,     // 18
    Keyb19  = 19,     // 19
    Keyb20  = 20,     // 20
    Keyb21  = 21,     // 21
    Keyb22  = 22,     // 22
    Keyb23  = 23,     // 23
    Keyb24  = 24,     // 24
};
//------------------------------------------------------------------------------------
//! Подключение пинов анализатора клавиатуры
void KEYB_SCLR(bool bit)    { HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, (bit) ? GPIO_PIN_SET : GPIO_PIN_RESET); }
void KEYB_CLK(bool bit)     { HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, (bit) ? GPIO_PIN_SET : GPIO_PIN_RESET); }
bool KEYB_QH(void)          { return (HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_10) == GPIO_PIN_SET) ? true : false; }
//------------------------------------------------------------------------------------

volatile char msg [100];

//------------------------------------------------------------------------------------
union SN74HC165_device KeyboardStorage[KeyboardNumberOf74HC165];
//! Экземпляр объекта клавиатуры
struct SN74HC165_line KeyboardLine = { KEYB_SCLR, KEYB_CLK, KEYB_QH, &KeyboardStorage, KeyboardNumberOf74HC165};
//------------------------------------------------------------------------------------
//osThreadId ledBoardHandle;

//void CreateKeyboardTask(void);

void StartKeyboardTask(void const * argument);

//void SN74HC165_readLine(struct SN74HC165_line *line);
//bool SN74HC165_state(struct SN74HC165_line *line, int id);
//------------------------------------------------------------------------------------
#endif // LEDBOARD_H
