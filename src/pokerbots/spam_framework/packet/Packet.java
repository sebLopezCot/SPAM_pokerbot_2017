package pokerbots.spam_framework.packet;

import pokerbots.spam_framework.Game;

public abstract class Packet {
	
	// Packet should parse information and update game
	// once the game is updated, the game will return
	// the strategy engine's next move.
	public abstract String updateGame(Game game);
	
}
