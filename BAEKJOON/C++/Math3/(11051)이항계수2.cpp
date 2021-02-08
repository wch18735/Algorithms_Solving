#include <iostream>

using namespace std;

int dp[1001][1001];

int main(void) {

	dp[0][0] = 1;
	dp[1][0] = 1;
	dp[1][1] = 1;

	int n, k;
	cin >> n >> k;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= i && j <= k; j++) {
			if (j == 0) dp[i][j] = dp[i - 1][j] % 10007;
			else dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1])%10007;
		}
	}

	cout << dp[n][k];

	return 0;
}

/*
	Use Pascal Triangle
*/