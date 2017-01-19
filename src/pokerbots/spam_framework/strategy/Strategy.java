package pokerbots.spam_framework.strategy;

import pokerbots.spam_framework.GameState;

public abstract class Strategy {

	// once the game state is updated, this get action method
	// will be called in order to make a decision on what to do.
	public abstract String getAction(GameState gameState);
}
