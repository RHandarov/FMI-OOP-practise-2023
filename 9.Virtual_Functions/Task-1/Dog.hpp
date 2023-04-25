#ifndef DOG_H
#define DOG_H

#include <string>

#include "Animal.hpp"

class Dog : public Animal {
public:
	Dog(const std::string& name);

	void talk() const;
};

#endif // !DOG_H