#include "Card.h"

Card::Card(Suit s, const string& r) : suit(s), rank(r) {}

int Card::getValue() const {
    if (rank == "A") return 11;
    if (rank == "K" || rank == "Q" || rank == "J") return 10;
    return stoi(rank);
}

bool Card::isAce() const {
    return rank == "A";
}

std::string Card::toString() const {
    static const char* suits[] = { "�R��", "���", "�®�", "����" };
    return  suits[suit] + rank;
}
