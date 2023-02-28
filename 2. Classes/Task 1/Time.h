#ifndef TIME_H
#define TIME_H

class Time {
private:
	unsigned int hour;
	unsigned int minute;
	unsigned int second;
public:
	Time();
	Time(unsigned int hour, unsigned int minute, unsigned int second);

	Time getDifference(Time other) const;
};

#endif // !TIME_H

