#include "SPAMHelper.h"

bool SPAMHelper::to_bool(std::string s) {
	if (s == "true" || s == "True") {
		return true;
	} else if (s == "false" || s == "False") {
		return false;
	} else {
		return NULL;
	}
} 

std::string SPAMHelper::to_string(int num) {
	std::stringstream stream;
	stream << num;
	std::string s = stream.str();
	return s;
}
