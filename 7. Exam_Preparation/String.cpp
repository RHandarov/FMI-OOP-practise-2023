#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <utility>
#include <ostream>

#include "String.hpp"

const unsigned int INITIAL_CAPACITY = 10;

unsigned int getOptimalCapacity(unsigned int size) {
	unsigned int capacity = INITIAL_CAPACITY;

	while (capacity < size) {
		capacity <<= 1;
	}

	return capacity + 1;
}

void String::free() {
	delete[] this->data;
	this->data = nullptr;
}

void String::setString(const char* newData) {
	this->free();

	this->size = strlen(newData);
	this->capacity = getOptimalCapacity(this->size);
	this->data = new char[this->capacity];
	strcpy(this->data, newData);
}

void String::moveFrom(String&& other) {
	this->free();

	this->size = other.size;
	this->capacity = other.capacity;
	this->data = other.data;

	other.data = nullptr;
}

String::String() : data(new char[INITIAL_CAPACITY + 1]), size(0), capacity(INITIAL_CAPACITY + 1) {
	data[0] = '\0';
}

String::String(const char* string) : data(nullptr) {
	this->setString(string);
}

String::String(const String& other) : data(nullptr) {
	this->setString(other.data);
}

String::String(String&& other) : data(nullptr) {
	this->moveFrom(std::move(other));
}

String& String::operator=(const String& other) {
	if (this != &other) {
		this->setString(other.data);
	}

	return *this;
}

String& String::operator=(String&& other) {
	if (this != &other) {
		this->moveFrom(std::move(other));
	}

	return *this;
}

bool String::operator==(const String& other) const {
	return strcmp(this->data, other.data) == 0;
}

String::~String() {
	this->free();
}

std::ostream& operator<<(std::ostream& stream, const String& string) {
	return stream << string.size << ' ' << string.data;
}
