#ifndef GLOBAL_HPP
#define GLOBAL_HPP

#include <vector>
#include <time.h>
#include <algorithm>

enum type {TREASURE, VICTORY, ACTION};
int turn = 0;
class kingdomCard;
class card;
std::vector< kingdomCard * > kingdom;

class player;

class card {
public:
    std::string title;
private:
    player *p;
    type t;
    int cost;
    int value;
    int points;
    int it;
    std::vector< void (*)(int, player *) > actionList;
    std::vector< int > actionListValues;
public:
    card(std::string title, player *p, type t, int cost, int value, int points):
    title(title), p(p), t(t), cost(cost), value(value), points(points), it(0) {}
    // std::string getTitle() { return title; }
    void addAction(void (*f)(int, player *), int value) {
        actionList.push_back(f);
        actionListValues.push_back(value);
    }
    void doAction() {
        actionList[it](actionListValues[it], p);
        it++;
    }
    int getCost() { return cost; }
    type getType() { return t; }
    int getValue() { return value; }
    std::vector< void (*)(int, player *) > getActionList() { return actionList; }
};

int myrandom (int i) { return std::rand()%i;}

class player {
    int loc;
    int actions;
    int gold;
    int buys;
    std::vector <card *> deck;
    std::vector <card *> discard;
    std::vector <card *> hand;
    std::vector <card *> board;
public:
    player(int loc): loc(loc), actions(1), gold(0), buys(1) {}
    void addCardDeck(card *c) {
        deck.push_back(c);
    }
    void addCardDiscard(card *c) {
        discard.push_back(c);
    }
    void shuffleDeck(/*std::vector<card *> v*/) {
        srand(time(NULL));
        std::random_shuffle(deck.begin(), deck.end(), myrandom);
    }
    void shuffleDiscard(/*std::vector<card *> v*/) {
        srand(time(NULL));
        std::random_shuffle(discard.begin(), discard.end(), myrandom);
    }
    void draw(unsigned int count) {
        if(deck.size() < count) {
            shuffleDiscard();
            unsigned int s = discard.size();
            for(unsigned int i = 0; i < s; i++) {
                card *c = discard[discard.size() - 1];
                discard.pop_back();
                deck.insert(deck.begin(), c); 
            }
        }
        for(unsigned int i = 0; i < count; i++) {
            card *c = deck[deck.size() - 1];
            deck.pop_back();
            hand.push_back(c);
        }
    }
    void printHand() {
        for(unsigned int i = 0; i < hand.size(); i++) {
            // std::string temp = hand[i]->getTitle;
            std::cout << "card " << i << ": " << hand[i]->title << std::endl;
        }
    }
    void playCard(int loc) {
        card *c = hand[loc];
        if(c->getType() == ACTION && actions > 0) {
            for(unsigned int i = 0; i < c->getActionList().size(); i++) {
                c->doAction();
            }
            board.push_back(c);
            hand.erase(hand.begin() + loc);
            actions--;
        }
    }
    void clearBoard() {
        for(unsigned int i = 0; i < board.size(); i++) {
            card *c = board[board.size() - 1];
            board.pop_back();
            discard.push_back(c);
        }
    }
    void clearHand() {
        int s = hand.size();
        for(int i = 0; i < s; i++) {
            card *c = hand[hand.size() - 1];
            hand.pop_back();
            discard.push_back(c);
        }
    }
    void clearAll() { clearBoard(); clearHand(); }

    void updateGold(int change) { gold += change; }
    void updateActions(int change) { actions += change; }
    void updateBuys(int change) { buys += change; }

    void setGold(int i) { gold = i; }
    void setActions(int i) { actions = i; }
    void setBuys(int i) { buys = i; }

    int getGold() { return gold; }
    int getActions() { return actions; }
    int getBuys() { return buys; }
    std::vector<card *> getDeck() { return deck; }
    std::vector<card *> getHand() { return hand; }
};

std::vector <player *> playerList;

class kingdomCard {
    card * (*cardCon)(player *);
    int remaining;
public:
    kingdomCard(card * (*c)(player *)): cardCon(c), remaining(10) {}
    void buyCard(player *p) {
        card *c = cardCon(p);
        if(c->getCost() <= p->getGold()) {
            if(remaining > 0) {
                p->addCardDiscard(c);
                p->updateGold(-c->getCost());
                p->updateBuys(-1);
                remaining--;
            } else {
                std::cout << "none remaining" << std::endl;
            }
        } else {
            std::cout << "not enough money" << std::endl;
        }
    }
    card *getCard() { return cardCon(playerList[turn]); }
    int getRemaining() { return remaining; }
};

#endif