#ifndef CARD_H
#define CARD_H 

#include <iostream>
#include <string>
#include <vector>
#include <map>

class Card
{
public:
	Card(std::string id);

	static void Init();
	static std::vector<std::string> GetCardList();
	static bool IsCard(std::string card_id);

	std::string ToString();
	int ToNumber();

private:
	std::string m_id;
	static const map<std::string, int> card_id_to_number;
};

#endif