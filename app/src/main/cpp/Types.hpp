//
// Created by lion on 17-6-21.
//

#ifndef _PACKT_TYPE_HPP_
#define _PACKT_TYPE_HPP_

#include <cstdint>
#include <cstdlib>

typedef int32_t status;

const status STATUS_OK = 0;
const status STATUS_KO = -1;
const status STATUS_EXIT = -2;

struct Location {
    Location() : x(0.0f), y(0.0f) {};

    float x;
    float y;
};

#define RAND(pMax) (float(pMax) * float(rand())/float(RAND_MAX))

#endif