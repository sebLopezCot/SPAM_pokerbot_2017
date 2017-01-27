#include "NewGamePacket.h"

NewGamePacket::NewGamePacket (int stack_size, int big_blind, 
		int num_hands, double time_bank) {
	m_stack_size = stack_size;
	m_big_blind = big_blind;
	m_num_hands = num_hands;
	m_time_bank = time_bank;
}

void NewGamePacket::UpdateGameState(GameState *gs) {
	gs->SetNumStartingChips(m_stack_size);
	gs->SetMyStackSize(m_stack_size);
	gs->SetVillainStackSize(m_stack_size);
	gs->SetBigBlindAmount(m_big_blind);
	gs->SetNumHandsLeft(m_num_hands);
	gs->SetHandDuration(m_time_bank);
	gs->SetCurrentStreet(GameState::PREGAME);
}
