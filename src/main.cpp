#include "main.h"

#include "platform/Window.h"


constexpr int WINDOW_WIDTH = 800;
constexpr int WINDOW_HEIGHT = 600;
constexpr const char* WINDOW_TITLE = "OpenGL Engine";

constexpr float BACKGROUND_COLOR[] = {
    1.0f, 0.64f, 0.0f, 1.0f
};


void processInput(platform::Window);
void render();


int main()
{
    // INIT PLATFORM LIB AND CREATE A WINDOW
    platform::initPlatformLib();
    platform::Window window(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

    // RENDER LOOP
    while (!window.shouldClose())
    {
        processInput(window);

        render();

        window.swapBuffers();

        platform::pollEvents();
    }

    // TERMINATE PLATFORM LIB
    platform::terminatePlatformLib();

    return 0;
}

void processInput(platform::Window window) {
    if (platform::getKey(window.getHandle(), GLFW_KEY_ESCAPE))
        window.closeWindow();
}

void render() {
    glClearColor(
        BACKGROUND_COLOR[0],
        BACKGROUND_COLOR[1],
        BACKGROUND_COLOR[2],
        BACKGROUND_COLOR[3]
    );
    glClear(GL_COLOR_BUFFER_BIT);
}
