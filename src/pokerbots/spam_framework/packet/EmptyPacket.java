package pokerbots.spam_framework.packet;

import pokerbots.spam_framework.Game;

public class EmptyPacket extends Packet {

	@Override
	public String updateGame(Game game) {
		return null;
	}

}
