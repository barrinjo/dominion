#ifndef KINGDOM_HPP
#define KINGDOM_HPP

#include "global.hpp"

void printKingdom() {
    std::cout << "  CARD SHOP:" << std::endl;
    for(unsigned int i = 0; i < kingdom.size(); i++) {
        if(kingdom[i]->getRemaining() > 0) {
            card *c = kingdom[i]->getCard();
            std::cout << i << ": " << c->title << "- " << kingdom[i]->getRemaining() << std::endl;
        }
    }
}

void kingdomInit() {
    card * (*f)(player *) = copper;
    kingdom.push_back(new kingdomCard(f));
    f = estate;
    kingdom.push_back(new kingdomCard(f));
    f = woodcutter;
    kingdom.push_back(new kingdomCard(f));
    f = village;
    kingdom.push_back(new kingdomCard(f));
}

#endif