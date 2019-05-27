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

inline bool isInteger(const std::string & s)
{
   if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

   char * p;
   strtol(s.c_str(), &p, 10);

   return (*p == 0);
}

void actionPhase() {
    std::cout << "action phase: " << std::endl;
    player *p = playerList[turn];
    std::vector<card *> hand = p->getHand();
    bool exit = !handCheck(hand, ACTION);
    std::string input;
    p->printHand();
    while(!exit) {
        std::cout << "play an action card" << std::endl;
        std::cin >> input;
        if(isInteger(input)) {
            p->playCard(std::stoi(input));
            p->printHand();
        } else if (input == "end") {
            exit = true;
        } else {
            std::cout << "input not recognized" << std::endl;
        }
        exit = handCheck(hand, ACTION);
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
    player *p = playerList[turn];
    p->clearAll();
    p->draw(5);
    p->setGold(0);
    p->setActions(1);
    p->setBuys(1);
    std::string temp;
    std::cout << "Enter \'0\' to Continue" << std::endl;
    std::cin >> temp;
}

#endif