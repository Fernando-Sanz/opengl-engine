#include "Shader.h"

#include <iostream>

#include <glad/glad.h>


namespace renderer {
    unsigned int createShaderProgram(const char* vertexShaderCode, const char* fragmentShaderCode) {
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

    void checkShaderCompilation(unsigned int shader) {
        int success;
        char infolog[512];
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

        if (!success) {
            glGetShaderInfoLog(shader, 512, NULL, infolog);
            std::cout << "ERROR: SHADER COMPILATION FAILED:\n" << infolog << std::endl;
        }
    }

    void checkShaderProgramLinking(unsigned int shaderProgram) {
        int success;
        char infolog[512];
        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

        if (!success) {
            glGetProgramInfoLog(shaderProgram, 512, NULL, infolog);
            std::cout << "ERROR: SHADER PROGRAM LINKING FAILED:\n" << infolog << std::endl;
        }
    }
}
