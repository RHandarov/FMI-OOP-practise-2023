#ifndef WENDING_MACHINE_H
#define WENDING_MACHINE_H

#include <ostream>
#include <fstream>

struct Inventory {
    unsigned int salty;
    unsigned int sweet;
    unsigned int drinks;

    Inventory();

    void changeSalty(int quantity);
    void changeSweets(int quantity);
    void changeDrinks(int quantity);
    void print();
};

class StringArray {
private:
    char** strings;
    unsigned int size;
    unsigned int capacity;

    void allocateMemory();
    void freeMemory();

    unsigned int getNewCapacity() const;
    void setStringsToBuffer(char**& destination) const;

    void resize();

    void setString(const char* string, unsigned int index);
    void setStrings(char** strings, unsigned int size);

    void copy(const StringArray& other);

public:
    StringArray();
    StringArray(const StringArray& other);

    void addString(const char* string);

    void print() const;

    StringArray& operator=(const StringArray& other);

    friend std::ostream& operator<<(std::ostream& stream, const StringArray& array);

    ~StringArray();
};

class VendingMachine {
    int id;
    char* address;
    Inventory inventory;
    StringArray warningMessages;
    std::ofstream warningsFile;

    void freeAddress();

    void setId(int id);
    void setAddress(const char* address);
    void setInventory(const Inventory& other);
    void setWarningMessages(const StringArray& other);

    void copy(const VendingMachine& other);
    void move(VendingMachine&& other);

public:
    VendingMachine(); //default constructor
    VendingMachine(const char* address, Inventory inventory); //default constructor
    VendingMachine(VendingMachine const& other); // copy constructor
    VendingMachine(VendingMachine&& other); // move constructor
    VendingMachine& operator=(VendingMachine const& other);
    ~VendingMachine();

    //include other needed methods
    int getId() const;
    Inventory& getInventory();

    void addWarningMessage(const char* message);

    void outputWarningMessages(std::ostream& stream) const;
};


class VendingController {
    VendingMachine* vendingMachineList;
    int numMachines;
    int capacity;

    void free() {
        delete[] vendingMachineList;
        vendingMachineList = nullptr;
    }

    void setNumMachines(unsigned int numMachines);
    void setCapacity();
    void setVendingMachineList(const VendingMachine* list, int size);

    void copyToBuffer(VendingMachine*& other);

    void allocateEmptyList();
    void resize();

    void copy(const VendingController& other);

public:
    //include big 4-5-6 
    VendingController();
    VendingController(const VendingController& other);

    VendingController& operator=(const VendingController& other);

    ~VendingController();

    void addVendingMachine(VendingMachine machine);
    VendingMachine* getAddressOfMachine(int machineID);
    Inventory& getInventoryOfMachine(int machineID);
    void sellProductInMachine(int machineID, const char* product);
    void restockProductInMachine(int machineID, const char* product);
    void seeWarningMsgForMachine(int machineID);
    void seeAllWarningMessages(std::ostream& stream);
};

#endif // !WENDING_MACHINE_H
