#ifndef PROGRAMMER_H
#define PROGRAMMER_H

#include <string>

#include "ITEmployee.hpp"

class Programmer : public ITEmployee {
private:
	std::string programmingLanguage;

public:
	Programmer(const std::string& name, const unsigned int experienceInMonths, const unsigned int salary, const std::string& project, const std::string& programmingLanguage)
		: ITEmployee(name, experienceInMonths, salary, project), programmingLanguage(programmingLanguage) {

	}
};

#endif // !PROGRAMMER_H