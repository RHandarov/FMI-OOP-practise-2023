#include "MilkChocolate.hpp"

void MilkChocolate::setMilkAmount(const unsigned int amountInPercents) {
	if (amountInPercents > 100) {
		throw "Please give a valid milk percentage!";
	}

	milkAmount = amountInPercents / 100.0;
}

bool MilkChocolate::isIdValid() const {
	return true;
}

MilkChocolate::MilkChocolate(const unsigned int id, const unsigned int amountMilkInPercents)
	: Chocolate<unsigned int>(id) {
	if (!isIdValid()) {
		throw "Pleae give a valid ID!";
	}

	setMilkAmount(amountMilkInPercents);
}
