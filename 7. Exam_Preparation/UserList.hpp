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

public:
	UserList();

	UserList(const UserList& other);
	UserList(UserList&& other);

	UserList& operator=(const UserList& other);
	UserList& operator=(UserList&& other);

	~UserList();
};

#endif // !USER_LIST_H