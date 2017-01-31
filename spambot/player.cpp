#include <iostream>
#include "player.hpp"

#define DEBUG 1

Player::Player() {
}

void Player::run(tcp::iostream &stream) {

  // Init SPAM engine
  RankingTableConfig::Init();
  GameState *gs = new GameState();
  PacketParser *parser = new PacketParser();
//  CheckFoldStrategy *strategy = new CheckFoldStrategy();
  PotOddsStrategy *strategy = new PotOddsStrategy();

  std::string line;
  while (std::getline(stream, line)) {
    // For now, just print out whatever date is read in.
    std::cout << line << "\n";

    // Parse the packet, update the game state, and perform an action if needed
    Packet *packet = parser->Parse(line);
    packet->UpdateGameState(gs);

    // If we get an action request or the game is about to finish
    if (packet->GetType() == "GET_ACTION_PACKET" 
      || packet->GetType() == "REQUEST_KEY_VALUES_PACKET") {

      std::string action = strategy->GetAction(gs);

      if (DEBUG) {
        std::cout << "MY ACTION: " << action << std::endl;
      }

      // Send action to game engine
      stream << action + "\n";

    } else if (packet->GetType() == "HAND_OVER_PACKET") {

      if (DEBUG) {
        std::cout << "----------------------------------------------------------------------------" << std::endl;
      }

    }

    if (DEBUG) {
      std::cout << std::endl;
    }

  }

  std::cout << "Gameover, engine disconnected.\n";
}
