#ifndef QA_H
#define QA_H

#include "ITSpecialist.hpp"

class QA : public ITSpecialist {
private:
	bool isAutomation;

public:
	QA(std::string name, const unsigned int experience, const unsigned int salary, const bool isAutomation);
};

#endif // !QA_H

