#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <ostream>

class User {
private:
	static unsigned int CURRENT_ID;

	static bool isBigLetter(const char symbol);
	static bool isSmallLetter(const char symbol);
	static bool isLetter(const char symbol);
	static bool isDigit(const char symbol);

	static std::string decryptPassword(const std::string& password);

	unsigned int id;
	std::string username;
	std::string password;

	void encryptPassword();

	bool isPasswordValid() const;

public:
	static bool arePasswordsEqual(const User& first, const User& second);

	User(const std::string& username, const std::string& password);

	unsigned int getId() const;
	const std::string& getUsername() const;

	bool operator==(const User& other) const;

	friend std::ostream& operator<<(std::ostream& stream, const User& user);
};

#endif // !USER_HPP