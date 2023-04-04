#include <fstream>
#include <exception>

#include "UsersDB.hpp"

void UsersDB::loadDataFromFile() {
	std::ifstream file(this->fileName.cStr());

	if (!file) {
		std::ofstream file(this->fileName.cStr());
		file.close();
		return;
	}

	while (file) {
		String username;
		file >> username;

		if (!file) {
			break;
		}

		String password;
		file >> password;

		this->data.addUser(User(username, password));
	}

	file.close();
}

void UsersDB::saveDataToFile() {
	std::ofstream file(this->fileName.cStr());

	if (!file) {
		throw std::exception("Cannot write to the file!");
	}

	for (unsigned int index = 0; index < this->data.getSize(); ++index) {
		file << this->data[index] << std::endl;
	}

	file.close();
}

UsersDB::UsersDB(const String& fileName) : fileName(fileName) {
	this->loadDataFromFile();
}

void UsersDB::addUser(const User& user) {
	this->data.addUser(user);
}

void UsersDB::addUser(const String& username, const String& password) {
	this->data.addUser(User(username, password));
}

User* UsersDB::getUserByCredentials(const String& username, const String& password) const {
	User ourUser(username, password);

	for (unsigned int index = 0; index < this->data.getSize(); ++index) {
		if (this->data[index] == ourUser) {
			return new User(this->data[index]);
		}
	}

	return nullptr;
}

UsersDB::~UsersDB() {
	this->saveDataToFile();
}
