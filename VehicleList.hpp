#ifndef _VEHICLELIST_
#define _VEHICLELIST_
#include "Vehicle.hpp"
#include <fstream>

class VehicleList {
private:
	Vehicle** vehicle;
	unsigned _count;
	unsigned currentCount;

	void copy(const VehicleList& other) {
		this->_count = other._count;
		this->currentCount = other.currentCount;

		vehicle = new Vehicle * [_count];
		for (unsigned i = 0; i < _count; i++) {
			vehicle[i] = other.vehicle[i] ? new Vehicle(*vehicle[i]) : nullptr;
		}
	}

	void clear() {
		for (unsigned i = 0; i < _count; i++) {
			if(vehicle[i]) delete vehicle[i];
		}
		delete[] vehicle;
	}

	unsigned int VehicleCount() const;

public:
	VehicleList(unsigned count) {
		this->_count = count;
		this->currentCount = 0;

		vehicle = new Vehicle * [count];
		for (unsigned i = 0; i < count; i++) {
			vehicle[i] = nullptr;
		}
	}

	VehicleList(const VehicleList& other) {
		copy(other);
	}

	VehicleList& operator=(const VehicleList& other) {
		if (this != &other) {
			clear();
			copy(other);
		}
		return *this;
	}

	~VehicleList() {
		clear();
	}

	void insert(const char* regnum, const char* description) {
		/*for (unsigned i = 0; i < _count; i++) {												// this breaks it for some reason
			if (vehicle[i]->getRegNum().toString() == regnum && vehicle[i]!=nullptr) {
				throw std::invalid_argument("Matching regnum found, regnum has to be unique");
			}
		}*/
		for (unsigned i = 0; i < _count; i++) {
			if (vehicle[i] == nullptr) {
				vehicle[i] = new Vehicle(regnum, description);
				return;
			}
		}
		throw std::logic_error("Did not add new vehicle");
	}

	const Vehicle& at(size_t index) const {
		if (vehicle[index] == nullptr) {
			throw std::invalid_argument("Invalid input");
		}
		return *vehicle[index];
	}

	const Vehicle& operator[](size_t pos) const {
		return *vehicle[pos];
	}

	bool empty() const {
		for (unsigned i = 0; i < _count; i++) {
			if (vehicle[i] != nullptr) {
				return false;
			}
		}
		return true;
	}

	const Vehicle* find(const Registration& regnum) const {
		for (unsigned i = 0; i < _count; i++) {
			if (this->vehicle[i]->getRegNum() == regnum) {
				return vehicle[i];
			}
		}
		return nullptr;
	}

	unsigned VehicleSize();

};

unsigned int VehicleList::VehicleCount() const {
	return this->_count;
}

unsigned VehicleList::VehicleSize() {
	for (unsigned i = 0; i < _count; i++) {
		if (vehicle[i] != nullptr) {
			currentCount++;
		}
	}
	return currentCount;
}

#endif // !_VEHICLELIST