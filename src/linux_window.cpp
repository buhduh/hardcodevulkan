#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <iostream>

#include "linux_window.h"
#include "drone.h"

void LinuxWindow::initWindow() {
	//glfwInit();
	auto monitor = glfwGetPrimaryMonitor();
	const auto mode = glfwGetVideoMode(monitor);
	glfwWindowHint(GLFW_RED_BITS, mode->redBits);
	glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
	glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
	glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
	window = glfwCreateWindow(mode->width, mode->height, APP_NAME, nullptr, nullptr);
}

bool LinuxWindow::shouldClose() {
	glfwPollEvents();
	return glfwWindowShouldClose(window);
}

void LinuxWindow::destroy() {
	glfwDestroyWindow(window);
}
