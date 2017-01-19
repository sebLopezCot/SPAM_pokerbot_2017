package pokerbots.spam_framework.packet;

import java.util.ArrayList;

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
				int potSize = Integer.parseInt(data[1]);
				int numBoardCards = Integer.parseInt(data[2]);

				int dataPointer = 3; // Board cards start at 3rd index
				
				ArrayList<Card> boardCards = new ArrayList<Card>(numBoardCards);
				for (int i = 0; i < numBoardCards; i++){
					boardCards.add(new Card(data[i+dataPointer]));
				}
				
				dataPointer += numBoardCards;
				
				int numLastActions = Integer.parseInt(data[dataPointer]);
				
				dataPointer++;
				
				ArrayList<String> lastActions = new ArrayList<String>(numLastActions);
				for (int i = 0; i < numLastActions; i++) {
					lastActions.add(data[i+dataPointer]);
				}
				
				dataPointer += numLastActions;
				
				int numLegalActions = Integer.parseInt(data[dataPointer]);
				
				dataPointer++;
				
				ArrayList<String> legalActions = new ArrayList<String>(numLegalActions);
				for (int i = 0; i < numLegalActions; i++) {
					legalActions.add(data[i+dataPointer]);
				}
				
				dataPointer += numLegalActions;
				
				double timeAfter = Double.parseDouble(data[dataPointer]);

				return new GetActionPacket(potSize, numBoardCards, boardCards,
						numLastActions, lastActions, numLegalActions,
						legalActions, timeAfter);
				
			case "HANDOVER":
				int myStackSize = Integer.parseInt(data[1]);
				int villainStackSize = Integer.parseInt(data[2]);
				int numberBoardCards = Integer.parseInt(data[3]);
				
				int hoDataPointer = 4; // Board cards start from 4th index
				
				ArrayList<Card> endBoardCards = new ArrayList<Card>(numberBoardCards);
				for (int i = 0; i < numberBoardCards; i++) {
					endBoardCards.add(new Card(data[i+hoDataPointer]));
				}
				
				hoDataPointer += numberBoardCards;
				
				int numberLastActions = Integer.parseInt(data[hoDataPointer]);
				
				hoDataPointer++;
				
				ArrayList<String> endLastActions = new ArrayList<String>(numberLastActions);
				for (int i = 0; i < numberLastActions; i++) {
					endLastActions.add(data[i+hoDataPointer]);
				}
				
				hoDataPointer += numberLastActions;
				
				double endTimeBank = Double.parseDouble(data[hoDataPointer]);
				
				return new HandOverPacket(myStackSize, villainStackSize, numberBoardCards,
						endBoardCards, numberLastActions, endLastActions, endTimeBank);
			
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
