#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
	int n, k;
	int dp[10001] = { 0, };

	cin >> n >> k;

	vector<int> coins(n);
	fill(coins.begin(), coins.end(), 0);

	dp[0] = 1;

	for (int i = 0; i < n; i++)
	{
		cin >> coins[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (j - coins[i] >= 0) dp[j] = dp[j] + dp[j - coins[i]];
		}
	}

	cout << dp[k];

	return 0;
}