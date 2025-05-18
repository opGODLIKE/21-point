#include "Game.h"
#include <iostream>
using namespace std;

Game::Game() : player(false), dealer(true) {}

void Game::play() {
    while (player.getBalance() >= 200) {
        cout << "\n�s���}�l�I�ثe�w�X: $" << player.getBalance() << endl;
        cout << endl;

        player.placeBet(200);

        player.resetHand();
        dealer.resetHand();

        player.addCard(deck.dealCard());
        dealer.addCard(deck.dealCard());
        player.addCard(deck.dealCard());
        dealer.addCard(deck.dealCard());

        cout << "���a��P�G";
        player.showHand();
        cout << endl;
        cout << "���a��P�G";
        cout << endl;
        dealer.showHand(false);

        // ���a���
        while (true) {
            if (player.getScore() >= 21) break;
            cout << endl;
            cout << "�n�P(h)�ΰ��P(s)? ";
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

        // ���a�z�P
        if (player.isBusted()) {
            cout << "���a�z�P�A�鱼�o���I\n";
            cout << endl;
            continue;
        }

        // ���a���
        cout << "���a��P�G";
        cout << endl;
        dealer.showHand();
        while (dealer.getScore() < 17) {
            dealer.addCard(deck.dealCard());
            cout << "���a��P�G";
            cout << endl;
            dealer.showHand();
        }

        if (dealer.isBusted()) {
            cout << "���a�z�P�A���aĹ�F�I\n";
            cout << endl;
            player.adjustBalance(player.getBet() * 2);
        }
        else {
            int pScore = player.getScore();
            int dScore = dealer.getScore();
            if (pScore > dScore) {
                cout << "���aĹ�F�I\n";
                cout << endl;
                player.adjustBalance(player.getBet() * 2);
            }
            else if (pScore < dScore) {
                cout << "���a��F�I\n";
                cout << endl;
            }
            else {
                cout << "���� (Push)�A�h�٤U�`�I\n";
                cout << endl;
                player.adjustBalance(player.getBet());
            }
        }
    }

    cout << "\n�A���w�X�Χ��F�A�C�������I\n";
    cout << endl;
}