#ifndef GAME_H
#define GAME_H
#include "Deck.h"
#include "Player.h"
using namespace std;

class Game {
private:
    Deck deck;
    Player player;
    Player dealer;
public:
    Game();
    void play();
};

#endif