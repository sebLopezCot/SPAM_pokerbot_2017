#ifndef NEW_HAND_PACKET_H
#define NEW_HAND_PACKET_H 

#include <string>

#include "Packet.h"
#include "../GameState.h"
#include "../Card.h"

class NewHandPacket : public Packet
{
public:
	NewHandPacket(int hand_id, bool is_dealer, Card *card1, 
			Card *card2, int my_bank, int villain_bank, double time_bank);

	// Implement abstract methods
	void UpdateGameState(GameState *gs);
	std::string GetType() { return "NEW_HAND_PACKET"; }

private:
	int m_hand_id;
	bool m_is_dealer;
	Card *m_card1; 
	Card *m_card2;
	int m_my_bank;
	int m_villain_bank;
	double m_time_bank;
};

#endif