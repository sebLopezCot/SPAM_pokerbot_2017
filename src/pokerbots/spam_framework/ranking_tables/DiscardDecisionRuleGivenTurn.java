package pokerbots.spam_framework.ranking_tables;

public class DiscardDecisionRuleGivenTurn extends HandRanker {

	public DiscardDecisionRuleGivenTurn() {
		this.numBoardCards = 4;
		this.tableLocation = RankingTableConfig.TURN_DECISION_RULE_LOCATION;
	}
}
