#ifndef NEW_GAME_PACKET_H
#define NEW_GAME_PACKET_H 

#include <string>

#include "Packet.h"
#include "../GameState.h"

class NewGamePacket : public Packet
{
public:
	NewGamePacket(int stack_size, int big_blind, 
		int num_hands, double time_bank);
	
	// Implement abstract methods
	void UpdateGameState(GameState *gs);
	std::string GetType() { return "NEW_GAME_PACKET"; }

private:
	int m_stack_size;
	int m_big_blind;
	int m_num_hands;
	double m_time_bank;
};

#endif