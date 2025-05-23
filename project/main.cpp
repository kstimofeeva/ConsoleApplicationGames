#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <filesystem>
#include <cstdlib> 

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
            if (pr == "") {
                std::cout << "You are in the start menu. Select another command\n";
            }
            else {
                //
            }
        }
        else if (s == "/help") {
            system("cls");
            print_help_message();
        }
        else {

        }
        pr = s;
    }
}

signed main() {
    main_menu();
    return 0;
}
