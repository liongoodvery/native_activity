//
// Created by lion on 17-6-21.
//

#include "EventLoop.hpp"
#include "Log.hpp"

EventLoop::EventLoop(android_app *pApplication, ActivityHandler &pActivityHandler)
        : mApplication(pApplication),
          mActivityHandler(pActivityHandler),
          mEnabled(false),
          mQuit(false) {
    mApplication->userData = this;
    mApplication->onAppCmd = callback_appEnvnt;
}

void EventLoop::run() {
    int32_t result;
    int32_t events;
    android_poll_source *source;
    app_dummy();

    Log::info("Starting event loop");
    while (true) {
        while ((result = ALooper_pollAll(mEnabled ? 0 : -1, NULL,
                                         &events, (void **) &source)) >= 0) {
            if (source != NULL) {
                Log::info("Processing an event");
                source->process(mApplication, source);
            }

            if (mApplication->destroyRequested) {
                Log::info("Exiting event loop");
                return;
            }
        }
        if ((mEnabled) && (!mQuit)) {
            if (mActivityHandler.onStep() != STATUS_OK) {
                mQuit = true;
                ANativeActivity_finish(mApplication->activity);
            }
        }
    }
}


void EventLoop::activate() {
    // Enables activity only if a window is available.
    if ((!mEnabled) && (mApplication->window != NULL)) {
        mQuit = false;
        mEnabled = true;
        if (mActivityHandler.onActivate() != STATUS_OK) {
            goto ERROR;
        }
    }
    return;

    ERROR:
    mQuit = true;
    deactivate();
    ANativeActivity_finish(mApplication->activity);
}

void EventLoop::deactivate() {
    if (mEnabled) {
        mActivityHandler.onDeactivate();
        mEnabled = false;
    }
}


void EventLoop::callback_appEnvnt(android_app *pApplication, int32_t pCommand) {
    EventLoop &eventLoop = *(EventLoop *) pApplication->userData;
    eventLoop.processAppEvent(pCommand);
}


void EventLoop::processAppEvent(int32_t pCommand) {
    switch (pCommand) {
        case APP_CMD_CONFIG_CHANGED:
            mActivityHandler.onConfigurationChanged();
            break;
        case APP_CMD_INIT_WINDOW:
            mActivityHandler.onCreateWindow();
            break;
        case APP_CMD_DESTROY:
            mActivityHandler.onDestroy();
            break;
        case APP_CMD_GAINED_FOCUS:
            activate();
            mActivityHandler.onGainFocus();
            break;
        case APP_CMD_LOST_FOCUS:
            mActivityHandler.onLostFocus();
            deactivate();
            break;
        case APP_CMD_LOW_MEMORY:
            mActivityHandler.onLowMemory();
            break;
        case APP_CMD_PAUSE:
            mActivityHandler.onPause();
            deactivate();
            break;
        case APP_CMD_RESUME:
            mActivityHandler.onResume();
            break;
        case APP_CMD_SAVE_STATE:
            mActivityHandler.onSaveInstanceState(
                    &mApplication->savedState, &mApplication->savedStateSize);
            break;
        case APP_CMD_START:
            mActivityHandler.onStart();
            break;
        case APP_CMD_STOP:
            mActivityHandler.onStop();
            break;
        case APP_CMD_TERM_WINDOW:
            mActivityHandler.onDestroyWindow();
            deactivate();
            break;
        default:
            break;
    }
}
