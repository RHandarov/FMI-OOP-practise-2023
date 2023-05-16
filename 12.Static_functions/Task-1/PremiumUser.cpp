#include "PremiumUser.hpp"

PremiumUser::PremiumUser(const std::string& username, const std::string& password, const std::string& planDescription)
	: User(username, password), planDescription(planDescription) {
}

void PremiumUser::addPayment(const std::string& date) {
	paymentDates.emplace_back(date);
}

const std::string& PremiumUser::getPlanDescription() const {
	return planDescription;
}

const std::vector<std::string>& PremiumUser::getPaymentDates() const {
	return paymentDates;
}

bool PremiumUser::operator==(const PremiumUser& other) const {
	return User::operator==(other);
}

std::ostream& operator<<(std::ostream& stream, const PremiumUser& user) {
	stream << (const User&)user;
	stream << ' ' << user.planDescription;

	for (unsigned int index = 0; index < user.paymentDates.size(); ++index) {
		stream << ' ' << user.paymentDates[index];
	}

	return stream;
}
