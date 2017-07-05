#include <string.h>

#include "error.h"

const char * DroneException::what() const throw() {
	return this->msg.c_str();
}
