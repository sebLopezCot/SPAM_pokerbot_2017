#ifndef PACKET_H
#define PACKET_H 

#include <string>

#include "../GameState.h"

class Packet
{
public:

 	// Abstract methods
	virtual void UpdateGameState(GameState *gs) = 0;
	virtual std::string GetType() = 0;
};

#endif