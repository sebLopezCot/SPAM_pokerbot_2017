package pokerbots.spam_framework.packet;

import pokerbots.spam_framework.GameState;

public class RequestKeyValuesPacket extends Packet {

	@Override
	public void updateGameState(GameState gameState) {
		gameState.setCurrentStreet(GameState.GAMEOVER);
	}

}
