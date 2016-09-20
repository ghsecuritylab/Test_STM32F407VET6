#include "int2str.h"

//------------------------------------------------------------------------------------
char *itoa(int number, char *destination, int base) 
{
  int count = 0;
  do {
    int digit = number % base;
    destination[count++] = (digit > 9) ? digit - 10 +'A' : digit + '0';
  } while ((number /= base) != 0);
  destination[count] = '\0';
  int i;
  for (i = 0; i < count / 2; ++i) {
    char symbol = destination[i];
    destination[i] = destination[count - i - 1];
    destination[count - i - 1] = symbol;
  }
  return destination;
}
//------------------------------------------------------------------------------------
char * utoa_builtin_div(uint32_t value, char *buffer)
{
   buffer += 11;
// 11 байт достаточно для десятичного представления 32-х байтного числа
// и  завершающего нуля
   *--buffer = 0;
   do
   {
      *--buffer = value % 10 + '0';
      value /= 10;
   }
   while (value != 0);
   return buffer;
}
//------------------------------------------------------------------------------------
char * utoa_fast_div(uint32_t value, char *buffer)
{
    buffer += 11;
    *--buffer = 0;
    do
    {
        struct divmod10_t res = divmodu10(value);
        *--buffer = res.rem + '0';
        value = res.quot;
    }
    while (value != 0);
    return buffer;
}
//------------------------------------------------------------------------------------
