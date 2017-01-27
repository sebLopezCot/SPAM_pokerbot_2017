#ifndef PACKET_PARSER_H
#define PACKET_PARSER_H 

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

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

	static std::vector<std::string> split(std::string str, char delimiter);
	static bool to_bool(std::string s);
};

#endif