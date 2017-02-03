#include "RankingTableConfig.h"

std::string RankingTableConfig::FLOP_RANKINGS_LOCATION;
std::string RankingTableConfig::FLOP_DECISION_RULE_LOCATION;
std::string RankingTableConfig::TURN_RANKINGS_LOCATION;
std::string RankingTableConfig::TURN_DECISION_RULE_LOCATION;
std::string RankingTableConfig::RIVER_RANKINGS_LOCATION;
std::string RankingTableConfig::PREFLOP_RANKINGS_LOCATION;
std::string RankingTableConfig::PREFLOP_FILE;

void RankingTableConfig::Init() {
	FLOP_RANKINGS_LOCATION			= "./flop_rankings/";
	FLOP_DECISION_RULE_LOCATION		= "./flop_before_discard_decision_rule/";
	TURN_RANKINGS_LOCATION			= "./turn_rankings/";
	TURN_DECISION_RULE_LOCATION		= "./turn_before_discard_decision_rule/";
	RIVER_RANKINGS_LOCATION			= "./river_rankings/";
	PREFLOP_RANKINGS_LOCATION		= "./";
	PREFLOP_FILE					= "preflop";
}
