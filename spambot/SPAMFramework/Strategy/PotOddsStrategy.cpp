/*
 * PotOddsStrategy.cpp
 *
 *  Created on: Jan 29, 2017
 *      Author: root
 */

#include "PotOddsStrategy.h"
#include <iostream>

PotOddsStrategy::PotOddsStrategy() : Strategy(true) {
	flopDR = new DiscardDecisionRuleGivenFlop();
	turnDR = new DiscardDecisionRuleGivenTurn();

	preflopRanking = new HandRankerGivenPreFlop();
	flopRanking = new HandRankerGivenFlop();
	turnRanking = new HandRankerGivenTurn();
	riverRanking = new HandRankerGivenRiver();

	// timer = new Timer();
}

int PotOddsStrategy::GeneralStrategy(int stage, double winRate, int amount, int pot){
	switch(stage) {
	case GameState::PREFLOP:
		return PreflopStrategy(winRate, amount, pot);
	case GameState::FLOP:
		return FlopStrategy(winRate, amount, pot);
	case GameState::TURN:
		return TurnStrategy(winRate, amount, pot);
	case GameState::RIVER:
		return RiverStrategy(winRate, amount, pot);
	default:
		return -1;
	}
}

int PotOddsStrategy::Raise(int amount, int possibleRaise){
	if (amount > possibleRaise || possibleRaise < 2) {
		return amount;
	} else {
		return possibleRaise+amount;
	}
}

int PotOddsStrategy::PreflopStrategy(double winRate, int amount, int pot){
	if(winRate<0.55){
		if(winRate >= (amount*1.4)/(amount+pot)){
			return amount;
		}
		else{
			return 0;
		}
	}
	else if(0.55<=winRate && winRate<=0.7){
		if(SPAMHelper::rand() <= 0.25){
			return amount;
		}
		else{
			return Raise(amount, (int)(winRate-0.5)*10*pot);
		}
	}
	else if(0.7< winRate){
		return Raise(amount, (int)(2*pot));
	}

	return -1;
}

int PotOddsStrategy::FlopStrategy(double winRate, int amount, int pot){
	if(winRate<0.6){
		if(winRate>= 1.4*(amount*1.0)/(amount+pot)){
			return amount;
		}
		else{
			return 0;
		}
	}
	else if(0.6<=winRate && winRate<=0.7){
		if(amount > 3*pot){
			return 0;
		}
		else{
			return Raise(amount, (int)(winRate-0.5)*5*pot);
		}
	}

	else if(0.7< winRate && winRate<= 0.8){
		if(amount >4*pot){
			return 0;
		}
		else{
			return Raise(amount, (int)((1+(winRate-0.7)*12)*pot));
		}
	}
	else if(0.8< winRate && winRate<= 0.9){
		return Raise(amount, (int)((2.2+(winRate-0.8)*10)*pot));
	}
	else if(0.9< winRate){
		return Raise(amount, (int)((3.5*pot)));
	}

	return -1;
}

int PotOddsStrategy::TurnStrategy(double winRate, int amount, int pot) {
	if(winRate<0.62){
		if(winRate>= 1.5*(amount*1.0)/(amount+pot)){
			return amount;
		}
		else{
			return 0;
		}
	}
	else if(0.62<=winRate && winRate<=0.75){
		if(amount > pot*3){
			return 0;
		}
		else{
			return Raise(amount, (int)(((winRate-0.65)*10)*pot));
		}
	}

	else if(0.75< winRate&&winRate<= 0.8){
		if(amount > pot*5){
			return 0;
		}
		else{
			return Raise(amount, (int)((1+(winRate-0.7)*10)*pot));
		}
	}
	else if(0.8< winRate&&winRate<= 0.9){
		return Raise(amount, (int)((2+(winRate-0.8)*5)*pot));
	}
	else if(0.9< winRate){
		return Raise(amount, (int)((3*pot)));
	}

	return -1;
}

int PotOddsStrategy::RiverStrategy(double winRate, int amount, int pot) {
	if(winRate<0.65){
		if(winRate>= 1.5*(amount*1.0)/(amount+pot)){
			return amount;
		}
		else{
			return 0;
		}
	}
	else if(0.65<=winRate&&winRate<=0.7){
		if(amount < 2*pot){
			return amount;
		}
		else{
			return 0;
		}
	}

	else if(0.7< winRate&&winRate<= 0.8){
		if(amount > 3*pot){
			return 0;
		}
		else{
			return Raise(amount, (int)((0.2+(winRate-0.7)*10)*pot));
		}
	}
	else if(0.8< winRate&&winRate<= 0.9){
		if(amount >4*pot){
			return 0;
		}
		else{
			return Raise(amount, (int)((1.2+(winRate-0.8)*10)*pot));
		}
	}
	else if(0.9< winRate){
		return Raise(amount, (int)((4*pot)));
	}

	return -1;
}

