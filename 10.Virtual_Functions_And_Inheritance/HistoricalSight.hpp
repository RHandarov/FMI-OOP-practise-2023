#ifndef HISTORICAL_SIGHT_H
#define HISTORICAL_SIGHT_H

#include <string>

#include "Sights.hpp"

class HistoricalSight : public Sight {
private:
	unsigned int eventYear;

public:
	HistoricalSight(const double location, const std::string& description, const unsigned int eventYear);
};

#endif // !HISTORICAL_SIGHT_H