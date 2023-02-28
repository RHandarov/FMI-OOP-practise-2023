#define _CRT_SECURE_NO_WARNINGS

#include "Event.h"
#include "Time.h"
#include <cstring>

//helper class functions
Time min(const Time a, const Time b) {
	if (a.compare(b) == -1) {
		return a;
	}

	return b;
}

Time max(const Time a, const Time b) {
	if (a.compare(b) == 1) {
		return a;
	}

	return b;
}

Event::Event() {
	title[0] = '\0';
	organizer[0] = '\0';
	startTime = endTime = Time();
}

Event::Event(const char* title, const char* organizer, const Time startTime, const Time endTime) {
	strcpy(this->title, title);
	strcpy(this->organizer, organizer);
	this->startTime = startTime;
	this->endTime = endTime;
}

Time Event::getDuration() const {
	return endTime.getDifference(startTime);
}

bool Event::areIntersecting(const Event other) const {
	Time low = max(this->startTime, other.startTime);
	Time high = min(this->endTime, other.endTime);

	return low.compare(high) <= 0;
}