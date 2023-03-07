#include "Set.hpp"

void Set::copy(const int* elements, const unsigned int numElements, const unsigned int capacity) {
	this->numElements = numElements;
	this->capacity = capacity;

	if (this->elements) {
		delete[] this->elements;
	}

	this->elements = new int[this->capacity];
	for (unsigned int index = 0; index < this->capacity; ++index) {
		this->elements[index] = elements[index];
	}
}

Set::Set() {
	this->elements = new int[10];
	this->numElements = 0;
	this->capacity = 10;
}

Set::Set(const Set& other) {
	this->copy(other.elements, other.numElements, other.capacity);
}

Set& Set::operator=(const Set& other) {
	if (this != &other) {
		this->copy(other.elements, other.numElements, other.capacity);
	}

	return *this;
}

Set::~Set() {
	delete[] this->elements;
}