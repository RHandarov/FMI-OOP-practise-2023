#ifndef MILK_WITH_RAISINS_CHOCOLATE_HPP
#define MILK_WITH_RAISINS_CHOCOLATE_HPP

#include "MilkChocolate.hpp"
#include "RaisinsChocolate.hpp"

class MilkWithRaisinsChocolate : public MilkChocolate, public RaisinsChocolate<unsigned int> {
private:
	bool isIdValid() const;

public:
	MilkWithRaisinsChocolate(const unsigned int id, const unsigned int amountMilkInPercents, const unsigned int amountRaisinsInPercents);
};

#endif // !MILK_WITH_RAISINS_CHOCOLATE_HPP

