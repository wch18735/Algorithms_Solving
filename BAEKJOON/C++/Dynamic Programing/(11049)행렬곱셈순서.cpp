#include<iostream>
#include<algorithm>

using namespace std;

int N;

typedef unsigned long long ll;

struct MAT {
	ll row;
	ll col;
	ll value = -1;
};

struct SHAPE {
	ll row;
	ll col;
};

MAT dp[501][501];
SHAPE shp[501];

ll solution(int from, int to);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	int r, c;
	for (int i = 1; i <= N; i++)
	{
		cin >> r >> c;
		shp[i].row = r;
		shp[i].col = c;
	}

	cout << solution(1, N);

	return 0;
}

ll solution(int from, int to)
{
	// 최소 값 존재할 때
	if (dp[from][to].value != -1) return dp[from][to].value;

	// 해당 행렬
	if (from == to)
	{
		dp[from][to].row = shp[from].row;
		dp[from][to].col = shp[to].col;
		dp[from][to].value = 0;
		return dp[from][to].value;
	}

	// 인접행렬 곱
	if (from + 1 == to)
	{
		dp[from][to].row = shp[from].row;
		dp[from][to].col = shp[to].col; 
		dp[from][to].value = shp[from].row * shp[from].col * shp[to].col;
		return dp[from][to].value;
	}

	// 행렬곱 연산 최소 값
	ll res = 1234567890;
	for (int i = from; i < to; i++)
	{
		res = min(solution(from, i) + solution(i + 1, to) + dp[from][i].row * dp[from][i].col * dp[i + 1][to].col, res);
	}

	dp[from][to].row = shp[from].row;
	dp[from][to].col = shp[to].col;
	dp[from][to].value = res;

	return res;
}