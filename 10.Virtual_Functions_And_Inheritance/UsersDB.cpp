#include <fstream>
#include <string>

#include "UsersDB.hpp"

const std::string UsersDB::CLIENTS_FILE_NAME = "clients.txt";
const std::string UsersDB::ADMINS_FILE_NAME = "admins.txt";

void UsersDB::loadClients() {
	std::ifstream file(CLIENTS_FILE_NAME);

	if (!file) {
		return;
	}

	while (file) {
		std::string username, password;
		file >> username >> password;

		users.addClient(username, password);
	}

	file.close();
}

void UsersDB::loadAdmins() {
	std::ifstream file(ADMINS_FILE_NAME);

	if (!file) {
		return;
	}

	while (file) {
		std::string username, password;
		file >> username >> password;

		users.addAdmin(username, password);
	}

	file.close();
}

void UsersDB::loadUsersFromoFiles() {
	loadClients();
	loadAdmins();
}

void UsersDB::saveUsers() {
	std::ofstream clientsFile(CLIENTS_FILE_NAME), adminsFile(ADMINS_FILE_NAME);

	if (!clientsFile || !adminsFile) {
		return;
	}

	for (unsigned int index = 0; index < users.getSize(); ++index) {
		User& user = users[index];

		if (user.isAdmin()) {
			adminsFile << user << std::endl;
		} else {
			clientsFile << user << std::endl;
		}
	}

	adminsFile.close();
	clientsFile.close();
}

UsersDB::UsersDB() {
	loadUsersFromoFiles();
}

UsersDB::~UsersDB() {
	saveUsers();
}
