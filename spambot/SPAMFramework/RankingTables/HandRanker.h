#ifndef HAND_RANKER_H
#define HAND_RANKER_H 

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <fstream>

#include "RankingTableConfig.h"
#include "../Card.h"
#include "../Util/SPAMHelper.h"

class HandRanker
{
public:
	HandRanker(int num_board_cards, std::string table_location);

	int GetValue(std::vector<Card*> hand, std::vector<Card*> board_cards);  

	std::vector<std::string> MapToCompressionScheme(std::vector<int> hand_as_numbers, 
		std::vector<int> board_cards_as_numbers);

	bool AcceptableNumberOfCards(int num_hand_cards, int num_board_cards);

	int ParseRanking(std::string hand_string, std::string board_card_string);

	static bool Compare(std::vector<int> self, std::vector<int> other);

private:
	int m_num_hand_cards;
	int m_num_board_cards;
	std::string m_table_location;
};

#endif