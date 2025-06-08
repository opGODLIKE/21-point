#ifndef CARD_H
#define CARD_H
#include <string>
using namespace std;

class Card {
public:
    enum Suit { Hearts, Diamonds, Clubs, Spades };
private:
    Suit suit;
    string rank;
public:
    Card(Suit s, const string& r);
    int getValue() const;
    bool isAce() const;
    string toString() const;
};

#endif