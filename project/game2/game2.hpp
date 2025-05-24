//
// Created by manechka on 24.05.2025.
//

#ifndef GAME2_HPP
#define GAME2_HPP

#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <ctime>

enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
const int WIDTH = 50;
const int HEIGHT = 50;

class Snake {
public:
    std::vector<std::pair<int, int>> body;
    Direction dir;
    int score;

    Snake();
};

class Game {
private:
    Snake snake;
    std::pair<int, int> food;
    bool gameOver;

    void gotoxy(int x, int y);

public:
    Game();
    void Draw();
    void Input();
    void Logic();
    void Run();
};


#endif
