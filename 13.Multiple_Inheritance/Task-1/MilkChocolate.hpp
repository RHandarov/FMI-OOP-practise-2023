#ifndef MILK_CHOCOLATE_HPP
#define MILK_CHOCOLATE_HPP

#include "Chocolate.hpp"

class MilkChocolate : virtual public Chocolate<unsigned int> {
private:
	double milkAmount;

	void setMilkAmount(const unsigned int amountInPercents);

	bool isIdValid() const;

public:
	MilkChocolate(const unsigned int id, const unsigned int amountMilkInPercents = 35);
};

#endif // !MILK_CHOCOLATE_HPP