// Task 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Time.h"
#include "Event.h"

int main() {
    unsigned int n;
    std::cin >> n;

    Time totalDuration = Time();

    while (n--) {
        std::cin.ignore();

        char title[MAX_STRING_SIZE];
        std::cin.getline(title, MAX_STRING_SIZE);

        char organizer[MAX_STRING_SIZE];
        std::cin.getline(organizer, MAX_STRING_SIZE);

        unsigned int hour, minute, second;
        std::cin >> hour >> minute >> second;

        Time startTime = Time(hour, minute, second);

        std::cin >> hour >> minute >> second;

        Time endTime = Time(hour, minute, second);

        Event event = Event(title, organizer, startTime, endTime);
        totalDuration = totalDuration.addToTime(event.getDuration());
    }

    totalDuration.printToConsole();
    std::cout << std::endl;

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
