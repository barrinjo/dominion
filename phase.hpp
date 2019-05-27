#ifndef PHASE_HPP
#define PHASE_HPP

#include "global.hpp"

void cleanPhase();
void actionPhase();
void buyPhase();
bool handCheck(std::vector<card *> deck, type t);

bool handCheck(std::vector<card *> deck, type t) {
    for(unsigned int i = 0; i < deck.size(); i++) {
        if(deck[i]->getType() == t)
            return true;
    }
    return false;
}

void actionPhase() {
    std::cout << "action phase: " << std::endl;
    player *p = playerList[turn];
    std::vector<card *> hand = p->getHand();
    bool exit = !handCheck(hand, ACTION);
    std::string input;
    while(!exit) {
        p->printHand();
        std::cout << "play an action card" << std::endl;
        std::cin >> input;
        if(input == "quit")
            exit = true;
        else
            p->playCard(std::stoi(input));
    }
}

void buyPhase() {
    std::cout << "buy phase: " << std::endl;
    player *p = playerList[turn];
    std::vector<card *> hand = p->getHand();
    bool exit = !handCheck(hand, TREASURE);
    for(unsigned int i = 0; i < hand.size(); i++) {
        p->updateGold(hand[i]->getValue());
    }
    while(!exit) {
        std::cout << "you have " << p->getGold() << " gold and " << p->getBuys() << " buys" << std::endl;
        exit = true;
    }
}

void cleanPhase() {
    std::cout << "test" << std::endl;
    player *p = playerList[turn];
    p->clearAll();
    p->draw(5);
    p->setGold(0);
    p->setActions(1);
    p->setBuys(1);
    int temp;
    std::cin >> temp;
}

#endif