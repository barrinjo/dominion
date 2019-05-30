#ifndef LOOP_HPP
#define LOOP_HPP

#include "global.hpp"

void gameLoop(unsigned int playerCount);

void start(unsigned int playerCount) {
    turn = 0;
    kingdomInit();
    playerInit(playerCount);
    gameLoop(playerCount);
}

void gameLoop(unsigned int playerCount) {
    bool exit = false;
    while(!exit) {
        actionPhase();
        buyPhase();
        cleanPhase();
        exit = checkForGameEnd();
        turn++;
        totalTurns++;
        if(turn >= playerCount)
            turn = 0;
    }
}

#endif