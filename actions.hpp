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

void trashCard(int x, player *p) {
    p->trashCard();
}

void gainCard(int x, player *p) {
    std::cout << "  GAIN CARD COSTING UP TO " << x << ": " << std::endl;
    bool gained = false;
    printKingdom();
    while(!gained) {
        std::string input;
        std::getline(std::cin, input);
        if(isInteger(input)) {
            gained = kingdom[std::stoi(input)]->gain(p, x);
        }
    }
}

#endif