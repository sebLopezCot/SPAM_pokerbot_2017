package pokerbots.spam_framework.packet;

import pokerbots.spam_framework.GameState;

public class NewGamePacket extends Packet {
	
	private int stackSize;
	private int bigBlind;
	private int numHands;
	private double timeBank;
	
	public NewGamePacket(int stackSize, int bigBlind, int numHands, double timeBank){
		this.stackSize = stackSize;
		this.bigBlind = bigBlind;
		this.numHands = numHands;
		this.timeBank = timeBank;
	}

	@Override
	public void updateGameState(GameState gameState) {
		gameState.setNumStartingChips(stackSize);
		gameState.setMyStackSize(stackSize);
		gameState.setVillainStackSize(stackSize);
		gameState.setBigBlindAmount(bigBlind);
		gameState.setNumHandsLeft(numHands);
		gameState.setHandDuration(timeBank);
		gameState.setCurrentStreet(GameState.PREGAME);
	}
	
}
