package pokerbots.spam_framework.action;

public class Post extends Action {
	
	public int amount;
	
	public Post(String amount, String actor) {
		this.actor = actor;
		this.amount = Integer.parseInt(amount);
	}
}
