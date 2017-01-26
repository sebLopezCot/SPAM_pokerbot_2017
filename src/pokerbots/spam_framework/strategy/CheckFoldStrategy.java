package pokerbots.spam_framework.strategy;

import pokerbots.spam_framework.Card;
import pokerbots.spam_framework.GameState;
import pokerbots.spam_framework.ranking_tables.DiscardDecisionRuleGivenFlop;
import pokerbots.spam_framework.ranking_tables.DiscardDecisionRuleGivenTurn;
import pokerbots.spam_framework.ranking_tables.HandRanker;
import pokerbots.spam_framework.ranking_tables.HandRankerGivenFlop;
import pokerbots.spam_framework.ranking_tables.HandRankerGivenPreFlop;
import pokerbots.spam_framework.ranking_tables.HandRankerGivenRiver;
import pokerbots.spam_framework.ranking_tables.HandRankerGivenTurn;

public class CheckFoldStrategy extends Strategy {
	
	HandRankerGivenPreFlop preflop;
	HandRankerGivenFlop flop;
	DiscardDecisionRuleGivenFlop flopDR;
	HandRankerGivenTurn turn;
	DiscardDecisionRuleGivenTurn turnDR;
	HandRankerGivenRiver river;
	HandRanker currentRanker;
	HandRanker currentDR;
	
	public CheckFoldStrategy() {
		super(false);
		
		preflop = new HandRankerGivenPreFlop();
		flop = new HandRankerGivenFlop();
		flopDR = new DiscardDecisionRuleGivenFlop();
		turn = new HandRankerGivenTurn();
		turnDR = new DiscardDecisionRuleGivenTurn();
		river = new HandRankerGivenRiver();
	}

	@Override
	public String getAction(GameState gameState) {
		switch(gameState.getCurrentStreet()){
		case GameState.GAMEOVER:
			// At the end, engine will allow bot to send key/value pairs to store.
			// FINISH indicates no more to store.
			return "FINISH";
		default:
			
			if(gameState.getCurrentStreet() == GameState.PREFLOP) {
				currentRanker = preflop;
				currentDR = null;
			} else if (gameState.getCurrentStreet() == GameState.FLOP) {
				currentRanker = flop;
				currentDR = flopDR;
			} else if (gameState.getCurrentStreet() == GameState.TURN) {
				currentRanker = turn;
				currentDR = turnDR;
			} else if (gameState.getCurrentStreet() == GameState.RIVER) {
				currentRanker = river;
				currentDR = null;
			}
			
			Card[] hand = new Card[2];
			hand[0] = gameState.getCard1();
			hand[1] = gameState.getCard2();
			Card[] bc = new Card[gameState.getBoardCards().size()];
			for (int i=0; i < gameState.getBoardCards().size(); i++) {
				bc[i] = gameState.getBoardCards().get(i);
			}
			int rank = currentRanker.getValue(hand, bc);
			int dr = 0;
			if(currentDR != null) {
				dr = currentDR.getValue(hand, bc);
			}
			if(rank > -1 || dr != 0){
				gameState.getVillainHistory().setLastActions(null);
			}
			
			return "CHECK";
		}
	}

}
