#ifndef CHECK_FOLD_STRATEGY_H
#define CHECK_FOLD_STRATEGY_H 

#include <string>

#include "Strategy.h"
#include "../GameState.h"

class CheckFoldStrategy : public Strategy
{
public:
	CheckFoldStrategy();

	// Implementing abstract methods
	std::string GetAction(GameState *gs);

};

#endif