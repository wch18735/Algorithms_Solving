#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAXNUM 500000

int triangle[500][500];
int visit[500][500];
int max = 0;

void dfs(int count,int idx, int N, int sum) {
	// Leaf
	if (count == N) {
		if (sum > max) max = sum;
		return;
	}

	// 이전까지 어떤 값이었는가에 관계없이
	// 현재 도달했을 때, 해당 값이 기준에 미달하면 이후는 계산하지 않는다
	if (visit[count][idx] > triangle[count][idx] + sum) return;
	else visit[count][idx] = triangle[count][idx] + sum;
	
	// Not Leaf
	for (int i = 0; i < 2; i++) {
		dfs(count + 1, idx + i, N, visit[count][idx]);
	}
}

int main(void) {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			scanf("%d", &triangle[i][j]);
			visit[i][j] = 0;
		}
	}

	dfs(0, 0, n, 0);

	printf("%d", max);

	return 0;
}