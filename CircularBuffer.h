// Copyright [2021] <Gabriel Vega>

#ifndef _HOME_GABRIEL_DESKTOP_COMP4_HW_PS4B_CIRCULARBUFFER_H_
#define _HOME_GABRIEL_DESKTOP_COMP4_HW_PS4B_CIRCULARBUFFER_H_
#include <stdint.h>
#include <memory>
#include <iostream>

using std::cout;
using std::endl;

class circularBuffer{
 public:
    explicit circularBuffer(int initCapacity);
    ~circularBuffer(void);

    int size(void);
    bool isEmpty(void);
    bool isFull(void);
    void enqueue(int16_t x);
    int16_t dequeue(void);
    int16_t peek(void);

 private:
    int16_t* data;
    int capacity;
    int Size;
};
#endif  // _HOME_GABRIEL_DESKTOP_COMP4_HW_PS4B_CIRCULARBUFFER_H_
