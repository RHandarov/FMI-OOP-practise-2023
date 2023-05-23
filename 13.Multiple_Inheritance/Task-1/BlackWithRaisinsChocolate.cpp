#include "BlackWithRaisinsChocolate.hpp"

bool BlackWithRaisinsChocolate::isIdValid() const {
	return id[0] == '5';
}

BlackWithRaisinsChocolate::BlackWithRaisinsChocolate(const std::string& id, const unsigned int blackAmountInPercents, const unsigned int raisinsAmountInPercents)
	: Chocolate<std::string>(id), BlackChocolate(id, blackAmountInPercents), RaisinsChocolate(id, raisinsAmountInPercents) {
	if (!isIdValid()) {
		throw "Pleae give a valid ID!";
	}
}
