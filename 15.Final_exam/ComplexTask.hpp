#ifndef COMPLEX_TASK_HPP
#define COMPLEX_TASK_HPP

#include <vector>

#include "Task.hpp"

class ComplexTask {
private:
	std::vector<Task*> tasks;

	void setTasks(const std::vector<Task*>& tasks);
	void move(ComplexTask&& other) noexcept;

	void free() noexcept;

public:
	ComplexTask(const std::vector<Task*>& tasks);
	ComplexTask(const ComplexTask& other);
	ComplexTask(ComplexTask&& other) noexcept;

	ComplexTask& operator=(const ComplexTask& other);
	ComplexTask& operator=(ComplexTask&& other) noexcept;

	~ComplexTask();
};

#endif // !COMPLEX_TASK_HPP