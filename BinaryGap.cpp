#include "stdafx.h"

#include <stdio.h>

//https://codility.com/demo/results/training26PT3B-A8B/

void showbits(unsigned int x)
{
	int i;
	for (i = (sizeof(int) * 8) - 1; i >= 0; i--) {
		unsigned int op = (1u << i);
		(x&op) ? putchar('1') : putchar('0');
	}

	printf("\n");
}

int solution(int N) {
	bool isBitSet = false;
	int maxGap = 0;
	int currGap = 0;
	for (int i = (sizeof(int) * 8) - 1; i >= 0; i--) {
		unsigned int op = (1u << i);
		if (N&op) {
			isBitSet = true;
			if (currGap > maxGap)
				maxGap = currGap;			
			currGap = 0;
		} else if (isBitSet) {
			++currGap;
		}		
	}

	return maxGap;
}



int main()
{
	int num = 0;
	num = 9;
	printf("%i has binary gap: %i\n", num, solution(num));
	
	num = 529;
	printf("%i has binary gap: %i\n", num, solution(num));

	num = 20;
	printf("%i has binary gap: %i\n", num, solution(num));

	num = 15;
	printf("%i has binary gap: %i\n", num, solution(num));

#if 0
	int j = 5225, m, n;
	printf("%d in binary \t\t ", j);
	/* assume we have a function that prints a binary string when given
	a decimal integer
	*/
	showbits(j);

	/* the loop for right shift operation */
	for (m = 0; m <= 5; m++) {
		n = j >> m;
		printf("%d right shift %d gives ", j, m);
		showbits(n);
	}
#endif
	return 0;
}
