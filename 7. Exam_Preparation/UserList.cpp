#include <utility>

#include "UserList.hpp"

const unsigned int INITIAL_CAPACITY = 10;

void UserList::free() {
	for (unsigned int index = 0; index < this->size; ++index) {
		delete this->data[index];
	}

	delete[] this->data;
}

void UserList::copyFrom(const UserList& other) {
	this->free();

	this->size = other.size;
	this->capacity = other.capacity;

	this->data = new User * [this->capacity];
	for (unsigned int index = 0; index < this->size; ++index) {
		this->data[index] = new User(*other.data[index]);
	}
}

void UserList::moveFrom(UserList&& other) {
	this->free();

	this->size = other.size;
	this->capacity - other.capacity;
	this->data = other.data;

	other.data = nullptr;
	other.size = 0;
}

UserList::UserList() : data(new User*[INITIAL_CAPACITY]), size(0), capacity(INITIAL_CAPACITY) {
}

UserList::UserList(const UserList& other) : data(nullptr), size(0) {
	this->copyFrom(other);
}

UserList::UserList(UserList&& other) : data(nullptr), size(0) {
	this->moveFrom(std::move(other));
}

UserList& UserList::operator=(const UserList& other) {
	if (this != &other) {
		this->copyFrom(other);
	}

	return *this;
}

UserList& UserList::operator=(UserList&& other) {
	if (this != &other) {
		this->moveFrom(std::move(other));
	}

	return *this;
}

UserList::~UserList() {
	this->free();
}
