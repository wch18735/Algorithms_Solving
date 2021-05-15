#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAXNUM 1000000000

int main(void) {
	int n;
	scanf("%d", &n);

	int dp[101][10];
	for (int i = 0; i < 10; i++) dp[0][i] = 1;
	dp[0][0] = 0;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) dp[i][j] = dp[i - 1][j+1];
			else if (j == 9) dp[i][j] = dp[i - 1][j-1];
			else {
				dp[i][j] = (dp[i - 1][j + 1] + dp[i - 1][j - 1]) % MAXNUM;
			}
		}
	}

	int total = 0;
	for (int i = 0; i < 10; i++) {
		total = (total + dp[n-1][i]) % MAXNUM;
		// 위 부분에서 int type을 초과할 수 있으므로 modulo 연산을 진행
	}

	printf("%u", total % MAXNUM);

	return 0;
}