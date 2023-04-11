#ifndef ITEMPLOYEE_H
#define ITEMPLOYEE_H

#include <string>

#include "Employee.hpp"

class ITEmployee : public Employee {
private:
	std::string project;

public:
	ITEmployee(const std::string& name, const unsigned int experienceInMonths, const unsigned int salary, const std::string& project) : Employee(name, experienceInMonths, salary), project(project) {

	}
};

#endif // !ITEMPLOYEE_H
