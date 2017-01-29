#ifndef SPAM_HELPER_H
#define SPAM_HELPER_H 

#include <string>
#include <sstream>

class SPAMHelper
{
public:
	static std::string to_string(int num);
	static bool to_bool(std::string s);
};

#endif