#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>

#include "VendingMachine.hpp"

unsigned int ID = 1;

Inventory::Inventory() {
	salty = 0;
	sweet = 0;
	drinks = 0;
}

void Inventory::changeSalty(int quantity) {
	if (quantity < 0) {
		quantity = 0;
	}

	salty = quantity;
}

void Inventory::changeSweets(int quantity) {
	if (quantity < 0) {
		quantity = 0;
	}

	sweet = quantity;
}

void Inventory::changeDrinks(int quantity) {
	if (quantity < 0) {
		quantity = 0;
	}

	drinks = quantity;
}

void Inventory::print() {
	std::cout << '(' << salty << ", " << sweet << ", ";
	std::cout << drinks << std::endl;
}

void StringArray::allocateMemory() {
	strings = new char* [capacity];

	for (unsigned int index = 0; index < capacity; ++index) {
		strings[index] = nullptr;
	}
}

void StringArray::freeMemory() {
	for (unsigned int index = 0; index < capacity; ++index) {
		delete[] strings[index];
	}

	delete[] strings;
}

unsigned int StringArray::getNewCapacity() const {
	unsigned int newCapacity = 1;

	while (newCapacity < size) {
		newCapacity <<= 1;
	}

	return newCapacity < 10 ? 10 : newCapacity;
}

void StringArray::setStringsToBuffer(char**& destination) const {
	destination = new char* [capacity];

	for (unsigned int index = 0; index < capacity; ++index) {
		destination[index] = new char[strlen(strings[index]) + 1];
		strcpy(destination[index], strings[index]);
	}
}

void StringArray::resize() {
	char** buffer;
	unsigned int bufferSize = capacity;
	setStringsToBuffer(buffer);

	freeMemory();

	capacity = getNewCapacity();
	setStrings(buffer, bufferSize);

	for (unsigned int index = 0; index < bufferSize; ++index) {
		delete[] buffer[index];
	}

	delete[] buffer;
}

void StringArray::setString(const char* string, unsigned int index) {
	if (index > capacity) {
		return;
	}

	delete[] strings[index];

	if (!string) {
		strings[index] = nullptr;
		return;
	}

	strings[index] = new char[strlen(string) + 1];
	strcpy(strings[index], string);
}

void StringArray::setStrings(char** strings, unsigned int size) {
	allocateMemory();

	for (unsigned int index = 0; index < std::min(size, capacity); ++index) {
		setString(strings[index], index);
	}
}

void StringArray::copy(const StringArray& other) {
	freeMemory();

	size = other.size;
	capacity = other.capacity;
	setStrings(other.strings, other.capacity);
}

StringArray::StringArray() : size(0), capacity(10) {
	allocateMemory();
}

StringArray::StringArray(const StringArray& other) : capacity(0), size(0), strings(nullptr) {
	copy(other);
}

void StringArray::addString(const char* string) {
	++size;

	if (size > capacity) {
		resize();
	}

	setString(string, size - 1);
}

void StringArray::print() const {
	for (unsigned int index = 0; index < size; ++index) {
		if (!strings[index]) {
			continue;
		}

		std::cout << strings[index] << std::endl;
	}
}

StringArray& StringArray::operator=(const StringArray& other) {
	if (this != &other) {
		copy(other);
	}

	return *this;
}

StringArray::~StringArray() {
	freeMemory();
}

void VendingMachine::freeAddress() {
	delete[] address;
	address = nullptr;
}

void VendingMachine::setId(int id = -1) {
	if (id == -1) {
		this->id = ID++;
	} else {
		this->id = id;
	}
}

void VendingMachine::setAddress(const char* address) {
	freeAddress();

	this->address = new char[strlen(address) + 1];
	strcpy(this->address, address);
}

void VendingMachine::setInventory(const Inventory& other) {
	this->inventory = inventory;
}

void VendingMachine::setWarningMessages(const StringArray& other) {
	warningMessages = other;
}

void VendingMachine::copy(const VendingMachine& other) {
	freeAddress();

	setId(other.id);
	setAddress(other.address);
	setInventory(other.inventory);
	setWarningMessages(other.warningMessages);
}

void VendingMachine::move(VendingMachine&& other) {
	freeAddress();

	id = other.id;
	address = other.address;
	inventory = other.inventory;
	warningMessages = other.warningMessages;

	other.address = nullptr;
}

VendingMachine::VendingMachine() : address(nullptr), warningsFile("warinngs.txt", std::ios::out | std::ios::app) {
	setId();
	setAddress("");
}

VendingMachine::VendingMachine(const char* address, Inventory inventory) : address(nullptr), warningsFile("warinngs.txt", std::ios::out | std::ios::app) {
	setId();
	setAddress(address);
	setInventory(inventory);
}

VendingMachine::VendingMachine(VendingMachine const& other) : address(nullptr), warningsFile("warinngs.txt", std::ios::out | std::ios::app) {
	copy(other);
}

VendingMachine::VendingMachine(VendingMachine&& other) : warningsFile("warinngs.txt", std::ios::out | std::ios::app) {
	move(std::move(other));
}

VendingMachine& VendingMachine::operator=(VendingMachine const& other) {
	if (this != &other) {
		copy(other);
	}

	return *this;
}

VendingMachine::~VendingMachine() {
	freeAddress();
	warningsFile.close();
}

int VendingMachine::getId() const {
	return id;
}

Inventory& VendingMachine::getInventory() {
	return inventory;
}

void VendingMachine::addWarningMessage(const char* message) {
	if (!message) {
		return;
	}

	warningMessages.addString(message);

	warningsFile.put('#');
	warningsFile << id << ": " << message << std::endl;
}

