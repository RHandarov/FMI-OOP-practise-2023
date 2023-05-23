#ifndef RAISINS_CHOCOLATE_HPP
#define RAISINS_CHOCOLATE_HPP

#include "Chocolate.hpp"

template<class T>
class RaisinsChocolate : virtual public Chocolate<T> {
private:
	double raisinsAmount;

	void setRaisinsAmount(const unsigned int amountInPercents);

public:
	RaisinsChocolate(const T& id, const unsigned int raisinsAmountInPercents = 20);
};

template <class T>
void RaisinsChocolate<T>::setRaisinsAmount(const unsigned int amountInPercents) {
	if (amountInPercents > 100) {
		throw "Please give a valid percentage!";
	}

	raisinsAmount = amountInPercents / 100.0;
}

template <class T>
RaisinsChocolate<T>::RaisinsChocolate(const T& id, const unsigned int raisinsAmountInPercents)
	: Chocolate<T>(id) {
	setRaisinsAmount(raisinsAmount);
}

#endif // !RAISINS_CHOCOLATE_HPP