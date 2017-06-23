#ifndef _PACKT_DROIDBLASTER_HPP_
#define _PACKT_DROIDBLASTER_HPP_

#include "ActivityHandler.hpp"
#include "EventLoop.hpp"
#include "Types.hpp"
#include "GraphicsManager.hpp"
#include "Ship.hpp"
#include "Asteroid.hpp"
#include "PhysicsManager.hpp"
#include "TimeManager.hpp"

class DroidBlaster : public ActivityHandler {
public:
    DroidBlaster(android_app* pApplication);

    void run();

protected:
    status onActivate();

    void onDeactivate();

    status onStep();

    void onStart();

    void onResume();

    void onPause();

    void onStop();

    void onDestroy();

    void onSaveInstanceState(void** pData, size_t* pSize);

    void onConfigurationChanged();

    void onLowMemory();

    void onCreateWindow();

    void onDestroyWindow();

    void onGainFocus();

    void onLostFocus();

private:
    DroidBlaster(const DroidBlaster&);

    void operator=(const DroidBlaster&);

    TimeManager mTimeManager;
    GraphicsManager mGraphicsManager;
    PhysicsManager mPhysicsManager;
    Asteroid mAsteroids;
    Ship mShip;
    EventLoop mEventLoop;
};

#endif
