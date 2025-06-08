#include "Deck.h"
#include <algorithm>
#include <random>
using namespace std;

Deck::Deck() {
    const string ranks[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
    for (int s = Card::Hearts; s <= Card::Spades; ++s) {
        for (auto& r : ranks) {
            cards.emplace_back(static_cast<Card::Suit>(s), r);
        }
    }
    shuffle();
    currentIndex = 0;
}

void Deck::shuffle() {
    random_device rd;
    mt19937 g(rd());
    std::shuffle(cards.begin(), cards.end(), g);
}

Card Deck::dealCard() {
    if (currentIndex >= cards.size()) {
        shuffle();
        currentIndex = 0;
    }
    return cards[currentIndex++];
}