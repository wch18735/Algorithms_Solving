#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAXNUM 1000000
int min = MAXNUM;
int numArr[1000][3];
int visitArr[1000][3];

void dfs(int count, int N, int idx, int sum) {
	// If sum is larger than minimum, prunnning
	if (sum > min) return;
	
	// Leaf
	if (count == N) {
		if (min > sum) min = sum;
		return;
	}

	// Not Leaf
	for (int i = 0; i < 3; i++) {
		// Skip R or G or B index
		if (idx == i) continue;
		
		// If previous visit was smallar than now, skip
		// It use previous result, so dynamic programming with backtracking
		if (visitArr[count][i] < numArr[count][i] + sum) continue;
		else visitArr[count][i] = numArr[count][i] + sum;
		
		// next dfs
		dfs(count + 1, N, i, visitArr[count][i]);
	}
}


int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &numArr[i][0], &numArr[i][1], &numArr[i][2]);
		visitArr[i][0] = MAXNUM; visitArr[i][1] = MAXNUM; visitArr[i][2] = MAXNUM;
	}

	dfs(0, N, -1, 0);

	printf("%d ", min);

	return 0;
}

/*
backtracking: Pruning
dynamic programming:Use previous value
*/