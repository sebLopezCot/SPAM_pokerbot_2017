#ifndef GAME_STATE_H
#define GAME_STATE_H 

#include <string>
#include <vector>

#include "Card.h"
#include "PlayerHistory.h"

class GameState
{
public:
	GameState();

	// Street enum values
	static const int PREGAME = 0;
	static const int PREFLOP = 1;
	static const int FLOP = 2;
	static const int TURN = 3;
	static const int RIVER = 4;
	static const int HANDOVER = 5;
	static const int GAMEOVER = 6;
	
	// ----- GETTERS AND SETTERS --------------------------------------------

	int GetSmallBlindAmount();

	void SetSmallBlindAmount(int small_blind_amount);

	int GetBigBlindAmount();

	void SetBigBlindAmount(int big_blind_amount);

	int GetNumHandsLeft();

	void SetNumHandsLeft(int num_hands_left);

	double GetHandDuration();

	void SetHandDuration(double hand_duration);

	int GetCurrentHandID();

	void SetCurrentHandID(int current_hand_id);

	int GetNumStartingChips();

	void SetNumStartingChips(int num_starting_chips);

	double GetTimeLeft();

	void SetTimeLeft(double time_left);

	PlayerHistory* GetVillainHistory();

	void SetVillainHistory(PlayerHistory *villain_history);

	PlayerHistory* GetSelfHistory();

	void SetSelfHistory(PlayerHistory *self_history);

	int GetCurrentStreet();

	void SetCurrentStreet(int current_street);

	int GetPotSize();

	void SetPotSize(int pot_size);

	std::vector<std::string> GetLegalActions();

	void SetLegalActions(std::vector<std::string> legal_actions);

	std::vector<Card*> GetBoardCards();

	void SetBoardCards(std::vector<Card*> board_cards);

private:
	// Attributes
	int m_pot_size;					// number of chips in the pot
	std::vector<Card*> m_board_cards; 	// cards on the table
	std::vector<std::string> m_legal_actions; // legal actions for this street
	int m_num_starting_chips;	// number of chips
	int m_big_blind_amount; 	// number of chips for a big blind
	int m_small_blind_amount;
	int m_num_hands_left;		// number of hands left
	int m_current_hand_id; 		// ID of the current hand
	double m_hand_duration;	// duration allowed for each match
	double m_time_left;		// time left before match ends
	int m_current_street;		// the current street of the game

	PlayerHistory *m_self_history;	  // stats on our moves
	PlayerHistory *m_villain_history; // stats on previous villain moves
};

#endif		
