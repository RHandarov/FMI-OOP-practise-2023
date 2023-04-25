// Task-1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
    Animal* animals[10] = { nullptr };
    for (unsigned int index = 0; index < 10; ++index) {
        if (index & 1) {
            animals[index] = new Cat("" + index);
        } else {
            animals[index] = new Dog("" + index);
        }
    }

    for (unsigned int index = 0; index < 10; ++index) {
        std::cout << index << ": ";
        animals[index]->talk();
        std::cout << std::endl;
    }

    for (unsigned int index = 0; index < 10; ++index) {
        delete animals[index];
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
