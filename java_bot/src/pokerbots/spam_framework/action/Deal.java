package pokerbots.spam_framework.action;

import pokerbots.spam_framework.GameState;

public class Deal extends Action {

	public int street;
	
	private static int streetStringToStreet(String street) {
		switch(street){
		case "FLOP":
			return GameState.FLOP;
		case "TURN":
			return GameState.TURN;
		case "RIVER":
			return GameState.RIVER;
		}
		
		return GameState.GAMEOVER;
	}
	
	public Deal(String street) {
		this.street = streetStringToStreet(street);
	}
}
