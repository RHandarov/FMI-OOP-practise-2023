#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <utility>
#include <exception>
#include <iostream>

#include "String.hpp"

void String::freeMemory() {
	delete[] data;
	data = nullptr;
}

void String::setData(const char* data) {
	freeMemory();

	if (data) {
		this->data = new char[capacity];
		strcpy(this->data, data);
	}
}

void String::setSize(unsigned int size) {
	this->size = size;
}

void String::setCapacity() {
	capacity = 1;

	while (capacity < size) {
		capacity <<= 1;
	}

	if (capacity < MIN_CAPACITY) {
		capacity = MIN_CAPACITY;
	}

	++capacity;
}

void String::resize() {
	char* buffer = new char[capacity];
	strcpy(buffer, data);

	freeMemory();

	setCapacity();
	setData(buffer);

	delete[] buffer;
}

void String::copy(const String& other) {
	freeMemory();

	size = other.size;
	capacity = other.capacity;
	setData(other.data);
}

void String::copy(const char* data) {
	freeMemory();

	setSize(strlen(data));
	setCapacity();
	setData(data);
}

void String::move(String&& other) {
	freeMemory();

	size = other.size;
	capacity = other.capacity;
	data = other.data;

	other.data = nullptr;
}

String& String::append(const char* data) {
	if (!data) {
		return *this;
	}

	unsigned int oldSize = size;

	setSize(size + strlen(data));
	resize();

	for (unsigned int index = oldSize; index < size; ++index) {
		this->data[index] = data[index - oldSize];
	}

	this->data[size] = '\0';

	return *this;
}

String::String(const char* data) : data(nullptr) {
	copy(data);
}

String::String(const String& other) : data(nullptr) {
	copy(other);
}

String::String(String&& other) : data(nullptr) {
	move(std::move(other));
}

String& String::operator=(const char* data) {
	copy(data);

	return *this;
}

String& String::operator=(const String& other) {
	if (this != &other) {
		copy(other);
	}

	return *this;
}

String& String::operator=(String&& other) {
	move(std::move(other));

	return *this;
}

char String::operator[](unsigned int index) const {
	if (index > size) {
		throw std::exception("Index is out of bounds!");
	}

	return data[index];
}

String String::operator+(const String& other) const {
	return String(data).append(other.data);
}

String String::operator+(const char* data) const {
	return String(this->data).append(data);
}

bool String::operator==(const String& other) const {
	return strcmp(data, other.data) == 0;
}

bool String::operator==(const char* other) const {
	return strcmp(data, other) == 0;
}

bool String::operator!=(const String& other) const {
	return strcmp(data, other.data) != 0;
}

bool String::operator!=(const char* other) const {
	return strcmp(data, other) != 0;
}

bool String::operator<=(const String& other) const {
	return strcmp(data, other.data) <= 0;
}

bool String::operator<=(const char* other) const {
	return strcmp(data, other) <= 0;
}

bool String::operator<(const String& other) const {
	return strcmp(data, other.data) < 0;
}

bool String::operator<(const char* other) const {
	return strcmp(data, other) < 0;
}

bool String::operator>(const String& other) const {
	return strcmp(data, other.data) > 0;
}

bool String::operator>(const char* other) const {
	return strcmp(data, other) > 0;
}

bool String::operator>=(const String& other) const {
	return strcmp(data, other.data) >= 0;
}

bool String::operator>=(const char* other) const {
	return strcmp(data, other) >= 0;
}

bool operator!=(const char* leftHandSide, const String& rightHandSide) {
	return strcmp(leftHandSide, rightHandSide.data) != 0;
}

bool operator==(const char* leftHandSide, const String& rightHandSide) {
	return strcmp(leftHandSide, rightHandSide.data) == 0;
}

String operator+(const char* leftHandSide, const String& rightHandSide) {
	return String(leftHandSide).append(rightHandSide.data);
}

bool operator<=(const char* leftHandSide, const String& rightHandSide) {
	return strcmp(leftHandSide, rightHandSide.data) <= 0;
}

bool operator<(const char* leftHandSide, const String& rightHandSide) {
	return strcmp(leftHandSide, rightHandSide.data) < 0;
}

bool operator>(const char* leftHandSide, const String& rightHandSide) {
	return strcmp(leftHandSide, rightHandSide.data) > 0;
}

bool operator>=(const char* leftHandSide, const String& rightHandSide) {
	return strcmp(leftHandSide, rightHandSide.data) >= 0;
}

std::istream& operator>>(std::istream& stream, String& string) {
	if (!stream) {
		string = String();

		return stream;
	}

	char buffer[MAX_STRING_SIZE_FROM_IN_STREAM + 1];
	stream.getline(buffer, MAX_STRING_SIZE_FROM_IN_STREAM + 1);

	string = String(buffer);

	return stream;
}

std::ostream& operator<<(std::ostream& stream, const String& string) {
	if (!stream) {
		return stream;
	}

	stream << string.data;
	return stream;
}

inline unsigned int String::length() const {
	return size;
}

inline bool String::empty() const {
	return size == 0;
}

inline const char* String::c_str() const {
	return data;
}

String::~String() {
	freeMemory();
}
