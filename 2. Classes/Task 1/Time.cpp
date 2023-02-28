#include "Time.h"
#include <exception>

Time::Time() {
	this->hour = 0;
	this->minute = 0;
	this->second = 0;
}

Time::Time(unsigned int hour, unsigned int minute, unsigned int second) {
	if (hour >= 24) {
		throw std::exception("Hours cannot be bigger than 23!");
	}

	this->hour = hour;

	if (minute >= 60) {
		throw std::exception("Minutes cannot be bigger than 59!");
	}

	this->minute = minute;

	if (second >= 60) {
		throw std::exception("Seconds cannot be bigger than 59!");
	}

	this->second = second;
}

Time Time::getDifference(Time other) const {
	return Time();
}