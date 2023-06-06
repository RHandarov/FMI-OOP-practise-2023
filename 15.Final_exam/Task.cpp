#include "Task.hpp"

Task::Task(const std::string& description, const unsigned int size)
	: description(description), size(size), progress(0), isCompleted(false) {
}

const std::string& Task::getDescription() const {
	return description;
}

const unsigned int Task::getSize() const {
	return size;
}

const unsigned int Task::getProgress() const {
	return progress;
}

const bool Task::getCompleteness() const {
	return isCompleted;
}

unsigned int Task::work(const unsigned int decicatedTime) {
	unsigned int neededTime = getNeededTime();
	unsigned int result = abs((int)decicatedTime - (int)neededTime);
	
	if (decicatedTime < neededTime) {
		changeNeededTime(result);
	} else {
		isCompleted = true;
	}

	return result;
}

std::ostream& Task::print(std::ostream& stream) const {
	return stream << description << ' ' << size << ' ' << progress;
}
