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

void test() {
    std::cout << "woodcutter function" << std::endl;
}

void woodcutter(int loc) {
    card *c = new card("Woodcutter", ACTION, 3, 0, 0);
    void (*f)() = test;
    c->addAction(f);
    c->doAction();
    // void (*fcnPtr)() = test;
    // (*fcnPtr)();
    playerList[loc]->addCard(c);
}

#endif