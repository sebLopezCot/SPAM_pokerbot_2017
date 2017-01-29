#ifndef HAND_OVER_PACKET_H
#define HAND_OVER_PACKET_H 

#include <string>
#include <vector>

#include "Packet.h"
#include "../GameState.h"
#include "../Card.h"

class HandOverPacket : public Packet
{
public:
	HandOverPacket(int my_stack_size, int villain_stack_size,
			int num_board_cards, std::vector<Card*> board_cards, int num_last_actions,
			std::vector<std::string> last_actions, double time_bank);

	// Implement abstract methods
	void UpdateGameState(GameState *gs);
	std::string GetType() { return "HAND_OVER_PACKET"; }

private:
	int m_stack_size;
	int m_villain_stack_size;
	int m_num_board_cards;
	std::vector<Card*> m_board_cards;
	int m_num_last_actions;
	std::vector<std::string> m_last_actions;
	double m_time_bank;
};

#endif