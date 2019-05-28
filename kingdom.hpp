#ifndef KINGDOM_HPP
#define KINGDOM_HPP

#include "global.hpp"

void printKingdom() {
    std::cout << "  CARD SHOP:" << std::endl;
    for(unsigned int i = 0; i < kingdom.size(); i++) {
        if(kingdom[i]->getRemaining() > 0) {
            card *c = kingdom[i]->getCard();
            std::cout << i << ": " << c->title << "(" << c->getCost() << ")- " << kingdom[i]->getRemaining() << std::endl;
        }
    }
}

// addKingdomCard(card * (*f)(player *p, int remaining)) {
//     kingdom.push_back(new kingdomCard(f, remaining));
// }

void kingdomInit() {
    card * (*f)(player *) = copper;
    kingdom.push_back(new kingdomCard(f, 60));
    f = silver;
    kingdom.push_back(new kingdomCard(f, 40));
    f = gold;
    kingdom.push_back(new kingdomCard(f, 30));
    f = estate;
    kingdom.push_back(new kingdomCard(f, 24));
    f = duchy;
    kingdom.push_back(new kingdomCard(f, 12));
    f = province;
    kingdom.push_back(new kingdomCard(f, 12));
    f = woodcutter;
    kingdom.push_back(new kingdomCard(f));
    f = village;
    kingdom.push_back(new kingdomCard(f));
    f = smithy;
    kingdom.push_back(new kingdomCard(f));
    f = festival;
    kingdom.push_back(new kingdomCard(f));
    f = laboratory;
    kingdom.push_back(new kingdomCard(f));
    f = market;
    kingdom.push_back(new kingdomCard(f));
}

#endif