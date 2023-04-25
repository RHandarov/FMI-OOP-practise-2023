#include <iostream>

#include "Dog.hpp"

Dog::Dog(const std::string& name) : Animal(name, "dog") {
}

void Dog::talk() const {
	std::cout << "bay";
}
