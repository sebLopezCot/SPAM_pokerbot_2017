#ifndef PLAYER_HISTORY_H
#define PLAYER_HISTORY_H 

#include <string>
#include <vector>
#include <sstream>
#include <iostream>

#include "Util/SPAMHelper.h"
#include "Card.h"

class PlayerHistory
{
public:
	PlayerHistory();

	void LookForWins();

	int GetNumWins();

	void LookForDiscards();

	Card* GetCard2();

	void SetCard2(Card *card2);

	Card* GetCard1();

	void SetCard1(Card *card1);

	std::vector<std::string> GetLastActions();

	void SetLastActions(std::vector<std::string> last_actions);

	int GetBankRoll();

	void SetBankRoll(int bank_roll);

	int GetStackSize();

	void SetStackSize(int stack_size);

	std::string GetName();

	void SetName(std::string name);

	bool IsDealer();

	void SetDealer(bool is_dealer);

	void ResetForNewStreet(int new_street);

	int GetNumChipsThisStreet();

	void SetNumChipsThisStreet(int num_chips);

	void AddToNumChipsThisStreet(int num_chips);

	int GetLastRaiseToAmount();

	void SetLastRaiseToAmount(int raise_to_amount);

	int GetLastRaiseByAmount();

	void SetLastRaiseByAmount(int raise_by_amount);

	int GetSmallBlindAmount();

	void SetSmallBlindAmount(int small_blind_amount);

	int GetBigBlindAmount();

	void SetBigBlindAmount(int big_blind_amount);

	PlayerHistory* GetEnemy();

	void SetEnemy(PlayerHistory *enemy);

	int GetLastStreet();

	void SetLastStreet(int last_street);

	void UpdateBetAmounts(bool is_preflop);

	void IncrementActionsThisStreet();

	int GetNumActionsThisStreet();

	double time_sum;
	int num_steps;

private:
	std::vector<std::string> m_last_actions;
	int m_stack_size;
	int m_bank_roll;
	int m_num_my_chips_this_street;
	int m_my_last_raise_to;
	int m_my_last_raise_by;
	int m_last_street;
	std::string m_name;
	bool m_is_dealer;
	int m_big_blind_amount; 	// number of chips for a big blind
	int m_small_blind_amount;
	PlayerHistory *m_enemy;
	Card *m_card1, *m_card2;		// the two cards the player has
	int num_wins;
	int m_actions_this_street;
};

#endif
