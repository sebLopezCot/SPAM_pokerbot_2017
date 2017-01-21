package pokerbots.spam_framework.action;

public class Win extends Action {
	
	public int amount;
	
	public Win(String amount, String actor) {
		this.amount = Integer.parseInt(amount);
		this.actor = actor;
	}
}
