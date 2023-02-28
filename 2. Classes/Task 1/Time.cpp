#include "Time.h"
#include <exception>
#include <iostream>

//helper functions
inline unsigned int absoluteValue(unsigned int a, unsigned int b) {
	if (a > b) {
		return a - b;
	}

	return b - a;
}

void Time::setHour(unsigned int hour) {
	if (hour >= 24) {
		throw std::exception("Hours cannot be bigger than 23!");
	}

	this->hour = hour;
}

unsigned int Time::getHour() const {
	return hour;
}

void Time::setMinute(unsigned int minute) {
	if (minute >= 60) {
		throw std::exception("Minutes cannot be bigger than 59!");
	}

	this->minute = minute;
}

unsigned int Time::getMinute() const {
	return minute;
}

void Time::setSecond(unsigned int second) {
	if (second >= 60) {
		throw std::exception("Seconds cannot be bigger than 59!");
	}

	this->second = second;
}

unsigned int Time::getSecond() const {
	return second;
}

Time::Time() {
	setHour(0);
	setMinute(0);
	setSecond(0);
}

Time::Time(unsigned int hour, unsigned int minute, unsigned int second) {
	setHour(hour);
	setMinute(minute);
	setSecond(second);
}

Time::Time(unsigned int timeInSeconds) {
	if (timeInSeconds >= 24 * 60 * 60) {
		throw std::exception("Time in seconds is bigger than its allowed!");
	}

	this->second = timeInSeconds % 60;
	timeInSeconds /= 60;
	this->minute = timeInSeconds % 60;
	timeInSeconds /= 60;
	this->hour = timeInSeconds;
}

inline unsigned int Time::getTimeInSeconds() const {
	return hour * 60 * 60 + minute * 60 + second;
}

Time Time::getDifference(Time other) const {
	unsigned int firstTimeInSeconds = getTimeInSeconds();
	unsigned int secondTimeInSeconds = other.getTimeInSeconds();
	unsigned int differenceInSeconds = absoluteValue(firstTimeInSeconds, secondTimeInSeconds);
	return Time(differenceInSeconds);
}

void Time::printToConsole() const {
	std::cout << '(' << hour << ", " << minute << ", " << second << ')';
}

Time Time::addToTime(Time other) const {
	return Time(getTimeInSeconds() + other.getTimeInSeconds());
}