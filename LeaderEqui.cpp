#include "stdafx.h"
#include <iostream>

#include <queue>
#include <vector>
#include <map>

int solution(std::vector<int>& A) {	
	int size = 0;
	int value = 0;

	for (int i = 0; i < (int)A.size(); ++i) {
		if (0 == size) {			
			value = A[i];
			++size;
		} else if (A[i] == value) {
			++size;
		} else {
			--size;
		}
	}

	if (size <= 0)
		return 0;

	int count = 0;
	for (auto v : A) {
		if (value == v)
			++count;
	}

	if (count <= ((int)A.size() / 2))
		return 0;

	int eqCount = 0;
	int leaderCountSoFar = 0;
	for (int i = 0; i < (int)A.size(); ++i) {
		if (A[i] == value)
			++leaderCountSoFar;

		if ((leaderCountSoFar > (i + 1) / 2) && ((count - leaderCountSoFar) > ((int)A.size() - (i + 1)) / 2))
			++eqCount;			
	}

	return eqCount;
}

template <typename T>
void print(const T& v) {
	for (auto i : v)
		std::cout << " " << i;
}

int main() {
	{
		std::vector<int> A = { 4, 3, 4, 4, 4, 2 };		
		std::cout << "Solution: " << solution(A) << std::endl;
	}
	

	return 0;
}


