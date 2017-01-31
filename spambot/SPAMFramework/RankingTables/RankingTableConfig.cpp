#include "RankingTableConfig.h"

std::string RankingTableConfig::FLOP_RANKINGS_LOCATION;
std::string RankingTableConfig::FLOP_DECISION_RULE_LOCATION;
std::string RankingTableConfig::TURN_RANKINGS_LOCATION;
std::string RankingTableConfig::TURN_DECISION_RULE_LOCATION;
std::string RankingTableConfig::RIVER_RANKINGS_LOCATION;
std::string RankingTableConfig::PREFLOP_RANKINGS_LOCATION;
std::string RankingTableConfig::PREFLOP_FILE;

void RankingTableConfig::Init() {
	FLOP_RANKINGS_LOCATION			= "/home/sebastian/SPAM_pokerbot_2017/ranking_tables/flop_rankings/";
	FLOP_DECISION_RULE_LOCATION		= "/home/sebastian/SPAM_pokerbot_2017/ranking_tables/flop_before_discard_decision_rule/";
	TURN_RANKINGS_LOCATION			= "/home/sebastian/SPAM_pokerbot_2017/ranking_tables/turn_rankings/";
	TURN_DECISION_RULE_LOCATION		= "/home/sebastian/SPAM_pokerbot_2017/ranking_tables/turn_before_discard_decision_rule/";
	RIVER_RANKINGS_LOCATION			= "/home/sebastian/SPAM_pokerbot_2017/ranking_tables/river_rankings/";
	PREFLOP_RANKINGS_LOCATION		= "/home/sebastian/SPAM_pokerbot_2017/ranking_tables/";
	PREFLOP_FILE					= "preflop";
}
