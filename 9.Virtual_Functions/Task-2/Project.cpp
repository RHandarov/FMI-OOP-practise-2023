#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <stdexcept>
#include <utility>

#include "Project.hpp"

void Project::free() noexcept {
	delete[] name;
}

void Project::copy(const Project& other) {
	setComplexity(other.complexity);
	setName(other.name);
}

void Project::move(Project&& other) noexcept {
	complexity = other.complexity;
	name = other.name;

	other.name = nullptr;
}

void Project::setName(const char* name) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void Project::setComplexity(const unsigned int complexity) {
	if (complexity == 0 || complexity > 10) {
		throw std::exception("The complexity should be in the range [1, 10]!");
	}

	this->complexity = complexity;
}

Project::Project(const char* name, const unsigned int complexity) {
	setComplexity(complexity);
	setName(name);
}

Project::Project(const Project& other) {
	copy(other);
}

Project::Project(Project&& other) noexcept {
	move(std::move(other));
}

const char* Project::getName() const {
	return name;
}

unsigned int Project::getComplexity() const {
	return complexity;
}

Project& Project::operator=(const Project& other) {
	if (this != &other) {
		free();
		copy(other);
	}

	return *this;
}

Project& Project::operator=(Project&& other) noexcept {
	if (this != &other) {
		free();
		move(std::move(other));
	}

	return *this;
}

Project::~Project() {
	free();
}
