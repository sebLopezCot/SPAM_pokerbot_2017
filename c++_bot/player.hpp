#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include <boost/asio.hpp>

#include "SPAMFramework/GameState.h"
#include "SPAMFramework/Packet/PacketParser.h"
#include "SPAMFramework/Packet/Packet.h"
#include "SPAMFramework/Packet/GetActionPacket.h"
#include "SPAMFramework/Packet/RequestKeyValuesPacket.h"
#include "SPAMFramework/Packet/HandOverPacket.h"
//#include "SPAMFramework/Strategy/CheckFoldStrategy.h"
#include "SPAMFramework/Strategy/PotOddsStrategy.h"
#include "SPAMFramework/RankingTables/RankingTableConfig.h"

using boost::asio::ip::tcp;

class Player {
 public:
  Player();
  void run(tcp::iostream &stream);
};

#endif  // __PLAYER_HPP__
