#ifndef KINGDOM_HPP
#define KINGDOM_HPP

#include "global.hpp"

void endGame() {
    std::cout << "GAME END: " << std::endl;
    for(unsigned int playerLoc = 0; playerLoc < playerList.size(); playerLoc++) {
        player *p = playerList[playerLoc];
        p->clearAll();
        std::vector<card *> v = p->getDiscard();
        for(unsigned int i = 0; i < v.size(); i++) {
            if(v[i]->getType() == VICTORY) {
                p->updatePoints(v[i]->getPoints());
            }
        }
    }
    for(unsigned int playerLoc = 0; playerLoc < playerList.size(); playerLoc++) {
        std::cout << "player " << playerLoc << ": " << playerList[playerLoc]->getPoints() << " points" << std::endl;
    }
}

bool checkForGameEnd() {
    int endCount = 0;
    for(unsigned int i = 0; i < kingdom.size(); i++) {
        if(kingdom[i]->getRemaining() == 0)
            endCount++;
    }
    if(kingdom[5]->getRemaining() == 0 || endCount == 3) {
        endGame();
        return true;
    }
    return false;
}

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