std::string PotOddsStrategy::GetAction(GameState *gs) {

	if (gs->GetCurrentStreet() == GameState::GAMEOVER) {
		// std::cout << "AVG TIME PER FILE: " << gs->GetSelfHistory()->time_sum / (double) gs->GetSelfHistory()->num_steps << std::endl;
		// std::cout << "POT ODDS BANK ROLL: " << gs->GetSelfHistory()->GetBankRoll() << std::endl;
		// std::cout << "VILLAIN BANK ROLL: " << gs->GetVillainHistory()->GetBankRoll() << std::endl;
		// std::cout << "POT ODDS WINS: " << gs->GetSelfHistory()->GetNumWins() << std::endl;
		// std::cout << "VILLAIN WINS: " << gs->GetVillainHistory()->GetNumWins() << std::endl;
		return "FINISH";
	}

	std::vector<Card*> hand(2);
	hand[0] = (gs->GetSelfHistory()->GetCard1() != NULL) ? gs->GetSelfHistory()->GetCard1() : NULL;
	hand[1] = (gs->GetSelfHistory()->GetCard2() != NULL) ? gs->GetSelfHistory()->GetCard2() : NULL;

	std::vector<Card*> board_cards = gs->GetBoardCards();

	// Check if discard rule is needed for this action
	bool discard_rule_needed = false;
	for (int i=0; i < gs->GetLegalActions().size(); i++) {
		std::string legal_action = gs->GetLegalActions()[i];
		if (legal_action.find("DISCARD") != std::string::npos) {
			discard_rule_needed = true;
			break;
		}
	}

	if (discard_rule_needed) {
		// Load the discard decision rule
		int decision = -1;
		switch (gs->GetCurrentStreet()) {
		case GameState::FLOP:
			decision = (int) flopDR->GetValue(hand, board_cards);
			break;

		case GameState::TURN:
			decision = (int) turnDR->GetValue(hand, board_cards);
			break;
		}

		// Decide whether or not to discard (1 is smaller number, 2 is larger number)
		switch (decision) {
		case 1:
			// Discard smaller
			if (hand[0]->ToNumber() > hand[1]->ToNumber()) {
				return "DISCARD:" + hand[1]->ToString();
			} else if (hand[0]->ToNumber() < hand[1]->ToNumber()) {
				return "DISCARD:" + hand[0]->ToString();
			} else {
				return "CHECK";
			}

		case 2:
			// Discard larger
			if (hand[0]->ToNumber() < hand[1]->ToNumber()) {
				return "DISCARD:" + hand[1]->ToString();
			} else if (hand[0]->ToNumber() > hand[1]->ToNumber()) {
				return "DISCARD:" + hand[0]->ToString();
			} else {
				return "CHECK";
			}

		default:
			return "CHECK";
		}

	} else {
		// Perform our betting strategy
		double ranking = -1;

		// timer->Restart();

		// Parse winning rate
		switch(gs->GetCurrentStreet()) {
		case GameState::PREFLOP:
			ranking = preflopRanking->GetValue(hand, board_cards);
			break;

		case GameState::FLOP:
			ranking = flopRanking->GetValue(hand, board_cards);
			break;

		case GameState::TURN:
			ranking = turnRanking->GetValue(hand, board_cards);
			break;

		case GameState::RIVER:
			ranking = riverRanking->GetValue(hand, board_cards);
			break;
		}

		// double et = timer->GetElapsedTime();
		// gs->GetSelfHistory()->time_sum += et;
		// gs->GetSelfHistory()->num_steps += 1;
		// std::cout << "GET RANKING TIME: " << et << " seconds" << std::endl;

		if (ranking > -1) {

			// Adjust for preflop bug
			if (gs->GetCurrentStreet() == GameState::PREFLOP) {
				if (gs->GetSelfHistory()->IsDealer()) {
					gs->GetVillainHistory()->SetLastRaiseToAmount(gs->GetBigBlindAmount());
					gs->GetVillainHistory()->SetLastRaiseByAmount(gs->GetBigBlindAmount() - gs->GetSmallBlindAmount());
				} else {
					gs->GetVillainHistory()->SetLastRaiseToAmount(gs->GetSmallBlindAmount());
					gs->GetVillainHistory()->SetLastRaiseByAmount(-1.0 * (gs->GetBigBlindAmount() - gs->GetSmallBlindAmount()));
				}
			}

			// Pass to Pedro's strategy
			int raise_by = GeneralStrategy(gs->GetCurrentStreet(),
					ranking, gs->GetVillainHistory()->GetLastRaiseByAmount(), gs->GetPotSize());

			int raise_to = raise_by + gs->GetSelfHistory()->GetNumChipsThisStreet();

			// std::cout << "WIN RATE: " << ranking << std::endl;
			// std::cout << "LAST RAISE BY AMOUNT: " << gs->GetVillainHistory()->GetLastRaiseByAmount() << std::endl;
			// std::cout << "POT SIZE: " << gs->GetPotSize() << std::endl;
			// std::cout << "MY HAND: [" << gs->GetSelfHistory()->GetCard1()->ToString() << "," << gs->GetSelfHistory()->GetCard2()->ToString() << "]" << std::endl << std::endl;

			int max_bet = 0;
			bool can_bet = false;
			bool should_call_and_not_check = false;
			for (int i=0; i < gs->GetLegalActions().size(); i++) {
				std::string action = gs->GetLegalActions()[i];

				if (action.find("BET") != std::string::npos || action.find("RAISE") != std::string::npos) {
					std::istringstream(SPAMHelper::split(action, ':')[2]) >> max_bet;
					can_bet = true;
					break;
				}
			}
			for (int i=0; i < gs->GetLegalActions().size(); i++) {
				std::string action = gs->GetLegalActions()[i];

				if (action.find("CALL") != std::string::npos) {
					should_call_and_not_check = true;
					break;
				}
			}

			// Limit to all in
			if (raise_to > max_bet) {
				raise_to = max_bet;
			}

			if (can_bet) {
				if (raise_to == gs->GetVillainHistory()->GetLastRaiseToAmount() && raise_to != 0) {
					return "CALL";
				} else if (gs->GetVillainHistory()->GetLastRaiseToAmount() == 0) {
					return "BET:" + SPAMHelper::to_string(raise_to);
				} else if (gs->GetVillainHistory()->GetLastRaiseToAmount() != 0) {
					return "RAISE:" + SPAMHelper::to_string(raise_to);
				}
			} else {
				return (should_call_and_not_check) ? "CALL" : "CHECK";
			}

		} else {
			return "CHECK";
		}
	}

	return "CHECK";
}

