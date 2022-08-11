#pragma once
#include <iostream>
#include <deque>
#include <array>
#include <algorithm> //shuffle algorithm
#include <random>
#include "Player.h"
class Player;
class Card {
public:
	enum class Suit : char{
		CLUBS = 'C', DIAMONDS = 'D', HEARTS ='H', SPADES = 'S'
	};
	enum class Rank : char{
		TWO = '2', THREE = '3', FOUR = '4', FIVE = '5', SIX = '6', SEVEN = '7', EIGHT ='8',
		NINE ='9', TEN ='T', JACK = 'J', QUEEN = 'Q', KING = 'K', ACE = 'A'
	};
protected:
	Suit suit;
	Rank rank;
public:
	static constexpr std::array<Suit, 4> suitList = { Suit::CLUBS, Suit::DIAMONDS, Suit::HEARTS, Suit::SPADES };
	static constexpr std::array<Rank, 13> rankList = { Rank::TWO, Rank::THREE, Rank::FOUR, Rank::FIVE, Rank::SIX,
		Rank::SEVEN, Rank::EIGHT, Rank::NINE, Rank::TEN, Rank::JACK, Rank::QUEEN, Rank::KING, Rank::ACE };

	Card(Rank rank, Suit suit);
	Card(const Card&& card) noexcept;
	virtual ~Card(){}
	Rank getRank() const{
		return this->rank;
	}
	Suit getSuit() const{
		return this->suit;
	}
	friend std::ostream& operator << (std::ostream& os, const Card& card);
	void operator = (Card&& card) noexcept{
		this->rank = card.rank;
		this->suit = card.suit;
	}
	//virtual int getCardValue(Player* p = nullptr);
};
class Deck {
private:
	std::deque<Card> deck;
public:
	Deck();
	Card* deal();
	void generateCards();
	void shuffle() {
		std::shuffle(deck.begin(), deck.end(), std::random_device());
	}
	friend class Player;
};
class BJCard : public Card {
public:
	BJCard(Rank rank, Suit suit) : Card(rank, suit) {

	}
	virtual ~BJCard(){}
	int getCardValue(Player* p);
};