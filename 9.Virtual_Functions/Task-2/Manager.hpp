#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.hpp"

class Manager : public Employee {
private:
	unsigned int numManagedPeople;

	double getRaiseCoeficient() const;

public:
	Manager(std::string name, const unsigned int experience, const unsigned int salary, const unsigned int numManagedPeople);
};

#endif // !MANAGER_H

