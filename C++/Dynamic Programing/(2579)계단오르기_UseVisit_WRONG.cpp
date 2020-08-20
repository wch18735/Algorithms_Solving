#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>

using namespace std;

int step[300];
int visit[300];
int max_value = 0;

void dfs(int count, int n, int idx, int sum) {
	// Over range
	if (idx > n) return;

	// Leaf
	if (idx == n) {
		if (max_value < sum) max_value = sum;
		return;
	}

	// Check
	if (visit[idx] > sum) return;
	else visit[idx] = sum;

	// Not Leaf
	for (int i = 1; i <= 2; i++) {
		if (count == 1 && i == 1) continue;
		else if (count == 1 && i == 2) {
			dfs(0, n, idx + i, step[idx] + sum);
		}
		else if (count != 1 && i == 1) {
			dfs(count + 1, n, idx + i, step[idx] + sum);
		}
		else if (i != 1) {
			dfs(0, n, idx + i, step[idx] + sum);
		}
	}
}


int main(void) {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &step[i]);
		visit[i] = 0;
	}

	dfs(0, n, 0, 0);

	printf("%d", max_value);

	return 0;
}
