package pokerbots.spam_framework.packet;

import pokerbots.spam_framework.GameState;

public abstract class Packet {
	
	// Packet should parse information and update game state
	public abstract void updateGameState(GameState gameState);
	
}
