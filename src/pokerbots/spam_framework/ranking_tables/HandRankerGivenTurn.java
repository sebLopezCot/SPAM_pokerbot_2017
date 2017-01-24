package pokerbots.spam_framework.ranking_tables;

public class HandRankerGivenTurn extends HandRanker {

	public HandRankerGivenTurn() {
		this.numBoardCards = 4;
		this.tableLocation = RankingTableConfig.TURN_RANKINGS_LOCATION;
	}
}
