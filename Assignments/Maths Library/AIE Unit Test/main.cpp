// an example main function for the unit test
#include "unittest.h"
#include <iostream>

int main() {

	if (runUnitTests() == false) {
		std::cout << "Unit test failed!" << std::endl;
		system("pause");
		return -1;
	}
	std::cout << "All tests passed successfully." << std::endl;

	return 0;
}