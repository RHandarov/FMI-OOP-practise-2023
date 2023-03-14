#include "Set.hpp"
#include <iostream>

//helper functions
void swap(int& a, int& b) {
	int help = a;
	a = b;
	b = help;
}

void Set::copy(const int* elements, const unsigned int numElements) {
	this->numElements = numElements;
	this->capacity = this->calculateCurrentCapacity();

	if (this->elements) {
		delete[] this->elements;
	}

	this->elements = new int[this->capacity];
	for (unsigned int index = 0; index < this->numElements; ++index) {
		this->elements[index] = elements[index];
	}
}

Set::Set() {
	this->elements = new int[10];
	this->numElements = 0;
	this->capacity = 10;
}

Set::Set(const Set& other) {
	this->copy(other.elements, other.numElements);
}

Set::Set(Set&& other) {
	this->numElements = other.numElements;
	this->capacity = other.capacity;
	this->elements = other.elements;

	other.numElements = other.capacity = 0;
	other.elements = nullptr;
}

Set& Set::operator=(const Set& other) {
	if (this != &other) {
		this->copy(other.elements, other.numElements);
	}

	return *this;
}

Set& Set::operator=(Set&& other) {
	if (this != &other) {
		this->numElements = other.numElements;
		this->capacity = other.capacity;
		
		delete[] this->elements;
		this->elements = other.elements;

		other.numElements = other.capacity = 0;
		other.elements = nullptr;
	}

	return *this;
}

Set::~Set() {
	delete[] this->elements;
}

unsigned int Set::calculateCurrentCapacity() const {
	unsigned int newCapacity = 1;

	while (newCapacity < this->numElements) {
		newCapacity <<= 1;
	}

	return newCapacity < 10 ? 10 : newCapacity;
}

void Set::resize() {
	if (!this->numElements) {
		//corner case
		delete[] this->elements;
		this->elements = new int[10];

		this->capacity = 10;

		return;
	}

	int* buffer = new int[this->numElements];

	for (unsigned int index = 0; index < this->numElements; ++index) {
		buffer[index] = this->elements[index];
	}

	delete[] this->elements;

	this->capacity = this->calculateCurrentCapacity();
	this->elements = new int[this->capacity];

	for (unsigned int index = 0; index < this->numElements; ++index) {
		this->elements[index] = buffer[index];
	}
}

int Set::getIndex(const int element) const {
	for (unsigned int index = 0; index < this->numElements; ++index) {
		if (this->elements[index] == element) {
			return index;
		}
	}

	return -1;
}

bool Set::addElement(const int element) {
	if (this->getIndex(element) != -1) {
		return false;
	}

	++this->numElements;

	if (this->numElements > this->capacity) {
		this->resize();
	}

	this->elements[this->numElements - 1] = element;

	return true;
}

bool Set::shouldResize() const {
	if (this->numElements <= 10 && this->capacity > 10) {
		return true;
	}

	if (this->numElements <= 10 && this->capacity <= 10) {
		return false;
	}

	if (this->numElements > 10 && this->numElements * 2 <= this->capacity) {
		return true;
	}

	return false;
}

bool Set::deleteElement(const int element) {
	int elementIndex = this->getIndex(element);

	if (elementIndex == -1) {
		return false;
	}

	swap(this->elements[elementIndex], this->elements[this->numElements - 1]);
	--this->numElements;

	if (this->shouldResize()) {
		this->resize();
	}
}

void Set::setUnion(const Set& other) {
	for (unsigned int index = 0; index < other.numElements; ++index) {
		this->addElement(other.elements[index]);
	}
}

void Set::setIntersection(const Set& other) {
	Set intersection;

	for (unsigned int index = 0; index < this->numElements; ++index) {
		if (other.getIndex(this->elements[index]) != -1) {
			intersection.addElement(this->elements[index]);
		}
	}

	*this = intersection;
}

void Set::print() const {
	std::cout << '(';

	for (unsigned int index = 0; index < this->numElements; ++index) {
		if (index) {
			std::cout << ", ";
		}

		std::cout << this->elements[index];
	}

	std::cout << ')';
}