#include "Deck.h"
#include "Player.h"
#include <iostream>
#include <vector>
#include <cstdlib>
bool gameInSession(std::vector<Player*>::iterator begin, std::vector<Player*>::iterator end);
int main() {
	std::vector<Player*> players;
	Deck deck;
	players.emplace_back(new HumanPlayer());
	
	players.emplace_back(new AIPlayer(0));
	while (gameInSession(players.begin(), players.end())) {
		double money = collectBets(players.begin(), players.end());
		for (int i = 0; i < players.size(); i++) {
			players[i]->play(deck);
		}
		if (players[0]->wonRound(players[1]))
			players[0]->collectMoney(money);
		else
			players[1]->collectMoney(money);
	}
	
	return 0;
}
bool gameInSession(std::vector<Player*>::iterator begin, std::vector<Player*>::iterator end) {
	auto it = begin;
	int count = 0;
	while (it != end) {
		if ((*it)->canPlay())
			count++;
		if (count > 1)
			return true;
	}
	return false;
}