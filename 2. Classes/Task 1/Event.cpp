#define _CRT_SECURE_NO_WARNINGS

#include "Event.h"
#include "Time.h"
#include <cstring>

Event::Event() {
	title[0] = '\0';
	organizer[0] = '\0';
	startTime = endTime = Time();
}

Event::Event(const char* title, const char* organizer, Time startTime, Time endTime) {
	strcpy(this->title, title);
	strcpy(this->organizer, organizer);
	this->startTime = startTime;
	this->endTime = endTime;
}

Time Event::getDuration() const {
	return endTime.getDifference(startTime);
}