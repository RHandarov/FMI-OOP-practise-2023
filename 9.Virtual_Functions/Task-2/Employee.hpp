#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
private:
	std::string name;
	unsigned int experience;
	unsigned int salary;

protected:
	Employee(std::string name, const unsigned int experience, const unsigned int salary);

	void changeSalaryBy(const int delta);
	virtual double getRaiseCoeficient() const;

public:
	virtual void annualRaise();
};

#endif // !EMPLOYEE_H

