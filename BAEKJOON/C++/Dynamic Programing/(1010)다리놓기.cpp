#include<iostream>

using namespace std;

void solution();

typedef long long ll;
int N, M, testcase;
ll pascal[30][30];

int main(void)
{
	cin >> testcase;
	for (int i = 0; i < testcase; i++)
	{
		solution();
	}
	return 0;
}

ll combination(int m, int n)
{
	// Stop condition
	if (m == n) {
		pascal[m][n] = 1;
		return pascal[m][n];
	}
	else if (n == 1)
	{
		pascal[m][n] = m;
		return pascal[m][n];
	}
	else if (m < n) return 0;

	// Memoization
	if (pascal[m][n] != 0) return pascal[m][n];
	else
	{
		return pascal[m][n] = combination(m - 1, n - 1) + combination(m - 1, n);
	}
}

void input()
{
	cin >> N >> M;
}

void solution()
{
	input();

	cout << combination(M, N) << '\n';
}

