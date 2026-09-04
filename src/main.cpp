#include "main.h"

#include "platform/Window.h"
#include "renderer/Shader.h"
#include "renderer/VertexBuffer.h"
#include "assets/BasicMeshes.h"
#include "assets/VertexShader.h"
#include "assets/FragmentShader.h"


constexpr int WINDOW_WIDTH = 800;
constexpr int WINDOW_HEIGHT = 600;
constexpr const char* WINDOW_TITLE = "OpenGL Engine";

constexpr float BACKGROUND_COLOR[] = {
    1.0f, 0.64f, 0.0f, 1.0f
};


void processInput(platform::Window&);
void render(GLuint vao);


int main()
{
    // INIT PLATFORM LIB AND CREATE A WINDOW
    platform::initPlatformLib();
    platform::Window window(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

    // VBO AND VAO CONFIGURATION
    GLuint vertexArray;
    GLuint vertexBuffer;
    GLuint indexBuffer;
    renderer::configureVertexBuffers(vertexArray,
        vertexBuffer,
        sizeof(assets::squareVertices), assets::squareVertices,
        indexBuffer,
        sizeof(assets::squareIndices), assets::squareIndices
        );

    // SHADER PROGRAM
    unsigned int shaderProgram = renderer::createShaderProgram(assets::vertexShaderSource, assets::fragmentShaderSource);
    glUseProgram(shaderProgram);

    // RENDER LOOP
    while (!window.shouldClose())
    {
        processInput(window);

        render(vertexArray);

        window.swapBuffers();

        platform::pollEvents();
    }

    // TERMINATE PLATFORM LIB
    platform::terminatePlatformLib();

    return 0;
}


void processInput(platform::Window& window) {
    if (platform::getKey(window.getHandle(), GLFW_KEY_ESCAPE))
        window.closeWindow();
}

void render(GLuint vao) {
    // BACKGROUND
    glClearColor(
        BACKGROUND_COLOR[0],
        BACKGROUND_COLOR[1],
        BACKGROUND_COLOR[2],
        BACKGROUND_COLOR[3]
    );
    glClear(GL_COLOR_BUFFER_BIT);

    // RENDER
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // wireframe mode
    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
