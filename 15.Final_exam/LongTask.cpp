#include "LongTask.hpp"

LongTask::LongTask(const std::string& description, const unsigned int size, const unsigned int neededTime)
	: Task(description, size), neededTime(neededTime) {
}

unsigned int LongTask::getNeededTime() const {
	return neededTime;
}

std::ostream& LongTask::print(std::ostream& stream) const {
	stream << "LongTask ";
	return Task::print(stream);
}

Task* LongTask::clone() const {
	return new LongTask(*this);
}

void LongTask::changeNeededTime(const unsigned int delta) {
	neededTime += delta;
}
