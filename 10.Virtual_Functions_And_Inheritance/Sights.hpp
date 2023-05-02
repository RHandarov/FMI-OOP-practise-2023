#ifndef SIGHTS_H
#define SIGHTS_H

#include <string>

class Sight {
private:
	double location;
	std::string description;

protected:
	Sight(const double location, const std::string& description);
};

#endif // !SIGHTS_H