#ifndef GLOBAL_HPP
#define GLOBAL_HPP

#include <vector>
#include <time.h>
#include <algorithm> 

enum type {TREASURE, VICTORY, ACTION};
int turn;

class card {
public:
    std::string title;
private:
    type t;
    int cost;
    int value;
    int points;
public:
    card(std::string title, type t, int cost, int value, int points):
    title(title), t(t), cost(cost), value(value), points(points) {}
    // std::string getTitle() { return title; }
    int getCost() { return cost; }
    type getType() { return t; }
    int getValue() { return value; }
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
    void addCard(card *c) {
        deck.push_back(c);
    }
    void shuffleDeck(/*std::vector<card *> v*/) {
        srand(time(NULL));
        std::random_shuffle(deck.begin(), deck.end(), myrandom);
    }
    void shuffleDiscard(/*std::vector<card *> v*/) {
        srand(time(NULL));
        std::random_shuffle(discard.begin(), discard.end(), myrandom);
    }
    // void shuffleDeck() { shuffle(deck); }
    // void shuffleDiscard() { shuffle(discard); }
    void draw(unsigned int count) {
        if(deck.size() < count) {
            shuffleDiscard();
            for(unsigned int i = 0; i < discard.size(); i++) {
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

#endif