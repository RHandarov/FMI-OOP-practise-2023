#ifndef NATURE_SIGHT_H
#define NATURE_SIGHT_H

#include <string>

#include "Sights.hpp"

class NatureSight : public Sight {
private:
	unsigned long long appropriateMonthsForVisits;

public:
	NatureSight(const double location, const std::string& description, const unsigned long long appropriateMonthsForVisits);
};

#endif // !NATURE_SIGHT_H