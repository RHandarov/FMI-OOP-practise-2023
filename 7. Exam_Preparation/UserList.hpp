#ifndef USER_LIST_H
#define USER_LIST_H

#include "User.hpp"

class UserList {
private:
	User** data;
	unsigned int capacity;
	unsigned int size;

	void free();

	void copyFrom(const UserList& other);
	void moveFrom(UserList&& other);

	void resize(const unsigned int capacity);

public:
	UserList();

	UserList(const UserList& other);
	UserList(UserList&& other);

	unsigned int getSize() const;

	void addUser(const User& user);

	UserList& operator=(const UserList& other);
	UserList& operator=(UserList&& other);

	User& operator[](const unsigned int index);
	User operator[](const unsigned int index) const;

	~UserList();
};

#endif // !USER_LIST_H