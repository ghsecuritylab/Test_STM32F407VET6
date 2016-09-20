#ifndef INT2STR_H
#define INT2STR_H
//------------------------------------------------------------------------------------
//#include <stdint.h>
#include <stdint-gcc.h>

//------------------------------------------------------------------------------------
// http://we.easyelectronics.ru/Soft/preobrazuem-v-stroku-chast-1-celye-chisla.html
//------------------------------------------------------------------------------------
// #include "int2str.h"
//------------------------------------------------------------------------------------
char *itoa(int number, char *destination, int base);

// самая быстрая по тестам на stm32f4
char * utoa_builtin_div(uint32_t value, char *buffer);
//------------------------------------------------------------------------------------
struct divmod10_t
{
    uint32_t quot;
    uint8_t rem;
};

inline static struct divmod10_t divmodu10(uint32_t n)
{
    struct divmod10_t res;
// умножаем на 0.8
    res.quot = n >> 1;
    res.quot += res.quot >> 1;
    res.quot += res.quot >> 4;
    res.quot += res.quot >> 8;
    res.quot += res.quot >> 16;
    uint32_t qq = res.quot;
    (void) qq;
// делим на 8
    res.quot >>= 3;
// вычисляем остаток
    //res.rem = uint8_t(n - ( (res.quot << 1) + (qq & ~7ul) ) );
    res.rem = (uint8_t)(n - ( (res.quot << 1) + (qq & ~7ul) ) );
// корректируем остаток и частное
    if(res.rem > 9)
    {
        res.rem -= 10;
        res.quot++;
    }
    return res;
}

// самая быстрая по тестам на остальных
char * utoa_fast_div(uint32_t value, char *buffer);
//------------------------------------------------------------------------------------
#endif // INT2STR_H
