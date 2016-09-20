#ifndef RINGBUFFER_H
#define RINGBUFFER_H
//------------------------------------------------------------------------------------
#include <stdbool.h>
//------------------------------------------------------------------------------------
// #include "RingBuffer.h"
//------------------------------------------------------------------------------------
// http://chipenable.ru/index.php/programming-avr/item/44-uchebnyy-kurs-organizatsiya-obmena-po-usart-u-s-ispolzovaniem-koltsevogo-bufera.html

// Простая реализация кольцевого буфера включает в себя массив и три дополнительные переменные
// - указатель головы буфера
// - указатель хвоста буфера
// - счетчик символов, содержащихся в массиве
//------------------------------------------------------------------------------------
#define SIZE_BUF 8

//------------------------------------------------------------------------------------
// кольцевой (циклический) буфер
struct RingBuffer {
    unsigned char tail;                     // "указатель" хвоста буфера
    unsigned char head;                     // "указатель" головы буфера
    unsigned char count;                    // счетчик символов

    //unsigned char cycleBuf[SIZE_BUF];

    unsigned char *cycleBuffer;             // Указатель на массив буфера

    int bufferLength;                       // размер буфера
};
//------------------------------------------------------------------------------------
// "очищает" буфер, без зануления
void flushRingBuffer(struct RingBuffer *buffer)
{
    buffer->tail = 0;
    buffer->head = 0;
    buffer->count = 0;
}
//------------------------------------------------------------------------------------
//
struct RingBuffer createRingBuffer(unsigned char *cycleBuffer, int length)
{
    struct RingBuffer ringBuffer = {0, 0, 0, cycleBuffer, length};

    flushRingBuffer(&ringBuffer);

    return ringBuffer;
}
//------------------------------------------------------------------------------------
// положить символ в буфер
void putCharToRingBuffer(struct RingBuffer *buffer, unsigned char sym)
{
    if (buffer->count < SIZE_BUF)                   // если в буфере еще есть место
    {
        buffer->cycleBuffer[buffer->tail] = sym;    // помещаем в него символ
        buffer->count++;                            // инкрементируем счетчик символов
        buffer->tail++;                             // и индекс хвоста буфера

        if (buffer->tail == SIZE_BUF)
            buffer->tail = 0;
    }
}
//------------------------------------------------------------------------------------
// взять символ из буфера
unsigned char getCharFromRingBuffer(struct RingBuffer *buffer)
{
    unsigned char sym = 0;

    if (buffer->count > 0)                          // если буфер не пустой
    {
        sym = buffer->cycleBuffer[buffer->head];    // считываем символ из буфера
        buffer->count--;                            // уменьшаем счетчик символов
        buffer->head++;                             // инкрементируем индекс головы буфера

        if (buffer->head == SIZE_BUF)
            buffer->head = 0;
    }

    return sym;
}
//------------------------------------------------------------------------------------
#endif // RINGBUFFER_H
