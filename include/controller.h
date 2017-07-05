#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <string>
#include <vector>

#include "error.h"

//This may not be the most universal solution, but for now just assume the controller knows
//what throttle, rudder, etc. are

struct ControllerOutput {
	int rightRudder;
	int leftRudder;
	int throttle;
	int roll;
	int pitch; 
};

inline std::ostream& operator<<(std::ostream& os, const ControllerOutput& rhs) {
	char rr [50];
	sprintf(rr, "right rudder: %d", rhs.rightRudder);
	char lr [50];
	sprintf(lr, "left rudder:  %d", rhs.leftRudder);
	char th [50];
	sprintf(th, "throttle:     %d", rhs.throttle);
	char ro [50];
	sprintf(ro, "roll:         %d", rhs.roll);
	char pi [50];
	sprintf(pi, "pitch:        %d", rhs.pitch);
	os << rr << std::endl;
	os << lr << std::endl;
	os << th << std::endl;
	os << ro << std::endl;
	os << pi << std::endl;
	return os;
};

class Controller {
	public:
	virtual void read(ControllerOutput*) throw(ControllerReadException) = 0;
	virtual std::vector<std::string> getControllerIds() = 0;
	virtual void connect(std::string) throw(ControllerNotFoundException) = 0;
};
#endif
