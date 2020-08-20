#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

using namespace std;

int dp[10001];
int grape[10001];
int before[10001];

void dfs(int idx, int n, int sum, int* total) {
	// Leaf
	if (idx == n) {
		if(*total < sum) *total = sum;
		return;
	}

	if (idx >= 2 && before[idx - 2] == 1 && before[idx - 1] == 1) dfs(idx + 1, n, sum, total);
	else {
		// ������ ����
		before[idx] = 1;
		dfs(idx + 1, n, grape[idx] + sum, total);

		// ������ ���� ����
		before[idx] = 0;
		dfs(idx + 1, n, sum, total);
	}
}

int main(void) {
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) scanf("%d", &grape[i]);

	int total = 0;
	dfs(0, n, 0, &total);

	printf("%d", total);

	return 0;
}

/*
	��ȭ���� ����Ѵ�. n�� ������ �� �ִ� ��츦
	���ǿ� ���� �б���.
*/