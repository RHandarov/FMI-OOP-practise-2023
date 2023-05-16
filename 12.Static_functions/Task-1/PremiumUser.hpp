#ifndef PREMIUM_USER_HPP
#define PREMIUM_USER_HPP

#include <vector>
#include <ostream>

#include "User.hpp"

class PremiumUser : public User {
private:
	std::string planDescription;
	std::vector<std::string> paymentDates;

public:
	PremiumUser(const std::string& username, const std::string& password,
		const std::string& planDescription);

	void addPayment(const std::string& date);

	const std::string& getPlanDescription() const;
	const std::vector<std::string>& getPaymentDates() const;

	bool operator==(const PremiumUser& other) const;

	friend std::ostream& operator<<(std::ostream& stream, const PremiumUser& user);
};

#endif // !PREMIUM_USER_HPP