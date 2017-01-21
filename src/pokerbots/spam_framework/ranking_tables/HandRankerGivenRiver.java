package pokerbots.spam_framework.ranking_tables;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

import pokerbots.spam_framework.Card;

public class HandRankerGivenRiver {

	private static String RIVER_RANKINGS_LOCATION = "ranking_tables/river_rankings/";
	
	public static int parseRanking(String handString, String riverString) 
			throws FileNotFoundException, IOException {
		
		FileReader fr = new FileReader(RIVER_RANKINGS_LOCATION + riverString);
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
	
	public static int getRanking(Card[] hand, Card[] river) {
		int rank = -1;
		
		try {
			if (hand.length == 2 && river.length == 5) {
				
				String[] handCardIds = new String[2];
				for (int i = 0; i < hand.length; i++){
					handCardIds[i] = hand[i].toNumericString();
				}
				
				String[] riverCardIds = new String[5];
				for (int i = 0; i < river.length; i++){
					riverCardIds[i] = river[i].toNumericString();
				}
				
				rank = parseRanking(String.join(",", handCardIds),
						String.join(",", riverCardIds));
				
			} else {
				throw new Exception("HAND OR RIVER NOT THE RIGHT LENGTH");
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
		
		return rank;
	}
}
