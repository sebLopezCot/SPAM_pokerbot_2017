package pokerbots.spam_framework;

import java.util.ArrayList;

public class GameState {
	
	// Street enum values
	public static final int PREGAME = 0;
	public static final int PREFLOP = 1;
	public static final int FLOP = 2;
	public static final int TURN = 3;
	public static final int RIVER = 4;
	public static final int HANDOVER = 5;
	public static final int GAMEOVER = 6;
	
	// Attributes
	private int potSize;					// number of chips in the pot
	private ArrayList<Card> boardCards; 	// cards on the table
	private ArrayList<String> legalActions; // legal actions for this street
	private int numStartingChips;	// number of chips
	private int myStackSize;			// number of chips left in player's stack
	private int villainStackSize;	// number of chips left in other player's stack
	private int bigBlindAmount; 	// number of chips for a big blind
	private int numHandsLeft;		// number of hands left
	private int currentHandID; 		// ID of the current hand
	private double handDuration;	// duration allowed for each match
	private double timeLeft;		// time left before match ends
	private boolean isDealer; 		// whether or not we are the dealer
	private Card card1, card2;		// the two cards the player has
	private int currentStreet;		// the current street of the game

	private PlayerHistory selfHistory;	  // stats on our moves
	private PlayerHistory villainHistory; // stats on previous villain moves
	
	public GameState() {
		selfHistory = new PlayerHistory();
		villainHistory = new PlayerHistory();
	}
	
	// ----- GETTERS AND SETTERS --------------------------------------------
	
	public int getMyStackSize() {
		return myStackSize;
	}

	public void setMyStackSize(int numMyChips) {
		this.myStackSize = numMyChips;
	}

	public int getVillainStackSize() {
		return villainStackSize;
	}

	public void setVillainStackSize(int numVillianChips) {
		this.villainStackSize = numVillianChips;
	}

	public int getBigBlindAmount() {
		return bigBlindAmount;
	}

	public void setBigBlindAmount(int bigBlindAmount) {
		this.bigBlindAmount = bigBlindAmount;
	}

	public int getNumHandsLeft() {
		return numHandsLeft;
	}

	public void setNumHandsLeft(int numHandsLeft) {
		this.numHandsLeft = numHandsLeft;
	}

	public double getHandDuration() {
		return handDuration;
	}

	public void setHandDuration(double handDuration) {
		this.handDuration = handDuration;
	}

	public boolean isDealer() {
		return isDealer;
	}

	public void setDealer(boolean isDealer) {
		this.isDealer = isDealer;
	}

	public Card getCard2() {
		return card2;
	}

	public void setCard2(Card card2) {
		this.card2 = card2;
	}

	public Card getCard1() {
		return card1;
	}

	public void setCard1(Card card1) {
		this.card1 = card1;
	}

	public int getCurrentHandID() {
		return currentHandID;
	}

	public void setCurrentHandID(int currentHandID) {
		this.currentHandID = currentHandID;
	}

	public int getNumStartingChips() {
		return numStartingChips;
	}

	public void setNumStartingChips(int numStartingChips) {
		this.numStartingChips = numStartingChips;
	}

	public double getTimeLeft() {
		return timeLeft;
	}

	public void setTimeLeft(double timeLeft) {
		this.timeLeft = timeLeft;
	}

	public PlayerHistory getVillainHistory() {
		return villainHistory;
	}

	public void setVillainHistory(PlayerHistory villainHistory) {
		this.villainHistory = villainHistory;
	}

	public PlayerHistory getSelfHistory() {
		return selfHistory;
	}

	public void setSelfHistory(PlayerHistory selfHistory) {
		this.selfHistory = selfHistory;
	}

	public int getCurrentStreet() {
		return currentStreet;
	}

	public void setCurrentStreet(int currentStreet) {
		this.currentStreet = currentStreet;
	}

	public int getPotSize() {
		return potSize;
	}

	public void setPotSize(int potSize) {
		this.potSize = potSize;
	}

	public ArrayList<String> getLegalActions() {
		return legalActions;
	}

	public void setLegalActions(ArrayList<String> legalActions) {
		this.legalActions = legalActions;
	}

	public ArrayList<Card> getBoardCards() {
		return boardCards;
	}

	public void setBoardCards(ArrayList<Card> boardCards) {
		this.boardCards = boardCards;
	}
	
	
}
