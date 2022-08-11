#include "Player.h"
#include <iomanip> //for money formatting
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>
Player::Player(const std::string& name, double money) {
	this->name = name;
	this->money = money;
	this->currentScore = 0;
	hand.reserve(2);
}
Player::Player(double money) {
	this->money = money;
	this->currentScore = 0;
	hand.reserve(2);
}
void Player::draw(Deck& d) {
	hand.emplace_back((static_cast<BJCard*>(d.deal()))); //move the card from the deck to the hand
}
bool Player::wonRound(Player* other) {
	if ((currentScore > other->currentScore) && currentScore <= 21)
		return true;
	return false;
}
HumanPlayer::HumanPlayer(double money) : Player(money){
	std::cout << "Enter your name: ";
	std::cin >> name;
}
int HumanPlayer::getAceValue() {
	int aceVal;
	std::cout << "Pick ace value 1 or 11: ";
	std::cin >> aceVal;
	while (aceVal != 1 && aceVal != 11) {
		std::cout << "Invalid value! Try again! ";
		std::cin >> aceVal;
	}
	return aceVal;
}
void HumanPlayer::play(Deck& d) {
	std::string answer;
	std::cout << "Hit or stand: ";
	std::cin >> answer;
	std::for_each(answer.begin(), answer.end(), [](char& c) { //convert to lower case
		c = ::tolower(c);
		});
	while (answer == "hit") {
		draw(d);
		std::cout << name << " hits and he draws " << *hand[hand.size() - 1] << "\n";
		currentScore += hand[hand.size() - 1]->getCardValue(this);
		if (currentScore > 21) {
			std::cout << name << " has busted!\n";
			break;
		}
		else if (currentScore == 21) {
			std::cout << name << " got a blackjack!\n";
			break;
		}
		std::cout << "CurrentScore: " << currentScore << "Hit or stand: ";
		std::cin >> answer;
	}
	if (answer == "stand")
		std::cout << name << " is standing with score of " << currentScore << "\n";
	for (int i = 0; i < hand.size(); i++) {
		delete hand[i]; //deallocated memory pointed to by pointers
	}
	hand.clear();
	currentScore = 0;
}
double HumanPlayer::getBet() {
	double bet;
	std::cout << "Enter your bet: ";
	std::cin >> bet;
	while (!canBet(bet)) {
		std::cout << "Try again: ";
		std::cin >> bet;
	}
	std::cout << name << " bets $" << std::setprecision(2) << bet << "\n";
	money -= bet;
	return bet;
}
int AIPlayer::getAceValue() {
	if (currentScore <= 10)
		return 11;
	return 1;
}
void AIPlayer::play(Deck& d) {
	while (currentScore <= 16) {
		draw(d);
		std::cout << name << " hits and he draws " << *hand[hand.size() - 1] << "\n";
		currentScore += hand[hand.size() - 1]->getCardValue(this);
	 }
	if (currentScore < 21)
		std::cout << name << " He stands with score " << currentScore << "!\n";
	else if (currentScore == 21)
		std::cout << name << " got a blackjack!\n";
	else
		std::cout << name << " has busted!\n";

	for (int i = 0; i < hand.size(); i++) {
		delete hand[i];
	}
	hand.clear();
	currentScore = 0;
}
double AIPlayer::getBet() {
	std::random_device r;
	double dollar[6] = { 1.0, 5.0, 10.0, 20.0, 50.0, 100.0};
	int index = r() % 6;
	double bet = dollar[index];
	while (canBet(bet) && index > 0) {
		index--;
		bet = dollar[index];
	}
	money -= bet;
	std::cout << name << " bets $" << std::setprecision(2) << bet << "\n";
	return bet;
}
double collectBets(std::vector<Player*>::iterator begin, std::vector<Player*>::iterator end) {
	auto it = begin;
	double betsCollected = 0.0;
	while (it != end) {
		betsCollected += (*it)->getBet();
		it++;
	}
	return betsCollected;
}