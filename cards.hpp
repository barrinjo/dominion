#ifndef CARDS_HPP
#define CARDS_HPP

#include "global.hpp"

void copper(int loc) {
    player *p = playerList[loc];
    card *c = new card("Copper", p, TREASURE, 0, 1, 0);
    playerList[loc]->addCard(c);
}

void estate(int loc) {
    player *p = playerList[loc];
    card *c = new card("Estate", p, VICTORY, 2, 0, 1);
    playerList[loc]->addCard(c);
}

void test() {
    std::cout << "woodcutter function" << std::endl;
}

void woodcutter(int loc) {
    player *p = playerList[loc];
    card *c = new card("Woodcutter", p, ACTION, 3, 0, 0);
    void (*f)(int x, player *p) = addGold;
    c->addAction(f, 2);
    f = addBuys;
    c->addAction(f, 1);
    p->addCard(c);
}

#endif