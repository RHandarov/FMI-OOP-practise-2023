#include <string>
#include <utility>

#include "ITSpecialist.hpp"
#include "Project.hpp"

void ITSpecialist::free() noexcept {
	for (unsigned int index = 0; index < size; ++index) {
		delete projects[index];
	}

	delete[] projects;
}

void ITSpecialist::copy(const ITSpecialist& other) {
	size = other.size;
	capacity = other.capacity;

	projects = new Project * [capacity];
	for (unsigned int index = 0; index < size; ++index) {
		projects[index] = new Project(*other.projects[index]);
	}
}

void ITSpecialist::move(ITSpecialist&& other) noexcept {
	size = other.size;
	capacity = other.capacity;
	projects = other.projects;

	other.size = 0;
	other.projects = nullptr;
}

ITSpecialist::~ITSpecialist() {
	free();
}

ITSpecialist::ITSpecialist(std::string name, const unsigned int experience, const unsigned int salary)
	: Employee(name, experience, salary), size(0), capacity(4)
{
	projects = new Project * [capacity];
	for (unsigned int index = 0; index < capacity; ++index) {
		projects[index] = nullptr;
	}
}

ITSpecialist::ITSpecialist(const ITSpecialist& other) : Employee(other) {
	copy(other);
}

ITSpecialist::ITSpecialist(ITSpecialist&& other) noexcept : Employee(other) {
	move(std::move(other));
}

double ITSpecialist::getAverageProjectsComplexity() const {
	unsigned int totalComplexity = 0;

	for (unsigned int index = 0; index < size; ++index) {
		totalComplexity += projects[index]->getComplexity();
	}

	return ((double)totalComplexity) / size;
}

ITSpecialist& ITSpecialist::operator=(const ITSpecialist& other) {
	if (this != &other) {
		Employee::operator=(other);

		free();
		copy(other);
	}

	return *this;
}

ITSpecialist& ITSpecialist::operator=(ITSpecialist&& other) noexcept {
	if (this != &other) {
		Employee::operator=(std::move(other));

		free();
		move(std::move(other));
	}

	return *this;
}
