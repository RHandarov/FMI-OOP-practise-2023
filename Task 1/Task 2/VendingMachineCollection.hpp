#ifndef VENDING_MACHINE_COLLECTION_H
#define VENDING_MACHINE_COLLECTION_H

#include "VendingMachine.hpp"

class VendingMachineCollection {
private:
	VendingMachine* machines;
	unsigned int numNachines;
	unsigned int capacity;

	unsigned int calculateAppropriateCapacity() const;
	void resize();

	void initialize(const VendingMachine* machines, const unsigned int numMachines);
public:
	VendingMachineCollection();
	VendingMachineCollection(const VendingMachineCollection& other);

	VendingMachineCollection& operator=(const VendingMachineCollection& other);

	void addMachine();

	//returns the address in the heap
	const char* getMachineAddressById(unsigned int id) const;
	void getNumGoodsInMachineById(unsigned int id, unsigned int& numSweets,
		unsigned int& numSnacks, unsigned int& numBeverages) const;

	void sellSweet(unsigned int machineId);
	void sellSnack(unsigned int machineId);
	void sellBeverage(unsigned int machineId);

	void addSweet(unsigned int machineId, unsigned int amount);
	void addSnack(unsigned int machineId, unsigned int amount);
	void addBeverage(unsigned int machineId, unsigned int amount);

	~VendingMachineCollection();
};

#endif // !VENDING_MACHINE_COLLECTION_H

