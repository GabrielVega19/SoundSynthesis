// Copyright [2021] <Gabriel Vega>
#include "CircularBuffer.h"
#include <iostream>
#include <algorithm>
using std::cout;
using std::endl;
using std::make_shared;
using std::invalid_argument;
using std::runtime_error;
circularBuffer::circularBuffer(int initCapacity):
data(new int16_t[initCapacity]), capacity(initCapacity), Size(0) {
    if (initCapacity < 1) {
        throw invalid_argument
        ("CircularBuffer constructor: capacity must be greater than zero");
    }
    for (int i = 0; i < capacity; ++i) {
        data[i] = 0;
    }
}

circularBuffer::~circularBuffer(void) {
    delete data;
    data = nullptr;
}

int circularBuffer::size(void) {
    return Size;
}

bool circularBuffer::isEmpty(void) {
    if (this->size() == 0) {
        return true;
    }
    return false;
}

bool circularBuffer::isFull(void) {
    if (this->size() == capacity) {
        return true;
    }
    return false;
}

void circularBuffer::enqueue(int16_t x) {
    if (Size < capacity) {
        data[Size] = x;
        Size++;
    } else {
        throw runtime_error("enqueue: can't enqueue to a full ring.");
    }
}

int16_t circularBuffer::dequeue(void) {
    if (this->isEmpty()) {
        throw runtime_error("Tried to dequeue an empty ring");
    }

    int16_t r = data[0];

    for (int i = 0; i < capacity - 1; ++i) {
        data[i] = data[i + 1];
    }
    data[capacity - 1] = 0;
    Size--;

    return r;
}

int16_t circularBuffer::peek(void) {
    if (this->isEmpty()) {
        throw runtime_error("Tried to peek an empty ring");
    }
    return data[0];
}
