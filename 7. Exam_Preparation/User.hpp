#ifndef USER_H
#define USER_H

#include "String.hpp"

class User {
private:
	String username;
	String password;

public:
	User(const String& username, const String& password);

	bool operator==(const User& other) const;
};

#endif // !USER_H