package pokerbots.spam_framework.packet;

import pokerbots.spam_framework.Card;
import pokerbots.spam_framework.GameState;

public class NewHandPacket extends Packet {

	private int handID;
	private boolean isDealer;
	private Card card1; 
	private Card card2;
	private int myBank;
	private int villainBank;
	private double timeBank;
	
	public NewHandPacket(int handID, boolean isDealer, Card card1, 
			Card card2, int myBank, int villainBank, double timeBank) {

		this.handID = handID;
		this.isDealer = isDealer;
		this.card1 = card1;
		this.card2 = card2;
		this.myBank = myBank;
		this.villainBank = villainBank;
		this.timeBank = timeBank;
	}
	
	@Override
	public void updateGameState(GameState gameState) {
		gameState.setCurrentHandID(handID);
		gameState.setDealer(isDealer);
		gameState.setCard1(card1);
		gameState.setCard2(card2);
		gameState.setMyStackSize(gameState.getNumStartingChips() + myBank);
		gameState.setVillainStackSize(gameState.getNumStartingChips() + villainBank);
		gameState.setTimeLeft(timeBank);
		gameState.setCurrentStreet(GameState.PREFLOP);
	}

}
