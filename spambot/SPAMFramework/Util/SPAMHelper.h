#ifndef SPAM_HELPER_H
#define SPAM_HELPER_H 

#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>

class SPAMHelper
{
public:
	static std::string to_string(int num);
	static bool to_bool(std::string s);

	static double rand();
	static std::vector<std::string> split(std::string str, char delimiter);
};

#endif
