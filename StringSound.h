// Copyright [2021] <Gabriel Vega>
#ifndef _HOME_GABRIEL_DESKTOP_COMP4_HW_PS4B_STRINGSOUND_H_
#define _HOME_GABRIEL_DESKTOP_COMP4_HW_PS4B_STRINGSOUND_H_

#include "CircularBuffer.h"
#include <vector>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

using std::vector;

class StringSound{
 public:
    explicit StringSound(double frequency);
    explicit StringSound(vector<sf::Int16> init);
    StringSound(const StringSound &obj) {}

    ~StringSound(void);

    void pluck(void);
    void tic(void);
    sf::Int16 sample(void);
    int time(void);

 private:
    circularBuffer* cb;
    int _time;
};

#endif  // _HOME_GABRIEL_DESKTOP_COMP4_HW_PS4B_STRINGSOUND_H_
