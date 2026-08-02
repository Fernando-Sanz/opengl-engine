cmake_minimum_required(VERSION 3.20)

project(OpenGLEngine VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(OpenGLEngine
    src/main.cpp
)

target_include_directories(OpenGLEngine PRIVATE
    include
)
