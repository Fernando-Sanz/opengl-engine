#include "Window.h"

#include <iostream>


namespace platform {

    Window::Window(int width, int height, const char* title)
        : width(width), height(height)
    {
        // CREATE WINDOW
        window = createWindow(width, height, title);

        // LOAD OPENGL FUNCTIONS
        loadOpenGLFunctions();

        // INDICATE OPENGL RENDER SURFACE 
        glViewport(0, 0, width, height);
        glfwSetWindowUserPointer(window, this);
        glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    }

    void Window::closeWindow() {
        setWindowShouldClose(window);
    }

    void Window::swapBuffers() {
        glfwSwapBuffers(window);
    }

    void Window::framebuffer_size_callback(WindowHandle window, int width, int height)
    {
        auto* self = static_cast<Window*>(
            glfwGetWindowUserPointer(window)
            );

        self->width = width;
        self->height = height;

        glViewport(0, 0, width, height);
    }
}
