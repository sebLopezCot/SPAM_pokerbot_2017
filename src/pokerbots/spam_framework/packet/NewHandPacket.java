package pokerbots.spam_framework.packet;

import pokerbots.spam_framework.Card;
import pokerbots.spam_framework.Game;

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
	public String updateGame(Game game) {
		game.setCurrentHandID(handID);
		game.setDealer(isDealer);
		game.setCard1(card1);
		game.setCard2(card2);
		game.setNumMyChips(game.getNumStartingChips() + myBank);
		game.setNumVillianChips(game.getNumStartingChips() + villainBank);
		game.setTimeLeft(timeBank);
		
		// No action to return here
		return null;
	}

}
