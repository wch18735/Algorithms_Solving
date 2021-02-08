#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define idx_max 9

void dfs(int count, int n, int m, int* store) {
	/* Leaf������ ���� */
	if (count == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", store[i]);
		}
		printf("\n");
		return;
	}

	/* �ֺ� Node�� ã�� ���� */
	for (int i = 1; i <= n; i++) {
		store[count] = i;
		dfs(count + 1, n, m, store);
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	int store[idx_max] = { 0, };

	dfs(0, n, m, store);

	return 0;
}