#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void) {
	int n;
	scanf("%d", &n);

	int grape[10000];
	int dp[10000];

	for (int i = 0; i < n; i++) {
		scanf("%d", &grape[i]);
	}

	dp[0] = grape[0];
	dp[1] = grape[0] + grape[1];
	dp[2] = max({ grape[0] + grape[1], grape[0] + grape[2], grape[1] + grape[2] });

	for (int i = 3; i < n; i++) {
		dp[i] = max({ dp[i - 3] + grape[i - 1] + grape[i],dp[i - 2] + grape[i], dp[i - 1] });
	}

	printf("%d", dp[n - 1]);

	return 0;
}

/*
	dp[idx] (idx에서 최대) 가 가능한 값
	1) dp[idx-3] + grape[idx-1] + grape[idx]
	2) dp[idx-2] + grape[idx]
	3) dp[idx-1]

	dp[idx]: idx 위치에서 마시던 안 마시던 혼합된 상태
	그 다음이 분명히 결정되는 곳 이전까지 dp 로 포함 가능
*/