#ifndef LONG_TASK_HPP
#define LONG_TASK_HPP

#include "Task.hpp">

class LongTask : public Task {
private:
	unsigned int neededTime;

public:
	LongTask(const std::string& description, const unsigned int size, const unsigned int neededTime);;

	unsigned int getNeededTime() const override;
	std::ostream& print(std::ostream& stream = std::cout) const override;
	Task* clone() const override;
	void changeNeededTime(const unsigned int delta) override;
};

#endif // !LONG_TASK_HPP

