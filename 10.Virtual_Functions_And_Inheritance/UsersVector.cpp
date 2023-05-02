#include <utility>

#include "UsersVector.hpp"
#include "Client.hpp"
#include "Admin.hpp"

const unsigned int INITIAL_CAPACITY = 4;

void UsersVector::free() noexcept {
	for (unsigned int index = 0; index < size; ++index) {
		delete users[index];
	}

	delete[] users;
}

void UsersVector::moveFrom(UsersVector&& other) noexcept {
	size = other.size;
	capacity = other.capacity;
	users = other.users;

	other.users = nullptr;
	other.size = 0;
}

void UsersVector::copyFrom(const UsersVector& other) {
	size = other.size;
	capacity = other.capacity;

	users = new User * [capacity];
	for (unsigned int index = 0; index < size; ++index) {
		users[index] = User::createCopyOfOtherUser(*other.users[index]);
	}
}

void UsersVector::resize(const unsigned int newCapacity) {
	if (newCapacity < size) {
		return;
	}

	capacity = newCapacity;

	User** buffer = new User * [capacity];
	for (unsigned int index = 0; index < size; ++index) {
		buffer[index] = users[index];
	}

	delete[] users;
	users = buffer;
}

UsersVector& UsersVector::operator=(const UsersVector& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

UsersVector& UsersVector::operator=(UsersVector&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

User& UsersVector::operator[](const unsigned int index) {
	if (index >= size) {
		throw std::exception("Index out of bounds!");
	}

	return *users[index];
}

void UsersVector::addClient(const std::string& username, const std::string& password) {
	if (size == capacity) {
		resize(capacity << 1);
	}

	++size;
	users[size - 1] = new Client(username, password);
}

void UsersVector::addAdmin(const std::string& username, const std::string& password) {
	if (size == capacity) {
		resize(capacity << 1);
	}

	++size;
	users[size - 1] = new Admin(username, password);
}

unsigned int UsersVector::getSize() const {
	return size;
}

UsersVector::~UsersVector() {
	free();
}

UsersVector::UsersVector() : size(0), capacity(INITIAL_CAPACITY) {
	users = new User * [INITIAL_CAPACITY];
}

UsersVector::UsersVector(const UsersVector& other) {
	copyFrom(other);
}

UsersVector::UsersVector(UsersVector&& other) noexcept {
	moveFrom(std::move(other));
}
