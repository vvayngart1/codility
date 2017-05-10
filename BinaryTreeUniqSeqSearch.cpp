#include "stdafx.h"
#include <iostream>

#include <queue>
#include <vector>
#include <map>

struct tree {
	int x;
	tree* l;
	tree* r;
};

int countNodes(tree* T, int count = 0) {
	if (nullptr == T)
		return count;

	++count;
	count = countNodes(T->l, count);
	count = countNodes(T->r, count);

	return count;
}


int solution(tree* T, std::vector<int>& history, int toHere, int parentValue) {
	if (nullptr == T)
		return toHere;

	if (0 == history[T->x])
		++toHere;
	++history[T->x];
	
	int left = solution(T->l, history, history[T->x] == parentValue ? 1 : toHere, T->x);
	int right = solution(T->r, history, history[T->x] == parentValue ? 1 : toHere, T->x);

	int a = left < right ? right : left;
	toHere = a < toHere ? toHere : a;

	--history[T->x];

	return toHere;
}

int solution(tree* T) {
	int n = countNodes(T);
	std::vector<int> history;
	history.resize(n+1);

	return solution(T, history, 0, -1);
}

template <typename T>
void print(const T& v) {
	for (auto i : v)
		std::cout << " " << i;
}

int main() {
	{
		tree* t = new tree();
		t->x = 4;

		t->l = new tree();
		t->l->x = 5;

		t->l->l = new tree();
		t->l->l->x = 4;
		t->l->r = nullptr;

		t->l->l->l = new tree();
		t->l->l->l->x = 5;
		t->l->l->r = nullptr;

		t->r = new tree();
		t->r->x = 6;

		t->r->l = new tree();
		t->r->l->x = 1;

		t->r->r = new tree();
		t->r->r->x = 3;
		
		std::cout << "result: " << solution(t) << std::endl;
	}

	{
		tree* t = new tree();
		t->x = 1;

		t->l = new tree();
		t->l->x = 2;

		t->l->l = new tree();
		t->l->l->x = 1;
		t->l->r = nullptr;

		t->l->l->l = new tree();
		t->l->l->l->x = 2;
		t->l->l->r = nullptr;

		std::cout << "result: " << solution(t) << std::endl;
	}

	{
		tree* t = new tree();
		t->x = 1;

		t->l = new tree();
		t->l->x = 2;

		t->l->l = new tree();
		t->l->l->x = 2;
		t->l->r = nullptr;

		t->l->l->l = new tree();
		t->l->l->l->x = 3;
		t->l->l->r = nullptr;

		std::cout << "result: " << solution(t) << std::endl;
	}

	return 0;
}


