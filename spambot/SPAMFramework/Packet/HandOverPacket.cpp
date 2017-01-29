#include "HandOverPacket.h"

HandOverPacket::HandOverPacket(int my_stack_size, int villain_stack_size,
			int num_board_cards, std::vector<Card*> board_cards, int num_last_actions,
			std::vector<std::string> last_actions, double time_bank) {

	m_stack_size = my_stack_size;
	m_villain_stack_size = villain_stack_size;
	m_num_board_cards = num_board_cards;
	m_board_cards = board_cards;
	m_num_last_actions = num_last_actions;
	m_last_actions = last_actions;
	m_time_bank = time_bank;
}

void HandOverPacket::UpdateGameState(GameState *gs) {
	gs->SetMyStackSize(m_stack_size);
	gs->SetVillainStackSize(m_villain_stack_size);
	gs->SetCurrentStreet(GameState::HANDOVER);
	gs->SetBoardCards(m_board_cards);
	
	// TODO: Need to separate the two action histories
	gs->GetSelfHistory()->SetLastActions(m_last_actions);
	gs->GetVillainHistory()->SetLastActions(m_last_actions);
	
	gs->SetTimeLeft(m_time_bank);
}
