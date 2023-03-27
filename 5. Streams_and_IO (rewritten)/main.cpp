#include <iostream>
#include <fstream>

#include "VendingMachine.hpp"

void clearWarningsFile() {
	std::ofstream file("warinngs.txt");
	file.close();
}

int main() {
	clearWarningsFile();

	VendingMachine machine1("#1", Inventory());
	VendingMachine machine2("#2", Inventory());

	VendingController controller;

	controller.addVendingMachine(machine1);
	controller.addVendingMachine(machine2);

	controller.sellProductInMachine(1, "salty");
	controller.sellProductInMachine(2, "drinks");

	controller.seeWarningMsgForMachine(1);
	controller.seeWarningMsgForMachine(2);

	controller.getAddressOfMachine(1)->getInventory().changeSalty(5);
	controller.getAddressOfMachine(2)->getInventory().changeDrinks(6);

	controller.sellProductInMachine(1, "salty");
	controller.sellProductInMachine(2, "drinks");

	std::cout << controller.getAddressOfMachine(1)->getInventory().salty;
	std::cout << ' ' << controller.getAddressOfMachine(2)->getInventory().drinks;
	std::cout << std::endl;

	controller.seeWarningMsgForMachine(1);
	controller.seeWarningMsgForMachine(2);

	std::cout << "reading from file...\n";

	controller.seeAllWarningMessages(std::cout);
}