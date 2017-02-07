package pokerbots.spam_framework.action;

public class Refund extends Action {

	public int amount;
	
	public Refund(String amount, String actor) {
		this.amount = Integer.parseInt(amount);
		this.actor = actor;
	}
}
