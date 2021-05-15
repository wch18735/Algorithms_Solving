#include<iostream>

using namespace std;

long long TARGET;
long long dp[100][2];

void solution();
void input();
void init();

int main(void)
{
	solution();
	return 0;
}

void input()
{
	cin >> TARGET;
}

void init()
{
	dp[1][0] = 0;
	dp[1][1] = 1;
	dp[2][1] = 0;
	dp[2][0] = 1;
}

void solution()
{
	// input
	input();

	// init
	init();

	// dp
	if (TARGET < 3)
	{
		cout << dp[TARGET][0] + dp[TARGET][1];
	}
	else
	{
		for (int i = 3; i <= TARGET; i++)
		{
			dp[i][0] = dp[i - 1][0] + dp[i-1][1];
			dp[i][1] = dp[i - 1][0];
		}
		cout << dp[TARGET][0] + dp[TARGET][1];
	}
}