void VendingMachine::outputWarningMessages(std::ostream& stream) const {
	stream << warningMessages;
}

void VendingController::setNumMachines(unsigned int numMachines) {
	this->numMachines = numMachines;
}

void VendingController::setCapacity() {
	capacity = 1;

	while (capacity < numMachines) {
		capacity <<= 1;
	}

	if (capacity < 10) {
		capacity = 10;
	}
}

void VendingController::setVendingMachineList(const VendingMachine* list, int size) {
	free();

	setCapacity();
	vendingMachineList = new VendingMachine[capacity];

	for (unsigned int index = 0; index < std::min(capacity, size); ++index) {
		vendingMachineList[index] = list[index];
	}
}

void VendingController::copyToBuffer(VendingMachine*& other) {
	other = new VendingMachine[capacity];

	for (unsigned int index = 0; index < capacity; ++index) {
		other[index] = vendingMachineList[index];
	}
}

void VendingController::allocateEmptyList() {
	vendingMachineList = new VendingMachine[capacity];
}

void VendingController::resize() {
	VendingMachine* bufferList;
	unsigned int bufferSize = capacity;
	copyToBuffer(bufferList);

	setVendingMachineList(bufferList, bufferSize); //it will autoresize

	delete[] bufferList;
}

void VendingController::copy(const VendingController& other) {
	setNumMachines(other.numMachines);
	setVendingMachineList(other.vendingMachineList, other.numMachines);
}

VendingController::VendingController() : numMachines(0), capacity(10) {
	allocateEmptyList();
}

VendingController::VendingController(const VendingController& other) : vendingMachineList(nullptr) {
	copy(other);
}

VendingController& VendingController::operator=(const VendingController& other) {
	if (this != &other) {
		copy(other);
	}

	return *this;
}

VendingController::~VendingController() {
	free();
}

void VendingController::addVendingMachine(VendingMachine machine) {
	++numMachines;

	if (numMachines > capacity) {
		resize();
	}

	vendingMachineList[numMachines - 1] = machine;
}

//returns pointer to the machine with id equals to machineId and nullptr if not found
VendingMachine* VendingController::getAddressOfMachine(int machineID) {
	for (unsigned int index = 0; index < numMachines; ++index) {
		if (vendingMachineList[index].getId() == machineID) {
			return vendingMachineList + index;
		}
	}

	return nullptr;
}

Inventory& VendingController::getInventoryOfMachine(int machineID) {
	VendingMachine* machine = getAddressOfMachine(machineID);

	if (!machine) {
		throw std::exception("Machine was not found!");
	}

	return machine->getInventory();
}

void VendingController::sellProductInMachine(int machineID, const char* product) {
	VendingMachine* machine = getAddressOfMachine(machineID);

	if (!machine) {
		throw std::exception("Machine was not found!");
	}

	if (strcmp(product, "salty") == 0) {
		int numSalty = machine->getInventory().salty;
		
		if (numSalty == 0) {
			machine->addWarningMessage("Salty products are not in stock!");
		} else {
			if (numSalty < 10) {
				machine->addWarningMessage("Salty products will run out soon!");
			}

			machine->getInventory().changeSalty(numSalty - 1);
		}
	}
	else if (strcmp(product, "sweet") == 0) {
		int numSweet = machine->getInventory().sweet;

		if (numSweet == 0) {
			machine->addWarningMessage("Sweet products are not in stock!");
		}
		else {
			if (numSweet < 10) {
				machine->addWarningMessage("Sweet products will run out soon!");
			}

			machine->getInventory().changeSweets(numSweet - 1);
		}
	}
	else if (strcmp(product, "drinks") == 0) {
		int numDrinks = machine->getInventory().drinks;

		if (numDrinks == 0) {
			machine->addWarningMessage("Drink products are not in stock!");
		}
		else {
			if (numDrinks < 10) {
				machine->addWarningMessage("Drink products will run out soon!");
			}

			machine->getInventory().changeDrinks(numDrinks - 1);
		}
	}
	else {
		throw std::exception("This type of product was not found!");
	}
}

void VendingController::restockProductInMachine(int machineID, const char* product) {
	VendingMachine* machine = getAddressOfMachine(machineID);

	if (!machine) {
		throw std::exception("Machine was not found!");
	}

	if (strcmp(product, "salty") == 0) {
		int numSalty = machine->getInventory().salty;
		machine->getInventory().changeSalty(numSalty + 200);
	} else if (strcmp(product, "sweet") == 0) {
		int numSweet = machine->getInventory().sweet;
		machine->getInventory().changeSweets(numSweet + 200);
	} else if (strcmp(product, "drinks") == 0) {
		int numDrinks = machine->getInventory().drinks;
		machine->getInventory().changeDrinks(numDrinks + 200);
	} else {
		throw std::exception("This type of product was not found!");
	}
}

void VendingController::seeWarningMsgForMachine(int machineID) {
	VendingMachine* machine = getAddressOfMachine(machineID);

	if (!machine) {
		throw std::exception("The machine was not found!");
	}

	std::cout << "Machine #" << machineID << ":\n";
	machine->outputWarningMessages(std::cout);
}

void VendingController::seeAllWarningMessages(std::ostream& stream) {
	std::ifstream warningsFile("warinngs.txt");

	char buffer[1024];
	while (warningsFile.getline(buffer, 1024)) {
		stream << buffer << std::endl;
	}

	warningsFile.close();
}

std::ostream& operator<<(std::ostream& stream, const StringArray& array) {
	for (unsigned int index = 0; index < array.size; ++index) {
		stream << array.strings[index] << std::endl;
	}

	return stream;
}
