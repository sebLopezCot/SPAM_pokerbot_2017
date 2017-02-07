#include "CheckFoldStrategy.h"

CheckFoldStrategy::CheckFoldStrategy() : Strategy() {

}

std::string CheckFoldStrategy::GetAction(GameState *gs) {
	switch(gs->GetCurrentStreet()) {
	case GameState::GAMEOVER:
		// At the end, engine will allow bot to send key/value pairs to store.
		// FINISH indicates no more to store.
		return "FINISH";

	default:
		return "CHECK";
	}
}
