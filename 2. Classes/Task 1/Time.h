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

	void setHour(unsigned int hour);
	unsigned int getHour() const;

	void setMinute(unsigned int minute);
	unsigned int getMinute() const;

	void setSecond(unsigned int second);
	unsigned int getSecond() const;

	Time getDifference(const Time other) const;
	Time addToTime(const Time other) const;
	void printToConsole() const;

	int compare(const Time other) const;
};

#endif // !TIME_H

