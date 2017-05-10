#include "stdafx.h"
#include <iostream>

#include <queue>
#include <vector>
#include <map>
#include <string>
#include <ctype.h>


std::vector<int> solution(std::string& S, std::vector<int>& P, std::vector<int>& Q) {
	std::vector<int> result;
	result.resize(P.size());

	std::vector<int> valuesA;
	std::vector<int> valuesC;
	std::vector<int> valuesG;	

	valuesA.resize(S.size()+1);
	valuesC.resize(S.size()+1);
	valuesG.resize(S.size()+1);

	int sumA = 0;
	int sumC = 0;
	int sumG = 0;
	for (int i = 0; i < S.length(); ++i) {
		char c = S[i];
		switch (c) {
		case 'A':
			sumA += 1;			
			break;
		case 'C':
			sumC += 1;			
			break;
		case 'G':
			sumG += 1;			
			break;		
		}

		valuesA[i + 1] = sumA;
		valuesC[i + 1] = sumC;
		valuesG[i + 1] = sumG;
	}	
	
	for (unsigned i = 0; i < P.size(); ++i) {
		result[i] = 4;

		int b = P[i];
		int e = Q[i];

		if ((valuesA[e + 1]) - valuesA[b] > 0)
			result[i] = 1;
		else if ((valuesC[e + 1]) - valuesC[b] > 0)
			result[i] = 2;
		else if ((valuesG[e + 1]) - valuesG[b] > 0)
			result[i] = 3;		
	}

	return result;
}

template <typename T>
void print(const T& v) {
	for (auto i : v)
		std::cout << " " << i;
}

int main() {
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

	return 0;
}


