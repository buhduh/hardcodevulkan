#ifdef LINUX
#include "linux.h"
LinuxController controller = LinuxController();
LinuxWindow window = LinuxWindow();
#endif

#include <iostream>

#include "controller.h"

#include "unistd.h"

using namespace std; 

#define LOCAL_CONTROLLER_PATH "usb-©Microsoft_Corporation_Controller_1789644-event-joystick"

int main() {
	//controller.getControllerIds();
	controller.connect("don't matter");
	ControllerOutput controllerData = ControllerOutput{0, 0, 0, 0, 0};
	window.initWindow();
	while(!window.shouldClose()) {
		usleep(1000);
		controller.read(&controllerData);
		std::cout << controllerData << std::endl;
	}
	window.destroy();
	return 0;
}
