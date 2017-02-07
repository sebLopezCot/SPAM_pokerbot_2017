package pokerbots.spam_framework.ranking_tables;


public class HandRankerGivenRiver extends HandRanker {

	public HandRankerGivenRiver(){
		this.numBoardCards = 5;
		this.tableLocation = RankingTableConfig.RIVER_RANKINGS_LOCATION;
	}
	
}
