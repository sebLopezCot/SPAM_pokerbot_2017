#include "HandOverPacket.h"

HandOverPacket::HandOverPacket(int myStackSize, int villainStackSize,
			int numBoardCards, std::vector<Card*> boardCards, int numLastActions,
			std::vector<std::string> lastActions, double timeBank) {

	m_my_stack_size = my_stack_size;
	m_villain_stack_size = villain_stack_size;
	m_num_board_cards = num_board_cards;
	m_board_cards = board_cards;
	m_num_last_actions = num_last_actions;
	m_last_actions = last_actions;
	m_time_bank = time_bank;
}

void HandOverPacket::UpdateGameState(GameState *gs) {
	gs->SetMyStackSize(m_my_stack_size);
	gs->SetVillainStackSize(m_villain_stack_size);
	gs->SetCurrentStreet(GameState::HANDOVER);
	gs->SetBoardCards(m_board_cards);
	
	// TODO: Need to separate the two action histories
	gs->GetSelfHistory()->SetLastActions(m_last_actions);
	gs->GetVillainHistory()->SetLastActions(m_last_actions);
	
	gs->SetTimeLeft(m_time_bank);
}
