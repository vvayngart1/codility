#include "stdafx.h"
#include <iostream>

#include <queue>
#include <vector>
#include <map>

#include <limits.h>

int solution(std::vector<int>& A) {
	int maxEnding = 0;
	int maxSlice = INT_MIN;
	
	for (int i = 0; i < (int)A.size(); ++i) {
		maxEnding = (maxEnding < 0) ? A[i] : maxEnding + A[i];
		maxSlice = std::max(maxSlice, maxEnding);
	}	

	return maxSlice;
}

template <typename T>
void print(const T& v) {
	for (auto i : v)
		std::cout << " " << i;
}

int main() {
	{
		std::vector<int> A = { 3, 2, -6, 4, 0 };
		std::cout << "Solution: " << solution(A) << std::endl;
	}

	{
		std::vector<int> A = { -10 };
		std::cout << "Solution: " << solution(A) << std::endl;
	}

	{
		std::vector<int> A = { -2, 3 };
		std::cout << "Solution: " << solution(A) << std::endl;
	}
	

	return 0;
}


