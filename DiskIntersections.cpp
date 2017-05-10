#include "stdafx.h"
#include <iostream>

#include <queue>
#include <vector>
#include <map>
#include <string>
#include <ctype.h>

#include <set>

int solution(std::vector<int> &A) {
	std::set<int> begins;
	std::set<int> ends;






	std::vector<int> a_begins; // how many discs begins at this point
	a_begins.resize(A.size(), 0);
	std::vector<int> a_ends; // how many discs ends at this point
	a_ends.resize(A.size(), 0);

	for (size_t idx = 0; idx < A.size(); ++idx)
	{
		size_t val = static_cast<size_t>(A[idx]);
		size_t idx_begin = val > idx ? 0 : idx - val;
		++a_begins[idx_begin];
		size_t idx_end = val > (A.size() - idx - 1) ? A.size() - 1 : idx + val;
		++a_ends[idx_end];
	}

	int cnt = 0;
	int ret_val = 0;
	for (size_t idx = 0; idx < A.size(); ++idx)
	{
		if (a_begins[idx] != 0)
		{
			// Every new discs intersects with every existing
			ret_val += cnt * a_begins[idx];
			// New discs intersect with each other (combinatorics)
			int inter_cnt = a_begins[idx] - 1;
			ret_val += inter_cnt * (inter_cnt + 1) / 2;
			if (inter_cnt > 10000 || ret_val > 10000000)
			{
				return -1;
			}
		}
		cnt += a_begins[idx];
		cnt -= a_ends[idx];
	}

	return ret_val;
}

template <typename T>
void print(const T& v) {
	for (auto i : v)
		std::cout << " " << i;
}

int main() {
	std::vector<int> v = { 1, 5, 2, 1, 4, 0 };
	std::cout << solution(v) << std::endl;

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


