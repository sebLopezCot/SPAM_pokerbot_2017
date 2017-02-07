#include "NewGamePacket.h"

NewGamePacket::NewGamePacket (std::string my_name, std::string villain_name, int stack_size, int big_blind,
		int num_hands, double time_bank) {
	m_stack_size = stack_size;
	m_big_blind = big_blind;
	m_num_hands = num_hands;
	m_time_bank = time_bank;
	m_my_name = my_name;
	m_villain_name = villain_name;
}

void NewGamePacket::UpdateGameState(GameState *gs) {
	gs->GetSelfHistory()->SetName(m_my_name);
	gs->GetVillainHistory()->SetName(m_villain_name);
	gs->SetNumStartingChips(m_stack_size);
	gs->GetSelfHistory()->SetBankRoll(0);
	gs->GetVillainHistory()->SetBankRoll(0);
	gs->SetBigBlindAmount(m_big_blind);
	gs->SetSmallBlindAmount(m_big_blind / 2);
	gs->GetSelfHistory()->SetBigBlindAmount(m_big_blind);
	gs->GetSelfHistory()->SetSmallBlindAmount(m_big_blind / 2);
	gs->GetVillainHistory()->SetBigBlindAmount(m_big_blind);
	gs->GetVillainHistory()->SetSmallBlindAmount(m_big_blind / 2);
	gs->SetNumHandsLeft(m_num_hands);
	gs->SetHandDuration(m_time_bank);
	gs->SetCurrentStreet(GameState::PREGAME);
}
