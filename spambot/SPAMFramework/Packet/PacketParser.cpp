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

Packet* PacketParser::Parse(std::string raw_input) {
	// Split up the incoming packet into pieces to parse
	std::vector<std::string> data = split(raw_input, ' ');

	if (data.size() > 0) {

		// Create a new packet based on input data
		std::string packet_type = data[0];

		if (packet_type == "NEWGAME") {

			int stack_size;
			std::istringstream(data[3]) >> stack_size;
			int big_blind;
			std::istringstream(data[4]) >> big_blind;
			int num_hands;
			std::istringstream(data[5]) >> num_hands;
			double time_bank;
			std::istringstream(data[6]) >> time_bank;

			return new NewGamePacket(stack_size, big_blind, num_hands, time_bank);

		} else if (packet_type == "NEWHAND") {

			int hand_id;
			std::istringstream(data[1]) >> hand_id;
			bool is_dealer = SPAMHelper::to_bool(data[2]);
			Card *card1 = new Card(data[3]);
			Card *card2 = new Card(data[4]);
			int my_bank;
			std::istringstream(data[5]) >> my_bank;
			int villain_bank;
			std::istringstream(data[6]) >> villain_bank;
			double time_left;
			std::istringstream(data[7]) >> time_left;

			return new NewHandPacket(hand_id, is_dealer, card1, card2,
				my_bank, villain_bank, time_left);


		} else if (packet_type == "GETACTION") {

			int pot_size;
			std::istringstream(data[1]) >> pot_size;
			int num_board_cards;
			std::istringstream(data[2]) >> num_board_cards;

			// position in the vector as we continually parse
			int idx = 3;	// Board cards start at 3rd index
			std::vector<Card*> board_cards(num_board_cards);
			for (int i=0; i < num_board_cards; i++) {
				board_cards[i] = new Card(data[i+idx]);
			}
			idx += num_board_cards;


			int num_last_actions;
			std::istringstream(data[idx]) >> num_last_actions;
			idx++;

			std::vector<std::string> last_actions(num_last_actions);
			for (int i=0; i < num_last_actions; i++) {
				last_actions[i] = data[i+idx];
			}
			idx += num_last_actions;

			int num_legal_actions;
			std::istringstream(data[idx]) >> num_legal_actions;
			idx++;

			std::vector<std::string> legal_actions(num_legal_actions);
			for (int i=0; i < num_legal_actions; i++) {
				legal_actions[i] = data[i+idx];
			}
			idx += num_legal_actions;

			double time_after;
			std::istringstream(data[idx]) >> time_after;

			return new GetActionPacket(pot_size, num_board_cards, board_cards,
				num_last_actions, last_actions, num_legal_actions, legal_actions,
				time_after);

		} else if (packet_type == "HANDOVER") {

			int my_stack_size;
			std::istringstream(data[1]) >> my_stack_size;
			int villain_stack_size;
			std::istringstream(data[2]) >> villain_stack_size;
			int number_board_cards;
			std::istringstream(data[3]) >> number_board_cards;

			int idx = 4; // Board cards start from 4th index

			std::vector<Card*> end_board_cards(number_board_cards);
			for (int i=0; i < number_board_cards; i++) {
				end_board_cards[i] = new Card(data[i+idx]);
			}
			idx += number_board_cards;

			int number_last_actions;
			std::istringstream(data[idx]) >> number_last_actions;
			idx++;

			std::vector<std::string> end_last_actions(number_last_actions);
			for (int i=0; i < number_last_actions; i++) {
				end_last_actions[i] = data[i+idx];
			}
			idx += number_last_actions;

			double end_time_bank;
			std::istringstream(data[idx]) >> end_time_bank;

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
