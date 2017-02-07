# M.I.T. SPAM Pokerbot 2017

#### Written by Sebastian Lopez-Cot and Pedro Mantica with help from Andrew Lu.

This pokerbot was written for the MIT Pokerbots 2017 IAP competition season. It consists of a partial Java implementation and full C++ implementation.


## Strategy Report

#### Creating the win rate tables and formulating a decision rule 	
The very first thing we needed to do was to determine the win rates of each possible hand given the five river cards shown on the table. In order to do this, we used a python library called Deuce to give each poker hand a score that determined their strength. Then for each combination of river hands, we would sort the possible hands based on their score to determine their win rate. (The reason that the score by itself wasn’t self-sufficient was because if there was, for instance, a three of a kind on the table, all hands would have a relatively high score). 
After we have calculated the win rate for the river, we proceeded to calculating the win rate for the turn by taking the average win rate of our hand over the 46 different possibilities for the last table card. Then we proceeded to formulate the decision rule based on the turn win rate table. We would consider the average win rate if we discarded the first card, the average win rate if we discarded the second card, and our win rate if we didn’t discard either. Based on this information, we would choose which option to take and the maximum win rate of the three would be used as part of the “turn before discard” win rate table. Afterwards, we used the “turn before discard” table to calculate the win rates for the flop in a similar way that we used to calculate the turn tables. Then we normalized the win rates for the flop because they were inflated because of the discard option which rose the average win rate above 50 percent. Finally, we continued this process to determine the win rates at the preflop and the decision rule at the flop. 

#### Optimizations 
First, we set the rule that both the table cards and the hand cards had to be in increasing order in order to make sure we didn’t consider two different permutations of the same of combination of cards. Then, we took advantage of suit symmetry to reduce the number of hands we needed to consider by setting the following rule on the cards on the table. #Clubs>=#Hearts>=#Diamonds>=#Spades. When actually playing the game, we could then transform the hands on the table and our hand accordingly to find their win rate. For instance, having a 3s, 4s, 5s, 7c, and 9d on the table and having a 8s and 9s in our hand is equivalent to there being a 3c,4c,5c, 7h and 9d on the table and having a 8c and 9c in our hand. This scheme help reduce the number of hands to consider by a factor of around tenfold. 
Future options 
The tables so far, to some degree, determine our win rate and discard decisions against a normal player that doesn’t discard. For this reason, they are still somewhat inaccurate and inflate our actual win rate by a considerable amount. To deal with this issue, we would first calculate the distributions of hands based on our previously formulated discard decision rule and then redo the entire process of calculating the win tables and formulating the discard decision rules.  In other words, we are formulating a decision rule that would maximize win rate against a bot that worked under our first decision rule. Then we would repeat this process around 8 times to assure that we have a more a realistic win rate table and an optimal decision rule. 


#### Strategy 
We created a basic strategy bot that bets and calls according to the win rate tables. We divided the possible win rate tables into different intervals. The bot acts differently according to which interval its win rate is placed on. Within the lower win rate intervals it would call if it has very favorable pot odds. Within the higher win rate intervals, it generally raised by an amount that grew, to some degree, inversely proportional to our probability of losing.  Most of the time we would raise unless our enemies previous raise, to some degree, indicated that he had a much stronger card.  In general the basic bot is very aggressive when it has a high win ratio, especially at the earlier streets where a very high win ratio is rarely guaranteed since many possibilities can occur that improve or worsen your current hand potential. 

#### Scrimmage optimizations 
The first thing we noticed when we participated in the scrimmage is the presence of many aggressive all in bots. To optimize against these we made our bot much tighter and especially wary of situations where the opponent would raise by an incredible amount. The next thing is that the CFR bots would generally fold when we raised by a large amount. So we reduced the amount we betted when we had great cards to encourage the CFR bots to be more open to calling our hands. 
Future options	

#### Future steps / improvements
We wanted to implement a reinforcement algorithm poker that would work based on several exploitive factors that would train with many random variations of the basic bot, that unlike our current bot, would periodically bluff. The “reinforcement signals”, that are based on the money made through different strategies, would encourage the bot optimize all to optimize the possible parameters of our basic bots.  After a while we would train the reinforcement algorithm bot with itself and, after optimizing it, test it against other bots in the scrimmage server to search for any possible optimizations.

