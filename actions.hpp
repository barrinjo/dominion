#ifndef ACTIONS_HPP
#define ACTIONS_HPP

#include "global.hpp"

void addGold(int x, player *p) {
    p->updateGold(x);
}

void addBuys(int x, player *p) {
    p->updateBuys(x);
}

void addActions(int x, player *p) {
    p->updateActions(x);
}

void drawCards(int x, player *p) {
    p->draw(x);
}

#endif