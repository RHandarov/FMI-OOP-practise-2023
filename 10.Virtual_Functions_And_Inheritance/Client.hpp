#ifndef CLIENT_H
#define CLIENT_H

#include <string>

#include "User.hpp"

class Client : public User {
public:
	Client(const std::string& username, const std::string& password);

	virtual bool isClient() const override;
	virtual bool isAdmin() const override;
};

#endif // !CLIENT_H