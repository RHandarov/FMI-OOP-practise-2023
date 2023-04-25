#include <string>

#include "Employee.hpp"

Employee::Employee(std::string name, const unsigned int experience, const unsigned int salary) 
	: name(name), experience(experience), salary(salary)
{
}

void Employee::changeSalaryBy(const int delta) {
	if (delta < 0 && -delta >= salary) {
		salary = 0;
	}
	else {
		salary += delta;
	}
}

double Employee::getRaiseCoeficient() const {
	return 0.0;
}

void Employee::annualRaise() {
	changeSalaryBy(getRaiseCoeficient() * salary);
}
