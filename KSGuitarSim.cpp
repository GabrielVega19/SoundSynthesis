/*
  Copyright 2015 Fred Martin, 
  Y. Rykalova, 2020
*/

#include "CircularBuffer.h"
#include "StringSound.h"

#include <math.h>
#include <limits.h>

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#define CONCERT_A 220.0
#define SAMPLES_PER_SEC 44100

using std::string;
using std::cout;

vector<sf::Int16> makeSamples(StringSound* gs) {
    std::vector<sf::Int16> samples;

    gs->pluck();
    for (int i = 0; i < 44100 * 8; ++i) {
        gs->tic();
        samples.push_back(gs->sample());
    }

    return samples;
}

int main() {
    sf::RenderWindow window(sf::VideoMode(300, 200),
    "SFML Plucked String Sound Lite");
    string keys = "q2we4r5ty7u8i9op-[=zxdcfvgbnjmk,.;/' ";
    vector<sf::Int16> samples[37];
    sf::Sound sound[37];
    sf::SoundBuffer buf[37];
    sf::Event event;

    for (int i = 0; i < 37; i++) {
        StringSound gs(440 * pow(2.0, (i - 24) / 12.0));
        samples[i] = makeSamples(&gs);
        buf[i].loadFromSamples(&samples[i][0], samples[i].size(), 2, 44100);
        sound[i].setBuffer(buf[i]);
    }

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::TextEntered) {
                int i = keys.find(event.text.unicode);
                if (i >= 0 && i <= 36) {
                    sound[i].play();
                }
            }
        }
    }
    return 0;
}
