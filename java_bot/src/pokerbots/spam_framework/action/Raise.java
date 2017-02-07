package pokerbots.spam_framework.action;

public class Raise extends Action {
	
	public int amount;
	public int minBet;
	public int maxBet;
	
	public Raise(int amount){
		this.amount = amount;
	}
	
	public Raise(String param1, String param2) {
		try {
			this.maxBet = Integer.parseInt(param2);
			this.minBet = Integer.parseInt(param1);
		} catch (NumberFormatException e) {
			this.amount = Integer.parseInt(param1);
			this.actor = param2;
		}
	}
}
