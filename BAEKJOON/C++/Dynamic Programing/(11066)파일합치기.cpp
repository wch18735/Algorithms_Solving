#include<iostream>
#include<algorithm>

using namespace std;

int dp[501][501];
int script_data[501];
int script_sum[501];

int T, K;
const int MAX_VAL = 500000000;

void solution();

int main(void)
{
	cin >> T;

	for (int test_case = 0; test_case < T; test_case++)
	{
		solution();
	}

	return 0;
}

int check_cost(int from, int to)
{
	// 해당 범위의 최소 사용된 값이 정해진 경우
	if (dp[from][to] != -1) return dp[from][to];

	// 같은 경우
	if (from == to)
	{
		dp[from][to] = 0;
		return dp[from][to];
	}

	// 하나 차이
	if (from + 1 == to)
	{
		dp[from][to] = script_data[from] + script_data[to];
		return dp[from][to];
	}

	// 최소 값 찾기
	int res = MAX_VAL;
	for (int i = from; i < to; i++)
	{
		res = min(check_cost(from, i) + check_cost(i + 1, to), res);
	}

	dp[from][to] = res + script_sum[to] - script_sum[from - 1];
	return dp[from][to];
}

void input()
{
	cin >> K;
	for (int i = 1; i <= K; i++)
	{
		cin >> script_data[i];
		script_sum[i] = script_sum[i - 1] + script_data[i];
	}
}

void init()
{
	fill(&dp[0][0], &dp[500][501], -1);
}

void solution()
{
	// 초기화
	init();

	// 입력
	input();

	// 계산
	cout << check_cost(1, K) << '\n';
}