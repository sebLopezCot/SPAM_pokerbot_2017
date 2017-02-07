package pokerbots.spam_framework;

import java.util.ArrayList;

public class PlayerHistory {

	// game stats
	int numHandsPlayed = 0;
	int winCount;
	int instantFold;
	
	// pre-flop stats
	int pfrCount = 0;		// preflop raise
	int vpipCount = 0;		// call or raise pre-flop
	int initFoldCount = 0;	// related to vpip, counts when they don't play their hand.
	int threeBCount = 0;	// re-raise pre-flop
	int pfrFoldCount = 0;	// fold to initial pre-flop raise
	int f3Count = 0;		// fold to a re-raise pre-flop
	int callRaiseCount = 0;
	int checkRaiseCount = 0;
	boolean hasCalledPreflop = false;
	int poss3Bet = 0;
	int poss2Bet = 0;
	
	// post-flop stats
	double aggressionFactor = 0.0; //(Raise% + Bet%) / Call%, calculated for post-flop only
	int raiseCount = 0;
	int betCount = 0;
	int callCount = 0;
	int actionCount = 0;	// post-flop rates
	int wtsdCount = 0; 		// how often opponent goes to showdown after seeing flop (can be used with aggression)
	int showdownCount = 0;	// how often we go to showdown in total
	int seenFlopCount = 0;	// number of times we've made it to the flop
	int cbCount = 0;		// how often opponent continuation bets as the pre-flop raiser
	int twoBCount = 0;		// how often opponent makes another continuation bet after the first one (second barrel)
	int myCBet = 0;			// how many times we c-bet
	int myBarrel = 0;		// how many times we double barrel
	int fbCount = 0;		// fold to continuation bets
	int f2Count = 0;		// fold to second barrels
	int sdwCount = 0;
	int foldCount = 0;		
	int checkCount = 0;
	boolean oppCheckThisStreet = false;
	
	// default stats (the "placeholder" values we use when calculating stuff)
	private double vpip = 0.8;
	private double pfr = 0.5;
	private double threeB = 0.45;
	private double pfrFold = 0.3;
	private double threeBFold = 0.4;
	private double wtsd = 0.5;
	private double cbet = 0.2;
	private double db = 0.15;
	private double cbFold = 0.4;
	private double bFold = 0.4;
	private double aggression = 1.5;
	private double sdw = 0.5;
	private double aggrofreq = 0.5;
	private double callraise = 0.0;
	private double checkraise = 0.0;
	private double twoB = 0.15;
	
	private ArrayList<String> lastActions;
	
	public PlayerHistory() {
		
	}

	public ArrayList<String> getLastActions() {
		return lastActions;
	}

	public void setLastActions(ArrayList<String> lastActions) {
		this.lastActions = lastActions;
	}
	
	public double getPFR() { 
		double pfrRate  = ((double)pfrCount) / Math.max(1, (numHandsPlayed-instantFold)); 
		return (25*pfr + pfrRate*(numHandsPlayed-instantFold)) / ((numHandsPlayed-instantFold) + 25);  
	} 
	
	public double getCallRaise() {
		double callRaiseRate = ((double)callRaiseCount) / Math.max(1,  (numHandsPlayed-instantFold));
		return (50*callraise + callRaiseRate*(numHandsPlayed-instantFold)) / ((numHandsPlayed-instantFold) + 50);
	}
	
	public double getCheckRaise() {
		double checkRaiseRate = ((double)checkRaiseCount) / Math.max(1, seenFlopCount);
		return (50*callraise + checkRaiseRate*seenFlopCount) / (seenFlopCount + 50);
	}

	public double get3BetRate() {
		double threeBRate = ((double)threeBCount) / Math.max(1, poss3Bet);
		return (50*threeB + threeBRate*poss3Bet) / (poss3Bet + 50);
	}
	
	public double get2BetRate() {
		double twoBRate = ((double)twoBCount) / Math.max(1, poss2Bet);
		return (50*twoB + twoBRate*poss2Bet) / (poss2Bet + 50);
	}
	
	public double getAggression() {
		double rate = (double)(raiseCount + betCount) / Math.max(1, callCount);
		return (200 * aggression + rate * actionCount) / (200 + actionCount);
	}
	
	public double getAggressionFrequency() {
		int actions = raiseCount + betCount + callCount + foldCount + checkCount;
		double rate = (double)(raiseCount + betCount) / Math.max(1, actions);
		return (100 * aggrofreq + rate * actions) / (100 + actions);
	}
}
