#include "stdafx.h"
#include <iostream>

#include <queue>
#include <vector>
#include <map>
#include <string>
#include <ctype.h>


std::string expandString(const std::string& source) {
	std::string result;
	std::string numberString;

	for (auto c : source) {
		if (isalpha(c)) {
			if (!numberString.empty()) {
				long n = ::atol(numberString.c_str());
				while (--n >= 0)
					result.push_back('*');
				numberString.clear();
			}
			result.push_back(c);
		} else {
			numberString.push_back(c);
		}
	}

	if (!numberString.empty()) {
		long n = ::atol(numberString.c_str());
		while (--n >= 0)
			result.push_back('*');
		numberString.clear();
	}

	return result;
}

bool solution(const std::string &S, const std::string &T) {
	std::string expandedS = expandString(S);
	std::string expandedT = expandString(T);

	if (expandedS.length() != expandedT.length())
		return false;

	for (unsigned i = 0; i < expandedS.length(); ++i) {
		auto c1 = expandedS[i];
		auto c2 = expandedT[i];
		if (c1 != c2) {
			if ('*' != c1 && '*' != c2)
				return false;
		}
	}

	return true;
}

int main() {
	std::cout << solution("A2Le", "2pL1") << std::endl;
	std::cout << solution("a10", "10a") << std::endl;
	std::cout << solution("ba1", "1Ad") << std::endl;
	std::cout << solution("3x2x", "8") << std::endl;


	return 0;
}


