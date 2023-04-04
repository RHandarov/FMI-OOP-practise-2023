// 7. Exam_Preparation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "UsersDB.hpp"
#include "String.hpp"

int main() {
    UsersDB database("users.txt");

    while (true) {
        std::cout << "1) Login\n";
        std::cout << "2) Register\n";
        std::cout << "3) Exit\n";

        unsigned int inputCode;
        std::cin >> inputCode;

        if (inputCode == 1) {
            std::cout << "Username: ";

            String username;
            std::cin >> username;

            std::cout << "Password: ";

            String password;
            std::cin >> password;

            User* user = database.getUserByCredentials(username, password);

            if (!user) {
                std::cout << "Wrong username or password! Please try again!\n";
            } else {
                std::cout << "You have logged in successfully!\n";
                std::cout << "Welcome, " << user->getUsername() << "!\n";

                delete user;

                break;
            }
        } else if (inputCode == 2) {
            std::cout << "Username: ";

            String username;
            std::cin >> username;

            std::cout << "Password: ";

            String password;
            std::cin >> password;

            database.addUser(username, password);

        } else if (inputCode == 3) {
            break;
        } else {
            std::cout << "Invalid operation! Please try again!\n";
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
