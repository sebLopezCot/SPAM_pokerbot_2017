package pokerbots.spam_framework.action;

import pokerbots.spam_framework.Card;

public class Show extends Action {

	public Card card1;
	public Card card2;
	
	public Show (String card1Id, String card2Id, String actor) {
		this.card1 = new Card(card1Id);
		this.card2 = new Card(card2Id);
		this.actor = actor;
	}
}
