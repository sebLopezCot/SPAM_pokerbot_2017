#ifndef REQUEST_KEY_VALUES_PACKET_H
#define REQUEST_KEY_VALUES_PACKET_H 

#include <string>

#include "Packet.h"
#include "../GameState.h"

class RequestKeyValuesPacket : public Packet
{
public:

	// Implement abstract methods
	void UpdateGameState(GameState *gs);
	std::string GetType() { return "REQUEST_KEY_VALUES_PACKET"; }
};

#endif