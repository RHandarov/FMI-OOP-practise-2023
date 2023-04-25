#include "QA.hpp"
#include "ITSpecialist.hpp"

QA::QA(std::string name, const unsigned int experience, const unsigned int salary, const bool isAutomation)
	: ITSpecialist(name, experience, salary), isAutomation(isAutomation)
{
}
