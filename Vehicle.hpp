#ifndef _VEHICLE_
#define _VEHICLE_
#include "Registration.hpp"
#include <iostream>

class Vehicle {
private:
	Registration regnum;
	std::string description;
public:
	Vehicle(const char* _regnum, const char* _description) : regnum(_regnum) {
		this->description = description;
	}

	const Registration getRegNum() const {
		return regnum;
	}
};

#endif // !_VEHICLE_
