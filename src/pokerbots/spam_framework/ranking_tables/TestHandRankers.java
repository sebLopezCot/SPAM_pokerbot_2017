package pokerbots.spam_framework.ranking_tables;

import static org.junit.Assert.*;

import java.util.Arrays;

import org.junit.Test;

import pokerbots.spam_framework.Card;
import pokerbots.spam_framework.Deck;

public class TestHandRankers {
	
	Card[] hand = new Card[2];
	Card[] boardCards = new Card[5];
	
	public TestHandRankers() {
		Deck deck = new Deck();
		
		for (int i=0; i < 2; i++) {
			hand[i] = deck.draw();
		}
		
		for (int i=0; i < 5; i++) {
			boardCards[i] = deck.draw();
		}
	}
	
	@Test
	public void testPreFlopHandRanker() {
		HandRankerGivenPreFlop ranker = new HandRankerGivenPreFlop();
		int ranking = ranker.getValue(this.hand, new Card[] {});
		assertNotEquals(ranking, -1);
	}
	
	@Test
	public void testFlopHandRanker() {
		HandRankerGivenFlop ranker = new HandRankerGivenFlop();
		int ranking = ranker.getValue(this.hand, Arrays.copyOfRange(this.boardCards, 0, 3));
		assertNotEquals(ranking, -1);
	}
	
	@Test
	public void testFlopDecisionRule() {
		DiscardDecisionRuleGivenFlop dr = new DiscardDecisionRuleGivenFlop();
		int choice = dr.getValue(this.hand, Arrays.copyOfRange(this.boardCards, 0, 3));
		assertNotEquals(choice, -1);
	}
	
	@Test
	public void testTurnHandRanker() {
		HandRankerGivenTurn ranker = new HandRankerGivenTurn();
		int ranking = ranker.getValue(this.hand, Arrays.copyOfRange(this.boardCards, 0, 4));
		assertNotEquals(ranking, -1);
	}

	@Test
	public void testTurnDecisionRule() {
		DiscardDecisionRuleGivenTurn dr = new DiscardDecisionRuleGivenTurn();
		int choice = dr.getValue(this.hand, Arrays.copyOfRange(this.boardCards, 0, 4));
		assertNotEquals(choice, -1);
	}
	
	@Test
	public void testRiverHandRanker() {
		HandRankerGivenRiver ranker = new HandRankerGivenRiver();
		int ranking = ranker.getValue(this.hand, this.boardCards);
		assertNotEquals(ranking, -1);
	}

}
