#ifndef EMPTY_PACKET_H
#define EMPTY_PACKET_H 

#include <string>

#include "Packet.h"
#include "../GameState.h"

class EmptyPacket : public Packet
{
public:
 	// Implement abstract method
 	void UpdateGameState(GameState *gs) {}
 	std::string GetType() { return "EMPTY_PACKET"; }
};

#endif