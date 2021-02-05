#include<iostream>
#define DEVIDOR 10007
#define ONEBRICK 0
#define TWOBRICK_HORIZONTAL 1
#define TWOBRICK_VERTICAL 2

using namespace std;

int dp[1001][3];
int TARGET;

void input();
void init();
void solution();

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
	// n == 1
	dp[1][ONEBRICK] = 1;
	dp[1][TWOBRICK_HORIZONTAL] = 0;
	dp[1][TWOBRICK_VERTICAL] = 0;

	// n == 2
	dp[2][ONEBRICK] = 1;
	dp[2][TWOBRICK_HORIZONTAL] = 1;
	dp[2][TWOBRICK_VERTICAL] = 1;
}

void solution()
{
	input();
	init();
	if (TARGET < 3)
	{
		cout << dp[TARGET][ONEBRICK] + dp[TARGET][TWOBRICK_HORIZONTAL] + dp[TARGET][TWOBRICK_VERTICAL];
	}
	else
	{
		for (int i = 3; i <= TARGET; i++)
		{
			dp[i][ONEBRICK] = (dp[i - 1][ONEBRICK] + dp[i-1][TWOBRICK_HORIZONTAL] + dp[i-1][TWOBRICK_VERTICAL]) % DEVIDOR;
			dp[i][TWOBRICK_HORIZONTAL] = (dp[i-2][ONEBRICK] + dp[i - 2][TWOBRICK_HORIZONTAL] + dp[i - 2][TWOBRICK_VERTICAL]) % DEVIDOR;
			dp[i][TWOBRICK_VERTICAL] = (dp[i - 2][ONEBRICK] + dp[i - 2][TWOBRICK_HORIZONTAL] + dp[i - 2][TWOBRICK_VERTICAL]) % DEVIDOR;
		}
		cout << (dp[TARGET][ONEBRICK] + dp[TARGET][TWOBRICK_HORIZONTAL] + dp[TARGET][TWOBRICK_VERTICAL]) % DEVIDOR;
	}
}
