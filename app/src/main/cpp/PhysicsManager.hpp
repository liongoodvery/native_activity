//
// Created by lion on 17-6-22.
//

#ifndef NATIVEACTIVITY_PHYSICSMANAGER_HPP
#define NATIVEACTIVITY_PHYSICSMANAGER_HPP

#include "Types.hpp"
#include "TimeManager.hpp"
#include "GraphicsManager.hpp"

struct PhysicsBody {
    PhysicsBody(Location* pLocation, int32_t pWidth, int32_t pHeight) :
            location(pLocation),
            width(pWidth), height(pHeight),
            velocityX(0.0f), velocityY(0.0f) {
    }

    Location* location;
    int32_t width;
    int32_t height;
    float velocityX;
    float velocityY;

};

class PhysicsManager {

public:
    PhysicsManager(TimeManager& pTimeManager,
            GraphicsManager& pGraphicsManager);

    ~PhysicsManager();

    PhysicsBody* loadBody(Location& pLocation, int32_t pWidth,
            int32_t pHeight);

    void update();

private:
    PhysicsManager(const PhysicsManager&);

    void operator=(const PhysicsManager&);

    TimeManager& mTimeManager;
    GraphicsManager& mGraphicsManager;

    PhysicsBody* mPhysicsBodies[1024];
    int32_t mPhysicsBodyCount;

};


#endif //NATIVEACTIVITY_PHYSICSMANAGER_HPP
