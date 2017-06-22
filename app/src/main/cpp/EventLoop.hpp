//
// Created by lion on 17-6-21.
//


#ifndef NATIVEACTIVITY_EVENTLOOP_H
#define NATIVEACTIVITY_EVENTLOOP_H

#include <android_native_app_glue.h>
#include "ActivityHandler.hpp"

class EventLoop {
public:
    EventLoop(android_app *pApplication,
            ActivityHandler &pActivityHandler);

    void run();

private:
    void activate();

    void deactivate();

    void processAppEvent(int32_t pCommand);

    static void callback_appEnvnt(android_app *pApplication, int32_t pCommand);

private:
    android_app *mApplication;
    bool mEnabled;
    bool mQuit;
    ActivityHandler &mActivityHandler;
};

#endif //NATIVEACTIVITY_EVENTLOOP_H
