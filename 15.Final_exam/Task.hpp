#ifndef TASK_HPP
#define TASK_HPP

#include <string>
#include <iostream>

class Task {
private:
	std::string description;
	unsigned int size;
	unsigned int progress;

protected:
	bool isCompleted;

public:
	Task(const std::string& description, const unsigned int size);

	const std::string& getDescription() const;
	const unsigned int getSize() const;
	const unsigned int getProgress() const;
	const bool getCompleteness() const;
	virtual unsigned int getNeededTime() const = 0;

	unsigned int work(const unsigned int decicatedTime);
	virtual void changeNeededTime(const unsigned int delta) = 0;
	virtual std::ostream& print(std::ostream& stream = std::cout) const;

	virtual Task* clone() const = 0;

	virtual ~Task() {};
};

#endif // !TASK_HPP