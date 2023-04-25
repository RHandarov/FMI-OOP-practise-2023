#ifndef CAT_H
#define CAT_H

#include <string>

#include "Animal.hpp"

class Cat : public Animal {
public:
	Cat(const std::string& name);

	void talk() const;
};

#endif // !CAT_H