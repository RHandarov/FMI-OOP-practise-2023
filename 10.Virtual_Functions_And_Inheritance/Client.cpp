#include "Client.hpp"

Client::Client(const std::string& username, const std::string& password)
	: User(username, password)
{
}

bool Client::isClient() const {
	return true;
}

bool Client::isAdmin() const {
	return false;
}
