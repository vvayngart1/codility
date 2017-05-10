#include "stdafx.h"
#include <iostream>

#include <vector>

// https://codility.com/demo/results/training2BSRCK-FEM/
std::vector<int> solution(int N, std::vector<int> &A) {
	std::vector<int> counter;
	counter.resize(N);

	int maxCounter = 0;	
	int maxCounterToAdd = 0;	
	for (unsigned i = 0; i < A.size(); ++i) {
		int v = A[i];
		if (v <= N) {
			int& c = counter[v-1];
			if (c < maxCounterToAdd)
				c = maxCounterToAdd;
			++c;			
			if (c > maxCounter)
				maxCounter = c;
		} else {
			maxCounterToAdd = maxCounter;			
		}
	}

	if (0 < maxCounterToAdd) {
		for (unsigned i = 0; i < counter.size(); ++i) {
			if (counter[i] < maxCounterToAdd)
				counter[i] = maxCounterToAdd;
		}
	}	

	return counter;
}

template <typename T>
void print(const T& v) {
	for (auto i : v)
		std::cout << " " << i;
}

int main() {
	{
		std::vector<int> v = { 3, 4, 4, 6, 1, 4, 4 };
		std::cout << "counters:";
		print(solution(5, v));
		std::cout << std::endl;
	}

	{
		std::vector<int> v = { 3, 4, 4, 6, 1, 4, 7, 4 };
		std::cout << "counters:";
		print(solution(5, v));
		std::cout << std::endl;
	}
	
	return 0;
}


