#ifndef ADMIN_H
#define ADMIN_H

#include <string>

#include "User.hpp"

class Admin : public User {
public:
	Admin(const std::string& username, const std::string& password);

	virtual bool isClient() const override;
	virtual bool isAdmin() const override;
};

#endif // !ADMIN_H