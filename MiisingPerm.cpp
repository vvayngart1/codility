#include "stdafx.h"
#include <iostream>

#include <vector>

int solution(std::vector<int> &A) {
	int sum = 0;
	for (int i = 0; i < A.size(); ++i) {
		sum += A[i];
	}

	int sum2 = ((A.size())*(A.size() + 1)) / 2;
	return (sum2 - (sum - (A.size() + 1)));
}

int main() {
	{
		std::vector<int> v = { 2, 3, 1, 5 };
		std::cout << "missing: " << solution(v) << std::endl;
	}

	{
		std::vector<int> v;
		for (int i = 0; i < 100000; ++i) {
			if (i != 9)
				v.push_back(i+1);
		}

		v.push_back(100001);

		std::cout << "missing: " << solution(v) << std::endl;
	}
	return 0;
}
