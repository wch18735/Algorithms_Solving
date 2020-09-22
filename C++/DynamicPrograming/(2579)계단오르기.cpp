#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

using namespace std;

int dp[301];
int step[301];

int main(void) {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &step[i]);
	}

	dp[0] = 0;
	dp[1] = step[1];
	dp[2] = max(step[1] + step[2], step[2]);

	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 3] + step[i - 1] + step[i], dp[i - 2] + step[i]);
	}

	printf("%d", dp[n]);

	return 0;
}

/*
	점화식을 세우면
	어떠한 n 칸에 도달했을 때,
	도달할 수 있는 경우는 두 가지 중 하나이다.
	1) n-3 칸에서 2칸 이동 후 1칸 이동
	2) n-2 칸에서 2칸 한 번에 이동

	즉,
	dp[n] = dp[n-3] + array[n-1] + array[n]
	dp[n] = dp[n-2] + array[n]

	※ 1칸을 세 번 이상 붙는 건 불가능하기 때문에
*/