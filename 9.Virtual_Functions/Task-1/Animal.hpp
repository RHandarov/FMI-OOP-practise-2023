#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal {
private:
	std::string name;
	std::string type;

protected:
	Animal(const std::string& name, const std::string& type);

public:
	virtual void talk() const;
};

#endif // !ANIMAL_H