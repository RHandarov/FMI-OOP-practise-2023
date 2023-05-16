// Task-1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "User.hpp"
#include "PremiumUser.hpp"
#include "System.hpp"

void printCommandMessages() {
    std::cout << "1) Check if user exists?\n";
    std::cout << "2) Exit\n";
}

int main() {
    User user1("rado", "12340abc");
    PremiumUser user2("ivan", "abc1234", "master");
    user2.addPayment("01-02-2023");
    user2.addPayment("01-04-2023");

    System::getInstance().addUser(user1);
    System::getInstance().addPremiumUser(user2);

    while (true) {
        printCommandMessages();

        unsigned int cmdNumber;
        std::cin >> cmdNumber;

        if (cmdNumber == 1) {
            std::string username;
            std::cout << "Username: ";
            std::cin >> username;

            std::string password;
            std::cout << "Password: ";
            std::cin >> password;

            System::getInstance().callWhetherUserExists(username, password);
        } else if (cmdNumber == 2) {
            std::cout << "Goodbye!\n";
            break;
        }
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
