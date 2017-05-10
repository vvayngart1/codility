#include "stdafx.h"
#include <iostream>

#include <vector>

//https://codility.com/demo/results/trainingWANW7R-JVS/
int solution(std::vector<int> &A) {	
	unsigned minDiff = (1 << 31);

	switch (A.size()) {
	case 0:
	case 1:
		minDiff = 0;
		break;
	default:
	{		
		int total = 0;
		for (auto i : A) {
			total += i;
		}

		int beforeSum = 0;
		int afterSum = 0;
		for (unsigned i = 0; i < A.size() - 1; ++i) {
			beforeSum += A[i];
			afterSum = total - beforeSum;
			int diff = afterSum - beforeSum;
			if (diff < 0)
				diff *= -1;
			
			if ((unsigned)diff < minDiff) {
				minDiff = (int)diff;
			}
		}

	}
	break;
	}

	return (int)minDiff;
}

int main() {
	{
		std::vector<int> v = { 3, 1, 2, 4, 3 };
		std::cout << "minDiff: " << solution(v) << std::endl;
	}

	{
		std::vector<int> v = { 1, 2, 3, 4, 5 };
		std::cout << "minDiff: " << solution(v) << std::endl;
	}

	{
		std::vector<int> v = { 0, 2000 };
		std::cout << "minDiff: " << solution(v) << std::endl;
	}
	
	return 0;
}
