#include <iostream>

#include "VendingMachine.hpp"

void Inventory::changeSalty(int quantity) {
	salty = quantity;
}

void Inventory::changeSweets(int quantity) {
	sweet = quantity;
}

void Inventory::changeDrinks(int quantity) {
	drinks = quantity;
}

void Inventory::print() const {
	std::cout << "(salty = " << salty << ", ";
	std::cout << "sweet = " << sweet << ", drinks = ";
	std::cout << drinks << std::endl;
}