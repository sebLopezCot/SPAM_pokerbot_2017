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
	HandOverPacket(int myStackSize, int villainStackSize,
			int numBoardCards, std::vector<Card*> boardCards, int numLastActions,
			std::vector<std::string> lastActions, double timeBank);

	// Implement abstract methods
	void UpdateGameState(GameState *gs);

private:
	int m_my_stack_size;
	int m_villain_stack_size;
	int m_num_board_cards;
	std::vector<Card*> m_board_cards;
	int m_num_last_actions;
	std::vector<std::string> m_last_actions;
	double m_time_bank;
};

#endif