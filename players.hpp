#ifndef PLAYERS_HPP
#define PLAYERS_HPP

#include "global.hpp"

void playerInit(int playerCount) {
    for(int i = 0; i < playerCount; i++) {
        player *p = new player(i);
        playerList.push_back(p);
        for(int j = 0; j < 7; j++) {
            p->addCardDeck(copper(p));
        }
        for(int j = 0; j < 3; j++) {
            p->addCardDeck(estate(p));
        }
    }
}

#endif