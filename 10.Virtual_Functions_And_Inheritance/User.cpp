#include "User.hpp"
#include "Client.hpp"
#include "Admin.hpp"

User::User(const std::string& username, const std::string& password)
	: username(username), password(password)
{
}

User* User::createCopyOfOtherUser(const User& other) {
	if (other.isAdmin()) {
		return new Admin(other.username, other.password);
	}

	return new Client(other.username, other.password);
}

std::string User::getUsername() const {
	return username;
}

std::string User::getPassword() const {
	return password;
}

std::ostream& operator<<(std::ostream& stream, const User& user) {
	return stream << user.username << ' ' << user.password;
}
