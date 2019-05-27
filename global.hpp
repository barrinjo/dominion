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
};

int myrandom (int i) { return std::rand()%i;}

class player {
    int loc;
    int actions;
    int gold;
    int buys;
    bool myTurn;
    std::vector <card *> deck;
    std::vector <card *> discard;
    std::vector <card *> hand;
public:
    player(int loc): loc(loc), actions(1), gold(0), buys(1), myTurn(false) {}
    void addCard(card *c) {
        deck.push_back(c);
    }
    void activateTurn() { myTurn = true; }
    void shuffleDeck() {
        srand(time(NULL));
        std::random_shuffle(deck.begin(), deck.end(), myrandom);
    }
    void draw(int count) {
        for(int i = 0; i < count; i++) {
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
    void updateGold(int change) { gold += change; }
};

std::vector <player *> playerList;

#endif