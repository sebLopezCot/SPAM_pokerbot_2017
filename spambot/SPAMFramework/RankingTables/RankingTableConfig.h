#ifndef RANKING_TABLE_CONFIG_H
#define RANKING_TABLE_CONFIG_H 

#include <string>

class RankingTableConfig
{
public:

	static const std::string FLOP_RANKINGS_LOCATION			= "../ranking_tables/flop_rankings/";
	static const std::string FLOP_DECISION_RULE_LOCATION	= "../ranking_tables/flop_before_discard_decision_rule/";
	static const std::string TURN_RANKINGS_LOCATION			= "../ranking_tables/turn_rankings/";
	static const std::string TURN_DECISION_RULE_LOCATION	= "../ranking_tables/turn_before_discard_decision_rule/";
	static const std::string RIVER_RANKINGS_LOCATION		= "../ranking_tables/river_rankings/";
	static const std::string PREFLOP_RANKINGS_LOCATION		= "../ranking_tables/";
	static const std::string PREFLOP_FILE					= "preflop";

};

#endif