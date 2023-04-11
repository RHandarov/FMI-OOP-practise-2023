#ifndef QA_H
#define QA_H

#include "ITEmployee.hpp"

class QA : public ITEmployee {
private:
	bool isAutomation;

public:
	QA(const std::string& name, const unsigned int experienceInMonths, const unsigned int salary, const std::string& project, const bool isAutomation)
		: ITEmployee(name, experienceInMonths, salary, project), isAutomation(isAutomation) {

	}
};

#endif // !QA_H
