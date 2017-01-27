#include "RequestKeyValuesPacket.h"

RequestKeyValuesPacket::UpdateGameState(GameState *gs) {
	gs->SetCurrentStreet(GameState::GAMEOVER);
}
