#ifndef DRONE_EXCEPTION_H
#define DRONE_EXCEPTION_H

#include <stdexcept>
#include <exception>
#include <string>
//This is only linux compatible....
#include <string.h>
#include <errno.h>

#include "utils.h"

class DroneException : public std::runtime_error {
	public:
	DroneException(std::string msg): runtime_error(msg), msg(msg) {}
	virtual const char * what() const throw();
	protected:
	std::string msg;
};

class ControllerNotFoundException : public DroneException {
	public:
	ControllerNotFoundException(std::string id)
	: DroneException("Controller id not found: " + id + ".") {}
};

class ControllerReadException : public DroneException {
	public:
	ControllerReadException(int id)
	: DroneException("Could not read controller error: " + utils::readErrno(id)) {}
};

#endif
