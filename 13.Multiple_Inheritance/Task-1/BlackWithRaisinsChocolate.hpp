#ifndef BLACK_WITH_RAISINS_CHOCOLATE_HPP
#define BLACK_WITH_RAISINS_CHOCOLATE_HPP

#include "BlackChocolate.hpp"
#include "RaisinsChocolate.hpp"

class BlackWithRaisinsChocolate : public BlackChocolate, public RaisinsChocolate<std::string> {
private:
	bool isIdValid() const;
public:
	BlackWithRaisinsChocolate(const std::string& id, const unsigned int blackAmountInPercents, const unsigned int raisinsAmountInPercents);
};

#endif // !BLACK_WITH_RAISINS_CHOCOLATE_HPP

