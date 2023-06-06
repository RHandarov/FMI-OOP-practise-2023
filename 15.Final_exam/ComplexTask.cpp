#include "ComplexTask.hpp"

void ComplexTask::setTasks(const std::vector<Task*>& tasks) {
	for (unsigned int index = 0; index < tasks.size(); ++index) {
		this->tasks.emplace_back(tasks[index]->clone());
	}
}

void ComplexTask::move(ComplexTask&& other) noexcept {
	tasks = std::move(other.tasks);
}

void ComplexTask::free() noexcept {
	for (unsigned int index = 0; index < tasks.size(); ++index) {
		delete tasks[index];
	}
}

ComplexTask::ComplexTask(const std::vector<Task*>& tasks) {
	setTasks(tasks);
}

ComplexTask::ComplexTask(const ComplexTask& other) {
	setTasks(other.tasks);
}

ComplexTask::ComplexTask(ComplexTask&& other) noexcept {
	move(std::move(other));
}

ComplexTask& ComplexTask::operator=(const ComplexTask& other) {
	if (this != &other) {
		free();
		setTasks(other.tasks);
	}

	return *this;
}

ComplexTask& ComplexTask::operator=(ComplexTask&& other) noexcept {
	if (this != &other) {
		free();
		move(std::move(other));
	}

	return *this;
}

ComplexTask::~ComplexTask() {
	free();
}
