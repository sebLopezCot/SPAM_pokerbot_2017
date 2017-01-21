package pokerbots.spam_framework;

import java.util.HashSet;

public class Card {

	private static HashSet<String> cardIds;
	
	private String id;
	
	private static void init(){
		String[] suits = { "c", "s", "d", "h" };
		String[] values = { "2", "3", "4", "5", "6", "7", 
				"8", "9", "T", "J", "Q", "K", "A" };
		
		cardIds = new HashSet<String>();
		
		for (int i = 0; i < values.length; i++){
			for (int j = 0; j < suits.length; j++){
				cardIds.add(values[i] + suits[j]);
			}
		}
		
	}
	
	public static boolean isCard(String cardId) {
		if (cardIds == null) {
			init();
		}
		
		return cardIds.contains(cardId);
	}
	
	public Card(String id){
		if (cardIds == null){
			init();
		}
		
		try {
			if (cardIds.contains(id)) {
				this.id = id;
			} else {
				throw new Exception("Specified card ID is not valid");
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	public String toString(){
		return this.id;
	}
	
	// Return a number between 0 and 51 as a string
	public String toNumericString(){
		// TODO: NEED TO FIX THIS FUNCTION
		return this.id;
	}
}
