#ifndef EMPTY_PACKET_H
#define EMPTY_PACKET_H 

#include "Packet.h"
#include "../GameState.h"

class EmptyPacket : public Packet
{
public:
 	// Implement abstract method
 	void UpdateGameState(GameState *gs) {}
};

#endif