#include <iostream>

#include "Cat.hpp"

Cat::Cat(const std::string& name) : Animal(name, "cat") {
}

void Cat::talk() const {
	std::cout << "naiu";
}
