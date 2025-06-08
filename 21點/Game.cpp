#include "Game.h"
#include <iostream>
using namespace std;

Game::Game() : player(false), dealer(true) {}

void Game::play() {
    while (player.getBalance() >= 200) {
        cout << "\n新局開始！目前籌碼: $" << player.getBalance() << endl;
        cout << endl;

        player.placeBet(200);

        player.resetHand();
        dealer.resetHand();

        player.addCard(deck.dealCard());
        dealer.addCard(deck.dealCard());
        player.addCard(deck.dealCard());
        dealer.addCard(deck.dealCard());

        cout << "玩家手牌：";
        player.showHand();
        cout << endl;
        cout << "莊家手牌：";
        cout << endl;
        dealer.showHand(false);

        // 玩家行動
        while (true) {
            if (player.getScore() >= 21) break;
            cout << endl;
            cout << "要牌(h)或停牌(s)? ";
            char choice;
            cin >> choice;
            if (choice == 'h') {
                player.addCard(deck.dealCard());
                player.showHand();
            }
            else if (choice == 's') {
                break;
            }
        }

        // 玩家爆牌
        if (player.isBusted()) {
            cout << "玩家爆牌，輸掉這局！\n";
            cout << endl;
            continue;
        }

        // 莊家行動
        cout << "莊家手牌：";
        cout << endl;
        dealer.showHand();
        while (dealer.getScore() < 17) {
            dealer.addCard(deck.dealCard());
            cout << "莊家抽牌：";
            cout << endl;
            dealer.showHand();
        }

        if (dealer.isBusted()) {
            cout << "莊家爆牌，玩家贏了！\n";
            cout << endl;
            player.adjustBalance(player.getBet() * 2);
        }
        else {
            int pScore = player.getScore();
            int dScore = dealer.getScore();
            if (pScore > dScore) {
                cout << "玩家贏了！\n";
                cout << endl;
                player.adjustBalance(player.getBet() * 2);
            }
            else if (pScore < dScore) {
                cout << "玩家輸了！\n";
                cout << endl;
            }
            else {
                cout << "平手 (Push)，退還下注！\n";
                cout << endl;
                player.adjustBalance(player.getBet());
            }
        }
    }

    cout << "\n你的籌碼用完了，遊戲結束！\n";
    cout << endl;
}