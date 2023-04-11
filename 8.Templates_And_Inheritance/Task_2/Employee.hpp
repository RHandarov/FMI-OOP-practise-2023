#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
private:
	std::string name;
	unsigned int experienceInMonths;
	unsigned int salary;

public:
	Employee(const std::string& name, const unsigned int experienceInMonths, const unsigned int salary) : name(name), experienceInMonths(experienceInMonths), salary(salary) {

	}
};

#endif // !EMPLOYEE_H
