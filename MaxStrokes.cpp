#include "stdafx.h"
#include <iostream>

#include <queue>
#include <vector>
#include <map>


int solution(std::vector<int> &A) {
	const int MAX_STROKES = 1000000000;
	int height = 0;
	int strokes = 0;	

	for (int i = 0; i != A.size(); ++i) {
		int value = A[i];
		if (value > height) {
			strokes += value - height;
			if (strokes > MAX_STROKES)
				return -1;
		}

		height = value;
	}

	return strokes;
}

/*
A[0]  = 1
A[1]  = 3
A[2]  = 2
A[3]  = 1
A[4]  = 2
A[5]  = 1
A[6]  = 5
A[7]  = 3
A[8]  = 3
A[9]  = 4
A[10] = 2
*/

template <typename T>
void print(const T& v) {
	for (auto i : v)
		std::cout << " " << i;
}

int main() {
	{
		std::vector<int> v = { 1, 3, 2, 1, 2, 1, 5, 3, 3, 4, 2 };
		std::cout << "result: " << solution(v) << std::endl;
	}

	return 0;
}


