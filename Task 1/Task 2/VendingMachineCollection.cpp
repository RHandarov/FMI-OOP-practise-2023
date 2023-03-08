#include <exception>

#include "VendingMachineCollection.hpp"
#include "VendingMachine.hpp"

unsigned int VendingMachineCollection::calculateAppropriateCapacity() const {
	unsigned int newCapacity = 1;

	while (newCapacity < this->numNachines) {
		newCapacity <<= 1;
	}

	return newCapacity < 10 ? 10 : newCapacity;
}

void VendingMachineCollection::resize() {
	VendingMachine* buffer = new VendingMachine[this->capacity];

	for (unsigned int index = 0; index < this->numNachines; ++index) {
		buffer[index] = this->machines[index];
	}

	this->capacity = this->calculateAppropriateCapacity();

	delete[] this->machines;
	this->machines = new VendingMachine[this->capacity];

	for (unsigned int index = 0; index < this->numNachines; ++index) {
		this->machines[index] = buffer[index];
	}

	delete[] buffer;
}

void VendingMachineCollection::initialize(const VendingMachine* machines, const unsigned int numMachines) {
	this->numNachines = numMachines;
	this->capacity = this->calculateAppropriateCapacity();
	this->resize();

	for (unsigned int index = 0; index < numMachines; ++index) {
		this->machines[index] = machines[index];
	}
}

VendingMachineCollection::VendingMachineCollection() {
	this->machines = new VendingMachine[10];
	this->initialize(nullptr, 0);
}

VendingMachineCollection::VendingMachineCollection(const VendingMachineCollection& other) {
	this->initialize(other.machines, other.numNachines);
}

VendingMachineCollection& VendingMachineCollection::operator=(const VendingMachineCollection& other) {
	if (this != &other) {
		this->initialize(other.machines, other.numNachines);
	}

	return *this;
}

VendingMachine& VendingMachineCollection::getMachineById(unsigned int id) const {
	for (unsigned int index = 0; index < this->numNachines; ++index) {
		if (this->machines[index].getId() == id) {
			return this->machines[index];
		}
	}

	throw std::exception("Machine was not found!");
}

const char* VendingMachineCollection::getMachineAddressById(unsigned int id) const {
	return this->getMachineById(id).getAddress();
}

void VendingMachineCollection::getNumGoodsInMachineById(unsigned int id, unsigned int& numSweets,
	unsigned int& numSnacks, unsigned int& numBeverages) const {
	const VendingMachine& machine = this->getMachineById(id);

	numSweets = machine.getNumSweets();
	numSnacks = machine.getNumSnacks();
	numBeverages = machine.getNumBeverages();
}

VendingMachineCollection::~VendingMachineCollection() {
	delete[] this->machines;
}