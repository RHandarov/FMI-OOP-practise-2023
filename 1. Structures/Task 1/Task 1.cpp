// Task 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

const unsigned int MAX_STRING_LENGTH = 129; //because of \0

struct Time {
    unsigned int hour;
    unsigned int minute;
    unsigned int second;

    unsigned int convertToSeconds() const {
        return second + 60 * minute + 60 * 60 * hour;
    }

    void enter_time_in_console() {
        std::cin >> hour >> minute >> second;
    }

    void add(const Time other_time) {
        second = second + other_time.second;
        minute = minute + other_time.minute;
        hour = hour + other_time.hour;
    }

    void print_to_console() const {
        std::cout << '(' << hour << ", " << minute << ", " << second << ")\n";
    }

    Time get_difference(const Time other_time) const {
        unsigned int num_seconds = convertToSeconds();
        unsigned int other_time_num_seconds = other_time.convertToSeconds();
        unsigned int difference_in_seconds = (num_seconds > other_time_num_seconds) ? num_seconds - other_time_num_seconds : other_time_num_seconds - num_seconds;

        Time difference;

        difference.second = difference_in_seconds % 60;
        difference_in_seconds /= 60;
        difference.minute = difference_in_seconds % 60;
        difference_in_seconds /= 60;
        difference.hour = difference_in_seconds;

        return difference;
    }
};

struct Event {
    char title[MAX_STRING_LENGTH];
    char organizer[MAX_STRING_LENGTH];
    Time start_time;
    Time end_time;

    Time get_duration() const {
        return end_time.get_difference(start_time);
    }
};

int main() {
    std::cout << "n = ";
    unsigned int n;
    std::cin >> n;

    std::cin.ignore();

    Time total_duration = { 0, 0, 0 };

    while (n--) {
        Event event;
        std::cin.getline(event.title, MAX_STRING_LENGTH);
        std::cin.getline(event.organizer, MAX_STRING_LENGTH);
        event.start_time.enter_time_in_console();
        event.end_time.enter_time_in_console();

        std::cin.ignore();

        total_duration.add(event.get_duration());
    }

    total_duration.print_to_console();

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
