#include "HistoricalSight.hpp"

HistoricalSight::HistoricalSight(const double location, const std::string& description, const unsigned int eventYear)
	: Sight(location, description), eventYear(eventYear)
{
}
