#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.hpp"

class Rectangle : public Shape {
private:
	unsigned int width;
	unsigned int height;

protected:
	Rectangle(const std::string& type, const unsigned int width, const unsigned int height)
		: Shape(type), width(width), height(height) {

	}

public:
	Rectangle(const unsigned int width, const unsigned int height)
		: Shape("Rectangle"), width(width), height(height) {

	}

	unsigned int getWidth() const {
		return width;
	}

	unsigned int getHeight() const {
		return height;
	}
};

#endif // !RECTANGLE_H