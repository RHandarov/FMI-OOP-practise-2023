#include <iostream>

#include "System.hpp"

System::System() {

}

System::~System() {
	saveUsers();
	savePremiumUsers();
}

bool System::isUserExists(const User& user, const bool printMessage) const {
	for (unsigned int index = 0; index < users.size(); ++index) {
		if (user == users[index]) {
			if (printMessage) {
				std::cout << "User " << user.getUsername() << " was found!\n";
			}

			return true;
		}
	}

	for (unsigned int index = 0; index < premiumUsers.size(); ++index) {
		if (user == premiumUsers[index]) {
			if (printMessage) {
				std::cout << "User " << user.getUsername() << " was found!\n";
			}

			return true;
		}
	}

	if (printMessage) {
		std::cout << "User " << user.getUsername() << " was not found!\n";
	}

	return false;
}

void System::saveUsers() const {
	std::ofstream file("users.txt");

	if (!file) {
		return;
	}

	for (unsigned int index = 0; index < users.size(); ++index) {
		file << users[index] << std::endl;
	}

	file.close();
}

void System::savePremiumUsers() const {
	std::ofstream file("premiumUsers.txt");

	if (!file) {
		return;
	}

	for (unsigned int index = 0; index < premiumUsers.size(); ++index) {
		file << premiumUsers[index] << std::endl;
	}

	file.close();
}

System& System::getInstance() {
	static System instance;
	return instance;
}

void System::callWhetherUserExists(const std::string& username, const std::string& password) const {
	isUserExists(User(username, password), true);
}

void System::addUser(const std::string& username, const std::string& password) {
	User user(username, password);

	if (isUserExists(user, false)) {
		return;
	}

	users.emplace_back(std::move(user));
}

void System::addUser(const User& user) {
	if (isUserExists(user, false)) {
		return;
	}

	users.emplace_back(user);
}

void System::addPremiumUser(const std::string& username, const std::string& password, const std::string& planDescription) {
	PremiumUser user(username, password, planDescription);

	if (isUserExists(user, false)) {
		return;
	}

	premiumUsers.emplace_back(std::move(user));
}

void System::addPremiumUser(const PremiumUser& user) {
	if (isUserExists(user, false)) {
		return;
	}

	premiumUsers.emplace_back(user);
}
