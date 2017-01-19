package pokerbots.spam_framework;

public class Game {
	
	private int numStartingChips;	// number of chips
	private int numMyChips;			// number of chips left in player's stack
	private int numVillianChips;	// number of chips left in other player's stack
	private int bigBlindAmount; 	// number of chips for a big blind
	private int numHandsLeft;		// number of hands left
	private int currentHandID; 		// ID of the current hand
	private double handDuration;	// duration allowed for each match
	private double timeLeft;		// time left before match ends
	private boolean isDealer; 		// whether or not we are the dealer
	private Card card1, card2;		// the two cards the player has

	public void broadcastKeyValuePair(String key, String value){
		
	}
	
	public void requestKeyValuePairsToBeStored(int bytesLeft){
		
	}
	
	// ----- GETTERS AND SETTERS --------------------------------------------
	
	public int getNumMyChips() {
		return numMyChips;
	}

	public void setNumMyChips(int numMyChips) {
		this.numMyChips = numMyChips;
	}

	public int getNumVillianChips() {
		return numVillianChips;
	}

	public void setNumVillianChips(int numVillianChips) {
		this.numVillianChips = numVillianChips;
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
	
	
}
