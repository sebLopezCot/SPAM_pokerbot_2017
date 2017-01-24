package pokerbots.spam_framework.ranking_tables;


public class HandRankerGivenFlop extends HandRanker {

	public HandRankerGivenFlop(){
		this.numBoardCards = 3;
		this.tableLocation = RankingTableConfig.FLOP_RANKINGS_LOCATION;
	}
	
}

