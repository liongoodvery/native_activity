//
// Created by lion on 17-6-22.
//

#ifndef NATIVEACTIVITY_GRAPHICSMANAGER_HPP
#define NATIVEACTIVITY_GRAPHICSMANAGER_HPP


#include "Types.hpp"

class GraphicsManager {

};

struct GraphicsElement {

    GraphicsElement(int32_t pwidth, int32_t pheight) :
            location(), width(pwidth), height(pheight) {}

    Location location;
    int32_t width;
    int32_t height;
};

#endif //NATIVEACTIVITY_GRAPHICSMANAGER_HPP
