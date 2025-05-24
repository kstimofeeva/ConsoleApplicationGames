//
// Created by manechka on 24.05.2025.
//
#include <iostream>
#include <sstream>
#include <fstream>
#include <filesystem>
#include <random>
#include "game2/game2.hpp"

Snake::Snake() {
    body.push_back({WIDTH/2, HEIGHT/2});
    dir = STOP;
    score = 0;
}

void Game::gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
