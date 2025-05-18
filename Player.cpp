#include "Player.h"
#include <iostream>

Player::Player(bool dealer) : isDealer(dealer), balance(1000), bet(0) {}

void Player::addCard(Card c) {
    hand.push_back(c);
}

int Player::getScore() const {
    int total = 0;
    int aceCount = 0;
    for (const auto& c : hand) {
        total += c.getValue();
        if (c.isAce()) aceCount++;
    }
    while (total > 21 && aceCount > 0) {
        total -= 10;
        aceCount--;
    }
    return total;
}

void Player::showHand(bool showAll) const {
    if (!showAll && isDealer) {
        cout << "[未知] " << hand[1].toString() << endl;
    }
    else {
        for (const auto& c : hand) {
            cout << c.toString() << " ";
        }
        cout << "(" <<"手牌點數 : " << getScore() << ")" << endl;
    }
}

void Player::resetHand() {
    hand.clear();
}

bool Player::isBusted() const {
    return getScore() > 21;
}

bool Player::hasBlackjack() const {
    return hand.size() == 2 && getScore() == 21;
}

int Player::getBalance() const {
    return balance;
}

void Player::adjustBalance(int amount) {
    balance += amount;
}

void Player::placeBet(int amount) {
    bet = amount;
    balance -= amount;
}

int Player::getBet() const {
    return bet;
}