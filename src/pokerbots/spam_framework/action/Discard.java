package pokerbots.spam_framework.action;

import pokerbots.spam_framework.Card;

public class Discard extends Action {

	public Card card;
	
	public Discard(Card c) {
		this.card = c;
	}
	
	public Discard(String param) {
		if (Card.isCard(param)){
			this.card = new Card(param);
		} else {
			this.actor = param;
		}
	}
}
