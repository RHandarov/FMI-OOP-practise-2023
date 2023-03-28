#include <iostream>

#include "String.hpp"

int main() {
	String s1, s2("aba");

	s1 = s1 + s2;

	std::cout << s2[1] << std::endl;

	return 0;
}