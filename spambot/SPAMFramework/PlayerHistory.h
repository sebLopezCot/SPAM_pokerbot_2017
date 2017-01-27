#ifndef PLAYER_HISTORY_H
#define PLAYER_HISTORY_H 

#include <string>
#include <vector>

class PlayerHistory
{
public:
	PlayerHistory();

	std::vector<std::string> GetLastActions();

	void SetLastActions(std::vector<std::string> last_actions);

private:
	std::vector<std::string> m_last_actions;
};

#endif