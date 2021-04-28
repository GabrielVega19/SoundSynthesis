// Copyright [2021] <Gabriel Vega>
#include "StringSound.h"
#include "CircularBuffer.h"
#include <cmath>
#include <random>
#include <iostream>
#include <limits>

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int16_t> dist(std::numeric_limits<int16_t>::min(),
std::numeric_limits<int16_t>::max());

void StringSound::pluck(void) {
    while (!cb->isEmpty()) {
        cb->dequeue();
    }

    while (!cb->isFull()) {
        cb->enqueue(dist(gen));
    }
}
StringSound::StringSound(double frequency): _time(0) {
    if (110 > frequency  || frequency > 880) {
        throw std::invalid_argument
        ("invalid frequency passed to stringsound constructor");
    }
    cb = new circularBuffer(ceil(44100 / frequency));
}
StringSound::StringSound(vector<sf::Int16> init): _time(0) {
    if (init.size() == 0) {
        throw std::invalid_argument
        ("invalid vector passed to stringsound constructor");
    }
    cb = new circularBuffer(init.size());
    for (int i = 0; i < cb->size(); ++i) {
        cb->enqueue(init[i]);
    }
}
StringSound::~StringSound(void) {
    cb->~circularBuffer();

    delete cb;
    cb = nullptr;
    _time = 0;
}
int StringSound::time(void) {
    return _time;
}
sf::Int16 StringSound::sample(void) {
    return cb->peek();
}
void StringSound::tic(void) {
    int16_t x = cb->dequeue();
    int16_t y = cb->peek();

    cb->enqueue((x + y) * .5 * .996);

    _time++;
}
