#include "linux_controller.h"

#include <GLFW/glfw3.h>

//Just going to hard code this for now
#define MY_CONTROLLER "Microsoft X-Box 360 pad"

#define ROLL_IDX  0
#define PITCH_IDX 1
#define LEFT_RUDDER_IDX 2
#define RIGHT_RUDDER_IDX 5
#define THROTTLE_IDX 4 //multiply by -1

LinuxController::LinuxController() {
	//The documentation sugggests multiple calls to this is safe,
	glfwInit();
}

void LinuxController::read(ControllerOutput* out) throw(ControllerReadException) {
	if(this->controllerID == -1) {
		throw(ControllerReadException(1));
	}
	int count = 0;
	auto data = glfwGetJoystickAxes(this->controllerID, &count);
	if(data == NULL) throw(ControllerReadException(1));
	if(count < 6) throw(ControllerReadException(1));
	out->rightRudder = (int) (((data[RIGHT_RUDDER_IDX] * 100) + 100) / 2);
	out->leftRudder = (int) (((data[LEFT_RUDDER_IDX] * 100) + 100) / 2);
	out->throttle = (int) (data[THROTTLE_IDX] * 100 * -1);
	out->roll = (int) (data[ROLL_IDX] * 100);
	out->pitch = (int) (data[PITCH_IDX] * 100);
}

std::vector<std::string> LinuxController::getControllerIds() {
	const char* jName;
	std::vector<std::string> toRet = std::vector<std::string>();
	for(int i = GLFW_JOYSTICK_1; i <= GLFW_JOYSTICK_LAST; ++i) {
		if((jName = glfwGetJoystickName(i)) == NULL) {
			continue;
		}
		toRet.push_back(std::string(jName));
	}
	return toRet;
}

//NOTE not actually using passed string, just going to connect the hardcoded id,
//if in the future, i need to generalize this, i will
void LinuxController::connect(std::string) throw(ControllerNotFoundException) {
	const char* jName;
	const std::string myName = std::string(MY_CONTROLLER);
	for(int i = GLFW_JOYSTICK_1; i <= GLFW_JOYSTICK_LAST; ++i) {
		if((jName = glfwGetJoystickName(i)) == NULL) {
			continue;
		}
		if(myName.compare(jName) == 0) {
			this->controllerID = i;
			return;
		}
	}
	throw(ControllerNotFoundException(MY_CONTROLLER));
}
