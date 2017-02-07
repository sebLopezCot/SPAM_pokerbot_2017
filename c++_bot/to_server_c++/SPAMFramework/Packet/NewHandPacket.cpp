#include "NewHandPacket.h"
#include <iostream>

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
	// std::cout << "NEW HAND: " << m_hand_id << std::endl;
	gs->SetCurrentHandID(m_hand_id);
	gs->GetSelfHistory()->SetDealer(m_is_dealer);
	gs->GetVillainHistory()->SetDealer(!m_is_dealer);
	gs->GetSelfHistory()->SetCard1(m_card1);
	gs->GetSelfHistory()->SetCard2(m_card2);
	gs->GetSelfHistory()->SetBankRoll(m_my_bank);
	gs->GetVillainHistory()->SetBankRoll(m_villain_bank);
	gs->GetSelfHistory()->SetStackSize(gs->GetNumStartingChips());
	gs->GetVillainHistory()->SetStackSize(gs->GetNumStartingChips());
	gs->SetTimeLeft(m_time_bank);
	gs->SetCurrentStreet(GameState::PREFLOP);
	gs->GetSelfHistory()->SetLastStreet(GameState::PREFLOP);
	gs->GetVillainHistory()->SetLastStreet(GameState::PREFLOP);
	gs->GetSelfHistory()->ResetForNewStreet(GameState::PREFLOP);
	gs->GetVillainHistory()->ResetForNewStreet(GameState::PREFLOP);
}
