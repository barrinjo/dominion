#ifndef LOOP_HPP
#define LOOP_HPP

#include "global.hpp"

void gameLoop();

void start(int playerCount) {
    turn = 0;
    playerInit(playerCount);
    gameLoop();
}

void gameLoop() {
    actionPhase();
    // buyPhase();
    // cleanPhase();
}

#endif