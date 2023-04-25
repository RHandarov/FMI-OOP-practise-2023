#include "Manager.hpp"
#include "Employee.hpp"

double Manager::getRaiseCoeficient() const {
	if (numManagedPeople >= 1 && numManagedPeople <= 10) {
		return 0.06;
	} else if (numManagedPeople >= 11 && numManagedPeople <= 15) {
		return 0.12;
	}

	return 0.15;
}

Manager::Manager(std::string name, const unsigned int experience, const unsigned int salary, const unsigned int numManagedPeople)
	: Employee(name, experience, salary), numManagedPeople(numManagedPeople)
{
}
