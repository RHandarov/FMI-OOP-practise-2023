#ifndef USERS_VECTOR_H
#define USERS_VECTOR_H

#include <string>

#include "User.hpp"

class UsersVector {
private:
	User** users;
	unsigned int size;
	unsigned int capacity;

	void free() noexcept;

	void moveFrom(UsersVector&& other) noexcept;
	void copyFrom(const UsersVector& other);

	void resize(const unsigned int newCapacity);

public:
	UsersVector();
	UsersVector(const UsersVector& other);
	UsersVector(UsersVector&& other) noexcept;

	UsersVector& operator=(const UsersVector& other);
	UsersVector& operator=(UsersVector&& other) noexcept;

	User& operator[](const unsigned int index);

	void addClient(const std::string& username, const std::string& password);
	void addAdmin(const std::string& username, const std::string& password);

	unsigned int getSize() const;

	~UsersVector();
};

#endif // !USERS_VECTOR_H