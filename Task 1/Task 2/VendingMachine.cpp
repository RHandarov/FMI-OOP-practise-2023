#define _CRT_SECURE_NO_WARNINGS

#include <cstring>

#include "VendingMachine.hpp"

//constructors
VendingMachine::VendingMachine() {
	this->address = nullptr;
	this->initializeFieldsWith(0, "N/A", 0, 0, 0);
}

VendingMachine::VendingMachine(const unsigned int id, const char* address,
	const unsigned int numSweets, const unsigned int numSnacks,
	const unsigned int numBeverages) {
	this->address = nullptr;
	this->initializeFieldsWith(id, address, numSweets, numSnacks, numBeverages);
}

VendingMachine::VendingMachine(const VendingMachine& other) {
	this->initializeFieldsWith(other.id, other.address, other.numSweets,
		other.numSnacks, other.numBeverages);
}

void VendingMachine::initializeFieldsWith(const unsigned int id, const char* address,
	const unsigned int numSweets, const unsigned int numSnacks,
	const unsigned int numBeverages) {
	this->id = id;
	this->setAddress(address);
	this->numSweets = numSweets;
	this->numSnacks = numSnacks;
	this->numBeverages = numBeverages;
}

//getters and setters
void VendingMachine::setAddress(const char* address) {
	if (this->address != nullptr) {
		delete[] this->address;
	}

	this->address = new char[strlen(address) + 1];
	strcpy(this->address, address);
}

unsigned int VendingMachine::getId() const {
	return this->id;
}

const char* VendingMachine::getAddress() const {
	return this->address;
}

unsigned int VendingMachine::getNumSweets() const {
	return this->numSweets;
}

unsigned int VendingMachine::getNumSnacks() const {
	return this->numSnacks;
}

unsigned int VendingMachine::getNumBeverages() const {
	return this->numBeverages;
}

//operators
VendingMachine& VendingMachine::operator=(const VendingMachine& other) {
	if (this != &other) {
		this->initializeFieldsWith(other.id, other.address, other.numSweets,
			other.numSnacks, other.numBeverages);
	}

	return *this;
}

//destructor
VendingMachine::~VendingMachine() {
	delete[] this->address;
}