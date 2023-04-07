#ifndef _REGISTRATION_
#define _REGISTRATION_
#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
#include <stdexcept>
#include <string>
#include <cctype>

class Registration {
private:
	char regNumber[9];

	bool isValid();
public:
	Registration(const char* regNumber) {
		strcpy(this->regNumber, regNumber);

		if (!isValid()) {
			throw std::invalid_argument("Invalid input");
		}
	}

	Registration(const Registration& other) {
		strcpy(regNumber, other.regNumber);

		if (!isValid()) {
			throw std::invalid_argument("Invalid input");
		}
	}

	Registration& operator=(const Registration& other) {
		if (this != &other) {
			strcpy(regNumber, other.regNumber);
		}
		return *this;
	}

	bool operator==(const Registration& rhs) const {
		return !strcmp(this->regNumber, rhs.regNumber);
	}

	const char* toString() const {
		return regNumber;
	}
};

bool Registration::isValid() {
	if (isdigit(regNumber[0])) {
		return false;
	}
	if (isalpha(regNumber[2]) || isalpha(regNumber[3]) || isalpha(regNumber[4]) || isalpha(regNumber[5])) {
		return false;
	}
	if (isdigit(regNumber[7]) || isdigit(regNumber[8])) {
		return false;
	}
	return true;
}

#endif // !_REGISTRATION_
