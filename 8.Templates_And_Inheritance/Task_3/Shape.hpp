#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape {
private:
	std::string type;

protected:
	Shape(const std::string& type) : type(type) {

	}

public:
	std::string getType() const {
		return type;
	}
};

#endif // !SHAPE_H