#ifndef PLAYERS_HPP
#define PLAYERS_HPP

#include "global.hpp"

void playerInit(int playerCount) {
    for(int i = 0; i < playerCount; i++) {
        player *x = new player(i);
        playerList.push_back(x);
        for(int j = 0; j < 7; j++) {
            copper(i);
        }
        for(int j = 0; j < 3; j++) {
            estate(i);
        }
    }
}

#endif