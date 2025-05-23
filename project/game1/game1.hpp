#ifndef GAME1_HPP
#define GAME1_HPP

#include <iostream>
#include <string>

class Game1 {
public:
    void print_rules();
    int game();
    int string_to_int(const std::string& s);
};

#endif