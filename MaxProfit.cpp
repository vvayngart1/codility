#include "stdafx.h"
#include <iostream>

#include <queue>
#include <vector>
#include <map>

int solution(std::vector<int>& A) {	
	int maxEnding = 0;
	int maxSlice = 0;

	if (A.size() > 1) {
		for (int i = 1; i < A.size(); ++i) {
			int value = A[i] - A[i - 1];
			maxEnding = std::max(0, maxEnding + value);
			maxSlice = std::max(maxSlice, maxEnding);
		}
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
		std::vector<int> A = { 23171, 21011, 21123, 21366, 21013, 21367 };
		std::cout << "Solution: " << solution(A) << std::endl;
	}
	

	return 0;
}


