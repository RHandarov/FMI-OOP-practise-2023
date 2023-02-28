#ifndef EVENT_H
#define EVENT_H

#include "Time.h"

const int MAX_STRING_SIZE = 129; //because of \0

class Event {
private:
	char title[MAX_STRING_SIZE];
	char organizer[MAX_STRING_SIZE];
	Time startTime;
	Time endTime;
public:
	Event();
	Event(const char* title, const char* organizer, const Time startTime, const Time endTime);

	Time getDuration() const;
	bool areIntersecting(const Event other) const;
};

#endif // !EVENT_H

