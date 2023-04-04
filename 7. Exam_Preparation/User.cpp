#include "User.hpp"

User::User(const String& username, const String& password) : username(username), password(password) {
}

bool User::operator==(const User& other) const {
	return this->username == other.username && this->password == other.password;
}
