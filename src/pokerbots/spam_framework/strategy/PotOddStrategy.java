package pokerbots.spam_framework.strategy;

import pokerbots.spam_framework.Card;
import pokerbots.spam_framework.GameState;
import pokerbots.spam_framework.ranking_tables.DiscardDecisionRuleGivenFlop;
import pokerbots.spam_framework.ranking_tables.DiscardDecisionRuleGivenTurn;
import pokerbots.spam_framework.ranking_tables.HandRankerGivenFlop;
import pokerbots.spam_framework.ranking_tables.HandRankerGivenPreFlop;
import pokerbots.spam_framework.ranking_tables.HandRankerGivenRiver;
import pokerbots.spam_framework.ranking_tables.HandRankerGivenTurn;

public class PotOddStrategy extends Strategy {

	DiscardDecisionRuleGivenFlop flopDR;
	DiscardDecisionRuleGivenTurn turnDR;
	
	HandRankerGivenPreFlop preflopRanking;
	HandRankerGivenFlop flopRanking;
	HandRankerGivenTurn turnRanking;
	HandRankerGivenRiver riverRanking;
	
	public PotOddStrategy() {
		super(true);
		
		flopDR = new DiscardDecisionRuleGivenFlop();
		turnDR = new DiscardDecisionRuleGivenTurn();
		
		preflopRanking = new HandRankerGivenPreFlop();
		flopRanking = new HandRankerGivenFlop();
		turnRanking = new HandRankerGivenTurn();
		riverRanking = new HandRankerGivenRiver();
	}

	private int generalStrategy(int stage, double winRate, int amount, int pot) {
		switch(stage) {
		case GameState.PREFLOP:
			return preFlopStrategy(winRate, amount, pot);
		case GameState.FLOP:
			return flopStrategy(winRate, amount, pot);
		case GameState.TURN:
			return turnStrategy(winRate, amount, pot);
		case GameState.RIVER:
			return riverStrategy(winRate, amount, pot);
		default:
			return -1;
		}
	}
	
	private int raise(int amount, int possibleRaise) {
		if (amount > possibleRaise || possibleRaise < 4) {
			return amount;
		} else {
			return possibleRaise+amount;
		}
	}

	private int riverStrategy(double winRate, int amount, int pot) {
		if(winRate<0.65){
			if(winRate>= 1.35*(amount*1.0)/(2*amount+pot)){
				return amount;
			}
			else{
				return 0;
			}
		}
		else if(0.65<=winRate&&winRate<=0.7){
			if(winRate>= (amount*1.0)/(2*amount+pot)){
				return amount;
			}
			else{
				return 0;
			}
		}

		else if(0.7< winRate&&winRate<= 0.8){
			if(Math.random() <= 0.5){
				return amount;
			}
			else{
				raise(amount, (int)((0.2+(winRate-0.7)*5)*pot));
			}
		}
		else if(0.8< winRate&&winRate<= 0.9){
			if(Math.random() <= 0.4){
				return amount;
			}
			else{
				raise(amount, (int)((0.7+(winRate-0.8)*10)*pot));
			}
		}
		else if(0.9< winRate){
			if(Math.random() <= 0.3){
				return amount;
			}
			else{
				raise(amount, (int)((2*pot)));
			}
		}
		
		return -1;
	}

	private int turnStrategy(double winRate, int amount, int pot) {
		if(winRate<0.6){
			if(winRate>= 1.3*(amount*1.0)/(2*amount+pot)){
				return amount;
			}
			else{
				return 0;
			}
		}
		else if(0.6<=winRate && winRate<=0.7){
			if(Math.random() <= 0.8){
				return amount;
			}
		}

		else if(0.7< winRate&&winRate<= 0.8){
			if(Math.random() <= 0.5){
				return amount;
			}
			else{
				raise(amount, (int)((0.4+(winRate-0.7)*6)*pot));
			}
		}
		else if(0.8< winRate&&winRate<= 0.9){
			if(Math.random() <= 0.4){
				return amount;
			}
			else{
				raise(amount, (int)((1.0+(winRate-0.8)*5)*pot));
			}
		}
		else if(0.9< winRate){
			if(Math.random() <= 0.3){
				return amount;
			}
			else{
				raise(amount, (int)((2*pot)));
			}
		}
		
		return -1;
	}
	
	private int flopStrategy(double winRate, int amount, int pot) {
		if(winRate<0.55){
			if(winRate>= 1.2*(amount*1.0)/(2*amount+pot)){
				return amount;
			}
			else{
				return 0;
			}
		}
		else if(0.55<=winRate && winRate<=0.7){
			if(Math.random() <= 0.8){
				return amount;
			}
			else{
				raise(amount, (int)(winRate-0.5)*4*pot);
			}
		}

		else if(0.7< winRate && winRate<= 0.8){
			if(Math.random() <= 0.5){
				return amount;
			}
			else{
				raise(amount, (int)((0.8+(winRate-0.7)*6)*pot));
			}
		}
		else if(0.8< winRate && winRate<= 0.9){
			if(Math.random() <= 0.4){
				return amount;
			}
			else{
				raise(amount, (int)((1.4+(winRate-0.8)*5)*pot));
			}
		}
		else if(0.9< winRate){
			if(Math.random() <= 0.3){
				return amount;
			}
			else{
				raise(amount, (int)((2*pot)));
			}
		}

		return -1;
	}

