#include "SimpleTask.hpp"

unsigned int SimpleTask::getNeededTime() const {
	return !isCompleted;
}

std::ostream& SimpleTask::print(std::ostream& stream) const {
	stream << "SimpleTask ";
	return Task::print(stream);
}

Task* SimpleTask::clone() const {
	return new SimpleTask(*this);
}

void SimpleTask::changeNeededTime(const unsigned int delta) {
}
