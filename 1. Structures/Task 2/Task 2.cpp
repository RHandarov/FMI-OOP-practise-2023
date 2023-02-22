// Task 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

const size_t MAX_STRING_LENGTH = 257; //because of \0
const size_t EGN_LENGTH = 15;
const size_t MAX_NUMBER_OF_STUDENTS = 100;

struct Student {
    char name[MAX_STRING_LENGTH];
    char surname[MAX_STRING_LENGTH];
    char EGN[EGN_LENGTH];
};

struct University {
    char name[MAX_STRING_LENGTH];
    Student students[MAX_NUMBER_OF_STUDENTS];
};

int main() {
    

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
