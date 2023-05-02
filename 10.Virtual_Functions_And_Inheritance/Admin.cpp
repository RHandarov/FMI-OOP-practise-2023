#include "Admin.hpp"

Admin::Admin(const std::string& username, const std::string& password)
	: User(username, password)
{
}

bool Admin::isClient() const {
	return false;
}

bool Admin::isAdmin() const {
	return true;
}
