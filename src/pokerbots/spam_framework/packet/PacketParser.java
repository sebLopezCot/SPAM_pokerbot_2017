package pokerbots.spam_framework.packet;

import pokerbots.spam_framework.Card;

public class PacketParser {
	
	public Packet parse(String rawInput){
		// Split up the incoming packet into pieces to parse
		String[] data = rawInput.split(" ");
		
		if (data.length > 0){
			
			// Create a new packet based on input data
			String packetType = data[0];
			
			switch(packetType){
			case "NEWGAME":
				int stackSize = Integer.parseInt(data[3]);
				int bigBlind = Integer.parseInt(data[4]);
				int numHands = Integer.parseInt(data[5]);
				double timeBank = Double.parseDouble(data[6]);
				
				return new NewGamePacket(stackSize, bigBlind, numHands, timeBank);
				
			case "NEWHAND":
				int handID = Integer.parseInt(data[1]);
				boolean isDealer = Boolean.parseBoolean(data[2]);
				Card card1 = new Card(data[3]);
				Card card2 = new Card(data[4]);
				int myBank = Integer.parseInt(data[5]);
				int villainBank = Integer.parseInt(data[6]);
				double timeLeft = Double.parseDouble(data[7]);
				
				return new NewHandPacket(handID, isDealer, card1, card2, 
						myBank, villainBank, timeLeft);
				
			case "GETACTION":
				// TODO: Implement getaction packet
				
				return new GetActionPacket();
				
			case "HANDOVER":
				// TODO: Implement handover packet
				
				return new HandOverPacket();
			
			case "REQUESTKEYVALUES":
				return new RequestKeyValuesPacket();
			
			}
				
		} else {
			System.out.println("ERROR: EMPTY PACKET WAS SENT TO SPAMBOT.");
		}
		
		// In the event we get this far
		return new EmptyPacket();
	}
}
