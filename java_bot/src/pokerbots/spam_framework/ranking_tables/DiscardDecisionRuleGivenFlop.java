package pokerbots.spam_framework.ranking_tables;

public class DiscardDecisionRuleGivenFlop extends HandRanker {

	public DiscardDecisionRuleGivenFlop() {
		this.numBoardCards = 3;
		this.tableLocation = RankingTableConfig.FLOP_DECISION_RULE_LOCATION;
	}
}
