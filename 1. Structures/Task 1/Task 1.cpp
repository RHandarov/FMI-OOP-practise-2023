// Task 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

const unsigned int MAX_STRING_LENGTH = 129; //because of \0

struct Time {
    unsigned int hour;
    unsigned int minute;
    unsigned int second;

    Time get_difference(const Time other_time) const;
};

struct Event {
    char title[MAX_STRING_LENGTH];
    char organizer[MAX_STRING_LENGTH];
    Time start_time;
    Time end_time;

    Time get_duration() const;
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
