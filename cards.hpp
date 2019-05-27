#ifndef CARDS_HPP
#define CARDS_HPP

#include "global.hpp"

void copper(int loc) {
    card *c = new card("Copper", TREASURE, 0, 1, 0);
    playerList[loc]->addCard(c);
}

void estate(int loc) {
    card *c = new card("Estate", VICTORY, 2, 0, 1);
    playerList[loc]->addCard(c);
}

#endif