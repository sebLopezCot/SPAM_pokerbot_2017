#include "HandRanker.h"

HandRanker::HandRanker(int num_board_cards, std::string table_location) {
	m_num_board_cards = num_board_cards;
	m_table_location = table_location;
}

int HandRanker::GetValue(std::vector<Card*> hand, std::vector<Card*> board_cards) {
	int rank = -1;

	// Make sure card arrays are of right lengths
	try {
		if (AcceptableNumberOfCards(hand.size(), board_cards.size())) {

			// Convert card objects to number arrays
			std::vector<int> hand_cards_as_nums(2);
			for (int i=0; i < 2; i++) {
				hand_cards_as_nums[i] = hand[i]->ToNumber();
			}

			std::vector<int> board_cards_as_nums(board_cards.size());
			for (int i=0; i < board_cards.size(); i++) {
				board_cards_as_nums[i] = board_cards[i]->ToNumber();
			}

			// Map to compression scheme
			std::vector<std::string> hand_and_board_card_strings 
					= MapToCompressionScheme(hand_cards_as_nums, board_cards_as_nums);

			// Parse ranking from table in file system
			rank = ParseRanking(hand_and_board_card_strings[0], hand_and_board_card_strings[1]);

		} else {
			throw 10;
		}
	} catch (int e) {
		std::cout << "INVALID HAND OR BOARD CARD ARRAY SIZES: (Hand: " << hand.size()
			<< ", Board Cards: " << board_cards.size() << ")" << std::endl;
	}

	return rank;
}

bool HandRanker::Compare(std::vector<int> self, std::vector<int> other) {
	int s = self[0];
	int o = other[0];

	return (s <= o);
}

std::vector<std::string> HandRanker::MapToCompressionScheme(std::vector<int> hand_as_numbers, 
	std::vector<int> board_cards_as_numbers) {

	// Suit array
	std::vector<std::vector<int>> num_of_each_suit(4);

	// init suit array
	for (int i=0; i < 4; i++) {
		std::vector<int> temp(2);
		temp[0] = 0;
		temp[1] = i;
		num_of_each_suit[i] = temp;
	}

	// Count the frequency of each suit in board cards
	for (int i=0; i < board_cards_as_numbers.size(); i++) {
		int board_card = board_cards_as_numbers[i];
		num_of_each_suit[board_card % 4][0]++;
	}

	// Sort based on frequency
	std::sort(num_of_each_suit.begin(), num_of_each_suit.end(), Compare);
	std::reverse(num_of_each_suit.begin(), num_of_each_suit.end());

	// Transforming old suits into new ones
	std::vector<int> new_hand_cards(2);

	for (int i=0; i < 2; i++) {
		int card_suit = 0;
		int hand_card = hand_as_numbers[i];
		for (int j=0; j < 4; j++) {
			if (hand_card % 4 == num_of_each_suit[j][1]) {
				card_suit = j;
				break;
			}
		}

		// Note: Using integer division on purpose
		new_hand_cards[i] = hand_card/4 * 4 + card_suit;
	}

	std::vector<int> new_board_cards(board_cards_as_numbers.size());

	for (int i=0; i < board_cards_as_numbers.size(); i++) {
		int card_suit = 0;
		int board_card = board_cards_as_numbers[i];
		for (int j=0; j < 4; j++) {
			if (board_card % 4 == num_of_each_suit[j][1] ) {
				card_suit = j;
				break;
			}
		}

		// Note: Using integer division on purpose
		new_board_cards[i] = board_card/4 * 4 + card_suit;
	}

	// Sort arrays again
	std::sort(new_board_cards.begin(), new_board_cards.end());
	std::sort(new_board_cards.begin(), new_board_cards.end());

	// Convert to string array
	std::string new_hand_string = "";
	for (int i=0; i < 2; i++) {
		new_hand_string += std::to_string(new_hand_cards[i]);
		if (i < new_hand_cards.size()-1) {
			new_hand_string += ",";
		}
	}

	std::string new_board_card_string = "";
	for (int i=0; i < new_board_cards.size(); i++) {
		new_board_card_string += std::to_string(new_board_cards[i]);
		if (i < new_board_cards.size()-1) {
			new_board_card_string += ",";
		}
	}

	std::vector<std::string> new_card_strings(2);
	new_card_strings[0] = new_hand_string;
	new_card_strings[1] = new_board_card_string;

	return new_card_strings;
}

bool HandRanker::AcceptableNumberOfCards(int num_hand_cards, int num_board_cards) {
	return (num_hand_cards == m_num_hand_cards && num_board_cards == m_num_board_cards);
}

int HandRanker::ParseRanking(std::string hand_string, std::string board_card_string) {
	// Get location (is this the preflop or other)
	std::string file_location = 
		(m_num_board_cards > 0) ? board_card_string : RankingTableConfig::PREFLOP_FILE;

	// Load the file and read it until we get to the thing we want
	std::ifstream file(m_table_location + file_location);
	std::string line;
	int rank = -1;
	while (std::getline(file, line) && rank == -1) {
		int pos = line.find(hand_string);
		if (pos != std::string::npos) {

			// Split the string and parse the ranking value
			pos = line.find(" ");
			std::string value = line.substr(pos+1);
			rank = std::stoi(value);
		}
	}

	file.close();

	return rank;
}
