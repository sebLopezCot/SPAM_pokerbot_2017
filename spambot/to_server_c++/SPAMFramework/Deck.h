#ifndef DECK_H
#define DECK_H 

#include <string>
#include <vector>
#include <cstdlib>

#include "Card.h"

class Deck
{
public:
	Deck();
	
	Card* Draw();

private:
	std::vector<std::string> m_card_ids;
};

#endif