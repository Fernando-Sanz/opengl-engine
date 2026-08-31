#include "main.h"

#include "platform/Window.h"
#include "assets/basic_geometry.h"
#include "assets/vertex_shader.h"
#include "assets/fragment_shader.h"


constexpr int WINDOW_WIDTH = 800;
constexpr int WINDOW_HEIGHT = 600;
constexpr const char* WINDOW_TITLE = "OpenGL Engine";

constexpr float BACKGROUND_COLOR[] = {
    1.0f, 0.64f, 0.0f, 1.0f
};


void configureVertexBuffers(
    GLuint& vertexArray,
    GLuint& vertexBuffer,
    GLsizeiptr vertexSize, const void* vertices,
    GLuint& indexBuffer,
    GLsizeiptr indexSize, const void* indices);
GLuint createShaderProgram(const char* vertexshaderCode, const char* fragmentshaderCode);
void checkShaderCompilation(GLuint shader);
void checkShaderProgramLinking(GLuint shaderProgram);
void processInput(platform::Window);
void render(GLuint arrayBuffer);


int main()
{
    // INIT PLATFORM LIB AND CREATE A WINDOW
    platform::initPlatformLib();
    platform::Window window(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

    // VBO AND VAO CONFIGURATION
    GLuint vertexArray;
    GLuint vertexBuffer;
    GLuint indexBuffer;
    configureVertexBuffers(vertexArray, vertexBuffer,
        sizeof(assets::squareVertices), assets::squareVertices,
        indexBuffer,
        sizeof(assets::squareIndices), assets::squareIndices
        );

    // SHADER PROGRAM
    unsigned int shaderProgram = createShaderProgram(assets::vertexShaderSource, assets::fragmentShaderSource);
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


void configureVertexBuffers(
    GLuint& vertexArray,
    GLuint& vertexBuffer,
    GLsizeiptr vertexSize, const void* vertices,
    GLuint& indexBuffer,
    GLsizeiptr indexSize, const void* indices
) {
    // VERTEX ARRAY OBJECT
    glGenVertexArrays(1, &vertexArray);
    glBindVertexArray(vertexArray);

    // VERTEX BUFFER
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, vertexSize, vertices, GL_STATIC_DRAW);

    // VERTEX ATTRIBUTES DESCRIPTION
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // INDEX BUFFER
    glGenBuffers(1, &indexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexSize, indices, GL_STATIC_DRAW);
}

GLuint createShaderProgram(const char* vertexShaderCode, const char* fragmentShaderCode) {
    // CREATE AND COMPILE SHADERS
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderCode, NULL);
    glCompileShader(vertexShader);
    checkShaderCompilation(vertexShader);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderCode, NULL);
    glCompileShader(fragmentShader);
    checkShaderCompilation(fragmentShader);

    // CREATE PROGRAM
    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    checkShaderProgramLinking(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;
}

void checkShaderCompilation(GLuint shader) {
    int success;
    char infolog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if (!success) {
        glGetShaderInfoLog(shader, 512, NULL, infolog);
        std::cout << "ERROR: SHADER COMPILATION FAILED:\n" << infolog << std::endl;
    }
}

void checkShaderProgramLinking(GLuint shaderProgram) {
    int success;
    char infolog[512];
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infolog);
        std::cout << "ERROR: SHADER PROGRAM LINKING FAILED:\n" << infolog << std::endl;
    }
}

void processInput(platform::Window window) {
    if (platform::getKey(window.getHandle(), GLFW_KEY_ESCAPE))
        window.closeWindow();
}

void render(GLuint arrayBuffer) {
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
    glBindVertexArray(arrayBuffer);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
