#ifndef LINUX_WINDOW_H
#define LINUX_WINDOW_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "window.h"

class LinuxWindow : public Window {
	public:
	virtual void initWindow();
	virtual bool shouldClose();
	virtual void destroy();
	private:
	GLFWwindow *window;
};
#endif
