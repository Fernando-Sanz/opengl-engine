cmake_minimum_required(VERSION 3.20)

project(OpenGLEngine VERSION 0.1 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(OpenGLEngine
    src/main.cpp
)

find_package(OpenGL REQUIRED)

target_include_directories(OpenGLEngine PRIVATE
    include
    "C:/development/cpp/glfw/glfw-3.5.1/include"
    "C:/development/cpp/glad/include/"
)

target_link_libraries(OpenGLEngine PRIVATE
    OpenGL::GL
    "C:/development/cpp/glfw/glfw-3.5.1/build/src/Debug/glfw3.lib"
)
