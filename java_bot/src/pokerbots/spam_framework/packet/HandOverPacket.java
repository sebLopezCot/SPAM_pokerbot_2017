package pokerbots.spam_framework.packet;

import java.util.ArrayList;

import pokerbots.spam_framework.Card;
import pokerbots.spam_framework.GameState;

public class HandOverPacket extends Packet {

	private int myStackSize;
	private int villainStackSize;
	private int numBoardCards;
	private ArrayList<Card> boardCards;
	private int numLastActions;
	private ArrayList<String> lastActions;
	private double timeBank;
	
	public HandOverPacket(int myStackSize, int villainStackSize,
			int numBoardCards, ArrayList<Card> boardCards, int numLastActions,
			ArrayList<String> lastActions, double timeBank) {
		
		this.myStackSize = myStackSize;
		this.villainStackSize = villainStackSize;
		this.numBoardCards = numBoardCards;
		this.boardCards = boardCards;
		this.numLastActions = numLastActions;
		this.lastActions = lastActions;
		this.timeBank = timeBank;
	}
	
	@Override
	public void updateGameState(GameState gameState) {
		gameState.setMyStackSize(myStackSize);
		gameState.setVillainStackSize(villainStackSize);
		gameState.setCurrentStreet(GameState.HANDOVER);
		gameState.setBoardCards(boardCards);
		
		// TODO: Need to separate the two action histories
		gameState.getSelfHistory().setLastActions(lastActions);
		gameState.getVillainHistory().setLastActions(lastActions);
		
		gameState.setTimeLeft(timeBank);
	}

}
