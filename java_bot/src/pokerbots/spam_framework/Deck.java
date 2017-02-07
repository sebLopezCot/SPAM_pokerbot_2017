package pokerbots.spam_framework;

import java.util.ArrayList;

public class Deck {

	ArrayList<String> cardIds;
	
	public Deck() {
		cardIds = new ArrayList<String>(Card.getCardSet());
	}
	
	public Card draw() {
		if (cardIds.size() > 0) {
			int rand =  0 + (int)(Math.random() * ((cardIds.size()-1 - 0) + 1));
			return new Card(cardIds.remove(rand));
		} else {
			return null;
		}
	}
}
