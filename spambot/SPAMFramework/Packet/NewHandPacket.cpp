#include "NewHandPacket.h"

NewHandPacket::NewHandPacket(int hand_id, bool is_dealer, Card *card1, 
			Card *card2, int my_bank, int villain_bank, double time_bank) {

	m_hand_id = hand_id;
	m_is_dealer = is_dealer;
	m_card1 = card1;
	m_card2 = card2;
	m_my_bank = my_bank;
	m_villain_bank = villain_bank;
	m_time_bank = time_bank;
}

void NewHandPacket::UpdateGameState(GameState *gs) {
	gs->SetCurrentHandID(m_hand_id);
	gs->SetDealer(m_is_dealer);
	gs->SetCard1(m_card1);
	gs->SetCard2(m_card2);
	gs->SetMyStackSize(gs->GetNumStartingChips() + m_my_bank);
	gs->SetVillainStackSize(gs->GetNumStartingChips() + m_villain_bank);
	gs->SetTimeLeft(m_time_bank);
	gs->SetCurrentStreet(GameState::PREFLOP);
}
