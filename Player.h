#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Deck.h"
class Deck;
class Card;
class BJCard;
class Player { //abstract player class for both humans and AI
protected:
	double money;
	int currentScore;
	std::vector<BJCard*> hand;
	std::string name;
public:
	Player(const std::string& name, double money);
	Player(double money);
	virtual ~Player() {

	}
	 //pure virtual function to be implemented by AI and HumanPlayer classes
	bool canBet(double moneyBetted) {
		return money >= moneyBetted;
	}
	bool canPlay() {
		return money > 0.0;
	}
	bool wonRound(Player* other);
	void collectMoney(double jackpot) {
		money += jackpot;
	}
	double getMoney() const {
		return money;
	}
	void draw(Deck& d);
	virtual int getAceValue() = 0;
	virtual double getBet() = 0;
	virtual void play(Deck& d) = 0;
	friend double collectBets(std::vector<Player*>::iterator begin, std::vector<Player*>::iterator end);
};
class HumanPlayer : public Player {
public:
	HumanPlayer(double money = 100.00);
	virtual ~HumanPlayer() {

	}
	void play(Deck& d) override;
	double getBet() override;
	int getAceValue() override;
};
class AIPlayer : public Player {
public:
	AIPlayer(int num) : Player("AIPlayer " + std::to_string(num), 100.0) {
	}
	virtual ~AIPlayer() {

	}
	void play(Deck& d) override;
	double getBet() override;
	int getAceValue() override;
};