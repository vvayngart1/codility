#include "stdafx.h"
#include <iostream>

#include <vector>

//https://codility.com/demo/results/trainingFCCZH8-NAR/
int solution(int X, int Y, int D) {
	return ((Y - X) / D + ((Y - X) % D > 0 ? 1 : 0));
}

int main() {
	std::cout << "jumps: " << solution(10, 85, 30) << std::endl;
	return 0;
}
