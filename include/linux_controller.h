#ifndef LINUX_CONTROLLER_H
#define LINUX_CONTROLLER_H

#include <string>
#include <vector>

#include "controller.h"
#include "error.h"

class LinuxController : public Controller {
	public:
	LinuxController();
	virtual void read(ControllerOutput*) throw(ControllerReadException);
	virtual std::vector<std::string> getControllerIds();
	virtual void connect(std::string) throw(ControllerNotFoundException);
	private:
	int controllerID = -1;
};
#endif
