#include "RequestKeyValuesPacket.h"

void RequestKeyValuesPacket::UpdateGameState(GameState *gs) {
	gs->SetCurrentStreet(GameState::GAMEOVER);
}
