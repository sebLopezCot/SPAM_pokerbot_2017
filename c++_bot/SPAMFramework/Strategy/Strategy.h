#ifndef STRATEGY_H
#define STRATEGY_H 

#include <iostream>
#include <string>

#include "../GameState.h"

class Strategy
{
public:
	Strategy();
	Strategy(bool show_logo);

	void ShowLogo();

	// Abstract methods
	virtual std::string GetAction(GameState *gs) = 0;
};

#endif