#ifndef CARDS_HPP
#define CARDS_HPP

#include "global.hpp"

card *copper(player *p) {
    return new card("Copper", p, TREASURE, 0, 1, 0);
}

card *silver(player *p) {
    return new card("Silver", p, TREASURE, 3, 2, 0);
}

card *gold(player *p) {
    return new card("Gold", p, TREASURE, 6, 3, 0);
}

card *estate(player *p) {
    return new card("Estate", p, VICTORY, 2, 0, 1);
}

card *duchy(player *p) {
    return new card("Duchy", p, VICTORY, 5, 0, 3);
}

card *province(player *p) {
    return new card("Province", p, VICTORY, 8, 0, 6);
}

card *woodcutter(player *p) {
    card *c = new card("Woodcutter", p, ACTION, 3, 0, 0);
    void (*f)(int x, player *p) = addGold;
    c->addAction(f, 2);
    f = addBuys;
    c->addAction(f, 1);
    return c;
}

card *feast(player *p) {
    card *c = new card("Feast", p, ACTION, 4, 0, 0);
    void (*f)(int x, player *p) = trashCard;
    c->addAction(f, 0);
    f = gainCard;
    c->addAction(f, 5);
    return c;
}

card *village(player *p) {
    card *c = new card("Village", p, ACTION, 3, 0, 0);
    void (*f)(int x, player *p) = drawCards;
    c->addAction(f, 1);
    f = addActions;
    c->addAction(f, 2);
    return c;
}

card *smithy(player *p) {
    card *c = new card("Smithy", p, ACTION, 4, 0, 0);
    void (*f)(int x, player *p) = drawCards;
    c->addAction(f, 3);
    return c;
}

card *festival(player *p) {
    card *c = new card("Festival", p, ACTION, 5, 0, 0);
    void (*f)(int x, player *p) = addActions;
    c->addAction(f, 2);
    f = addBuys;
    c->addAction(f, 1);
    f = addGold;
    c->addAction(f, 2);
    return c;
}

card *laboratory(player *p) {
    card *c = new card("Laboratory", p, ACTION, 5, 0, 0);
    void (*f)(int x, player *p) = drawCards;
    c->addAction(f, 2);
    f = addActions;
    c->addAction(f, 1);
    return c;
}

card *market(player *p) {
    card *c = new card("Market", p, ACTION, 5, 0, 0);
    void (*f)(int x, player *p) = drawCards;
    c->addAction(f, 1);
    f = addActions;
    c->addAction(f, 1);
    f = addBuys;
    c->addAction(f, 1);
    f = addGold;
    c->addAction(f, 1);
    return c;
}

#endif