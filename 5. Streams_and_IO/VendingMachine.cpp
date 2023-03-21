#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

#include "VendingMachine.hpp"

Inventory::Inventory() {
	salty = 0;
	sweet = 0;
	drinks = 0;
}

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

void VendingMachine::setId(int id) {
	if (id < 0) {
		id = 0;
	}

	this->id = id;
}

void VendingMachine::setAddress(const char* address) {
	this->freeAddress();

	this->address = new char[strlen(address) + 1];
	strcpy(this->address, address);
}

void VendingMachine::setInventory(const Inventory& inventory) {
	this->inventory = inventory;
}

void VendingMachine::setWarningMessages(const char** warningMessages) {
	//it is supposed to be cleared earlier
	this->warningMessages = new char* [this->capacity];

	for (unsigned int index = 0; index < this->numWarningMsgs; ++index) {
		this->warningMessages[index] = new char[strlen(warningMessages[index]) + 1];
		strcpy(this->warningMessages[index], warningMessages[index]);
	}
}

void VendingMachine::setNumWarningMessages(int numWarningMessages) {
	if (numWarningMessages < 0) {
		numWarningMessages = 0;
	}

	this->numWarningMsgs = numWarningMessages;
}

void VendingMachine::setCapacity() {
	this->capacity = CAPACITY;
}

void VendingMachine::copy(int id, const char* address, const Inventory& inventory, int numWarningMessages, const char** warningMessages) {
	setId(id);
	setAddress(address);
	setInventory(inventory);
	freeAddress();
	setCapacity();
	setNumWarningMessages(numWarningMessages);
	setWarningMessages(warningMessages);
}

void VendingMachine::move(int id, char* address, const Inventory& inventory, int numWarningMessages, char** warningMessages) {
	setId(id);
	freeAddress();
	this->address = address;
	setInventory(inventory);
	freeWarningMessages();
	this->warningMessages = warningMessages;
	setNumWarningMessages(numWarningMessages);
}

void VendingMachine::freeAddress() {
	if (this->address) {
		delete[] this->address;
	}
}

void VendingMachine::freeWarningMessages() {
	for (unsigned int index = 0; index < numWarningMsgs; ++index) {
		delete[] warningMessages[index];
	}

	delete[] warningMessages;
}

VendingMachine::VendingMachine() {
	copy(0, "", Inventory(), 0, nullptr);
}

VendingMachine::VendingMachine(char* address, Inventory inventory) {
	copy(0, address, inventory, 0, nullptr);
}

VendingMachine::VendingMachine(VendingMachine const& other) {
	copy(other.id, other.address, other.inventory, other.numWarningMsgs, other.warningMessages);
}

VendingMachine::VendingMachine(VendingMachine&& other) {
	move(other.id, other.address, other.inventory, other.numWarningMsgs, other.warningMessages);

	other.address = nullptr;
	other.warningMessages = nullptr;
}

VendingMachine& VendingMachine::operator=(VendingMachine const& other) {
	if (this != &other) {
		copy(other.id, other.address, other.inventory, other.numWarningMsgs, other.warningMessages);
	}

	return *this;
}

VendingMachine::~VendingMachine() {
	freeAddress();
	freeWarningMessages();
}
