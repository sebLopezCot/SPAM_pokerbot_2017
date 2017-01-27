#include "Card.h"

Card::Card(std::string id) {
	if (card_id_to_number == NULL) {
		Init();
	}

	try {
		// Check if id is in map
		if (IsCard(id)) {
			m_id = id;
		} else {
			throw 10;
		}

	} catch (int e) {
		std::cout << "Specified card ID is not valid" << std::endl;
	}
}

void Card::Init() {
	std::string[] suits = { "h", "s", "c", "d" };
	std::string[] values = { "2", "3", "4", "5", "6", "7", 
				"8", "9", "T", "J", "Q", "K", "A" };

	int num_suits = sizeof(suits) / sizeof(suits[0])
	int num_values = sizeof(values) / sizeof(values[0])
	for (int i=0; i < num_values; i++) {
		for (int j=0; j < num_suits; j++) {
			card_id_to_number[values[i]+suits[j]] = i*4 + j;
		}
	}
}

std::vector<std::string> Card::GetCardList() {
	if (card_id_to_number == NULL) {
		Init();
	}

	std::vector<std::string> card_list(52);
	for (std::map<std::string, int>::iterator it = card_id_to_number.begin(); it != card_id_to_number.end(); ++it) {
		card_list.push_back(it->first);
	}

	return card_list;
}

bool Card::IsCard(std::string card_id) {
	if (card_id_to_number == NULL) {
		Init();
	}

	return (card_id_to_number.count(id) > 0);
}

std::string Card::ToString() {
	return m_id;
}

int Card::ToNumber() {
	if (card_id_to_number == NULL) {
		Init();
	}

	return card_id_to_number[m_id];
}
