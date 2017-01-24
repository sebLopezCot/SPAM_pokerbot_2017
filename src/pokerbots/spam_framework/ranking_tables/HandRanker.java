package pokerbots.spam_framework.ranking_tables;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

import pokerbots.spam_framework.Card;

public abstract class HandRanker {
	
	private int numHand = 2;
	public int numBoardCards;
	public String tableLocation;
	
	private boolean acceptableNumberOfCards(int numHand, int numBoardCards) {
		return (numHand == this.numHand && numBoardCards == this.numBoardCards);
	}
	private int parseRanking(String handString, String boardCardString) 
			throws FileNotFoundException, IOException {
		
		String fileLocation = (numBoardCards > 0) ? boardCardString : RankingTableConfig.PREFLOP_FILE;
		FileReader fr = new FileReader(tableLocation + fileLocation);
		BufferedReader br = new BufferedReader(fr);

		int rank = -1;
		String line;
		while(( line = br.readLine() ) != null && rank == -1) {
			String[] handAndRank = line.split(" ");
			
			if(handAndRank[0].equals(handString)) {
				rank = Integer.parseInt(handAndRank[1]);
			}
		}
		
		br.close();
		
		return rank;
	}

	private String[] mapToCompressionScheme(int[] handCardsAsNums, int[] boardCardsAsNums) {
		ArrayList<Integer[]> numOfEachSuit = new ArrayList<Integer[]>(4);
		
		// Init suit array
		for (int i=0; i < 4; i++){
			Integer[] temp = { 0 , i };
			numOfEachSuit.add(temp);
		}
		
		// Count freq of each suit
		for (int n = 0; n < boardCardsAsNums.length; n++) {
			int boardCard = boardCardsAsNums[n];			
			numOfEachSuit.get(boardCard%4)[0]++;
		}
		
		// Sort based on freq.
		Collections.sort(numOfEachSuit, new Comparator<Integer[]>() {

			@Override
			public int compare(Integer[] self, Integer[] other) {
				int s = self[0];
				int o = other[0];
				
				if (s == o) {
					return 0;
				} else {
					return (s > o) ? 1 : -1;
				}
			}
		});
		
		// Reverse order
		Collections.reverse(numOfEachSuit);
		
		// Transforming old suits into new ones
		ArrayList<Integer> newBoardCards = new ArrayList<Integer>();
		
		for (int boardCard : boardCardsAsNums) {
			int cardSuit = 0;
			for (int i=0; i < 4; i++) {
				if (boardCard % 4 == numOfEachSuit.get(i)[1]){
					cardSuit = i;
					break;
				}
			}
			
			// Note: Using integer division on purpose
			newBoardCards.add(boardCard/4 * 4 + cardSuit);
		}
		
		ArrayList<Integer> newHandCards = new ArrayList<Integer>();
		
		for (int handCard : handCardsAsNums) {
			int cardSuit = 0;
			for (int i=0; i < 4; i++) {
				if (handCard % 4 == numOfEachSuit.get(i)[1]){
					cardSuit = i;
					break;
				}
			}
			
			// Note: Using integer division on purpose
			newHandCards.add(handCard/4 * 4 + cardSuit);
		}
		
		// Sorted arrays
		Collections.sort(newBoardCards);
		Collections.sort(newHandCards);
		
		// Convert to string arrays
		String newHandString = "";
		for (int i=0; i<newHandCards.size(); i++){
			newHandString += newHandCards.get(i).toString() + ",";
		}
		if (numHand > 0) newHandString.substring(0, newHandCards.size()-1);

		String newBoardCardString = "";
		for (int i=0; i<newBoardCards.size(); i++){
			newBoardCardString += newBoardCards.get(i).toString() + ",";
		}
		if(numBoardCards > 0) newBoardCardString.substring(0, newBoardCards.size()-1);
		
		return new String[] { newHandString, newBoardCardString } ;
		
	}
	
	public int getRanking(Card[] hand, Card[] boardCards) {
		int rank = -1;
		
		try {
			if (acceptableNumberOfCards(hand.length, boardCards.length)) {
				
				int[] handCardsAsNums = new int[hand.length];
				for (int i = 0; i < hand.length; i++){
					handCardsAsNums[i] = hand[i].toNumber();
				}
				
				int[] boardCardsAsNums = new int[boardCards.length];
				for (int i = 0; i < boardCards.length; i++){
					boardCardsAsNums[i] = boardCards[i].toNumber();
				}
				
				String[] handAndBoardCardsStrings = 
						mapToCompressionScheme(handCardsAsNums, boardCardsAsNums);
				
				rank = parseRanking(handAndBoardCardsStrings[0], 
						handAndBoardCardsStrings[1]);
				
			} else {
				throw new Exception("HAND OR BORAD CARDS NOT THE RIGHT LENGTH");
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
		
		return rank;
	}
}
