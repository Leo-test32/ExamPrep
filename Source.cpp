#include "VehicleList.hpp"
#include "VehicleListFile.hpp"

int main() {

	/*try {
		Registration reg("12Abcd23");
	}
	catch (std::exception e) {
		std::cout << e.what();
	}*/

	Registration reg1("AB1234AB");
	Registration reg2("CD5678CD");

	unsigned capacity = 10;
	VehicleList _vl(capacity);

	_vl.insert("AB1234Ac", "Testing");
	std::cout << _vl.VehicleSize();

	
	return 0;
}