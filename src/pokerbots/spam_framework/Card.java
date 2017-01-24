package pokerbots.spam_framework;

import java.util.HashMap;

public class Card {

	private static HashMap<String, Integer> cardIdToNumber;
	
	private String id;
	private int number;
	
	private static void init(){
		String[] suits = { "h", "s", "c", "d" };
		String[] values = { "2", "3", "4", "5", "6", "7", 
				"8", "9", "T", "J", "Q", "K", "A" };
		
		cardIdToNumber = new HashMap<String, Integer>();
		
		
		for (int i = 0; i < values.length; i++){
			for (int j = 0; j < suits.length; j++){
				cardIdToNumber.put(values[i] + suits[j], i*4 + j);
			}
		}
		
	}
	
	public static boolean isCard(String cardId) {
		if (cardIdToNumber == null) {
			init();
		}
		
		return cardIdToNumber.containsKey(cardId);
	}
	
	public Card(String id){
		if (cardIdToNumber == null){
			init();
		}
		
		try {
			if (cardIdToNumber.containsKey(id)) {
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
	public int toNumber() {
		if(cardIdToNumber == null) {
			init();
		}
		
		return cardIdToNumber.get(this.id);
	}
}
