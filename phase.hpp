#ifndef PHASE_HPP
#define PHASE_HPP

#include "global.hpp"

void actionPhase() {
    player *p = playerList[turn];
    p->activateTurn();
    p->shuffleDeck();
    p->draw(5);
    p->printHand();
}

#endif