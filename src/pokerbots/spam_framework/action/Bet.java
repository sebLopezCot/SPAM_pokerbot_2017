package pokerbots.spam_framework.action;

public class Bet extends Action {

	public int amount;
	public int minBet;
	public int maxBet;
	
	public Bet(int amount) {
		this.amount = amount;
	}
	
	public Bet(String param1, String param2) {
		try {
			this.maxBet = Integer.parseInt(param2);
			this.minBet = Integer.parseInt(param1);
		} catch (NumberFormatException e) {
			this.amount = Integer.parseInt(param1);
			this.actor = param2;
		}
	}
}
