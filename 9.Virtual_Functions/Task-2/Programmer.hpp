#ifndef PROGRAMMER_H
#define PROGRAMMER_H

#include <string>

#include "ITSpecialist.hpp"

class Programmer : public ITSpecialist {
private:
	std::string programmingLanguage;

	double getRaiseCoeficient() const;

public:
	Programmer(std::string name, const unsigned int experience, const unsigned int salary, const std::string& programmingLanguage);
};

#endif // !PROGRAMMER_H