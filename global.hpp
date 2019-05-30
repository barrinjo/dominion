#ifndef GLOBAL_HPP
#define GLOBAL_HPP

#include <vector>
#include <time.h>
#include <algorithm>

enum type {TREASURE, VICTORY, ACTION};
unsigned int turn = 0;
unsigned int totalTurns = 0;
class kingdomCard;
class card;
std::vector< kingdomCard * > kingdom;
std::vector< card * > trash;
void printKingdom();
inline bool isInteger(const std::string & s);

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
    void resetCard() { it = 0; }\

    int getCost() { return cost; }
    type getType() { return t; }
    int getValue() { return value; }
    int getPoints () { return points; }
    std::vector< void (*)(int, player *) > getActionList() { return actionList; }
    player * getPlayer() { return p; }
};

int myrandom (int i) { return std::rand()%i;}

class player {
    int loc;
    int actions;
    int gold;
    int buys;
    int points;
    std::vector <card *> deck;
    std::vector <card *> discard;
    std::vector <card *> hand;
    std::vector <card *> board;
public:
    player(int loc): loc(loc), actions(1), gold(0), buys(1), points(0) {}
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
            board.push_back(c);
            hand.erase(hand.begin() + loc);
            for(unsigned int i = 0; i < c->getActionList().size(); i++) {
                c->doAction();
            }
            actions--;
        }
        c->resetCard();
    }
    // void trashCard(card *c) {
    //     c->resetCard();
    //     for(unsigned int i = 0; i < hand.size(); i++) {
    //         if(board[i] == c) {
    //             board.erase(board.begin() + i);
    //             trash.push_back(c);
    //         }
    //     }
    // }
    void trashCard() {
        card *c = board[board.size()];
        board.pop_back();
        trash.push_back(c);
    }

    void clearBoard() {
        for(unsigned int i = 0; i < board.size(); i++) {
            card *c = board[board.size() - 1];
            board.pop_back();
            c->resetCard();
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
    void clearDeck() {
        for(unsigned int i = 0; i < deck.size(); i++) {
            card *c = deck[deck.size() - 1];
            deck.pop_back();
            c->resetCard();
            discard.push_back(c);
        }
    }
    // void gainCard(int value) {
    //     std::cout << "  GAIN CARD COSTING UP TO " << value << ": " << std::endl;
    //     bool gained = false;
    //     printKingdom();
    //     while(!gained) {
    //         std::string input;
    //         std::getline(std::cin, input);
    //         if(isInteger(input)) {
    //             gained = kingdom[std::stoi(input)]->gain(this, value);
    //         }
    //     }
    // }
    void clearAll() { clearBoard(); clearHand(); clearDeck(); }

    void updateGold(int change) { gold += change; }
    void updateActions(int change) { actions += change; }
    void updateBuys(int change) { buys += change; }
    void updatePoints(int change) { points += change; }

    void setGold(int i) { gold = i; }
    void setActions(int i) { actions = i; }
    void setBuys(int i) { buys = i; }

    int getGold() { return gold; }
    int getActions() { return actions; }
    int getBuys() { return buys; }
    int getPoints() { return points; }
    std::vector<card *> getDeck() { return deck; }
    std::vector<card *> getDiscard() { return discard; }
    std::vector<card *> getHand() { return hand; }
};

std::vector <player *> playerList;

class kingdomCard {
    card * (*cardCon)(player *);
    int remaining;
public:
    kingdomCard(card * (*c)(player *), int r): cardCon(c), remaining(r) {}
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
    bool gain(player *p, int value) {
        card *c = cardCon(p);
        if(c->getCost() <= value) {
            if(remaining > 0) {
                p->addCardDiscard(c);
                p->updateGold(-c->getCost());
                remaining--;
                return true;
            } else {
                std::cout << "none remaining" << std::endl;
            }
        } else {
            std::cout << "too expensive" << std::endl;
        }
        return false;
    }
    card *getCard() { return cardCon(playerList[turn]); }
    int getRemaining() { return remaining; }
};

#endif