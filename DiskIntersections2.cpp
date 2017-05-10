#include "stdafx.h"
#include <iostream>

#include <iterator>
#include <queue>
#include <vector>
#include <map>
#include <string>
#include <ctype.h>


#include <algorithm>
int solution(std::vector<int>& A) {
	std::vector<int64_t> begins;
	std::vector<int64_t> ends;

	const unsigned size = A.size();

	begins.resize(A.size());
	ends.resize(A.size());

	for (unsigned i = 0; i < size; ++i) {
		begins[i] = (int)i - A[i];
		ends[i] = A[i] + i;
	}

	std::sort(begins.begin(), begins.end());
	std::sort(ends.begin(), ends.end());

	int nonIntersections = 0;
	for (unsigned i = 0; i < size; ++i) {		
		nonIntersections += std::distance(std::upper_bound(begins.begin(), begins.end(), ends[i]), begins.end());		
	}

	int intersections = (size * (size - 1)) / 2 - nonIntersections;
	if (intersections > 10000000)
		return -1;

	return intersections;
}

template <typename T>
void print(const T& v) {
	for (auto i : v)
		std::cout << " " << i;
}

int main() {
	std::vector<int> v = { 1, 2, 3, 3, 4, 6, 7 };
	/*
	int i = std::distance(v.begin(), std::lower_bound(v.begin(), v.end(), 5));
	std::cout << std::distance(v.begin(), std::lower_bound(v.begin(), v.end(), 5)) << std::endl;
	std::cout << std::distance(v.begin(), std::lower_bound(v.begin(), v.end(), 6)) << std::endl;
	std::cout << std::distance(v.begin(), std::lower_bound(v.begin(), v.end(), 0)) << std::endl;

	std::cout << std::distance(std::upper_bound(v.begin(), v.end(), 0), v.end()) << std::endl;
	std::cout << std::distance(std::upper_bound(v.begin(), v.end(), 3), v.end()) << std::endl;
	std::cout << std::distance(std::upper_bound(v.begin(), v.end(), 6), v.end()) << std::endl;
	std::cout << std::distance(std::upper_bound(v.begin(), v.end(), 7), v.end()) << std::endl;
	std::cout << std::distance(std::upper_bound(v.begin(), v.end(), 8), v.end()) << std::endl;	
	*/
	{
		std::vector<int> v = { 1, 5, 2, 1, 4, 0 };
		std::cout << solution(v) << std::endl;
	}

	{
		std::vector<int> v = { 1, 2147483647, 0 };		
		std::cout << solution(v) << std::endl;
	}

	{		
		std::vector<int> v = { 1, 214, 0 };
		std::cout << solution(v) << std::endl;
	}

	/*
	{
		std::string S = "CAGCCTA";
		std::vector<int> P = { 2, 5, 0 };
		std::vector<int> Q = { 4, 5, 6 };

		std::cout << "solution:";
		print(solution(S, P, Q));
		std::cout << std::endl;
	}

	{
		std::string S = "AC";
		std::vector<int> P = { 0, 0, 1 };
		std::vector<int> Q = { 0, 1, 1 };

		std::cout << "solution:";
		print(solution(S, P, Q));
		std::cout << std::endl;
	}
	*/
	return 0;
}


