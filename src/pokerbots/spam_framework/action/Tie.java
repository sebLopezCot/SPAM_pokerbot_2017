package pokerbots.spam_framework.action;

public class Tie extends Action {

	public int amount;
	
	public Tie(String amount, String actor) {
		this.amount = Integer.parseInt(amount);
		this.actor = actor;
	}
}
