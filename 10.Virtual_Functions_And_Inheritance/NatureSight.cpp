#include "NatureSight.hpp"

NatureSight::NatureSight(const double location, const std::string& description, const unsigned long long appropriateMonthsForVisits)
	: Sight(location, description), appropriateMonthsForVisits(appropriateMonthsForVisits)
{
}
