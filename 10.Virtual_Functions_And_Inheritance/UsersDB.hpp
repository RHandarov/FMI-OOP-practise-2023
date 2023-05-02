#ifndef USERS_DB_H
#define USERS_DB_H

#include <string>

#include "UsersVector.hpp"

class UsersDB {
private:
	static const std::string CLIENTS_FILE_NAME;
	static const std::string ADMINS_FILE_NAME;

	UsersVector users;

	void loadClients();
	void loadAdmins();
	void loadUsersFromoFiles();

	void saveUsers();

public:
	UsersDB();

	~UsersDB();
};

#endif // !USERS_DB_H