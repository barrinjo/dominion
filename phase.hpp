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
    std::cout << "\033[2J\033[1;1H" << "  ACTION PHASE: " << std::endl;
    player *p = playerList[turn];
    std::vector<card *> hand = p->getHand();
    bool exit = !handCheck(hand, ACTION);
    std::string input;
    while(!exit) {
        p->printHand();
        std::cout << "You have " << p->getActions() << " actions" << std::endl;
        std::getline(std::cin, input);
        if(isInteger(input)) {
            p->playCard(std::stoi(input));
            hand = p->getHand();
            // exit = !handCheck(hand, ACTION);
        } else {
            exit = true;
        }
        if(p->getActions() == 0 || !handCheck(hand, ACTION)) {
            break;
        }
    }
}

void buyPhase() {
    std::cout << "  BUY PHASE: " << std::endl;
    player *p = playerList[turn];
    p->printHand();
    std::vector<card *> hand = p->getHand();
    for(unsigned int i = 0; i < hand.size(); i++) {
        p->updateGold(hand[i]->getValue());
    }
    while(p->getBuys() > 0 && p->getGold() > 0) {
        std::cout << "you have " << p->getGold() << " gold and " << p->getBuys() << " buys" << std::endl;
        printKingdom();
        std::string input;
        std::getline(std::cin, input);
        if(isInteger(input)) {
            kingdom[std::stoi(input)]->buyCard(p);
        } else {
            break;
        }
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
    std::cout << "Enter to Continue" << std::endl;
    std::getline(std::cin, temp);
}

#endif