//
// Created by lion on 17-6-21.
//
#include "Types.hpp"
#ifndef NATIVEACTIVITY_ACTIVITYHANDLER_H
#define NATIVEACTIVITY_ACTIVITYHANDLER_H


class ActivityHandler {
public:
    virtual ~ActivityHandler() {};

    virtual status onActivate() = 0;
    virtual void onDeactivate() = 0;
    virtual status onStep() = 0;

    virtual void onStart() {};
    virtual void onResume() {};
    virtual void onPause() {};
    virtual void onStop() {};
    virtual void onDestroy() {};

    virtual void onSaveInstanceState(void** pData, size_t* pSize) {};
    virtual void onConfigurationChanged() {};
    virtual void onLowMemory() {};

    virtual void onCreateWindow() {};
    virtual void onDestroyWindow() {};
    virtual void onGainFocus() {};
    virtual void onLostFocus() {};
};

#endif //NATIVEACTIVITY_ACTIVITYHANDLER_H
