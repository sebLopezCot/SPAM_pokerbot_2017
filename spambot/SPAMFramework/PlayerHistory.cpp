#include "PlayerHistory.h"

PlayerHistory::PlayerHistory(){
	time_sum = 0;
	num_steps = 0;
	num_wins = 0;
}

void PlayerHistory::LookForWins() {
	for (int i=0; i < GetLastActions().size(); i++) {
		std::string action = GetLastActions()[i];
		std::vector<std::string> parts = SPAMHelper::split(action, ':');
		if (parts[0] == "WIN" && parts.size() == 3 && parts[2] == GetName()) {
			num_wins++;
		}
	}
}

int PlayerHistory::GetNumWins() {
	return num_wins;
}

void PlayerHistory::LookForDiscards() {
	for (int i=0; i < GetLastActions().size(); i++) {
		std::string action = GetLastActions()[i];
		std::vector<std::string> parts = SPAMHelper::split(action, ':');
		if (parts[0] == "DISCARD" && parts.size() == 4 && parts[3] == GetName()) {
			if (parts[1] == GetCard1()->ToString()) {
				SetCard1(new Card(parts[2]));
			} else if (parts[1] == GetCard2()->ToString()) {
				SetCard2(new Card(parts[2]));
			}
		}
	}
}

Card* PlayerHistory::GetCard2(){
	return m_card2;
}

void PlayerHistory::SetCard2(Card *card2){
	m_card2 = card2;
}

Card* PlayerHistory::GetCard1(){
	return m_card1;
}

void PlayerHistory::SetCard1(Card *card1){
	m_card1 = card1;
}

std::vector<std::string> PlayerHistory::GetLastActions(){
	return m_last_actions;
}

void PlayerHistory::SetLastActions(std::vector<std::string> last_actions) {
	m_last_actions = last_actions;
}

int PlayerHistory::GetBankRoll() {
	return m_bank_roll;
}

void PlayerHistory::SetBankRoll(int bank_roll) {
	m_bank_roll = bank_roll;
}

int PlayerHistory::GetStackSize() {
	return m_stack_size;
}

void PlayerHistory::SetStackSize(int stack_size) {
	m_stack_size = stack_size;
}

std::string PlayerHistory::GetName() {
	return m_name;
}

void PlayerHistory::SetName(std::string name) {
	m_name = name;
}

bool PlayerHistory::IsDealer() {
	return m_is_dealer;
}

void PlayerHistory::SetDealer(bool is_dealer) {
	m_is_dealer = is_dealer;
}

void PlayerHistory::ResetForNewStreet(int new_street) {
	SetNumChipsThisStreet(0);
	SetLastRaiseToAmount(0);
	SetLastRaiseByAmount(0);
	SetLastStreet(new_street);
	// std::cout << "///// NEW STREET /////" << std::endl;
}

int PlayerHistory::GetNumChipsThisStreet() {
	return m_num_my_chips_this_street;
}

void PlayerHistory::SetNumChipsThisStreet(int num_chips) {
	m_num_my_chips_this_street = num_chips;
}

int PlayerHistory::GetLastRaiseToAmount() {
	return m_my_last_raise_to;
}

void PlayerHistory::AddToNumChipsThisStreet(int num_chips) {
	SetNumChipsThisStreet(GetNumChipsThisStreet() + num_chips);
}

void PlayerHistory::SetLastRaiseToAmount(int raise_to_amount){
	m_my_last_raise_to = raise_to_amount;
}

int PlayerHistory::GetLastRaiseByAmount() {
	return m_my_last_raise_by;
}

void PlayerHistory::SetLastRaiseByAmount(int raise_by_amount) {
	m_my_last_raise_by = raise_by_amount;
}

int PlayerHistory::GetSmallBlindAmount() {
	return m_small_blind_amount;
}

void PlayerHistory::SetSmallBlindAmount(int small_blind_amount){
	m_small_blind_amount = small_blind_amount;
}

int PlayerHistory::GetBigBlindAmount(){
	return m_big_blind_amount;
}

void PlayerHistory::SetBigBlindAmount(int big_blind_amount){
	m_big_blind_amount = big_blind_amount;
}

PlayerHistory* PlayerHistory::GetEnemy() {
	return m_enemy;
}

void PlayerHistory::SetEnemy(PlayerHistory *enemy) {
	m_enemy = enemy;
}

int PlayerHistory::GetLastStreet() {
	return m_last_street;
}

void PlayerHistory::SetLastStreet(int last_street) {
	m_last_street = last_street;
}

void PlayerHistory::UpdateBetAmounts() {

	// At some point, it would be nice to have a dedicated action parser, but for now
	// we'll parse the last actions in here and figure out how that has affected the
	// betting amounts

	for (int i=0; i < GetLastActions().size(); i++) {
		std::string action = GetLastActions()[i];
		std::vector<std::string> parts = SPAMHelper::split(action, ':');
		std::string type = parts[0];

		if (type == "BET") {

			std::string actor = parts[2];
			if (actor == GetName()) {
				int bet_to;
				std::istringstream(parts[1]) >> bet_to;

				SetNumChipsThisStreet(bet_to);
				SetLastRaiseToAmount(bet_to);
				SetLastRaiseByAmount(bet_to);
			}

		} else if (type == "CALL") {

			std::string actor = parts[1];
			if (actor == GetName()) {
				SetNumChipsThisStreet(GetEnemy()->GetNumChipsThisStreet());
			}

		} else if (type == "CHECK") {

			std::string actor = parts[1];
			if (actor == GetName()) {
				SetLastRaiseToAmount(0);
			}

		} else if (type == "POST") {

			// Posting a blind amount ( Dealer posts the small blind according to the docs)
			std::string actor = parts[2];
			if (actor == GetName()) {
				SetNumChipsThisStreet(IsDealer() ? GetSmallBlindAmount() : GetBigBlindAmount() );
			}

		} else if (type == "FOLD") {

			// Nothing really to update here

		} else if (type == "RAISE") {

			std::string actor = parts[2];
			if(actor == GetName()) {
				int raise_to;
				std::istringstream(parts[1]) >> raise_to;

				int raise_by = raise_to - GetEnemy()->GetLastRaiseToAmount();

				SetNumChipsThisStreet(raise_to);
				SetLastRaiseToAmount(raise_to);
				SetLastRaiseByAmount(raise_by);
			}
		}
	}

	// std::cout << "[" << GetName() << "] -> BET AMOUNTS AFTER UPDATE:" << std::endl
	// 			<< "NUM CHIPS THIS STREET: " << GetNumChipsThisStreet() << std::endl
	// 			<< "LAST RAISE TO AMOUNT:" << GetLastRaiseToAmount() << std::endl
	// 			<< "LAST RAISE BY AMOUNT:" << GetLastRaiseByAmount() << std::endl << std::endl;
}
