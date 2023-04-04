#ifndef USER_H
#define USER_H

#include <ostream>

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

	friend std::ostream& operator<<(std::ostream& stream, const User& user);
};

#endif // !USER_H