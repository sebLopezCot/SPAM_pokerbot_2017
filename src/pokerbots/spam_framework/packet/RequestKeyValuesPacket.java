package pokerbots.spam_framework.packet;

import pokerbots.spam_framework.Game;

public class RequestKeyValuesPacket extends Packet {

	private int bytesLeft;
	
	public RequestKeyValuesPacket(int bytesLeft) {
		this.bytesLeft = bytesLeft;
	}
	
	@Override
	public String updateGame(Game game) {
		game.requestKeyValuePairsToBeStored(bytesLeft);
		
		// No actions to perform yet
		return null;
	}

}
