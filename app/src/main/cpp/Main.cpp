//
// Created by lion on 17-6-21.
//
#include "EventLoop.hpp"
#include "DroidBlaster.hpp"

void android_main(android_app* pApplication) {
    DroidBlaster(pApplication).run();
}