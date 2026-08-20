#include "platform.h"

#include <iostream>


namespace platform {

	void initPlatformLib() {
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	}

	void terminatePlatformLib() {
		glfwTerminate();
	}

	WindowHandle createWindow(int width, int height, const char* title) {
		WindowHandle window = glfwCreateWindow(width, height, title, NULL, NULL);
		if (window == NULL)
		{
			glfwTerminate();
			throw std::runtime_error("Failed to create GLFW window");
		}
		glfwMakeContextCurrent(window);

		return window;
	}
	void setWindowShouldClose(WindowHandle window) {
		glfwSetWindowShouldClose((GLFWwindow*)window, true);
	}
	bool windowShouldClose(WindowHandle window) {
		return glfwWindowShouldClose(window);
	}

	void loadOpenGLFunctions() {
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			throw std::runtime_error("Failed to initialize GLAD");
		}
	}

	void pollEvents() {
		glfwPollEvents();
	}

	bool getKey(WindowHandle window, int key) {
		return glfwGetKey((GLFWwindow*)window, GLFW_KEY_ESCAPE) == GLFW_PRESS;
	}

}
