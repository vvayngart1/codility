#include "stdafx.h"
#include <iostream>

#include <iterator>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <string>
#include <ctype.h>


/*
int solution(Tree T, int* history, int to_here) {
if (history[T.x] == 0)
++to_here
++history[T.x]

left = solution(T.l, history, to_here);
right = solution(T.r, history, to_here);

to_here = max(left, right);

--history[T.x];

return to_here;
}
int solution(Tree T) {
return solution(T, new int[N], 0);
}
int solution(tree* T) {
return solution(T, new int[N], 0);
}

int solution(tree* T, int* history, int to_here) {
if (T == null)
return to_here;

if (history[T->x] == 0)
++to_here
++history[T->x]

left = solution(T->l, history, to_here);
right = solution(T->r, history, to_here);

to_here = max(left, right);

--history[T->x];

return to_here;
}

*/

//https://codility.com/demo/results/trainingY73DCE-TVC/
int solution(std::vector<int>& A) {
	std::deque<int> stack;	
	int blocks = 0;
	
	for (int i = 0; i < A.size(); ++i) {
		int curr = A[i];
		while (!stack.empty() && stack.front() > curr) {			
			stack.pop_front();			
		}

		if (stack.empty() || stack.front() < curr) {
			stack.push_front(curr);
			++blocks;
		}
	}	
	
	return blocks;
}

template <typename T>
void print(const T& v) {
	for (auto i : v)
		std::cout << " " << i;
}

int main() {
	{
		std::vector<int> v = { 8, 8, 5, 7, 9, 8, 7, 4, 8 };
		std::cout << solution(v) << std::endl;
	}

	{
		std::vector<int> v = { 3, 2, 1 };
		std::cout << solution(v) << std::endl;
	}

	return 0;
}


