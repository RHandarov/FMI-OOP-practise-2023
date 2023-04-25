#include <string>

#include "Programmer.hpp"
#include "ITSpecialist.hpp"

double Programmer::getRaiseCoeficient() const {
	double averageProjectComplexity = getAverageProjectsComplexity();

	if (averageProjectComplexity >= 1 && averageProjectComplexity <= 4) {
		return 0.06;
	} else if (averageProjectComplexity >= 5 && averageProjectComplexity <= 7) {
		return 0.12;
	}

	return 0.15;
}

Programmer::Programmer(std::string name, const unsigned int experience, const unsigned int salary, const std::string& programmingLanguage)
	: ITSpecialist(name, experience, salary), programmingLanguage(programmingLanguage)
{
}
