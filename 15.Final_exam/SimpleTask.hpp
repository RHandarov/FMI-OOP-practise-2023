#ifndef SIMPLE_TASK_HPP
#define SIMPLE_TASK_HPP

#include "Task.hpp"

class SimpleTask : public Task {
public:
	unsigned int getNeededTime() const override;
	std::ostream& print(std::ostream& stream = std::cout) const override;
	Task* clone() const override;
	void changeNeededTime(const unsigned int delta) override;
};

#endif // !SIMPLE_TASK_HPP