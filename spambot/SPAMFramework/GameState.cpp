#include "GameState.h"

	GameState::GameState::GameState() {
		m_self_history = new PlayerHistory();
		m_villain_history = new PlayerHistory();
	}

	int GameState::GetMyStackSize(){
		return m_stack_size;
	}

	void GameState::SetMyStackSize(int num_my_chips){
		m_stack_size = num_my_chips;
	}

	int GameState::GetVillainStackSize(){
		return m_villain_stack_size;
	}

	void GameState::SetVillainStackSize(int num_villian_chips){
		m_villain_stack_size = num_villian_chips;
	}

	int GameState::GetBigBlindAmount(){
		return m_big_blind_amount;
	}

	void GameState::SetBigBlindAmount(int big_blind_amount){
		m_big_blind_amount = big_blind_amount;
	}

	int GameState::GetNumHandsLeft(){
		return m_num_hands_left;
	}

	void GameState::SetNumHandsLeft(int num_hands_left){
		m_num_hands_left = num_hands_left;
	}

	double GameState::GetHandDuration(){
		return m_hand_duration;
	}

	void GameState::SetHandDuration(double hand_duration){
		m_hand_duration = hand_duration;
	}

	bool GameState::IsDealer(){
		return m_is_dealer;
	}

	void GameState::SetDealer(bool is_dealer){
		m_is_dealer = is_dealer;
	}

	Card* GameState::GetCard2(){
		return m_card2;
	}

	void GameState::SetCard2(Card *card2){
		m_card2 = card2;
	}

	Card* GameState::GetCard1(){
		return m_card1;
	}

	void GameState::SetCard1(Card *card1){
		m_card1 = card1;
	}

	int GameState::GetCurrentHandID(){
		return m_current_hand_id;
	}

	void GameState::SetCurrentHandID(int current_hand_id){
		m_current_hand_id = current_hand_id;
	}

	int GameState::GetNumStartingChips(){
		return m_num_starting_chips;
	}

	void GameState::SetNumStartingChips(int num_starting_chips){
		m_num_starting_chips = num_starting_chips;
	}

	double GameState::GetTimeLeft(){
		return m_time_left;
	}

	void GameState::SetTimeLeft(double time_left){
		m_time_left = time_left;
	}

	PlayerHistory* GameState::GetVillainHistory(){
		return m_villain_history;
	}

	void GameState::SetVillainHistory(PlayerHistory *villain_history){
		m_villain_history = villain_history;
	}

	PlayerHistory* GameState::GetSelfHistory(){
		return m_self_history;
	}

	void GameState::SetSelfHistory(PlayerHistory *self_history){
		m_self_history = self_history;
	}

	int GameState::GetCurrentStreet(){
		return m_current_street;
	}

	void GameState::SetCurrentStreet(int current_street){
		m_current_street = current_street;
	}

	int GameState::GetPotSize(){
		return m_pot_size;
	}

	void GameState::SetPotSize(int pot_size){
		m_pot_size = pot_size;
	}

	std::vector<std::string> GameState::GetLegalActions(){
		return m_legal_actions;
	}

	void GameState::SetLegalActions(std::vector<std::string> legal_actions){
		m_legal_actions = legal_actions;
	}

	std::vector<Card*> GameState::GetBoardCards(){
		return m_board_cards;
	}

	void GameState::SetBoardCards(std::vector<Card*> board_cards){
		m_board_cards = board_cards;
	}