	private int preFlopStrategy(double winRate, int amount, int pot) {
		if(winRate<0.5){
			if(winRate >= (amount*1.0)/(2*amount+pot)){
				return amount;
			}
			else{
				return 0;
			}
		}
		else if(0.5<=winRate && winRate<=0.7){
			if(Math.random() <= 0.8){
				return amount;
			}
			else{
				return raise(amount, (int)(winRate-0.5)*7*pot);
			}
		}
		else if(0.7< winRate){
			return raise(amount, (int)(1.4+(winRate-0.7)*20*pot));
		}
		
		return -1;
	}

	@Override
	public String getAction(GameState gameState) {
		
		if (gameState.getCurrentStreet() == GameState.GAMEOVER) return "FINISH";
		
		Card[] hand = new Card[2];
		hand[0] = (gameState.getCard1() != null) ? gameState.getCard1() : null;
		hand[1] = (gameState.getCard2() != null) ? gameState.getCard2() : null;
		
		Card[] boardCards = new Card[gameState.getBoardCards().size()];
		for (int i=0; i < gameState.getBoardCards().size(); i++) {
			boardCards[i] = gameState.getBoardCards().get(i);
		}
		
		// Check if a discard rule is needed for this action
		boolean discardRuleNeeded = false;
		for (String legalAction : gameState.getLegalActions()) {
			if (legalAction.indexOf("DISCARD") > -1) {
				discardRuleNeeded = true;
				break;
			}
		}
		
		if (discardRuleNeeded) {
			// Load the discard decision rule
			int decision = -1;
			switch (gameState.getCurrentStreet()) {
			case GameState.FLOP:
				decision = flopDR.getValue(hand, boardCards);
				break;

			case GameState.TURN:
				decision = turnDR.getValue(hand, boardCards);
				break;
			}
			
			// Decide whether or not to discard (1 is smaller number, 2 is larger number)
			switch(decision) {
			case 1:
				// Discard smaller
				if (hand[0].toNumber() > hand[1].toNumber()) {
					return "DISCARD:" + hand[1].toString();
				} else if (hand[0].toNumber() < hand[1].toNumber()) {
					return "DISCARD:" + hand[0].toString();
				} else {
					return "CHECK";
				}
				
			case 2:
				// Discard larger
				if (hand[0].toNumber() < hand[1].toNumber()) {
					return "DISCARD:" + hand[1].toString();
				} else if (hand[0].toNumber() > hand[1].toNumber()) {
					return "DISCARD:" + hand[0].toString();
				} else {
					return "CHECK";
				}
				
			default:
				return "CHECK";
			}
		} else {
			// Perform our betting strategy
			int ranking = -1;
			
			// Parse winning rate
			switch(gameState.getCurrentStreet()) {
			case GameState.PREFLOP:
				ranking = preflopRanking.getValue(hand, boardCards);
				break;
				
			case GameState.FLOP:
				ranking = flopRanking.getValue(hand, boardCards);
				break;
				
			case GameState.TURN:
				ranking = turnRanking.getValue(hand, boardCards);
				break;
				
			case GameState.RIVER:
				ranking = riverRanking.getValue(hand, boardCards);
				break;
			}
			
			if (ranking > -1) {
				int lastRaise = 0;
				int numLastActions = gameState.getVillainHistory().getLastActions().size();
				for (int i=numLastActions-1; i >= 0; i--){
					String act = gameState.getVillainHistory().getLastActions().get(i);
					if (act.contains("RAISE") || act.contains("BET")) {
						lastRaise = Integer.parseInt(act.split(":")[1]);
						break;
					}
					
				}
				
				// Pass to Pedro's strategy
				int raiseTo = generalStrategy(gameState.getCurrentStreet(), 
						ranking, lastRaise-gameState.getPotSize(), gameState.getPotSize());
				
				int maxBet = 0;
				boolean canBet = false;
				for (String action : gameState.getLegalActions()) {
					if (action.contains("BET")) {
						maxBet = Integer.parseInt(action.split(":")[2]);
						canBet = true;
						break;
					}
				}
				
				// Limit to all in
				if (raiseTo > maxBet) {
					raiseTo = maxBet;
				}
				
				if (canBet) {
					if (raiseTo == lastRaise && raiseTo != 0) {
						return "CALL";
					} else if (lastRaise == 0) {
						return "BET:" + String.valueOf(raiseTo);
					} else if (lastRaise != 0) {
						return "RAISE:" + String.valueOf(raiseTo);
					}
				} else {
					return "CALL";
				}
				
			} else {
				return "CHECK";
			}
		}
		return "CHECK";
	}

}
