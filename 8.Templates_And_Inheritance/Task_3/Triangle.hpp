#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <string>

#include "Shape.hpp"

class Triangle : public Shape {
private:
	unsigned int side1;
	unsigned int side2;
	unsigned int side3;

public:
	Triangle(const unsigned int side1, const unsigned int side2, const unsigned int side3)
		: Shape("Triangle"), side1(side1), side2(side2), side3(side3) {

	}

	unsigned int getSide1() const {
		return side1;
	}

	unsigned int getSide2() const {
		return side2;
	}

	unsigned int getSide3() const {
		return side3;
	}
};

#endif // !TRIANGLE_H
