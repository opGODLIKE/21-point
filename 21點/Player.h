#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include "Card.h"
using namespace std;

class Player {
private:
    vector<Card> hand;
    bool isDealer;
    int balance;
    int bet;
public:
    Player(bool dealer = false);
    void addCard(Card c);
    int getScore() const;
    void showHand(bool showAll = true) const;
    void resetHand();
    bool isBusted() const;
    bool hasBlackjack() const;
    int getBalance() const;
    void adjustBalance(int amount);
    void placeBet(int amount);
    int getBet() const;
};
#endif