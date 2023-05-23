#include "MilkWithRaisinsChocolate.hpp"

bool MilkWithRaisinsChocolate::isIdValid() const {
	int firstDigit = -1, secondDigit = -1;
	unsigned int idCopy = id;

	while (idCopy > 0) {
		unsigned int lastDigit = idCopy % 10;

		if (firstDigit == -1) {
			firstDigit = lastDigit;
		} else {
			secondDigit = firstDigit;
			firstDigit = lastDigit;
		}

		idCopy /= 10;
	}

	return (firstDigit == 4 && secondDigit == 5);
}

MilkWithRaisinsChocolate::MilkWithRaisinsChocolate(const unsigned int id, const unsigned int amountMilkInPercents, const unsigned int amountRaisinsInPercents)
	: Chocolate<unsigned int>(id), MilkChocolate(id, amountMilkInPercents), RaisinsChocolate(id, amountRaisinsInPercents) {
	if (!isIdValid()) {
		throw "Pleae give a valid ID!";
	}
}
