#include "GetActionPacket.h"

GetActionPacket::GetActionPacket(int pot_size, int num_board_cards,
		std::vector<Card*> board_cards, int num_last_actions,
		std::vector<std::string> last_actions, int num_legal_actions,
		std::vector<std::string> legal_actions, double time_bank) {
	m_pot_size = pot_size;
	m_num_board_cards = num_board_cards;
	m_board_cards = board_cards;
	m_num_last_actions = num_last_actions;
	m_last_actions = last_actions;
	m_num_legal_actions = num_legal_actions;
	m_legal_actions = legal_actions;
	m_time_bank = time_bank;
}

int GetActionPacket::NumBoardCardsToStreet(int num_cards) {
	switch (num_cards) {
	case 0:
		return GameState::PREFLOP;
	case 3:
		return GameState::FLOP;
	case 4:
		return GameState::TURN;
	case 5:
		return GameState::RIVER;
	}

	return GameState::GAMEOVER;
}

void GetActionPacket::UpdateGameState(GameState *gs) {
	gs->SetPotSize(m_pot_size);
	gs->SetCurrentStreet(NumBoardCardsToStreet(m_num_board_cards));
	gs->SetBoardCards(m_board_cards);
	
	// TODO: Need to separate the two action histories
	gs->GetSelfHistory()->SetLastActions(m_last_actions);
	gs->GetVillainHistory()->SetLastActions(m_last_actions);
	
	gs->SetLegalActions(m_legal_actions);
	
	gs->SetTimeLeft(m_time_bank);
}
