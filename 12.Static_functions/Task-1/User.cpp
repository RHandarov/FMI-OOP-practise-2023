#include "User.hpp"

unsigned int User::CURRENT_ID = 1;

inline bool User::isBigLetter(const char symbol) {
	return symbol >= 'A' && symbol <= 'Z';
}

inline bool User::isSmallLetter(const char symbol) {
	return symbol >= 'a' && symbol <= 'z';
}

inline bool User::isLetter(const char symbol) {
	return isSmallLetter(symbol) || isBigLetter(symbol);
}

inline bool User::isDigit(const char symbol) {
	return symbol >= '0' && symbol <= '9';
}

std::string User::decryptPassword(const std::string& password) {
	std::string plainPassword;

	for (unsigned int index = 0; index < password.size(); ++index) {
		char symbol = password[index];

		if (isSmallLetter(symbol)) {
			plainPassword.push_back((char)(((symbol - 'a' + 25) % 26) + 'a'));
		}
		else if (isBigLetter(symbol)) {
			plainPassword.push_back((char)(((symbol - 'A' + 25) % 26) + 'A'));
		}
		else if (symbol == '?') {
			plainPassword.push_back('0');
		}
		else {
			plainPassword.push_back((char)(symbol + 1));
		}
	}

	return std::move(plainPassword);
}

void User::encryptPassword() {
	for (unsigned int index = 0; index < password.size(); ++index) {
		char symbol = password[index];

		if (isSmallLetter(symbol)) {
			password[index] = ((symbol - 'a' + 1) % 26) + 'a';
		} else if (isBigLetter(symbol)) {
			password[index] = ((symbol - 'A' + 1) % 26) + 'A';
		} else if (symbol == '0') {
			password[index] = '?';
		} else {
			password[index] = symbol - 1;
		}
	}
}

bool User::isPasswordValid() const {
	for (unsigned int index = 0; index < password.size(); ++index) {
		char symbol = password[index];

		if (!isLetter(symbol) && !isDigit(symbol)) {
			return false;
		}
	}

	return true;
}

bool User::arePasswordsEqual(const User& first, const User& second) {
	return first.password == second.password;
}

User::User(const std::string& username, const std::string& password)
	: username(username), password(password) {
	if (!isPasswordValid()) {
		throw "Password must contain only letters and digits!";
	}

	id = CURRENT_ID++;
	encryptPassword();
}

unsigned int User::getId() const {
	return id;
}

const std::string& User::getUsername() const {
	return username;
}

bool User::operator==(const User& other) const {
	return username == other.username && arePasswordsEqual(*this, other);
}

std::ostream& operator<<(std::ostream& stream, const User& user) {
	return stream << user.username << ' ' << User::decryptPassword(user.password);
}
