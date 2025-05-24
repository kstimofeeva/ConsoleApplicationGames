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

void Game::Draw() {
    system("cls");
    for(int i = 0; i < WIDTH+2; i++)
        std::cout << "#";
    std::cout << '\n';

    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < WIDTH; x++) {
            if (x == 0){
                std::cout << "#";
            }

            bool isSnake = false;
            for(auto segment : snake.body) {
                if(segment.first == x && segment.second == y) {
                    std::cout << "O";
                    isSnake = true;
                    break;
                }
            }

            if(!isSnake) {
                if(x == food.first && y == food.second) {
                    std::cout << "F";
                }
                else
                    std::cout << " ";
            }

            if(x == WIDTH - 1) {
                std::cout << "#";
            }
        }
        std::cout << '\n';
    }

    for(int i = 0; i < WIDTH + 2; i++) {
        std::cout << "#";
    }
    std::cout << "\n";

    std::cout << "Score: " << snake.score << '\n';
}

void Game::Input() {
    if(_kbhit()) {
        if (_getch() == 'a' && snake.dir != RIGHT) {
                snake.dir = LEFT;
        }
        if (_getch() == 'd' && snake.dir != LEFT) {
            snake.dir = RIGHT;
        }
        if (_getch() == 'w' && snake.dir != DOWN) {
            snake.dir = UP;
        }
        if (_getch() == 's' && snake.dir != UP) {
            snake.dir = DOWN;
        }
        if (_getch() == 'x') {
            snake.dir = LEFT;
            gameOver = true;
        }
    }
}