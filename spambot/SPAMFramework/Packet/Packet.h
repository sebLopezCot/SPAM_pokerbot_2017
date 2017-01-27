#ifndef PACKET_H
#define PACKET_H 

#include "../GameState.h"

class Packet
{
public:

 	// Abstract methods
	virtual void UpdateGameState(GameState *gs) = 0;
};

#endif