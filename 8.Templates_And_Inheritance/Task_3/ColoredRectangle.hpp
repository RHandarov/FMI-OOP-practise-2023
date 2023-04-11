#ifndef COLORED_RECTANGLE_H
#define COLORED_RECTANGLE_H

#include <string>

#include "Rectangle.hpp"

class ColoredRectangle : public Rectangle {
private:
	std::string color;

public:
	ColoredRectangle(const unsigned int width, const unsigned int height, const std::string& color)
		: Rectangle("Colored rectangle", width, height), color(color) {

	}

	std::string getColor() const {
		return color;
	}
};

#endif // !COLORED_RECTANGLE_H
