// Task_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "MyVector.hpp"

double addOne(double& number) {
    return ++number;
}

int main() {
    MyVector<double> arr;

    arr.addElement(5.5);
    arr.addElement(5.7);
    arr.addElement(4.2);
    arr.addElement(9.3);
    arr.addElement(0.3);
    arr.addElement(0.5);

    arr.apply(addOne);

    for (unsigned int index = 0; index < arr.getSize(); ++index) {
        std::cout << arr[index] << std::endl;
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
