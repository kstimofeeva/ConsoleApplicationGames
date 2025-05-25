#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <filesystem>
#include <cstdlib> 
#include "game1/game1.hpp"
#include "game2/game2.hpp"

void print_start_message() {    
    std::ifstream file("start_message228.txt");
    if (!file) {
        std::cerr << "Error" << std::endl;
        return;
    }
    std::cout << file.rdbuf(); 
    file.close();
    std::cout << '\n';
}

void print_help_message() {
    std::ifstream file("help_message.txt");
    if (!file) {
        std::cerr << "Error" << std::endl;
        return;
    }
    std::cout << file.rdbuf();
    file.close();
    std::cout << '\n';
}

int game1() {
    Game1 g;
    std::string s;
    int res = -1;
    while (true) {
        g.print_rules();
        if (res != 1)
            std::getline(std::cin, s);
        if (s == "/back" || s == "/start") {
            system("cls");
            return 0;
        }
        else if (s == "/go" || s == "/again" || res == 1) {
            res = g.game();
        }
        else {
            std::cout << "I don't know this command. Try again\n";
            res = -1;
            continue;
        }
        if (res == 0) {
            system("cls");
            res = -1;
        }
        else if (res == 2) {
            system("cls");
            return 0;
        }
        else if (res == 1) {
            continue;
        }
    }
    return 0;
}

int game2() {


    return 0;
}

void main_menu() {
    print_start_message();
    std::string pr;
    while (true) {
        std::string s;
        std::getline(std::cin, s);
        if (s == "/start") {
            system("cls"); 
            print_start_message();
        }
        else if (s == "/back") {
            if (pr != "/help") {
                std::cout << "You are in the start menu. Select another command\n";
            }
            else {
                system("cls");
                print_start_message();
            }
        }
        else if (s == "/help") {
            system("cls");
            print_help_message();
        }
        else if (s == "/game1") {
            system("cls");
            game1();
            system("cls");
            print_start_message();
        }
        else {
            std::cout << "I don't know this command. Try again\n";
        }
        else if (s == "/game2") {
            system("cls");
            game2();
        }
        pr = s;
    }
}

signed main() {
    main_menu();
    return 0;
}
