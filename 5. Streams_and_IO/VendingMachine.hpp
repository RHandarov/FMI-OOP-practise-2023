#ifndef VENDING_MACHINE_H
#define VENDING_MACHINE_H

const unsigned int CAPACITY = 1000; //for test purpouses
unsigned int NEW_ID_COUNTER = 1;

struct Inventory {
    unsigned int salty;
    unsigned int sweet;
    unsigned int drinks;

    Inventory();

    void changeSalty(int quantity);
    void changeSweets(int quantity);
    void changeDrinks(int quantity);
    void print() const;
};

class VendingMachine {
    int id;
    char* address;
    Inventory inventory;
    char** warningMessages;
    int numWarningMsgs;
    int capacity;

    void setId(int id);
    void setAddress(const char* address);
    void setInventory(const Inventory& inventory);
    void setWarningMessages(const char** warningMessages);
    void setNumWarningMessages(int numWarningMessages);
    void setCapacity();

    void copy(int id, const char* address, const Inventory& inventory,
        int numWarningMessages, char** warningMessages);

    void move(int id, char* address, const Inventory& inventory,
        int numWarningMessages, char** warningMessages);

    void freeAddress();
    void freeWarningMessages();

public:
    VendingMachine(); //default constructor
    VendingMachine(char* address, Inventory inventory); //default constructor
    VendingMachine(VendingMachine const& other); // copy constructor
    VendingMachine(VendingMachine&& other); // move constructor
    VendingMachine& operator=(VendingMachine const& other);
    ~VendingMachine();

    //include other needed methods
    int getId() const;
    char* getAddress() const;
};


class VendingController {
    VendingMachine* vendingMachineList;
    int numMachines;
    int capacity;

    void setNumMachines(int numMachines);
    void setCapacity();
    void setVendingMachineList(const VendingMachine* vendingMachineList);

    void copy(int numMachines, const VendingMachine* machines);

    void freeMemory();

public:
    //include big 4-5-6 
    VendingController();
    VendingController(const VendingController& other);
    VendingController(VendingController&& other);

    VendingController& operator=(const VendingController& other);

    ~VendingController();

    void addVendingMachine(VendingMachine machine);
    char* getAddressOfMachine(int machineID);
    void getInventoryOfMachine(int machineID);
    void sellProductInMachine(int machineID, char* product);
    void restockProductInMachine(int machineID, char* product);
    void seeWarningMsgForMachine(int machineID);
};

#endif // !VENDING_MACHINE_H
