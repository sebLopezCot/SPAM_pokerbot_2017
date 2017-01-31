#ifndef PACKET_PARSER_H
#define PACKET_PARSER_H 

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "../Util/SPAMHelper.h"
#include "Packet.h"
#include "NewGamePacket.h"
#include "NewHandPacket.h"
#include "GetActionPacket.h"
#include "HandOverPacket.h"
#include "RequestKeyValuesPacket.h"
#include "EmptyPacket.h"

class PacketParser
{
public:
	
	Packet* Parse(std::string raw_input);
};

#endif
