#include <vector>
#include <ncurses.h>
#include <cstdlib>
#include <unistd.h>
#ifndef SNAKE_H
#define SNAKE_H

struct snakepart{
    int x, y;
    snakepart(int col, int row);
    snakepart();
};

class snakeclass{
    //점수 : points, 시간 : del
    int maxheight;
    int maxwidth;
    int points;
    char direction;
    std::vector<snakepart> snake;


public:
    bool grow;
    bool dok;
    bool fast;

    bool isDied;
    snakeclass();
    ~snakeclass();
    void Update();
    bool collision();
    void movesnake(float eTime);
    void PushData();

};


#endif
