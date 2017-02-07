#ifndef RANKING_TABLE_CONFIG_H
#define RANKING_TABLE_CONFIG_H 

#include <string>

class RankingTableConfig
{
public:

	static std::string FLOP_RANKINGS_LOCATION;
	static std::string FLOP_DECISION_RULE_LOCATION;
	static std::string TURN_RANKINGS_LOCATION;		
	static std::string TURN_DECISION_RULE_LOCATION;
	static std::string RIVER_RANKINGS_LOCATION;	
	static std::string PREFLOP_RANKINGS_LOCATION;	
	static std::string PREFLOP_FILE;	

	static void Init();

};

#endif