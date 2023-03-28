#include <iostream>

#include "String.hpp"

int main() {
	String s1, s2("aba");

	s1 = "bbbbbbbbbbbbbbbbbbbbb";

	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;

	std::cout << s1 + s2 << std::endl;
	std::cout << s2 + s1 << std::endl;

	return 0;
}