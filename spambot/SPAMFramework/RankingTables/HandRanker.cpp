#include "HandRanker.h"

HandRanker::HandRanker(int num_board_cards, std::string table_location, int ranker_type) {
	m_num_hand_cards = 2;
	m_num_board_cards = num_board_cards;
	m_table_location = table_location;
	m_ranker_type = ranker_type;
}

double HandRanker::GetValue(std::vector<Card*> hand, std::vector<Card*> board_cards) {
	double rank = -1;

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

			// If we have a winnings ranker, normalize
			if (m_ranker_type == HandRanker::WINNING_RATE) {
				rank = (1080.0 - (double) rank) / 1080.0;
			}

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

	// Sort input arrays into increasing order
	std::sort(hand_as_numbers.begin(), hand_as_numbers.end());
	std::sort(board_cards_as_numbers.begin(), board_cards_as_numbers.end());

	// Suit array
	std::vector<std::vector<int> > num_of_each_suit(4);

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
	std::sort(num_of_each_suit.begin(), num_of_each_suit.end(), HandRanker::Compare);
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
		new_hand_string += SPAMHelper::to_string(new_hand_cards[i]);
		if (i < new_hand_cards.size()-1) {
			new_hand_string += ",";
		}
	}

	std::string new_board_card_string = "";
	for (int i=0; i < new_board_cards.size(); i++) {
		new_board_card_string += SPAMHelper::to_string(new_board_cards[i]);
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
	std::string fname = m_table_location + file_location;
	std::ifstream file(fname.c_str());
	std::string line;

	int rank = -1;
	while (std::getline(file, line) && rank == -1) {
		int pos = line.find(hand_string);
		if (pos != std::string::npos) {

			// Split the string and parse the ranking value
			pos = line.find(" ");
			std::string value_plus_newline = line.substr(pos+1); // The last char is a newline
			std::string value = SPAMHelper::split(value_plus_newline, '\r')[0];
			std::istringstream(value) >> rank;
		}
	}

	file.close();

	return rank;
}
