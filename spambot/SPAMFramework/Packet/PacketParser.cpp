#include "PacketParser.h"

std::vector<std::string> PacketParser::split(std::string str, char delimiter) {
	std::vector<std::string> internal;
	std::stringstream ss(str);
	std::string tok;

	while(std::getline(ss, tok, delimiter)) {
		internal.push_back(tok);
	}

	return internal;
}

bool PacketParser::to_bool(std::string s) {
	if (s == "true" || s == "True") {
		return true;
	} else if (s == "false" || s == "False") {
		return false;
	} else {
		return NULL;
	}
}

Packet* PacketParser::Parse(std::string raw_input) {
	// Split up the incoming packet into pieces to parse
	std::vector<std::string> data = split(raw_input, ' ');

	if (data.size() > 0) {

		// Create a new packet based on input data
		std::string packet_type = data[0];

		if (packet_type == "NEWGAME") {

			int stack_size = std::stoi(data[3]);
			int big_blind = std::stoi(data[4]);
			int num_hands = std::stoi(data[5]);
			double time_bank = std::stod(data[6]);

			return new NewGamePacket(stack_size, big_blind, num_hands, time_bank);

		} else if (packet_type == "NEWHAND") {

			int hand_id = std::stoi(data[1]);
			bool is_dealer = to_bool(data[2]);
			Card *card1 = new Card(data[3]);
			Card *card2 = new Card(data[4]);
			int my_bank  = std::stoi(data[5]);
			int villain_bank  = std::stoi(data[6]);
			double time_left = std::stod(data[7]);

			return new NewHandPacket(hand_id, is_dealer, card1, card2,
				my_bank, villain_bank, time_left);


		} else if (packet_type == "GETACTION") {

			int pot_size = std::stoi(data[1]);
			int num_board_cards = std::stoi(data[2]);

			// position in the vector as we continually parse
			int idx = 3;	// Board cards start at 3rd index
			std::vector<std::string> board_cards(num_board_cards);
			for (int i=0; i < num_board_cards; i++) {
				board_cards[i] = new Card(data[i+idx]);
				idx++;
			}

			int num_last_actions = std::stoi(data[idx]);
			idx++;

			std::vector<std::string> last_actions(num_last_actions);
			for (int i=0; i < num_last_actions; i++) {
				last_actions[i] = data[i+idx];
				idx++;
			}

			int num_legal_actions = std::stoi(data[idx]);
			idx++;

			std::vector<std::string> legal_actions(num_legal_actions);
			for (int i=0; i < num_legal_actions; i++) {
				legal_actions[i] = data[i+idx];
				idx++;
			}

			double time_after = std::stod(data[idx]);

			return new GetActionPacket(pot_size, num_board_cards, board_cards,
				num_last_actions, last_actions, num_legal_actions, legal_actions,
				time_after);

		} else if (packet_type == "HANDOVER") {

			int my_stack_size = std::stoi(data[1]);
			int villain_stack_size = std::stoi(data[2]);
			int number_board_cards = std::stoi(data[3]);

			int idx = 4; // Board cards start from 4th index

			std::vector<std::string> end_board_cards(number_board_cards);
			for (int i=0; i < number_board_cards; i++) {
				end_board_cards[i] = new Card(data[i+idx]);
				idx++;
			}

			int number_last_actions = std::stoi(data[idx]);
			idx++;

			std::vector<std::string> end_last_actions(number_last_actions);
			for (int i=0; i < number_last_actions; i++) {
				end_last_actions[i] = data[i+idx];
				idx++;
			}

			double end_time_bank = std::stod(data[idx]);

			return new HandOverPacket(my_stack_size, villain_stack_size,
				number_board_cards, end_board_cards, number_last_actions,
				end_last_actions, end_time_bank);

		} else if (packet_type == "REQUESTKEYVALUES") {

			return new RequestKeyValuesPacket();

		}

	} else {
		std::cout << "ERROR: EMPTY PACKET WAS SENT TO SPAMBOT." << std::endl;
	}

	// In the event we get this far
	return new EmptyPacket();
}
