#include <ostream>

#include "User.hpp"

User::User(const String& username, const String& password) : username(username), password(password) {
}

String User::getUsername() const {
	return this->username;
}

String User::getPassword() const {
	return this->password;
}

bool User::operator==(const User& other) const {
	return this->username == other.username && this->password == other.password;
}

std::ostream& operator<<(std::ostream& stream, const User& user) {
	return stream << user.username << ' ' << user.password;
}
