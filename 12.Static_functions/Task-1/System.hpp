#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <vector>
#include <string>

#include <fstream>

#include "User.hpp"
#include "PremiumUser.hpp"

class System {
private:
	std::vector<User> users;
	std::vector<PremiumUser> premiumUsers;

	System();
	System(const System& other);
	System(System&& other);

	System& operator=(const System& other);
	System& operator=(System&& other);

	~System();

	bool isUserExists(const User& user, const bool printMessage) const;

	void saveUsers() const;
	void savePremiumUsers() const;

public:
	static System& getInstance();

	void callWhetherUserExists(const std::string& username, const std::string& password) const;

	void addUser(const std::string& username, const std::string& password);
	void addUser(const User& user);

	void addPremiumUser(const std::string& username, const std::string& password, const std::string& planDescription);
	void addPremiumUser(const PremiumUser& user);
};

#endif // !SYSTEM_HPP