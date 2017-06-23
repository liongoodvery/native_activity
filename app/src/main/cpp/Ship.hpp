//
// Created by lion on 17-6-22.
//

#ifndef NATIVEACTIVITY_SHIP_HPP
#define NATIVEACTIVITY_SHIP_HPP

#include "GraphicsManager.hpp"
class Ship {
public:
    Ship(android_app* pApplication, GraphicsManager& graphicsManager);

    void registerShip(GraphicsElement* pGraphics);

    void initialize();

private:
    Ship(const Ship&);
    void operator=(const Ship&);

    GraphicsManager& mGraphicsManager;

    GraphicsElement* mGraphics;
};


#endif //NATIVEACTIVITY_SHIP_HPP
