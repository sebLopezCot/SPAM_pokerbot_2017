#include "HandOverPacket.h"
#include <iostream>

HandOverPacket::HandOverPacket(int my_stack_size, int villain_stack_size,
			int num_board_cards, std::vector<Card*> board_cards, int num_last_actions,
			std::vector<std::string> last_actions, double time_bank) {

	m_my_bank = my_stack_size;
	m_villain_bank = villain_stack_size;
	m_num_board_cards = num_board_cards;
	m_board_cards = board_cards;
	m_num_last_actions = num_last_actions;
	m_last_actions = last_actions;
	m_time_bank = time_bank;
}

void HandOverPacket::UpdateGameState(GameState *gs) {
	gs->GetSelfHistory()->SetBankRoll(m_my_bank);
	gs->GetVillainHistory()->SetBankRoll(m_villain_bank);
	gs->SetCurrentStreet(GameState::HANDOVER);
	gs->SetBoardCards(m_board_cards);
	
	gs->GetSelfHistory()->SetLastActions(m_last_actions);
	gs->GetVillainHistory()->SetLastActions(m_last_actions);

	gs->GetSelfHistory()->LookForWins();
	gs->GetVillainHistory()->LookForWins();

	gs->GetSelfHistory()->UpdateBetAmounts((gs->GetCurrentStreet() == GameState::PREFLOP));
	gs->GetVillainHistory()->UpdateBetAmounts((gs->GetCurrentStreet() == GameState::PREFLOP));

	gs->SetTimeLeft(m_time_bank);
}
