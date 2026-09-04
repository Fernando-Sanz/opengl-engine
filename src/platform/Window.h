#pragma once

#include "platform.h"


namespace platform {

    class Window {
    public:
        Window(int width, int height, const char* title);
        void closeWindow();

        bool shouldClose() { return windowShouldClose(window); }

        void swapBuffers();

        WindowHandle getHandle() { return window; }

    private:
        WindowHandle window;
        int width, height;

        static void framebuffer_size_callback(WindowHandle window, int width, int height);
    };
}
