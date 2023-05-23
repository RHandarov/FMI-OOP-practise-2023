#ifndef BLACK_CHOCOLATE_HPP
#define BLACK_CHOCOLATE_HPP

#include <string>

#include "Chocolate.hpp"

class BlackChocolate : virtual public Chocolate<std::string> {
private:
	double blackAmount;

	void setBlackAmount(const unsigned int amountInPercents);

	bool isIdValid() const;

public:
	BlackChocolate(const std::string& id, const unsigned int blackAmountInPercents = 80);
};

#endif // !BLACK_CHOCOLATE_HPP