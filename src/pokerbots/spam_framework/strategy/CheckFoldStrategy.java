package pokerbots.spam_framework.strategy;

import pokerbots.spam_framework.GameState;

public class BasicStrategy extends Strategy {

	public BasicStrategy() {
		System.out.println("                  /88888888888888888888888888\\");
		System.out.println("                  |88888888888888888888888888/");
		System.out.println("                   |~~____~~~~~~~~~'''''''''|");
		System.out.println("                  / \\_________/'''''''''''''\\");
		System.out.println("                 /  |              \\         \\");
		System.out.println("                /   |  88    88     \\         \\");
		System.out.println("               /    |  88    88      \\         \\");
		System.out.println("              /    /                  \\        |");
		System.out.println("             /     |   ________        \\       |");
		System.out.println("             \\     |   \\______/        /       |");
		System.out.println("  /'\\         \\     \\____________     /        |");
		System.out.println("  | |__________\\_        |  |        /        /");
		System.out.println("\\____/,___________\\                 -------/");
		System.out.println("------*            |                    \\");
		System.out.println("  ||               |                     \\");
		System.out.println("  ||               |                 ^    \\");
		System.out.println("  ||               |                | \\    \\");
		System.out.println("  ||               |                |  \\    \\");
		System.out.println("  ||               |                |   \\    \\");
		System.out.println("  \\|              /                /'''\\/    /");
		System.out.println("     -------------                |    |    /");
		System.out.println("     |\\--_                        \\____/___/");
		System.out.println("     |   |\\-_                       |");
		System.out.println("     |   |   \\_                     |");
		System.out.println("     |   |     \\                    |");
		System.out.println("     |   |      \\_                  |");
		System.out.println("     |   |        ----___           |");
		System.out.println("     |   |               \\----------|");
		System.out.println("     /   |                     |     ----------''\\");
		System.out.println("/'\\--'--_|                     |               |  \\");
		System.out.println("|_______/                      \\______________/    )");
		System.out.println(" ");
		System.out.println("BASIC STRATEGY INITIALIZED.");
		System.out.println(" ");
	}
	
	@Override
	public String getAction(GameState gameState) {
		switch(gameState.getCurrentStreet()){
		case GameState.GAMEOVER:
			// At the end, engine will allow bot to send key/value pairs to store.
			// FINISH indicates no more to store.
			return "FINISH";
		default:
			return "CHECK";
		}
	}

}
