#include "BlackChocolate.hpp"

inline bool isLittleLetter(const char symbol) {
	return symbol >= 'a' && symbol <= 'z';
}

inline bool isBigLetter(const char symbol) {
	return symbol >= 'A' && symbol <= 'Z';
}

void BlackChocolate::setBlackAmount(const unsigned int amountInPercents) {
	if (amountInPercents > 100) {
		throw "Pleae give valid percents!";
	}

	blackAmount = amountInPercents / 100.0;
}

bool BlackChocolate::isIdValid() const {
	for (size_t index = 0; index < id.size(); ++index) {
		if (!isLittleLetter(id[index]) && !isLittleLetter(id[index])) {
			return false;
		}
	}

	return true;
}

BlackChocolate::BlackChocolate(const std::string& id, const unsigned int blackAmountInPercents)
	: Chocolate<std::string>(id) {
	if (!isIdValid()) {
		throw "Pleae give a valid ID!";
	}

	setBlackAmount(blackAmountInPercents);
}
