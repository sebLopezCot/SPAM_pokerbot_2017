#include "PlayerHistory.h"

PlayerHistory::PlayerHistory(){
}

std::vector<std::string> PlayerHistory::GetLastActions(){
	return m_last_actions;
}

void PlayerHistory::SetLastActions(std::vector<std::string> last_actions) {
	m_last_actions = last_actions;
}
