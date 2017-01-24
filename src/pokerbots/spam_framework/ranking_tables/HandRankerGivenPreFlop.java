package pokerbots.spam_framework.ranking_tables;

public class HandRankerGivenPreFlop extends HandRanker {
	
	public HandRankerGivenPreFlop() {
		this.numBoardCards = 0;
		this.tableLocation = RankingTableConfig.PREFLOP_RANKINGS_LOCATION;
	}
}
