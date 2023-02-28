#ifndef TIME_H
#define TIME_H

class Time {
private:
	unsigned int hour;
	unsigned int minute;
	unsigned int second;

	unsigned int getTimeInSeconds() const;
public:
	Time();
	Time(unsigned int hour, unsigned int minute, unsigned int second);
	Time(unsigned int timeInSeconds);

	Time getDifference(Time other) const;
};

#endif // !TIME_H

