//
// Created by lion on 17-6-22.
//

#ifndef NATIVEACTIVITY_GRAPHICSMANAGER_HPP
#define NATIVEACTIVITY_GRAPHICSMANAGER_HPP


#include <android_native_app_glue.h>
#include "Types.hpp"
struct GraphicsElement;

class GraphicsManager {
public:
    GraphicsManager(android_app* pApplication);
    ~GraphicsManager();

    int32_t getRenderWidth() { return mRenderWidth; }
    int32_t getRenderHeight() { return mRenderHeight; }

    GraphicsElement* registerElement(int32_t pHeight, int32_t pWidth);

    status start();
    status update();
private:
    GraphicsManager(const GraphicsManager&);

    void operator=(const GraphicsManager&);

    android_app* mApplication;

    int32_t mRenderWidth;
    int32_t mRenderHeight;
    GraphicsElement* mElements[1024];
    int32_t mElementCount;
};

struct GraphicsElement {

    GraphicsElement(int32_t pwidth, int32_t pheight) :
            location(), width(pwidth), height(pheight) {}

    Location location;
    int32_t width;
    int32_t height;
};

#endif //NATIVEACTIVITY_GRAPHICSMANAGER_HPP
