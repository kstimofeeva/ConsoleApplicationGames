#include <iostream>
#include <sstream>
#include <fstream>
#include <filesystem>
#include <random>
#include <game1/game1.hpp>

void Game1::print_rules() {
    std::ifstream file("game1_rules.txt");
    if (!file) {
        std::cerr << "Error" << std::endl;
        return;
    }
    std::cout << file.rdbuf();
    file.close();
    std::cout << '\n';
}

int Game1::string_to_int(const std::string& s) {
    int res = 0;
    for (int i = 0; i < (int)(s.size()); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            res = res * 10 + s[i] - '0';
        }
        else {
            return -1;
        }
    }
    return res;
}

int Game1::game() {
    system("cls");
    int number = rand();
    std::string s;
    for (int i = 0; i < 10; ++i) {
        std::cout << "Remaining attempts: " << 10 - i << ". Enter a number from 1 to 1000\n";
        std::getline(std::cin, s);
        if (s == "/back") {
            system("cls");
            return 0;
        }
        else if (s == "/start") {
            system("cls");
            return 2;
        }
        else if (s == "/again") {
            system("cls");
            std::cout << "You started the game over\n";
            return 1;
        }
        else {
            int res = -1;
            while (res == -1) {
                res = string_to_int(s);
                std::cout << "Sorry, you entered the wrong number or I can't execute this command. Please re-enter\n";
                std::getline(std::cin, s);
                if (s == "/back" ) {
                    system("cls");
                    return 0;
                }
                else if (s == "/start") {
                    system("cls");
                    return 2;
                }
                else if (s == "/again") {
                    system("cls");
                    std::cout << "You started the game over\n";
                    return 1;
                }
            }
            if (res == number) {
                std::cout << "Congratulations! You win!\n If you want to repeat the game enter /again, else enter /back\n";
                while (true) {
                    std::getline(std::cin, s);
                    if (s == "/back") {
                        system("cls");
                        return 0;
                    }
                    else if (s == "/start") {
                        system("cls");
                        return 2;
                    }
                    else if (s == "/again") {
                        system("cls");
                        return 1;
                    }
                    else {
                        std::cout << "I don't know this command. Try again\n";
                    }
                }
            }
            else if (res < number) {
                std::cout << "The guessed number is greater than this\n";
            }
            else {
                std::cout << "The guessed number is less than this\n";
            }
        }
    }
    return 0;
}