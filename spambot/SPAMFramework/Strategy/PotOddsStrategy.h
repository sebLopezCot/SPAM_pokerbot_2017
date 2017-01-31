/*
 * PotOddsStrategy.h
 *
 *  Created on: Jan 29, 2017
 *      Author: root
 */

#ifndef SPAMFRAMEWORK_STRATEGY_POTODDSSTRATEGY_H_
#define SPAMFRAMEWORK_STRATEGY_POTODDSSTRATEGY_H_

#include <string>
#include <vector>

#include "Strategy.h"
#include "../Card.h"
#include "../GameState.h"
#include "../Util/SPAMHelper.h"
#include "../Util/Timer.h"
#include "../RankingTables/DiscardDecisionRuleGivenFlop.h"
#include "../RankingTables/DiscardDecisionRuleGivenTurn.h"
#include "../RankingTables/HandRankerGivenFlop.h"
#include "../RankingTables/HandRankerGivenPreFlop.h"
#include "../RankingTables/HandRankerGivenRiver.h"
#include "../RankingTables/HandRankerGivenTurn.h"

class PotOddsStrategy : public Strategy {
public:
	PotOddsStrategy();

	std::string GetAction(GameState *gs);

	int GeneralStrategy(int stage, double winRate, int amount, int pot);

	int Raise(int amount, int possibleRaise);

	int PreflopStrategy(double winRate, int amount, int pot);
	int FlopStrategy(double winRate, int amount, int pot);
	int TurnStrategy(double winRate, int amount, int pot);
	int RiverStrategy(double winRate, int amount, int pot);

private:
	DiscardDecisionRuleGivenFlop *flopDR;
	DiscardDecisionRuleGivenTurn *turnDR;

	HandRankerGivenPreFlop *preflopRanking;
	HandRankerGivenFlop *flopRanking;
	HandRankerGivenTurn *turnRanking;
	HandRankerGivenRiver *riverRanking;

	Timer *timer;
};

#endif /* SPAMFRAMEWORK_STRATEGY_POTODDSSTRATEGY_H_ */
