#ifndef GET_ACTION_PACKET_H
#define GET_ACTION_PACKET_H 

#include <string>
#include <vector>

#include "Packet.h"
#include "../GameState.h"
#include "../Card.h"

class GetActionPacket : public Packet
{
public:
	GetActionPacket(int pot_size, int num_board_cards,
		std::vector<Card*> board_cards, int num_last_actions,
		std::vector<std::string> last_actions, int num_legal_actions,
		std::vector<std::string> legal_actions, double time_bank);

	static int NumBoardCardsToStreet(int num_cards);

	// Implement abstract methods
	void UpdateGameState(GameState *gs);

private:
	int m_pot_size;
	int m_num_board_cards; 
	std::vector<Card*> m_board_cards;
	int m_num_last_actions; 
	std::vector<std::string> m_last_actions;
	int m_num_legal_actions;
	std::vector<std::string> m_legal_actions;
	double time_bank;
};

#endif