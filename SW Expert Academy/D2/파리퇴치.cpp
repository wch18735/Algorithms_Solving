#include<iostream>

using namespace std;

void solution(int test_case);

int PARI[15][15];
int N, M;

int main(void)
{
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++)
	{
		solution(test_case);
	}
	return 0;
}

void input()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> PARI[i][j];
		}
	}
}

int _sum(int i, int j, int M)
{
	int res = 0;
	for (int x = 0; x < M; x++)
	{
		for (int y = 0; y < M; y++)
		{
			res += PARI[i + x][j + y];
		}
	}

	return res;
}

int _max(int a, int b)
{
	if (a > b) return a;
	else return b;
}

void solution(int test_case)
{
	cin >> N >> M;

	input();

	int res = 0;
	for (int i = 0; i < N - M + 1; i++)
	{
		for (int j = 0; j < N - M + 1; j++)
		{
			res = _max(res, _sum(i, j, M));
		}
	}

	cout << '#' << test_case << ' ' << res << '\n';
}