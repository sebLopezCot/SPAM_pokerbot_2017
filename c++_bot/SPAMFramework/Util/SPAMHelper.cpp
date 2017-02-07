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

double SPAMHelper::rand() {
	return (((double) std::rand()) / RAND_MAX);
}

std::vector<std::string> SPAMHelper::split(std::string str, char delimiter) {
	std::vector<std::string> internal;
	std::stringstream ss(str);
	std::string tok;

	while(std::getline(ss, tok, delimiter)) {
		internal.push_back(tok);
	}

	return internal;
}
