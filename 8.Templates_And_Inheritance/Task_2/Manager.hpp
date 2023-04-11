#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.hpp"

class Manager : public Employee {
private:
	unsigned int numManagedPeople;

public:
	Manager(const std::string& name, const unsigned int experienceInMonths, const unsigned int salary, const unsigned int numManagedPeople)
		: Employee(name, experienceInMonths, salary), numManagedPeople(numManagedPeople) {

	}
};

#endif // !MANAGER_H
