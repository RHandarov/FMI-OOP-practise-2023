#ifndef VENDING_MACHINE_H
#define VENDING_MACHINE_H

class VendingMachine {
private:
	unsigned int id;
	char* address;
	unsigned int numSweets, numSnacks, numBeverages;

	void initializeFieldsWith(const unsigned int id, const char* address,
		const unsigned int numSweets, const unsigned int numSnacks,
		const unsigned int numBeverages);

	void setAddress(const char* address);
public:
	VendingMachine();
	VendingMachine(const unsigned int id, const char* address,
		const unsigned int numSweets, const unsigned int numSnacks,
		const unsigned int numBeverages);
	VendingMachine(const VendingMachine& other);

	VendingMachine& operator=(const VendingMachine& other);

	~VendingMachine();
};

#endif // !VENDING_MACHINE_H
