#include "stdafx.h"
#include <iostream>

#include <queue>
#include <vector>
#include <map>


int solution(std::vector<int>& A) {
	int index = -1;
	int size = 0;
	int value = 0;

	for (int i = 0; i < (int)A.size(); ++i) {
		if (0 == size) {
			index = i;
			value = A[i];
			++size;
		} else if (A[i] == value) {
			++size;
		} else {
			--size;
		}
	}

	if (size <= 0)
		return -1;

	int count = 0;
	for (auto v : A) {
		if (value == v)
			++count;
	}

	if (count > ((int)A.size() / 2))
		return index;

	return -1;
}

template <typename T>
void print(const T& v) {
	for (auto i : v)
		std::cout << " " << i;
}

int main() {
	{
		std::vector<int> A = { 3, 4, 3, 2, 3, -1, 3, 3 };		
		std::cout << "Solution: " << solution(A) << std::endl;
	}
	

	return 0;
}


