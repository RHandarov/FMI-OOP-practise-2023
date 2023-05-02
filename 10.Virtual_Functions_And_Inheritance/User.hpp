#ifndef USER_H
#define USER_H

#include <string>
#include <ostream>

class User {
private:
	std::string username;
	std::string password;

protected:
	User(const std::string& username, const std::string& password);

public:
	static User* createCopyOfOtherUser(const User& other);

	virtual bool isClient() const = 0;
	virtual bool isAdmin() const = 0;

	std::string getUsername() const;
	std::string getPassword() const;

	friend std::ostream& operator<<(std::ostream& stream, const User& user);
};

#endif // !USER_H