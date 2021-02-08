#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

#define MAXNUM 1000000

using namespace std;

int min_value(int a, int b, int c);

int main(void) {
	int n;
	scanf("%d", &n);
	
	vector <int> dp(MAXNUM);
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i <= n; i++) {
		if (i % 2 == 0 && i % 3 == 0) dp[i] = min_value(dp[i - 1] + 1, dp[i / 2] + 1, dp[i / 3] + 1);
		else if(i % 2 == 0 && i % 3 != 0) dp[i] = min(dp[i - 1] + 1, dp[i / 2] + 1);
		else if (i % 2 != 0 && i % 3 == 0) dp[i] = min(dp[i - 1] + 1, dp[i / 3] + 1);
		else dp[i] = dp[i - 1] + 1;
	}

	printf("%d", dp[n]);

	return 0;
}

int min_value(int a, int b, int c) {
	if (a > b) {
		if (c > b) return b;
		else return c;
	}
	else {
		if (c > a) return a;
		else return c;
	}
}

/*
	1. int 형 3개 비교하는 것은 직접 짜자
	2. int dp[maxnum] 은 25만, vector<int>는 1억 넘게 가능하다
	3. 점화식을 해결하는 dp 문제는 for 문으로 진행하자
*/