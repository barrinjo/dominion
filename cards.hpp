#ifndef CARDS_HPP
#define CARDS_HPP

#include "global.hpp"

card *copper(player *p) {
    return new card("Copper", p, TREASURE, 0, 1, 0);
}

card *estate(player *p) {
    return new card("Estate", p, VICTORY, 2, 0, 1);
}

card *woodcutter(player *p) {
    card *c = new card("Woodcutter", p, ACTION, 3, 0, 0);
    void (*f)(int x, player *p) = addGold;
    c->addAction(f, 2);
    f = addBuys;
    c->addAction(f, 1);
    return c;
}

card *village(player *p) {
    card *c = new card("Village", p, ACTION, 3, 0, 0);
    void (*f)(int x, player *p) = drawCards;
    c->addAction(f, 1);
    f = addActions;
    c->addAction(f, 2);
    return c;
}

#endif