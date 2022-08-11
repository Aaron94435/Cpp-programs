#include "Deck.h"
#include <utility>
Deck::Deck() {
	generateCards();
}
Card* Deck::deal() {
	if (deck.empty()) {
		generateCards();
	}	
	Card* card = new Card(std::move(deck.front())); //moves the card to "card" without creating a copy
	deck.pop_front();
	//deck.push_back(card);
	return card;
}
void Deck::generateCards() {
	for (int i = 0; i < Card::suitList.size(); i++) {
		for (int j = 0; j < Card::rankList.size(); j++) {
			deck.emplace_back(Card(Card::rankList[j], Card::suitList[i]));
		}
	}
	shuffle();
}
Card::Card(Card::Rank rank, Card::Suit suit) {
	this->rank = rank;
	this->suit = suit;
}
Card::Card(const Card&& card) noexcept{
	this->rank = card.rank;
	this->suit = card.suit;
}
/*int Card::getCardValue(Player* p) {
	switch (rank) {
	case Rank::TWO: return 2;
	case Rank::THREE: return 3;
	case Rank::FOUR: return 4;
	case Rank::FIVE: return 5;
	case Rank::SIX: return 6;
	case Rank::SEVEN: return 7;
	case Rank::EIGHT: return 8;
	case Rank::NINE: return 9;
	case Rank::TEN: return 10;
	case Rank::JACK: return 11;
	case Rank::QUEEN: return 12;
	case Rank::KING: return 13;
	case Rank::ACE: return 14;
	default: return -1;
	}
}*/
int BJCard::getCardValue(Player* p) {
	switch (rank) {
	case Rank::TWO: return 2;
	case Rank::THREE: return 3;
	case Rank::FOUR: return 4;
	case Rank::FIVE: return 5;
	case Rank::SIX: return 6;
	case Rank::SEVEN: return 7;
	case Rank::EIGHT: return 8;
	case Rank::NINE: return 9;
	case Rank::ACE: return p->getAceValue();
	default: return 10; //for 10 and all the face cards for optimization reasons
	}
}
std::ostream& operator <<(std::ostream& os, const Card& card) {
	os << "[" << static_cast<char>(card.rank) << " " << static_cast<char>(card.suit) << "]";
	return os;
}
