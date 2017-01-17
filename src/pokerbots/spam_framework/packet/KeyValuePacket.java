package pokerbots.spam_framework.packet;

import pokerbots.spam_framework.Game;

public class KeyValuePacket extends Packet {

	private String key;
	private String value;
	
	public KeyValuePacket(String key, String value) {
		this.key = key;
		this.value = value;
	}
	
	@Override
	public String updateGame(Game game) {
		game.broadcastKeyValuePair(key, value);
		
		// No action to perform here
		return null;
	}

}
