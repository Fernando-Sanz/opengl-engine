#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>


namespace platform {

	using WindowHandle = GLFWwindow*;

	void initPlatformLib();
	void terminatePlatformLib();

	WindowHandle createWindow(int width, int height, const char* title);
	void setWindowShouldClose(WindowHandle window);
	bool windowShouldClose(WindowHandle window);

	void loadOpenGLFunctions();

	void pollEvents();

	bool getKey(WindowHandle window, int key);
}
