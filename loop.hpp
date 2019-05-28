#ifndef LOOP_HPP
#define LOOP_HPP

#include "global.hpp"

void gameLoop(int playerCount);

void start(int playerCount) {
    turn = 0;
    kingdomInit();
    playerInit(playerCount);
    gameLoop(playerCount);
}

void gameLoop(int playerCount) {
    bool exit = false;
    while(!exit) {
        actionPhase();
        buyPhase();
        cleanPhase();
        // turn++;
        // if(turn >= playerCount)
        //     turn = 0;
    }
}

#endif