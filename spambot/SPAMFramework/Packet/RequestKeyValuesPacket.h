#ifndef REQUEST_KEY_VALUES_PACKET_H
#define REQUEST_KEY_VALUES_PACKET_H 

#include "Packet.h"
#include "../GameState.h"

class RequestKeyValuesPacket : public Packet
{
public:

	// Implement abstract methods
	void UpdateGameState(GameState *gs);
};

#endif