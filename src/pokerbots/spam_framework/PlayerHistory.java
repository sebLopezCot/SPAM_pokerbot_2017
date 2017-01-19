package pokerbots.spam_framework;

import java.util.ArrayList;

public class PlayerHistory {

	private ArrayList<String> lastActions;
	
	public PlayerHistory() {
		
	}

	public ArrayList<String> getLastActions() {
		return lastActions;
	}

	public void setLastActions(ArrayList<String> lastActions) {
		this.lastActions = lastActions;
	}
}
