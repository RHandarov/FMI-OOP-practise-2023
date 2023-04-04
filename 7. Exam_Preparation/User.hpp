#ifndef USER_H
#define USER_H

#include <iostream>

#include "String.hpp"

class User {
private:
	String username;
	String password;

public:
	User(const String& username, const String& password);

	String getUsername() const;
	String getPassword() const;

	bool operator==(const User& other) const;

	friend std::istream& operator>>(std::istream& stream, User& user);
	friend std::ostream& operator<<(std::ostream& stream, const User& user);
};

#endif // !USER_H