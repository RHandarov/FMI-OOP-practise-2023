#include <utility>
#include <exception>

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

void UserList::resize(const unsigned int capacity) {
	if (capacity < this->size) {
		return;
	}

	this->capacity = capacity;

	User** buffer = new User * [this->capacity];
	for (unsigned int index = 0; index < this->size; ++index) {
		buffer[index] = this->data[index];
	}

	delete[] this->data;
	this->data = buffer;
}

UserList::UserList() : data(new User*[INITIAL_CAPACITY]), size(0), capacity(INITIAL_CAPACITY) {
}

UserList::UserList(const UserList& other) : data(nullptr), size(0) {
	this->copyFrom(other);
}

UserList::UserList(UserList&& other) : data(nullptr), size(0) {
	this->moveFrom(std::move(other));
}

unsigned int UserList::getSize() const {
	return this->size;
}

void UserList::addUser(const User& user) {
	if (this->size == this->capacity) {
		this->resize(this->capacity << 1);
	}

	++this->size;
	this->data[this->size - 1] = new User(user);
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

User& UserList::operator[](const unsigned int index) {
	if (index >= this->size) {
		throw std::exception("Index out of bounds!");
	}

	return *(this->data[index]);
}

User UserList::operator[](const unsigned int index) const {
	if (index >= this->size) {
		throw std::exception("Index out of bounds!");
	}

	return *(this->data[index]);
}

UserList::~UserList() {
	this->free();
}
