#ifndef KEYBOARD_H
#define KEYBOARD_H
//------------------------------------------------------------------------------------
#include <stdbool.h>
#include <stdio.h>

#include "SN74HC165.h"
//------------------------------------------------------------------------------------
// #include "keyboard.h"
//------------------------------------------------------------------------------------
enum KeybName {
    Keyb1   = 0b00000001,                   // 1
    Keyb2   = 0b00000010,                   // 2
    Keyb3   = 0b00000100,                   // 3
    Keyb4   = 0b00001000,                   // 4
    Keyb5   = 0b00010000,                   // 5
    Keyb6   = 0b00100000,                   // 6
    Keyb7   = 0b01000000,                   // 7
    Keyb8   = 0b10000000,                   // 8

    Keyb9   = 0b00000001 + 0b100000000,     // 9
    Keyb10  = 0b00000010 + 0b100000000,     // 10
    Keyb11  = 0b00000100 + 0b100000000,     // 11
    Keyb12  = 0b00001000 + 0b100000000,     // 12
    Keyb13  = 0b00010000 + 0b100000000,     // 13
    Keyb14  = 0b00100000 + 0b100000000,     // 14
    Keyb15  = 0b01000000 + 0b100000000,     // 15
    Keyb16  = 0b10000000 + 0b100000000,     // 16
};
//------------------------------------------------------------------------------------
#define DEBUG
//------------------------------------------------------------------------------------
//An output pin can also be set using the integrated HAL library function
///* set PA0 */
//HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
///* reset PA0 */
//HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
///* read PC13 */
//if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13))
//{
///* user code */
//}
//------------------------------------------------------------------------------------
void KEYB_SCLR(bool)
{
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
}
//------------------------------------------------------------------------------------
void KEYB_CLK(bool)
{
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
}
//------------------------------------------------------------------------------------
bool KEYB_QH(void)
{
    return HIGH;
}
//------------------------------------------------------------------------------------
//void KEYB_SCLR(bool bit)    { printf("KEYB_SCLR - %d \n", bit); }
//void KEYB_CLK(bool bit)     { printf("KEYB_CLK - %d \n", bit); }
//bool KEYB_QH(void)          {
//                                printf("KEYB_QH return X\n");
//                                return HIGH;
//                            }
//------------------------------------------------------------------------------------
void SN74HC165_TEST( void )
{
    printf("SN74HC165_TEST\n");

    union SN74HC165_device device = SN74HC165_createDevice();

    device.value = Keyb6;

    printf("\n");

    static const int NumberOfDevice = 4;

    union SN74HC165_device lineStorage[NumberOfDevice];

    struct SN74HC165_line keybLine = SN74HC165_createLine(KEYB_SCLR, KEYB_CLK, KEYB_QH, lineStorage);

    keybLine.lineStorage[0].value = 0b10000111;
    keybLine.lineStorage[1].value = 0b01000000;
    keybLine.lineStorage[2].value = 0b00100000;
    keybLine.lineStorage[3].value = 0b00010000;

    //SN74HC165_readLine( &keybLine );

    printf("\n");

    //SN74HC165_printStateLine( &keybLine );

    printf("\n");

    printf("SN74HC165_state 0 : %d \n", (int)SN74HC165_state(&keybLine, 0));
    printf("SN74HC165_state 1 : %d \n", (int)SN74HC165_state(&keybLine, 1));
    printf("SN74HC165_state 2 : %d \n", (int)SN74HC165_state(&keybLine, 2));
    printf("SN74HC165_state 3 : %d \n", (int)SN74HC165_state(&keybLine, 3));
    printf("SN74HC165_state 4 : %d \n", (int)SN74HC165_state(&keybLine, 4));
    printf("SN74HC165_state 5 : %d \n", (int)SN74HC165_state(&keybLine, 5));
    printf("SN74HC165_state 6 : %d \n", (int)SN74HC165_state(&keybLine, 6));
    printf("SN74HC165_state 7 : %d \n", (int)SN74HC165_state(&keybLine, 7));


    printf("SN74HC165_state 13 : %d \n", (int)SN74HC165_state(&keybLine, Keyb13));
    printf("SN74HC165_state 14 : %d \n", (int)SN74HC165_state(&keybLine, Keyb14));
    printf("SN74HC165_state 15 : %d \n", (int)SN74HC165_state(&keybLine, Keyb15));


    return;
}
//------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------
#endif // KEYBOARD_H
