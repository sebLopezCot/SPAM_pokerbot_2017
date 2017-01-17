package pokerbots.spam_framework.packet;

import pokerbots.spam_framework.Game;

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
	public String updateGame(Game game) {
		game.setNumStartingChips(stackSize);
		game.setNumMyChips(stackSize);
		game.setNumVillianChips(stackSize);
		game.setBigBlindAmount(bigBlind);
		game.setNumHandsLeft(numHands);
		game.setHandDuration(timeBank);
		
		// No action string to return
		return null;
	}
	
}
