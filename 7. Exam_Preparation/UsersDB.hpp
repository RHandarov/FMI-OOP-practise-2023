#ifndef USERS_DB_H
#define USERS_DB_H

#include "String.hpp"
#include "UserList.hpp"

class UsersDB {
private:
	String fileName;
	UserList data;

	void loadDataFromFile();

	void saveDataToFile();

public:
	UsersDB(const String& fileName);

	void addUser(const User& user);
	void addUser(const String& username, const String& password);

	User* getUserByCredentials(const String& username, const String& password) const;

	~UsersDB();
};

#endif // !USERS_DB_H