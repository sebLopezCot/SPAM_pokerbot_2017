#include "Deck.h"

Deck::Deck() {
	std::vector<std::string> list(Card::GetCardList());
	m_card_ids = list;
}

Card* Deck::Draw() {
	if(m_card_ids.size() > 0) {
		int random = 0 + (rand() % (int)(m_card_ids.size() - 0 + 1));
		Card *c = new Card(m_card_ids.erase(m_card_ids.begin() + random));
		return c;
	} else {
		return NULL;
	}
}
