package pokerbots.spam_framework.packet;

import java.util.ArrayList;

import pokerbots.spam_framework.Card;
import pokerbots.spam_framework.GameState;

public class GetActionPacket extends Packet {

	private int potSize;
	private int numBoardCards; 
	private ArrayList<Card> boardCards;
	private int numLastActions; 
	private ArrayList<String> lastActions;
	private int numLegalActions;
	private ArrayList<String> legalActions;
	private double timeBank;
	
	public GetActionPacket(int potSize, int numBoardCards, 
			ArrayList<Card> boardCards, int numLastActions, 
			ArrayList<String> lastActions, int numLegalActions,
			ArrayList<String> legalActions, double timeBank) {
		
		this.potSize = potSize;
		this.numBoardCards = numBoardCards;
		this.boardCards = boardCards;
		this.numLastActions = numLastActions;
		this.lastActions = lastActions;
		this.numLegalActions = numLegalActions;
		this.legalActions = legalActions;
		this.timeBank = timeBank;
	}
	
	private static int numBoardCardsToStreet(int numCards) {
		switch(numCards){
		case 0:
			return GameState.PREFLOP;
		case 3:
			return GameState.FLOP;
		case 4:
			return GameState.TURN;
		case 5:
			return GameState.RIVER;
		}
		
		return GameState.GAMEOVER;
	}
	
	@Override
	public void updateGameState(GameState gameState) {
		gameState.setPotSize(potSize);
		gameState.setCurrentStreet(GetActionPacket
				.numBoardCardsToStreet(numBoardCards));
		gameState.setBoardCards(boardCards);
		
		// TODO: Need to separate the two action histories
		gameState.getSelfHistory().setLastActions(lastActions);
		gameState.getVillainHistory().setLastActions(lastActions);
		
		gameState.setLegalActions(legalActions);
		
		gameState.setTimeLeft(timeBank);
	}

}
