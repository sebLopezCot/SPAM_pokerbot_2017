#ifndef NEW_HAND_PACKET_H
#define NEW_HAND_PACKET_H 

#include "Packet.h"
#include "../GameState.h"

class NewHandPacket : public Packet
{
public:
	NewHandPacket(int stack_size, int big_blind, 
		int num_hands, double time_bank);

	// Implement abstract methods
	void UpdateGameState(GameState *gs);

private:
	int m_stack_size;
	int m_big_blind;
	int m_num_hands;
	double m_time_bank;
};

#endif