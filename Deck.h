#ifndef DECK_H
#define DECK_H
#include <vector>
#include "Card.h"
using namespace std;

class Deck {
private:
    vector<Card> cards;
    int currentIndex;
public:
    Deck();
    void shuffle();
    Card dealCard();
};

#endif