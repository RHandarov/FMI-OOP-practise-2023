#ifndef SQUARE_H
#define SQUARE_H

#include <string>

#include "Shape.hpp"

class Square : public Shape {
private:
	unsigned int side;

public:
	Square(const unsigned int side)
		: Shape("Square"), side(side) {

	}

	unsigned int getSide() const {
		return side;
	}
};

#endif // !SQUARE_H
